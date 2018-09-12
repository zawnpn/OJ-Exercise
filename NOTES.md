# Notes

## Tips
* 确定合适的输入输出方式、格式
* 尽量避免C和C++输入输出混用
* 两个scanf之间可用getchar()避免'\n'带来的影响
* 反复读题，做题中途再读题，确定没有遗漏关键信息
* 样本int，实际float；样本有序，实际乱序...认真读题，be careful
* float-%f,double-%lf,long double-%Lf
* 数组越界-Runtime Error；数据溢出-Wrong Answer
* 大数组定义成全局(全局-栈(小)、局部-堆(大))，容易Runtime Error
* 可以考虑用0x7fffffff(小心溢出，dijkstra不能用，更推荐0x3f3f3f3f=1061109567~10^9)等来表示Infinity
* 注意memset按字节操作，最大0x7f，建议0x3f(0,-1能保持原值)
* sort(a,a+size)
* 递推题n稍微一大，就可能产生大整数，注意高精度

## Solutions
* **大数量级、求模：** 考虑找规律
*

## Algorithms

### 贪心
* 若要用贪心算法求解某问题的整体最优解，必须首先证明贪心思想在该问题的应用结果就是最优解
* 贪心算法的常见提前操作——排序