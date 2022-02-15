import requests
from bs4 import BeautifulSoup
import pandas as pd

r = requests.get("https://books.toscrape.com")

categories = []
if r.status_code == 200:
    page_content = r.text
    soup = BeautifulSoup(page_content, "html.parser")

    categories_li = soup.select(".side_categories ul li ul li")

    for li in categories_li:
        name = li.text.replace("\n", "").rstrip().lstrip()
        link = li.find("a").get("href")

        categories.append([name, link])

    df = pd.DataFrame(data=categories, columns=["Name", "Link"])
    df = df.sort_values(by="Name")

    # Salvando os dados no arquivo categories.csv
    df.to_csv("categories.csv")

    # Para carregar os dados nós usamos o read_csv. O parâmetro index_col parameter informa o pandas que a primeira coluna do nosso csv está guardando o indice
    df = pd.read_csv("categories.csv", index_col=0)
    for index,book in df.iterrows():
        print("{}: {} , {}".format(index,book["Name"], book["Link"]))
