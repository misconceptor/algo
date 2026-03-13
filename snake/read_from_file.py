import fileinput

file_name : str
file_name = input("ENTER FILE NAME: ")

with open(file_name) as file:
    print(f"FILE NAME IS \'{file.name}\'")
    lines = []
    for line in file:
        lines.append(line)

print(f"{len(lines)} LINES TOTAL")
for l in lines:
    print(l)