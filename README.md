# practice-of-programming-22-spring
2022 程序设计实习
我把作业写了一下 放在了branch里面

怎么作业这么多。。我真的会谢

### 矩形排序
Comp类重载()时要重载为const 成员函数，就是这样：bool operator()(const Rectangle& r1,const Rectangle& r2) const{xxx}

因为set里面对comp的定义是一个const的，const对象无法调用非const 成员函数。所以将成员函数声明为const的就好。

（一开始没重载为const就一直疯狂compile error)
