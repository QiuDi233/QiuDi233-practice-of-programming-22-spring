# practice-of-programming-22-spring
2022 程序设计实习
我把作业写了一下 放在了branch里面

### 高阶函数F(x)
template<typename T1, typename T2>
auto f(T1 x) -> function<T2(T2)> {
    return [x](T2 y){return y + x;};
}

这是我在网上找到的另一个答案，我觉得这样写应该才是它的出题意图。
不过我写的那样也AC了（doge）
