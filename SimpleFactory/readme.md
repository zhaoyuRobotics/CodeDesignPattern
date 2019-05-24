
### 简单工厂模式：

　　　  （１）“产品”由抽象类派生两个产品，此目的为了减少耦合
     
       （２）“工厂”这里其实可以不需要抽象类，这里重点看下如何实例对象的问题，主要是为了考虑实例化对象多种（产品），所以用一个单独的类来创造产品
       
### 编译:

 
       g++ -c SimpleFactory.cpp

       g++ -c Product.cpp 

       g++ main.cpp -o a.exe SimpleFactory.o Product.o
 


### 参考：


　　　　　　https://www.cnblogs.com/cxjchen/p/3143633.html
