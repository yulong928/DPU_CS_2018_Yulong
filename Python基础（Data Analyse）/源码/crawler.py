import threading
import urllib

import re
from bs4 import BeautifulSoup
import requests


# def Craw(self, entryUrl):
#     g_toDlUrl.append(entryUrl)
#     self.logfile.write('>>>Entry:\n')
#     self.logfile.write(entryUrl)
#     depth = 0
#     while len(g_toDlUrl) != 0 and depth <= self.Maxdepth:
#         depth += 1
#         print('Searching depth ', depth, '...\n\n')
#         self.downloadAll()
#         self.updateToDl()
#         content = '\n>>>Depth ' + str(depth)+':\n'
#         self.logfile.write(content)
#         i = 0
#         while i < len(g_toDlUrl):
#             content = str(g_totalcount + i + 1) + '->' + g_toDlUrl[i] + '\n'
#             self.logfile.write(content)
#             i += 1


# class CrawlerThread(threading.Thread):
#     def __init__(self, url, fileName):
#         threading.Thread.__init__(self)
#         self.url = url
#         self.fileName = fileName


# def run(self):
#     global g_mutex
#     global g_failedUrl
#     global g_dledUrl
#     try:
#         f = urllib.urlopen(self.url)
#         s = f.read()
#         fout = file(self.fileName, 'w')
#         fout.write(s)
#         fout.close()
#     except:
#         g_mutex.acquire()
#         g_dledUrl.append(self.url)
#         g_failedUrl.append(self.url)
#         g_mutex.release()
#         print('Failed downloading and saving', self.url)
#         return None


# g_mutex.acquire()
# g_pages.append(s)
# g_dledUrl.append(self.url)
# g_mutex.release()


# def getHTMLText(url):
#     try:
#         r = requests.get(url, timeout=30)
#         r.raise_for_status()
#         r.encoding = 'utf-8'
#         return r.text
#     except:
#         return " error "


# def findHTMLText(text):
#     soup = BeautifulSoup(text, "html.parser")
#     return soup.find_all(string=re.compile('百度'))


# url = "https://www.baidu.com"
# text = getHTMLText(url)
# res = findHTMLText(text)
# print(res)

import sys
import time
lt = time.asctime(time.localtime(time.time()))
sys.ps1 = lt + " yulong >>"


class download(threading.Thread):
    def __init__(self, url, threadName):
        threading.Thread.__init__(self, name=threadName)
        self.thread_stop = False
        self.url = url

    def run(self):
        while not self.thread_stop:
            self.list = self.getUrl(self.url)
            self.downloading(self.list)

    def stop(self):
        self.thread_stop = True

    def downloading(self, list):
        for i in range(len(list) - 1):
            urllib.urlretrieve(list[i], '\%s.html' % time.time())

    def getUrl(self, url):
        result = []
        s = urllib.urlopen(url).read()
        ss = s.replace(' ', '')
        urls = re.findall('<a.*?href=.*?<\/a>', ss, re.I)
        for i in urls:
            tmp = i.split('"')
            if tmp[1]:
                if re.match(r'\http://.*', tmp[1]):
                    result.append(tmp[1])
        return result


if __name__ == '__main__':
    list = ['http://www.baidu.com', 'http://www.qq.com',
            'http://www.taobao.com', 'http://www.sina.com.cn']
    for i in range(len(list)):
        download(list[i], 'thread%s' % i).start()