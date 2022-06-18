import threading
import time

g_num = 0

lock = threading.Lock()

def sum_num1():
    for i in range(1000000):
        lock.acquire()
        global g_num
        g_num += 1
        lock.release()

def sum_num2():
    for i in range(1000000):
        lock.acquire()
        global g_num
        g_num += 1
        lock.release()

if __name__ == '__main__':
    first_thread = threading.Thread(target=sum_num1)
    second_thread = threading.Thread(target=sum_num2)
    first_thread.start()
    second_thread.start()
    for i in range(35):
        print(g_num,end=' ')
        if (i%10==0)&(i!=0):
            print()
        time.sleep(0.01)

# result:
    # 20343 88397 153357 248728 302287 356780 437757 494705 544366 652081 705001
    # 755286 835664 943429 996975 1051972 1100072 1154027 1207119 1288185 1366398
    # 1430254 1498314 1547544 1599400 1653668 1735005 1817667 1885925 1965791 2000000
    # 2000000 2000000 2000000 2000000