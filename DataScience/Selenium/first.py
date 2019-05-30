from selenium import webdriver

# chromedriver 위치 지정
driver = webdriver.Chrome('./chromedriver')

# 기다리는 시간 임의 지정
driver.implicitly_wait(3)

# url 접근
driver.get('https://google.com')