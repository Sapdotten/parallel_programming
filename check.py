from numpy import genfromtxt
import numpy as np
import os

root_folder = "data\examples"
# получение списка папок с тестами
examples = [os.path.join(root_folder, folder) for folder in os.listdir(root_folder) if os.path.isdir(os.path.join(root_folder, folder))]
# сортировка списка по номерам тестов
examples = sorted(examples, key = lambda x: int(x.split('_')[-1]))
# проверка тестов
for example in examples:
    mkmatrix = lambda x: genfromtxt(example+x, skip_header=1)
    A = mkmatrix("\A")
    B = mkmatrix("\B")
    C = mkmatrix("\C")
    C_test = np.dot(A, B)
    if np.allclose(C, C_test):
        print(f"{example} \033[92mSUCCESS\033[0m")
    else:
        print(f"{example} \033[91mFAILURE\033[0m")