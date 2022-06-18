import threading
import time
def task():
    time.sleep(0.5)
    print("当前线程:", threading.current_thread().name)
if __name__ == '__main__':
    for _ in range(5):
        sub_thread = threading.Thread(target=task)
        sub_thread.start()

#result:
    # 当前线程: Thread-1
    # 当前线程: Thread-3
    # 当前线程: 当前线程: Thread-2
    # Thread-5
    # 当前线程: Thread-4