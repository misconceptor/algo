import requests

api_key = "0c4ce8478debe5ebe16246682e7c6182"

lat = input("input latitude: ")
lon = input("input longtitude: ")

params = {
    "lat": lat,
    "lon": lon,
    "appid": api_key
}

r = requests.get(
    "https://api.openweathermap.org/data/2.5/weather",
    params = params
)
print(r.text)


