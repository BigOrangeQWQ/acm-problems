from pathlib import Path
from random import sample
from typing import List
from shutil import copy2

data_dir = Path('./garbage')
data_list: List[str]=['2','4','7','11','19','22','31','23','37']

# 打开文件
path: Path = data_dir / "train" #进入数据集文件夹

train_data_85: List[Path] = []
train_data_15: List[Path]= []

for name in data_list:
    files = list((path / name).iterdir())
    files_len = len(files)
    pre = sample(files, int(files_len * 0.15))
    train_data_15.extend(pre)
    train_data_85.extend([i for i in files if i not in pre])


for file in train_data_85:
    copy2(file, data_dir / "precent85" / file.name)
for file in train_data_15:
    copy2(file, data_dir / "precent15" / file.name)