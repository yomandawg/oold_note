import requests

url = "https://jsonplaceholder.typicode.com/"
response = requests.get(url + "posts")
print(response)\