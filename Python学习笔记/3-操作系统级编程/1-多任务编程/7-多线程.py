import threading
import time

def sing():
    for i in range(3):
        print("正在唱歌...%d"%i)
        time.sleep(0.5)

def dance():
    for i in range(3):
        print("正在跳舞...%d"%i)
        time.sleep(1)


if __name__ == '__main__':
    sing_thread = threading.Thread(target=sing)
    dance_thread = threading.Thread(target=dance)
    sing_thread.start()
    dance_thread.start()

#result:
    # 正在唱歌...0正在跳舞...0
    #
    # 正在唱歌...1
    # 正在跳舞...1
    # 正在唱歌...2
    # 正在跳舞...2