import os

def main():
    err = False
    os.system('ls samples_tiger/ > temp/files.temp');
    file = open('temp/files.temp')
    for line in file:
        nameline = line.replace('\n', '')
        os.system('./a.out samples_tiger/'+nameline+ ' 2> temp/execution.temp')
        execution = open('temp/execution.temp')
        for line2 in execution:
            if 'error' in line2:
                err = True
                print('Error into file('+nameline+'): '+line2)
                break
        if err:
            break

main()