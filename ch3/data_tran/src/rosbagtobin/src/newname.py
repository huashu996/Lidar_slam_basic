# coding = utf-8

# 给文件重命名

import os


def rename_number(dirpath):
    count = 0
    file_name = os.listdir(dirpath)
    print(file_name)
    for file in file_name:
        new_name = str(count) + ' ' +str(file)
        os.chdir(dirpath)
        os.rename (file, new_name)
        count +=1


rename_number('./data')
