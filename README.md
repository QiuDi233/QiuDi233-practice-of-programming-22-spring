# practice-of-programming-22-spring
2022 程序设计实习
我把作业写了一下 放在了branch里面

### goodcopy
网上看到的 我觉得这样写比我的好，它是从后往前拷贝，就不会覆盖了

void operator()(T* start, T* end, T* aim) {

		for (T* i = end-1; i >= start; i--) {
		
			*(aim+(i-start)) = *i;
			
		}
		
}
