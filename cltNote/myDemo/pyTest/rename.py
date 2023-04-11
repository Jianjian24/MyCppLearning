import os
import re

def rename (path):
    filename_list = os.listdir(path) 
    """os.listdir(path) 扫描路径的文件，将文件名存入存入列表"""

    for fileName in filename_list:
        newname = re.sub('正常.*.png$', 'Normal.png', fileName, 1)
        if newname == fileName:
            continue
        used_name = path + fileName
        new_name = path + newname # 保留原后缀
        os.rename(used_name, new_name)

    for fileName in filename_list:
        newname = re.sub('异常.*.png$', 'Exception.png', fileName, 1)
        if newname == fileName:
            continue
        used_name = path + fileName
        new_name = path + newname # 保留原后缀
        os.rename(used_name, new_name)

    # for fileName in filename_list:
    #     newname = re.sub('剩余.*.png$', 'Less.png', fileName, 1)
    #     if newname == fileName:
    #         continue
    #     used_name = path + fileName
    #     new_name = path + newname # 保留原后缀
    #     os.rename(used_name, new_name)

    # for fileName in filename_list:
    #     newname = re.sub('总数.*.png$', 'Total.png', fileName, 1)
    #     if newname == fileName:
    #         continue
    #     used_name = path + fileName
    #     new_name = path + newname # 保留原后缀
    #     os.rename(used_name, new_name)

if __name__=='__main__':
    path="C:\\Code\\框架调整-plc\\Bin\\Calibration\\v12\\x64\\Debug\\Resource\\StyleWhite\\DPI100\\CaliLog\\CaliLogIconSmall\\" # 目标路径
    rename(path)
    path="C:\\Code\\框架调整-plc\\Bin\\Calibration\\v12\\x64\\Debug\\Resource\\StyleWhite\\DPI150\\CaliLog\\CaliLogIconSmall\\" # 目标路径
    rename(path)
    path="C:\\Code\\框架调整-plc\\Bin\\Calibration\\v12\\x64\\Debug\\Resource\\StyleWhite\\DPI250\\CaliLog\\CaliLogIconSmall\\" # 目标路径
    rename(path)