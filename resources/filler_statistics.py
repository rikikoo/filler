import re
import sys
import os
import csv
sys.path.insert(1, "/usr/local/lib/python3.7/site-packages")
import pandas as pd
import matplotlib.pyplot as plt


def get_scores(results):
    with open(input_file) as f:
        writer = csv.writer(results)
        for line in f:
            if "AGAINST" in line:
                writer.writerow(re.findall(r'\d+', line))


if len(sys.argv) < 5:
    usage = "Usage: python3 " + sys.argv[0] + " <player 1 name> <player 2 name> <map[00...02]> <number of games>"
    example = "Example: python3 " + sys.argv[0] + " rkyttala superjeannot map00 50"
    print(usage)
    print(example)
    exit()

input_file = "filler.trace"
output_file = "results.csv"

if os.path.exists(output_file):
    while True:
        print(output_file + " already exists. Continuing will replace the existing file. Continue? y/n ")
        ans = input()
        if str.lower(ans) == "y":
            os.remove(output_file)
            break
        elif str.lower(ans) == "n":
            exit()
        else:
            continue

p1 = str.lower(sys.argv[1]) + ".filler"
p2 = str.lower(sys.argv[2]) + ".filler"
map_type = sys.argv[3]
games = int(sys.argv[4])

res = open(output_file, "a+", newline='')
w = csv.writer(res, delimiter=',')
w.writerow([p1, p2])

cmd = "./filler_vm -q -p1 players/" + p1 + " -p2 players/" + p2 + " -f maps/" + map_type

for n in range(games):
    os.system(cmd)
    print("Game #" + str(n + 1) + " finished.")
    get_scores(res)
    print("Game scores appended to table " + output_file + ".")

res.close()
df = pd.read_csv(output_file)
p1_col = df[p1]
p2_col = df[p2]

plt.plot(p1_col)
plt.plot(p2_col)
plt.figure()