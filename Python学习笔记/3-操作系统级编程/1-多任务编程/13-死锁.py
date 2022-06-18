import threading
import time

lock = threading.Lock()

def get_value(index):

    lock.acquire()
    print(threading.current_thread())
    my_list = [3,6,8,1]
    if index >= len(my_list):
        print("下标越界:", index)
        #在合适的地方释放锁
        lock.release()
        return
    value = my_list[index]
    print(value)
    time.sleep(0.2)
    lock.release()


if __name__ == '__main__':
    for i in range(30):
        sub_thread = threading.Thread(target=get_value, args=(i,))
        sub_thread.start()