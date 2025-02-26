import matplotlib.pyplot as plt
import pandas as pd

results_file = "data/time_result.csv"


data = pd.read_csv(results_file, header=None, delimiter=";")

plt.plot(data[0], data[1], marker="o")
plt.xlabel("Размер матриц")
plt.ylabel("Время вычисления, мс")
plt.title("График зависимости времени перпемножения матриц от их размера")
plt.grid()
plt.show()
