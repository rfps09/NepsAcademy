from email.mime import image
import requests
from bs4 import BeautifulSoup
import pandas as pd

r = requests.get("https://books.toscrape.com/catalogue/category/books/fantasy_19/index.html")

books = []

if r.status_code == 200:
    soup = BeautifulSoup(r.text, "html.parser")

    content = soup.select("section ol li")

    for li in content:
        image_url = li.find("img").get("src")
        stars = li.find("p").get("class")[1]
        title = li.find("h3").find("a").get("title")
        price = li.find("div", class_ = "product_price").find("p", class_="price_color").text
        price = price[1:len(price)]

        books.append([image_url,stars,title,price])
        print(image_url,stars,title,price)

    df = pd.DataFrame(data=books, columns=["Link","star","title","price"])

    print(df)
