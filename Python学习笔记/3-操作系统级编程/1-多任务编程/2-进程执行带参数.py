import multiprocessing
import time

def task(count):
    for i in range(count):
        print("process is going...")
        time.sleep(0.2)
    else:
        print('process is finished.')

if __name__ == '__main__':
    sub_process = multiprocessing.Process(target=task,kwargs={"count":3})
    sub_process.start()

# result:
#     process is going...
#     process is going...
#     process is going...
#     process is finished.