# whyc.py
# rewritten and updated from whyc.c
# Version 0.0.2

import sys
import os
import time
arguments = sys.argv

if len(arguments) < 2:
    sys.exit("No arguments provided.")

print("Valid")
time.sleep(1)
os.system('cls' if os.name == 'nt' else 'clear')

try:
    with open(arguments[1], 'r') as f:
        content = f.read()
        print(content)
        time.sleep(2)
except FileNotFoundError:
    print(f"Error: File '{arguments[1]}' not found")
except Exception as e:
    print(f"Error: {str(e)}")