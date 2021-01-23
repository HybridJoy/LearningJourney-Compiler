
char* GetUsername()
{
	char* username;
	username = "tas";
	return username;
}

char* GetPassword()
{
	char* password;
	password = "123456";
	return password;
}

int main()
{
	int result;
	int wrongCode = 0xFFFFFFFF;

	int accountNum = 10;
	char username[10] = "tas";
	char password[10] = "123456";
	
	char str = 'Y';

	if(strcmp(GetUsername(), username) == 0)
	{
		printf("username is right\n");
		if(strcmp(GetPassword, password) == 0)
		{
			printf("password is right\n");

			// int i = 0;
			for(i = 0; i < 10;i = i + 1)
			{
				if(i < 4)
				{
					result = result + wrongCode;
					continue;
				}
				else
				{
					while(1)
					{
						i = i + 1;
						if(i > 7)
						{
							break;
						}
					}
				}
				printf("%s\n",result);
			}
		}
		else
		{
			printf("password is wrong\n");
		}
		
	}
	else
	{
		printf("username is wrong\n");
	}
	return 0;
}