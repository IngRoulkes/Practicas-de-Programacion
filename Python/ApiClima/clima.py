import requests

API_KEY = 'esta es una clave que se genera desde la website'
URL = "https://api.openweathermap.org/data/2.5/weather"

ciudad = input("Ingresa el nombre de la ciudad para consultar los datos: ")

parametros = {
    "q": ciudad,
    "appid": API_KEY,
    "units": "metric",   
    "lang": "es"         
}

respuesta = requests.get(URL, params=parametros)
datos = respuesta.json()

if respuesta.status_code == 200:
    nombre = datos["name"]
    pais = datos["sys"]["country"]
    temp = datos["main"]["temp"]
    descripcion = datos["weather"][0]["description"]
    humedad = datos["main"]["humidity"]
    viento = datos["wind"]["speed"]

    print(f"\nClima en {nombre}, {pais}:")
    print(f"Temperatura: {temp}°C")
    print(f"Condición: {descripcion}")
    print(f"Humedad: {humedad}%")
    print(f"Velocidad del viento: {viento} m/s")
else:
    print(f"Error {datos['cod']}: {datos['message']}")
