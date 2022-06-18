import multiprocessing
import time


def child_process():
    for i in range(5):
        print("process is going...")
        time.sleep(0.2)


if __name__ == '__main__':
    child_sub_process = multiprocessing.Process(target=child_process)
    child_sub_process.start()
    time.sleep(0.5)
    print('parent process is end')
    child_sub_process.terminate()
    exit()

#result:
    # process is going...
    # process is going...
    # process is going...
    # parent process is end
