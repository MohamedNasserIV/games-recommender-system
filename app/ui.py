import streamlit as st
import requests
from urllib.parse import quote

st.set_page_config(page_title="Games Recommender", layout="wide")
st.title("🎮 Games Recommender")

game = st.text_input("Enter a game name")

if st.button("Recommend"):
    response = requests.get(f"http://127.0.0.1:8000/recommend/{quote(game)}")
    if response.status_code == 200:
        games = response.json()
        cols = st.columns(5)              
        for i, g in enumerate(games):
            with cols[i % 5]:
                st.image(f"https://cdn.cloudflare.steamstatic.com/steam/apps/{g['id']}/header.jpg")
                st.caption(g["name"])          
    else:
        st.error("Game not found")