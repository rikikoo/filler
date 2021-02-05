import re
import sys
import os
import csv
import pandas as pd
import matplotlib.pyplot as plt


def get_scores():
    results = open(output_file, "a+", newline='')
    w = csv.writer(results, delimiter=',')
    w.writerow([p1, p2])

    cmd = "./filler_vm -q -p1 players/" + p1 + " -p2 players/" + p2 + " -f maps/" + map_type

    for n in range(games):
        os.system(cmd)
        print("Game #" + str(n + 1) + " finished.")
        with open(input_file) as f:
            writer = csv.writer(results)
            for line in f:
                if "AGAINST" in line:
                    writer.writerow(re.findall(r'\d+', line))
        print("Game scores appended to table " + output_file + ".")

    results.close()


# Check arguments
if len(sys.argv) < 5:
    usage = "Usage: python3 " + sys.argv[0] + " <player 1 name> <player 2 name> <map[00...02]> <number of games>"
    example = "Example: python3 " + sys.argv[0] + " rkyttala superjeannot map00 30"
    print(usage)
    print(example)
    exit()

# initialize global variables
input_file = "filler.trace"
output_file = "results.csv"
p1 = str.lower(sys.argv[1]) + ".filler"
p2 = str.lower(sys.argv[2]) + ".filler"
map_type = sys.argv[3]
games = int(sys.argv[4])

# confirm overwrite from user and execute script if OK
if os.path.exists(output_file):
    while True:
        print(output_file + " already exists. Continuing will overwrite the existing file. Continue? y/n/(q)uit ")
        ans = input()
        if str.lower(ans) == "y":
            os.remove(output_file)
            get_scores()
            break
        elif str.lower(ans) == "n":
            break
        elif str.lower(ans) == "q":
            exit()
        else:
            continue

# output win percentages and draw plot
df = pd.read_csv(output_file)

score1 = 0
score2 = 0
for index, row in df.iterrows():
    if row[p1] > row[p2]:
        score1 += 1
    else:
        score2 += 1
print("\n" + p1 + "'s win percentage after " + str(games) + " games on " + map_type + ": "
      + str((score1 / games * 100)) + "%")
print(p2 + "'s win percentage after " + str(games) + " games on " + map_type + ": "
      + str((score2 / games * 100)) + "%\n")

plt.plot(df[p1], label=p1)
plt.plot(df[p2], label=p2)
plt.title("results of " + str(games) + " games of filler")
plt.xlabel("game #")
plt.ylabel("score")
plt.legend()
plt.show()

__doc__ = """
Script for running multiple games of filler and plotting the results.

The program takes 4 arguments (in the following order):
    player 1 name -- just the name, e.g. 'superjeannot'. Assumed path to player's binary is 'resources/players/'
    player 2 name -- exactly the same as with player 1
    map file -- 1 of 3 choices: 'map00', 'map01', 'map02'. NOTE: map02 games take a lot of time
    number of games -- any positive whole number. Program will run the filler_vm as many times as specified here, \
    regardless of any possible errors in the virtual machine
"""
