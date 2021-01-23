
// 注意：测试一部分代码时请注释其他部分的代码

//\\\\\\\\\\\\\创建和打印符号表\\\\\\\\\\\\

int globalVar_1 = 30;
int globalVar_2, globalVar_3;
int max();
int main()
{
	int localVar_1 = 40;
	if(localVar_1 > 30)
	{
		int locallocalVar_1 = 10;
	}
	return 0;
}
int max()
{
	int result;
	return result;
}

//\\\\\\\\\\\\\函数和变量重定义检查\\\\\\\\\\\\\

// int globalVar_1 = 30;
// int globalVar_1, globalVar_2, globalVar_3;
// int max();
// int max();
// int main()
// {
// 	int localVar_1 = 40;
// 	if(localVar_1 > 30)
// 	{
// 		int localVar_1 = 10;
// 	}
// 	return 0;
// }


//\\\\\\\\\\\\\函数和变量声明检查\\\\\\\\\\\\\

// int globalVar_1 = 30;
// int globalVar_2, globalVar_3;
// int max();
// int main()
// {
// 	int localVar_1 = 40;
// 	if(localVar_1 > 30)
// 	{
// 		locallocalVar_1 = max();
// 		localVar_1 = globalVar_2 - globalVar_1;
// 	}
// 	return 0;
// }
// int max()
// {
// 	int result;
// 	return result;
// }
//\\\\\\\\\\\\\类型检查\\\\\\\\\\\\\

// int main()
// {
// 	int int_1, int_2, int_3;
// 	float float_1, float_2;
// 	char char_1, char_2;
// 	int_2 = int_1 + int_3;
// 	int_2 = int_1 + char_1; // error
// 	int_2 = int_3 + 50;
// 	int_2 = 45 + 15.5; // error
// 	float_1 = float_2 + 30; // error
// 	float_1 = 1.5 + 2.5;
// 	char_1 = char_2;
// 	char_1 = int_1; // error
// 	char_1 = 'c';
// 	return 0;
// }

//\\\\\\\\\\\\括号不匹配\\\\\\\\\\\\\

// int main()
// {
// 	int a;
// 	a = (2 + 3;
// 	return 0;
// }
