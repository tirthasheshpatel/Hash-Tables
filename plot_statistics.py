import pandas as pd 
import matplotlib.pyplot as plt 
import numpy as np 

dataset = pd.read_csv("insert_time.csv")
plt.plot(dataset.iloc[:, 0], dataset.iloc[:, 1], color='g', label='time')
plt.plot(range(dataset.shape[0]), np.mean(dataset.iloc[:, 1].values)*np.ones((dataset.shape[0]), dtype='float32'), color='r', label='mean')
plt.xlabel("Keys Inserted")
plt.ylabel("Time Taken (nanoseconds)")
plt.title("Insertion time Analysis")
plt.legend()
plt.show()

dataset = pd.read_csv("search_time.csv")
plt.plot(dataset.iloc[:, 0], dataset.iloc[:, 1], color='g', label='time')
plt.plot(range(dataset.shape[0]), np.mean(dataset.iloc[:, 1].values)*np.ones((dataset.shape[0]), dtype='float32'), color='r', label='mean')
plt.xlabel("Keys Inserted")
plt.ylabel("Time Taken (nanoseconds)")
plt.title("Search time Analysis")
plt.legend()
plt.show()

dataset = pd.read_csv("delete_time.csv")
plt.plot(dataset.iloc[:, 0], dataset.iloc[:, 1], color='g', label='time')
plt.plot(range(dataset.shape[0]), np.mean(dataset.iloc[:, 1].values)*np.ones((dataset.shape[0]), dtype='float32'), color='r', label='mean')
plt.xlabel("Keys Inserted")
plt.ylabel("Time Taken (nanoseconds)")
plt.title("Search time Analysis")
plt.legend()
plt.show()