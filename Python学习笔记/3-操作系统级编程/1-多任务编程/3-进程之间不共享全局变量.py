import multiprocessing
import time

g_list = list()

def add_data():
    for i in range(5):
        g_list.append(i)
        print('add',i)
        time.sleep(0.2)
    print("add_data:",g_list)

def read_data():
    print("read_data:",g_list)

if __name__ == '__main__':
    add_data_process = multiprocessing.Process(target=add_data)
    read_data_process = multiprocessing.Process(target=read_data)
    add_data_process.start()
    add_data_process.join()
    read_data_process.start()
    print("main:",g_list)

#result:
    # add 0
    # add 1
    # add 2
    # add 3
    # add 4
    # add_data: [0, 1, 2, 3, 4]
    # main: []
    # read_data: []