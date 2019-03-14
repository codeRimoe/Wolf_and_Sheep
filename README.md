# Wolf-and-Sheep

> This is a Cpp homework, visualized by QT. It is an analogue simulation of the actions of wolf and sheep.

> more detail please refer to:[狼和羊捕食2D仿真实验报告.pdf](https://github.com/codeRimoe/Wolf_and_Sheep/blob/master/%E7%8B%BC%E5%92%8C%E7%BE%8A%E6%8D%95%E9%A3%9F2D%E4%BB%BF%E7%9C%9F%E5%AE%9E%E9%AA%8C%E6%8A%A5%E5%91%8A.pdf)

> or get infomation about this project from my blog:[大概是最弱鸡的2D仿真 - 写作业中学到的可视化](https://blog.rimoe.xyz/2017/07/27/post01/)

---

# License

                                 Apache License
                           Version 2.0, January 2004
                        http://www.apache.org/licenses/

   TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION

   Copyright 2017 Yue H.W. Luo, yue.rimoe@gmail.com .

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

---

# 狼和羊捕食2D仿真实验报告

## 一、实验要求

创建一个简单的二维“捕食者—被捕食者”模拟。在这个模拟中，被捕食者是羊，而捕食者是狼。这些生物生活在一个 n*n 的网格中。每个单元每次只能由一个生物体占据。

1. 羊的行为:
  * 吃:为了简单起见，此处不考虑羊吃草;
  * 移动:在每一个 time 中，都随机的向上，向下，向左，向右移动。如果准备移动的位置已经有其他生物，则保持当前位置不变;
  * 繁殖:如果一只羊在三个时间步中保持存活，那么在第三个 time 结束之后， 该羊繁殖后代。所谓繁殖后代就是在相邻的单元格中创建一个新的羊，如果 没有单元格，则不能成功繁殖后代;
  * 死亡: 除非被狼吃掉，不会饥饿而亡。所谓死亡即从模拟环境中消失。

2. 狼的行为:
  * 吃:狼吃羊;
  * 移动:如果在其上、下、左、右有羊，则移动到羊的任一位置，并且吃掉羊; 否则随机移动到上、下、左、右网格，如果网格有其他生物，则保持当前位置不变;
  * 繁殖:如果在 8 个时间步中仍保持存活，那么在第 8 个时间步后，按照羊的 方式进行繁殖;
  * 死亡:如果狼在连续 3 个时间步中都没有吃到羊，则在 3 个时间步后，饥饿而亡。该狼从模拟中消除。

## 二、改进

* 增加了羊吃草和羊饥饿死亡的情况。
* 增加狼和羊自然死亡的情况。
* 狼和羊可以往上、下、左、右、左上、左下、右上、右下方向移动。
* 狼和羊的移动策略改进：
  1. 羊会往没有狼和草多的地方移动。
  2. 狼会往羊多的方向移动。

  实现方法：使用权重比较的方法，模拟狼和羊的捕食与逃跑。
    1. 狼的捕食策略模拟：查找周边领域，对邻近八个格元进行权重计算，选取权重最大的方向移动。该策略的效果是：不会移动到有狼的格元。附近有羊时优先去有羊的地方吃羊，同样的格元会优先去邻域羊最多的格元，并使用随机因子模拟不确定性因素。
      * ![math01](https://github.com/codeRimoe/Wolf_and_Sheep/blob/master/pic/image001.png?raw=true)
      * ![math02](https://github.com/codeRimoe/Wolf_and_Sheep/blob/master/pic/image002.png?raw=true)
      * ![math03](https://github.com/codeRimoe/Wolf_and_Sheep/blob/master/pic/image003.png?raw=true)
      * ![math04](https://github.com/codeRimoe/Wolf_and_Sheep/blob/master/pic/image004.png?raw=true)
      * ![math05](https://github.com/codeRimoe/Wolf_and_Sheep/blob/master/pic/image005.png?raw=true)



    2. 羊的逃跑策略模拟：查找周边领域，对邻近八个格元进行权重计算，选取权重最大的方向移动。该策略的效果是：只会往没有动物的格元移动。附近有狼时优先往有狼的相反方向逃跑，同样的格元会优先去邻域草最多的格元，并使用随机因子模拟不确定性因素。

      * ![math06](https://github.com/codeRimoe/Wolf_and_Sheep/blob/master/pic/image006.png?raw=true)
      * ![math07](https://github.com/codeRimoe/Wolf_and_Sheep/blob/master/pic/image007.png?raw=true)
      * ![math08](https://github.com/codeRimoe/Wolf_and_Sheep/blob/master/pic/image008.png?raw=true)
      * ![math09](https://github.com/codeRimoe/Wolf_and_Sheep/blob/master/pic/image009.png?raw=true)
      * ![math10](https://github.com/codeRimoe/Wolf_and_Sheep/blob/master/pic/image010.png?raw=true)

*使用Qt进行可视化。

## 三、实验环境

1. 实验环境一
    *MacBook Air (13-inch, Early 2015)／macOS Sierra
    *处理器：1.6 GHz Intel Core i5
    *内存：4 GB 1600 MHz DDR3
    *IDE：Xcode Version 8.0 (8A218a)

2. 实验环境二
    *MacBook Air (13-inch, Early 2015)／Windows 10（Virtual Box虚拟机）
    *处理器：1.6 GHz Intel Core i5
    *内存：4 GB 1600 MHz DDR3
    *IDE：Qt Creater 4.3（Qt5.9.0）
    *在实验环境一中进行核心代码编写，用ASCII显示狼和羊。
    *在实验环境二中进行可视化设计与release版编译。

## 四、结果

1. 在MacOS终端下有较好的模拟效果，界面简约整洁，基本功能完全实现。

      ![pre01](https://github.com/codeRimoe/Wolf_and_Sheep/blob/master/pic/image012.png?raw=true)
      ![pre01](https://github.com/codeRimoe/Wolf_and_Sheep/blob/master/pic/image014.png?raw=true)


2. 在使用Qt可视化后，界面更加美观，同时可以很好地观察狼和羊的行为。提供暂停功能，帮助更好地观察狼和羊。我们可以明显看出狼和羊的数量变化关系，也能看出附加功能（狼的追踪和羊的逃跑）被实现。

      ![pre02](https://github.com/codeRimoe/Wolf_and_Sheep/blob/master/pic/image015.png?raw=true)
      ![pre03](https://github.com/codeRimoe/Wolf_and_Sheep/blob/master/pic/image016.png?raw=true)
      ![pre04](https://github.com/codeRimoe/Wolf_and_Sheep/blob/master/pic/image018.png?raw=true)

3. 在MacOS、Windows编译运行结果如下

      ![pre05](https://github.com/codeRimoe/Wolf_and_Sheep/blob/master/pic/image019.png?raw=true)
      ![pre06](https://github.com/codeRimoe/Wolf_and_Sheep/blob/master/pic/image020.png?raw=true)

## 五、总结

本次实验创建一个简单的二维“捕食者—被捕食者” 仿真，有效地了模拟了草原上狼和羊的捕食关系。此外还通过Qt实现了跨平台的可视化，帮助更好地观察狼和羊的行为。

本次实验也有不足之处，在模拟过程中会出现狼把羊逼迫到边界导致大量羊在边界堆积，没有或只有少部分羊在中间逃离狼的捕抓。可能会出现边界上的羊被狼吃光，而中间没有羊或狼还没来得及返回捕抓就饿死的情况，最终会出现狼灭绝的情况。

这是因为模拟环境是一个封闭的区域，相当于在农场进行本次实验，而要模拟草原的话可以设置无边界的情况，在边界可以往另一个边界移动，这样显示的区域实际上模拟了无穷个相似的局部草块，相当于在一个无穷大的区域内进行实验，生态系统更加平衡。
