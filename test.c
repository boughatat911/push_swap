int main(int argc, char **argv)
{
	int i;
	i = 1 ;
	int l = 0;
	if(argc >= 2)
	{
		while (argv[i])
		{
			int  j = 0;
			while (argv[i][j] != '\0' && (argv[i][j] >= 'a' && argv[i][j] <= 'z'))
				j++;
			if(argv[i][j] != '\0')
				return(printf("Erorr\n"));
			 j = 0;
			while (argv[i][j] != '\0' && (argv[i][j] >= 'a' && argv[i][j] <= 'z'))
			{
				printf("%c",argv[i][j]);
				i++;
			}
		}
		return(0);
	}
	else
		return(printf("Erorr\n"));
	
}