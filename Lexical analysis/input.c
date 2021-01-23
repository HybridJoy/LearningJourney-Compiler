int main()
{
	// 测试整型数和浮点数以及科学计数法
	const int a = 5;
	static int b = 5e34;
	float c = -1.5;
	float c_1 = 1.5f;
	double d = 2.35e34;

	// 测试八进制数和十六进制数
	int e = 0645;
	int f = 0xef68;

	// 测试字符常量和字符串常量
	char* str = "I like";
	char cr = 'h';

	// 测试位运算符和算术运算符
	a = a & b;
	a = a + c;
	a -= b;
	a = a * b;
	c = 34 + 15.0f;
	a >>= 1;
	a += 1;

	// 测试控制语句和逻辑运算符
	if(c > 0 && a <= 1)
	{
		int i,j;
		for(i = 0;i < 5;i++)
		{
			printf("%s\n", str);
		}
		while(i--)
		{
			if(i != 4)
				printf("%c\n", cr);
		}
	}

	// 测试无效字符
	$ @ 《 》 、、;

	// 测试无效变量名
	int 899a;
	int 5_DD&;

	// 测试多行注释
	/* 
	这里是多行注释
	这里是多行注释
	这里是多行注释
	这里是多行注释
	*/

	return 0;
}