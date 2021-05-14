import os

def main():
    err = False
    os.system('ls samples_tiger/ > temp/files.temp');
    file = open('temp/files.temp')
    for line in file:
        nameline = line.replace('\n', '')
        os.system('./a.out samples_tiger/'+nameline)        

main()