# practice-of-programming-22-spring
2022 程序设计实习
# 学生信息处理程序
带空格的名字用cin.get(name,21,',')处理很方便qwq
# Complex类的成员函数
我写的稍微有点长了 上CSDN上看了一下 觉得这样处理很不错 如下：
Complex& operator=(string s) {
        int pos = s.find('+', 0);
        string sTmp = s.substr(0, pos);
        r = stoi(sTmp);
        sTmp = s.substr(pos+1);
        i = stoi(sTmp);
    }

