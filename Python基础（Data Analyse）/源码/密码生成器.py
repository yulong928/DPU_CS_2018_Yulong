import random

def get_upper():
    count = random.randint(1, 3)    #表明生成的随机数只能在1～3之间
    return random.choices('ABCDEFGHIJKLMNOPQRSTUVWXYZ', k=count)    #在大写字母序列中选出k个字符


def get_special_char():
    count = random.randint(1, 3)
    return random.choices('!@$%^&*()_+~', k=count)      #在特殊字符串生成k个字符


def get_lower(count):   #参数count的值为字符总长度减去大写字母和特殊字符的长度
    string = 'abcdefghijklmnopqrstuvwxyz0123456789'
    return random.choices(string, k=count)


def generate_password():

    length = random.random() * 100
    length = int(length % 10 + 6 )      #设置密码长度，使其保持在6～16之间，可用random.randint(6, 16)代替


    lst = []       #初始化密码串
    upper_lst = get_upper()     #调用大写字母串生成函数
    special_char = get_special_char()       #调用特殊字符生成函数
    lst.extend(upper_lst)
    lst.extend(special_char)            #将大写字母和特殊字符加入密码串中

    surplus_count = length - len(lst)           #求出小写字母和数字串长度（密码剩余长度）
    lower_lst = get_lower(surplus_count)        #获取小写字母和数字串
    lst.extend(lower_lst)               #将获取的串加入密码串中

    random.shuffle(lst)                 #将生成串顺序打乱
    return ''.join(lst)                 #将所有字符输出在一行


if __name__ == '__main__':
    a = int(input("请输入要生成的密码个数："))
    for i in range(0,a):
        print(generate_password())