import threading
import time

def show_info():
    for i in range(5):
        print("test:", i)
        time.sleep(0.5)


if __name__ == '__main__':
    sub_thread = threading.Thread(target=show_info, daemon=True)
    # sub_thread.setDaemon(True)
    sub_thread.start()
    time.sleep(1)
    print("over")

#result：
    # test: 0
    # test: 1
    # over