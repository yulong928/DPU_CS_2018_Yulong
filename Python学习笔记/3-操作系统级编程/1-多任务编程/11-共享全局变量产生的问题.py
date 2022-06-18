import threading

g_num = 0

def sum_num1():
    for i in range(1000000):
        global g_num
        g_num += 1

    print("sum1:", g_num)

def sum_num2():
    for i in range(1000000):
        global g_num
        g_num += 1
    print("sum2:", g_num)

if __name__ == '__main__':
    first_thread = threading.Thread(target=sum_num1)
    second_thread = threading.Thread(target=sum_num2)
    first_thread.start()
    #进程等待
    first_thread.join()
    second_thread.start()