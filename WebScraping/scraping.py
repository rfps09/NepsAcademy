import requests
import pandas as pd
from BooksToScrap import BooksScrap

scraper = BooksScrap()
scraper.scrapeCategories("fantasy_19")
scraper.save("fantasy.csv")

df = pd.read_csv("fantasy.csv", index_col=0)

for index,book in df.iterrows():
    with open(f"{book['Title']}.jpg","wb") as f:
        response = requests.get(f"https://books.toscrape.com/{book['Image']}")
        f.write(response.content)