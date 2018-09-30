import re
import urllib.request
import sys
import pathlib
from os import path
import os
from shutil import copyfile

if len(sys.argv) < 2:
    print("Need option and problemset number")
    sys.exit(0)
 
number = sys.argv[1]
abs_file_path = ""
 
def parse_task(index):
    r = urllib.request.urlopen("http://codeforces.com/contest/" + number + "/problem/" +
                     index).read()
    s = str(r)
    a = re.findall("Input</div><pre>.*?</pre>", s)
    b = re.findall("Output</div><pre>.*?</pre>", s)

    global abs_file_path 
    abs_file_path = '\\Raghav\\C++\\Contests\\Codeforces\\' + number
 
    if (len(a) == 0):
        print("Something went wrong...")
        sys.exit(0)
 
    assert(len(a) == len(b))
    for i in range(len(a)):
        a[i] = a[i][16:-6].replace('<br />', '\n')
        b[i] = b[i][17:-6].replace('<br />', '\n')
 
    for i in range(len(a)):
        file_path = abs_file_path + '\\' + index + "\\in\\"
        if not os.path.exists(file_path):
            os.makedirs(file_path)
        with open(file_path + index + str(i) + ".in", "w+") as f:
            f.write(a[i])
        file_path = abs_file_path + '\\' + index + "\\out\\"
        if not os.path.exists(file_path):
            os.makedirs(file_path)
        with open(file_path + index + str(i) + ".out", "w+") as f:
            f.write(b[i])
 
r = urllib.request.urlopen("http://codeforces.com/contest/" + number).read()
s = str(r)
a = re.findall("/contest/" + number + "/problem/.", s)
a = sorted(list(set(a)))

for x in a:
    print(x)
    parse_task(x[-1])
    copyfile("\\Raghav\\C++\\sample\\main.cpp", abs_file_path + "\\" + x[-1] + "\\" + x[-1] + ".cpp")