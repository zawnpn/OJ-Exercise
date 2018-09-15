# Notes

## Tips
* 确定合适的输入输出方式、格式
* 尽量避免C和C++输入输出混用（缓冲）
* 两个scanf之间可用getchar()避免'\n'带来的影响
* 反复读题，做题中途再读题，确定没有遗漏关键信息
* 样本int，实际float；样本有序，实际乱序...认真读题，be careful
* float-%f,double-%lf,long double-%Lf
* 数组越界-Runtime Error；数据溢出-Wrong Answer
* 大数组定义成全局(全局-栈(小)、局部-堆(大))，容易Runtime Error
* 可以考虑用0x7fffffff(小心溢出，dijkstra慎用，更推荐0x3f3f3f3f=1061109567~10^9)等来表示Infinity
* 注意memset按字节操作，最大0x7f，建议0x3f(0,-1能保持原值)
* sort(a,a+size)
* 递推题n稍微一大，就可能产生大整数，注意高精度
* 嵌套模板中应使用'> >'而非'>>'，否则可能CE(eg. `<pair<int, int> >`)
* 全局变量声明数组无需清零
* 字符串最后一位是`\0`
* 不要将i、j等局部反复使用的变量定义为全局变量，尤其是在一些递归中，有坑
* string->const char*:const char* b = a.c_str();
* 大写->小写：tolower()/小写->大写：toupper()
* isalpha()/islower()/isupper()
* string:find() not found -> std::string::npos
* str.replace(begin,end,"some string")
* printf:%5s——右对齐、%-5s——左对齐
* 用于sort的cmp函数加`=`号可能RE
* stable_sort
* 注意long long 和 __int64 在不同环境下的表现

## Solutions

### 数据
* **大数量级、求模：** 考虑找规律
* n<500:O(n^3)-Floyd、高斯消元
* n~1000:O(n^2)/O(n^logn)
* n~1w:maybe O(nsqrt(n)logn)
* n~10w:O(log)/O(loglog)/O(sqrt)...
* n~50w:O(log)
* n~100w:O(nlogn)的数学题 or O(n)
* n~1000w:O(n)
* n>1000w:O(sqrt(n))/O(logn)/O(1)
* 若强调每个数字不超过N:复杂度可能与N密切相关

### 套路
* 树路径染色 - LCT
* 统计树满足要求的路径数 - 分治

### 优化
#### 使用位运算
* a%2==1 -> a&1 == 1
* a/=2 -> a>>=1

## Algorithms

### 贪心
* 若要用贪心算法求解某问题的整体最优解，必须首先证明贪心思想在该问题的应用结果就是最优解
* 贪心算法的常见提前操作——排序
* 用交换法进行一些证明

### DP
* 现在决定未来，未来与过去无关。

### 图论

#### 最小生成树
* Kruscal - 稀疏图
* Prim - 稠密图
* 两者均用于无向图
* 一个N个点的联通图最少有N-1条边

#### 最短路径
* 注意读题，处理好双向/单向边、重边、回环等

### 搜索
* 若函数有多个出口，则需在每个出口恢复被修改的全局变量

### 递推
* 错排问题 - Dn=(n-1)(Dn-1+Dn-2)