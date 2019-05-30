from selenium import webdriver
from bs4 import BeautifulSoup

driver = webdriver.Chrome('chromedriver')

driver.implicitly_wait(3)

driver.get('https://nid.naver.com/nidlogin.login')

# id/pw 입력해준다
driver.find_element_by_name('id').send_keys('savemywords')
driver.find_element_by_name('pw').send_keys('jaesu4snu')

# 로그인 버튼 누르기
driver.find_element_by_xpath('//*[@id="frmNIDLogin"]/fieldset/input').click()

# 네이버 페이 들어가기
driver.get('https://order.pay.naver.com/home')
html = driver.page_source
soup = BeautifulSoup(html, 'html.parser')
notices = soup.select('div.p_inr > div.p_info > a > span')

for n in notices:
    print(n.text.strip())