import os
import time

if __name__=='__main__':
  folder_path = "E:\\EffectiveDebug\\111\\notes\\test"  # 文件夹路径
  log_file_name = "loginfo.log"  # 日志文件名
  log_file_path = os.path.join(folder_path, log_file_name)  # 日志文件路径

  # 检查文件夹是否存在，如果不存在则创建
  if not os.path.exists(folder_path):
    os.makedirs(folder_path)

  # 检查loginfo.log文件是否存在，如果不存在则创建
  if not os.path.exists(log_file_path):
    with open(log_file_path, "w") as f:
        pass

  # 获取文件夹中的所有日志文件
  log_files = [f for f in os.listdir(folder_path) if f.startswith("loginfo_")]
  last_mtime = 0  # 初始化 last_mtime 为 0
  while True:
    # 遍历日志文件，将它们的内容追加到loginfo.log文件中
    with open(log_file_path, "w") as log_file:
        for log_file_name in log_files:
            log_file_path = os.path.join(folder_path, log_file_name)
            # 获取日志文件的最近一次修改时间
            log_file_mtime = os.stat(log_file_path).st_mtime
            # 如果日志文件被修改，则将内容追加到loginfo.log文件中
            if log_file_mtime > last_mtime:
                with open(log_file_path, "r") as f:
                    log_file.write(f.read())
                last_mtime = log_file_mtime

    # 等待一段时间后重新检查日志文件
    # time.sleep(60)