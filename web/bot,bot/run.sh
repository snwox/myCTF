source virtualenv/bin/activate
nohup python3 app.py 1 10000 &
nohup python3 app.py 2 10010 &
nohup python3 app.py 3 10020 &
nohup python3 app.py 4 10030 &
deactivate
