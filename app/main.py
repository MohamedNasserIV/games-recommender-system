import pandas as pd
import numpy as np
from sklearn.metrics.pairwise import cosine_similarity
from sklearn.feature_extraction.text import TfidfVectorizer
from fastapi import FastAPI, HTTPException
from pathlib import Path

DATA_PATH = Path(__file__).resolve().parent.parent / "data" / "processed" / "Clean_Steam.csv"


df = pd.read_csv(DATA_PATH)
df['soup'] = (df['Genre'].str.replace(',', ' ') + ' ' + 
              df['Category'].str.replace(',', ' ') + ' ' + 
              df['Description'] + ' ' + 
              df['Developer'] + ' ' + 
              df['Publishers'])


tfidf = TfidfVectorizer(stop_words= 'english')
tfidf_matrix = tfidf.fit_transform(df['soup'].fillna(''))

app = FastAPI()

@app.get("/")
def home():
    return {"message": "Games Recommender API"}

@app.get("/recommend/{game_name}")
def recommend(game_name: str):
    matches = df.index[df['Game_Name'] == game_name]
    if len(matches) == 0:
        raise HTTPException(status_code=404, detail="Game not found")
    index = matches[0]
    game_cosine = cosine_similarity(tfidf_matrix[index], tfidf_matrix).flatten()
    scores = list(enumerate(game_cosine))
    scores = sorted(scores, key=lambda x: x[1], reverse=True)
    return [{"id": int(df.loc[i[0], 'Game_ID']), "name": df.loc[i[0], 'Game_Name']} for i in scores[1:11]]


