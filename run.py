import sys
import subprocess
import matplotlib.pyplot as plt
import pandas as pd
import os.path


if not os.path.exists("render"):
    program = "g++ -std=c++17 -o render triangle.cpp sampler/sampler.cpp rndlb.cpp camera.cpp main.cpp sampler/halton.cpp sampler/scramble.cpp sampler/sobol.cpp"

    process = subprocess.Popen(program, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    output, error = process.communicate()

    if process.returncode != 0:
        print('Произошла ошибка при компиляции программы:')
        print(error.decode())
    else:
        print("Программа скомпилирована")

def run(args):

    execution_command = "./render " + " ".join(str(arg) for arg in args)

    execute_process = subprocess.Popen(execution_command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    execute_output, execute_error = execute_process.communicate()

    if execute_process.returncode == 0:
        print('Готово!')
    else:
        print('Произошла ошибка при выполнении программы:')
        print(execute_error.decode())

n = len(sys.argv)
if n == 1:
    args = ['--gen_type 0', '--spp 16']
    run(args)
else:
    spp = sys.argv[1] #сэмплы на пиксель
    gen_type = sys.argv[2] # тип генерации
    width = sys.argv[3] # ширина
    height = sys.argv[4] # высота
    generator = 0
    if gen_type == 'halton':
        generator = 1
    elif gen_type == 'sobol':
        generator = 2
    args = ['--gen_type ' + str(generator), '--spp ' + spp, '-w ' + width, '-h ' + height]
    run(args)