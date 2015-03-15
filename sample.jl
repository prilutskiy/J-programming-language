void main
{
	int a;
	int b;
	for (int i = 0; i < 5; i++)
	{	
		if (i == 3)
			print i;
		if(i == a || i == b)
		{
			print a;
			print b;
		}
	}
	int result = myTestSumFunc(a, b);
}
//single-line comment
/*
*Multiline comment
*/
func int myTestSumFunc(int a, int b)
{
	return a + b;
}
