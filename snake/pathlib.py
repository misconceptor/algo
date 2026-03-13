from pathlib import Path
current = Path('.')
print(current.absolute())
print("FILES: ")
for i in current.iterdir():
    if i.is_file():
        print(i.name, end = ' ')

print()
print("DIRECTORIES: ")
for i in current.iterdir():
    if i.is_dir():
        print(i.name, end = ' ')
print()