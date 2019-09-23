代码参考链接：https://blog.csdn.net/wuzhekai1985/article/details/6665197  
理论学习：大话设计模式  


**笔记：**

1.面向对象的编程，并不是类越多越好，类的划分是为了分装，但分类的基础是抽象，具有相同属性和功能的对象的抽象集合才是类.  
2.策略模式定义了一些列可重用的行为  
3.策略模式其实就是**将多种有相同属性的事物抽象出一个抽象类**，然后当做纯虚函数不实现功能，由派生类来实现  

--------------------------------------



**编译：**  
>g++ -c Algorithm.cpp  

>g++ -c context.cpp  

>g++ main.cpp -o a.exe Algorithm.o context.o
