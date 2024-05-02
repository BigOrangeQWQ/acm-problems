# 对当前文件夹及子文件下的所有 .bin .exe 文件进行删除

from pathlib import Path

path: Path = Path(".")

def rm_cache(path: Path):
    for file in path.iterdir():
        if file.is_dir():
            rm_cache(file)
        elif file.suffix == ".bin" or file.suffix == ".exe":
            print(f"Delete '{file}'")
            file.unlink()

if __name__ == "__main__":
    rm_cache(path)
