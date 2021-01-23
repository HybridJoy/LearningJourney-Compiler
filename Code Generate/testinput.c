Yes Yes // 默认输出语法树和符号表
int main()
{
	int a, b = 30;
	int c, d;
	int e = 30;
	int f = e - 10;
	a = e + 40;
	b = a * 20;
	c = (b - 100) / 100;
	d = c * 50 + 1000;
	a = -d;
	b = -10;
	return 0;
}