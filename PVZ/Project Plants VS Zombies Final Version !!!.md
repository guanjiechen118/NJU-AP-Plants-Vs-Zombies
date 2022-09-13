# Project:	*Plants VS Zombies*	Final Version !!!

**201220061	计算机科学与技术系	陈冠杰	**

**Date：2021/12/12/19:33**



## 1.阶段任务

1、增加**攻击**与**被攻击**的效果
2、添加或者优化**UI界面**
3、接着**卷**



## 2.成果展示

### 2-1.增加多方向攻击植物：StarFruit &&非直线移动子弹：Star

![Starfruit](E:\Pvz_v2\resource\rc\Starfruit.gif) 			![Star](E:\Pvz_v2\resource\rc\Star.gif)

游戏内效果展示：

![image-20211212194355015](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211212194355015.png)

虽然但是，游戏里看其实还蛮漂亮的。

### 2-2.增加僵尸生命值现实：

效果如下：

![image-20211212194641598](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211212194641598.png)

——就是说，土到极致就是美

### 2-3.增加僵尸受伤效果：燃烧状态

![image-20211212194925221](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211212194925221.png)

好不容易截到的，将就着看叭

### 2-4.优化植物攻击效果

豌豆子弹命中后会裂开

胡桃子弹命中后会原地旋转

樱桃炸弹爆照后会有“boom”图标

地刺攻击时会变大（好丑，因为找不到图了没办法

### 2-5.增加开场动画和失败动画

（就放一个开场动画叭，死亡动画好丑

![image-20211212194844684](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211212194844684.png)



## 3.实现思路

### 3-1.胡桃和胡桃子弹

胡桃直接继承自Plant类，主要是重写基类中的虚函数

```cpp
virtual void Plant::make_action();
```

重写如下：

```cpp
void StarFruit::make_action()
{
    if(!grass::line_has_zom(line)) return;
    new Star(this->parentWidget(),_x,_y,0);
    new Star(this->parentWidget(),_x,_y,1);
    new Star(this->parentWidget(),_x,_y,2);
    new Star(this->parentWidget(),_x,_y,3);
    new Star(this->parentWidget(),_x,_y,4);
}
```

胡桃子弹直接继承Bullet类，重写虚函数

```cpp
virtual void Bullet::move();
```

因为之前重构了草坪的结构，所以可以直接对坐标变动，余下的定位和查找僵尸交给基类函数和草坪类来实现

move重写如下

```cpp
switch(mystate)
    {
    case 0:
    {
        _x+=speed;
        _y+=speed/3;
        label->move(_x,_y);
        break;
    }
    case 1:
    {
        _x+=speed;
        _y-=speed/3;
        label->move(_x,_y);
        break;
    }
    case 2:
    {
        _y+=speed;
        _x-=speed/3;
        label->move(_x,_y);
        break;
    }
    case 3:
    {
        _y-=speed;
        _x-=speed/3;
        label->move(_x,_y);
        break;
    }
    case 4:
    {
        _x-=speed;
        label->move(_x,_y);
        break;
    }
    }
```

### 3-2.僵尸血条

嗯，挺简单的，直接两个label拼在一块就好了

每次计时器timeout的时候，把红色的label做如下操作：

```cpp
back->move(pix_x,pix_y);
hp_label->move(pix_x+2,pix_y+2);
hp_label->resize((ZOMWID-4)*HP/Full_HP,16);
```

即，移动label，缩小长度



### 3-3.其他

植物攻击效果优化在子弹或者植物的make_action函数中，多是简单的设计，不做赘述

游戏开场动画和结束动画也很简单，不必赘述



## 4.一点遗憾

之前说好的好多新的僵尸和植物都来不及做了，为什么呢
因为我下个星期有两次上机考试，英语六级，我还有亲爱的数电大实验，一个字没动的数据结构大作业，小实验。
反正就很多事情，我没时间了:(
还有就是，没法给游戏加音乐，不知道为啥，我的QT没法把QMediaPlayer库包含进来，我音乐都找好了。。。
最后就是一个，真-无能为力的问题：

为什么我的游戏跑一会就会非常非常卡呢？？？？？？
我仔细检查了每次内存释放，内存都是可以即使释放出来的，我在析构函数中都能看到输出，但是就是会变卡，真的无能为力了，就这样了，等我以后有能耐了再来康康。



## 5.一点感悟

第一次做出来一个游戏，感觉还挺好的
第一次使用了C++里面一些高级的东西，像模板啊，库啊，继承啊，等等
第一次写出了一个自己觉得设计的非常好的一个大项目
第一次完全靠自己学会了QT，学会了一个库，能简单的用多线程

and so on

救命，居然有点舍不得了。。。

嗐，That's all for my project:	*Plants Vs Zombies*

