import requests
from bs4 import BeautifulSoup
import pandas as pd

class Books:
    def __init__(self,title,review,price,image_url):
        self.title = title
        self.review = review
        self.price = price
        self.image_url = image_url

    def __repr__(self):
        return f"<{self.title},{self.review},{self.price},{self.image_url}>"

class BooksScrap:
    base_url = "https://books.toscrape.com"

    def __init__(self):
        self.books = []

    def scrapeCategories(self, category, page=1):
        r = requests.get(f"{self.base_url}/catalogue/category/books/{category}/page-{page}.html")

        if r.status_code == 200:
            page_content = r.text
            soup =  BeautifulSoup(page_content,"html.parser")

            for book in soup.select("section ol li"):
                image_url = book.find("div").find("img").get("src")
                image_url = image_url.replace("../../../..","")
                title = book.find("h3").find("a").get("title")
                review = book.find("p").get("class")[1]
                price = book.find("div", class_="product_price").find("p").text
                price = price[1:len(price)]

                self.books.append([title,price,review,image_url])

            if self.__has_next(page_content):
                self.scrapeCategories(category, page + 1)

    def __has_next(self, html):
        soup = BeautifulSoup(html, "html.parser")

        next_button = soup.select("li.next a")

        return not next_button is None

    def save(self, name):
        if len(self.books) > 0:
            df = pd.DataFrame(data=self.books,columns=["Title","Price","Review","Image"])
            df.to_csv(name)