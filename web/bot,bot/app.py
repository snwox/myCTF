from flask import Flask, request, url_for, abort, render_template
from selenium import webdriver
from urllib import parse
from pyvirtualdisplay import Display
import os
import sqlite3
import json
import re
import sys

app = Flask(__name__)
app.secret_key = os.urandom(16)


@app.route('/', methods=['GET'])
def index():
    return render_template('main.html')


@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'GET':
        return render_template('login.html')
    elif request.method == 'POST':
        username = request.form.get('username')
        password = request.form.get('password')

        db = sqlite3.connect(os.path.dirname(os.path.realpath(__file__)) + "/db/" + DBNAME)
        cursor = db.cursor()
        cursor.execute("SELECT role, state, id FROM users WHERE id=? AND password=?", (username, password))
        query_data = cursor.fetchall()
        db.close()
        print(query_data)
        if len(query_data) == 1:
            if query_data[0][0] == 'admin' and query_data[0][1] == 'active':
                return FLAG
            elif query_data[0][1] == 'active':
                return f"Hi {query_data[0][0]}. Login as admin."
            else:
                abort(401, "No hack.")
        else:
            abort(401, "No hack.")


@app.route('/____read_report____')
def read_report():
    message = request.args.get('report', '')
    return message


@app.route('/error', methods=['GET', 'POST'])
def report_error():
    if request.method == 'GET':
        return render_template('report.html')
    elif request.method == 'POST':
        if app.config['WARGAME_LEVEL'] > 3 and \
                len(re.compile(r'script|onerror', re.IGNORECASE).findall(request.form.get('report'))) != 0:
            abort(401, 'No hack.')

        try:
            display = Display(visible=0, size=(1920, 1080))
            display.start()
            driver = webdriver.Chrome(os.path.dirname(os.path.realpath(__file__))+'/chromedriver')
            driver.implicitly_wait(3)
            driver.set_page_load_timeout(3)

            driver.get(f"http://127.0.0.1:{app.config['PORT_NO']}{url_for('read_report')}?report="
                       f"{parse.quote(request.form.get('report'))}")
        except:
            driver.quit()
            return "<script> alert(\"Error\"); history.go(-1) </script>"
        driver.quit()
        return "<script> alert(\"Success\"); history.go(-1) </script>"


@app.route('/api', methods=['GET'])
def api_usage():
    return render_template('api.html', level=app.config['WARGAME_LEVEL'])


@app.route('/api/<path:query>', methods=['GET'])
def local_api(query):
    if request.remote_addr != '127.0.0.1' and app.config['WARGAME_LEVEL'] > 1:
        abort(401, 'Due to security reasons, only localhost is allowed to use the API.')

    if query.split('/')[0].lower() != 'select':
        abort(401, 'Due to security reasons, only select query is available.')
    else:
        query = ' '.join(query.split('/'))
        
    if app.config['WARGAME_LEVEL'] > 2 and \
            re.compile(r'\'|admin|=|*', re.IGNORECASE).findall(query) != 0:
        abort(401, 'No hack.')

    try:
        db = sqlite3.connect(os.path.dirname(os.path.realpath(__file__)) + "/db/" + DBNAME)
        cursor = db.cursor()
        cursor.execute(query)

        return_data = []
        for data in cursor.fetchall():
            return_data.append(data)
        db.close()
    except sqlite3.Error as e:
        print(e)
        return json.dumps({"result": "fail"})
    return json.dumps({"result": "success", "data": return_data})


if __name__ == '__main__':
    '''
        WARGAME_LEVEL 
        1: Vulnerable API, with no protection method 
        2: API is only available to localhost. Use XSS and SSRF to exploit.
        3: Simple SQLi filtering on API + protection method above
        4: Simple JS filtering on report function + protection method above
    '''
    if len(sys.argv) == 1:
        app.config['WARGAME_LEVEL'] = 2
        app.config['PORT_NO'] = '10000'
    else:
        app.config['WARGAME_LEVEL'] = int(sys.argv[1])
        app.config['PORT_NO'] = str(sys.argv[2])
    
    with open(f"flag{str(app.config['WARGAME_LEVEL'])}.txt", 'r') as f:
        try:
            FLAG = f.read()
        except FileNotFoundError:
            FLAG = 'SNWO{}'
    DBNAME = f"database{str(app.config['WARGAME_LEVEL'])}.db"

    app.run(debug=False, host='0.0.0.0', port=app.config['PORT_NO'])
