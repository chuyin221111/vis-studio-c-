//编写算法，判断某个字符串是否有中心对称关系（又称回文），例如xyzzyx、xyzyx都是中心对称的字符串。
//提示：用栈帮忙。将字符串的前半部分依次入栈，再逐个比较剩余字符和栈顶元素是否一致，正确匹配一个则出栈一个，只要有1个不匹配则不是回文；
//如果剩余字符顺利匹配完后，栈为空，则是回文。注意字符串长度为奇数或偶数的操作是不同的。