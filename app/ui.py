import streamlit as st
import requests
from urllib.parse import quote

st.set_page_config(page_title="Games Recommender", layout="wide")
st.title("🎮 Games Recommender")

game = st.text_input("Enter a game name")

if st.button("Recommend"):
    API_URL = "https://games-recommender-system-g3n2.onrender.com"
    response = requests.get(f"{API_URL}/recommend/{quote(game)}", timeout=90)
    if response.status_code == 200:
        games = response.json()
        cols = st.columns(5)              
        for i, g in enumerate(games):
            with cols[i % 5]:
                st.image(f"https://cdn.cloudflare.steamstatic.com/steam/apps/{g['id']}/header.jpg")
                st.caption(g["name"])          
    else:
        st.error("Game not found")