#include <stdio.h> 
#include <string.h>
int main()
{
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");

	if (input != NULL)
	{
		int in_A[256] = { 0 }, count = 0;
		char symbol[255] = { 0 }; 

		while (fscanf(input, "%s", &symbol)!=-1)
		{
				count = strlen(symbol);
			if (count != 0)
			{
				in_A[count]++;
				count = 0;
			}
		}

		for (int i = 0; i < 255; i++)
		{
			if (in_A[i] > 0)
			{
				fprintf(output, "%d - %d\n", i, in_A[i]);
			}
		}
	}

	fclose(input);
	fclose(output);

	return 0;
}