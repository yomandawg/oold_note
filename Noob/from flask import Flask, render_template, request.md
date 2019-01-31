from flask import Flask, render_template, request
import requests

app = Flask(__name__)

@app.route('/')
def index():
​    return render_template('index.html')
​    
@app.route('/sendmsg')
def sendmsg():
​    msg = request.args.get('msg') # 파라미터의 이름 == 보낸 박스의 이름
​    
    token = "bot636693654:AAEkWQkkGcJiFWcaf2AS7D0-IPnAjuj7JG8"
    original_url = "https://api.telegram.org/"
    url = "https://api.hphk.io/telegram/" # 우회 url, origianl 막힘
    
    result = url + token + "/sendMessage?chat_id=706212804&text=" + msg
    
    # result = url + token + "/sendMessage?chat_id=" + friend_chat_id + "&text=" + msg
    
    my_chat_id = '779667174'
    friend_chat_id = '706212804'
    # https://api.telegram.org/bot636693654:AAEkWQkkGcJiFWcaf2AS7D0-IPnAjuj7JG8/
    
    # telegram에 메세지를 보내자
    # 1. 우리 챗봇의 고유 key값을 받아 저장한다.
    # 2. key/token 값을 통해서 /getMe (나(봇)에 대한 정보) /getUpddates (봇에 대한 상태 정보) 메쏘드
    # 3. https://api.telegram.org/bot<token>/METHOD_NAME
    # https://api.telegram.org/bot123456:ABC-DEF1234ghIkl-zyx57W2v1u123ew11/getMe
    # 5. 메세지를 보내는 메소드(방법)는 sendMessage
    #   - chat_id='779667174' (나의 아이디)
    # https://api.telegram.org/bot636693654:AAEkWQkkGcJiFWcaf2AS7D0-IPnAjuj7JG8/sendMessage?chat_id=706212804&text=<text> 보내기
    requests.get(result)
    
    return render_template('sendmsg.html', msg = msg)