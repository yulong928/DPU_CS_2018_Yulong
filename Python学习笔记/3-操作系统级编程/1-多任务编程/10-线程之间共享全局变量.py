import threading
import time

my_list = list()

def write_data():
    for i in range(5):
        my_list.append(i)
        print("write_data:", my_list)
        time.sleep(0.1)


def read_data():
    for i in range(5):
        print("read_data:", my_list)
        time.sleep(0.1)


if __name__ == '__main__':
    write_thread = threading.Thread(target=write_data)
    read_thread = threading.Thread(target=read_data)
    write_thread.start()
    time.sleep(0.2)
    read_thread.start()

#result:
    # write_data: [0]
    # write_data: [0, 1]
    # read_data: [0, 1]
    # write_data: [0, 1, 2]
    # read_data: [0, 1, 2]
    # write_data: [0, 1, 2, 3]
    # read_data:write_data: [0, 1, 2, 3, 4]
    #  [0, 1, 2, 3, 4]
    # read_data: [0, 1, 2, 3, 4]
    # read_data: [0, 1, 2, 3, 4]
