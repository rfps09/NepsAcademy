import requests
from bs4 import BeautifulSoup

x = requests.get("https://books.toscrape.com/")

if x.status_code == 200:
    h = BeautifulSoup(x.text,"html.parser")

    li_content = h.select(".side_categories ul li ul li")

    for li in li_content:
        print(li.text.replace("\n", "").lstrip().rstrip())