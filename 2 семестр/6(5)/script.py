import sys
import random


def main():
    with open(sys.argv[1], "r") as f:
        names = f.readlines()
    output_args = sys.argv[1].split(".")
    output_name = output_args[0] + "_out" + "." + output_args[1] 
    with open(output_name, "w") as f:
        for j in names:
            info = j.split()
            last_name = info[0]
            gender = info[3]
            gio = info[0][0] + info[1][0] + info[2][0]
            score1 = random.randint(60, 100)
            score2 = random.randint(60, 100)
            score3 = random.randint(60, 100)        
            medal = random.randint(0, 1)
            num_of_school = random.randint(1000, 1600)
            sochin = 1
            f.write(f"{last_name} {gio} {gender} {num_of_school} {medal} {score1} {score2} {score3} {sochin}\n")
            

if __name__ == "__main__":
    main()
