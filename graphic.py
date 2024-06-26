import pandas as pd
import matplotlib.pyplot as plt

# Leer el archivo
archivo = '/Users/niaggar/Developer/Temporal/GaltonBoardTest/histogram.txt'
data = pd.read_csv(archivo, sep=" ", header=None, names=["Bin", "Conteo"])

# Graficar el histograma
plt.figure(figsize=(10, 6))
plt.bar(data['Bin'], data['Conteo'], width=0.8, color='skyblue', edgecolor='black')
plt.xlabel('Número de Bin')
plt.ylabel('Conteo')
plt.title('Histograma de Datos')
plt.xticks(data['Bin'])
plt.grid(axis='y', linestyle='--', alpha=0.7)
plt.show()
