#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMS 12

int main()
{
	char *months[] = {"January", "February", "March", "April", "May", "June",
						"July", "August", "September", "October", "November", "December"};

	double numbers[MAX_NUMS];
	int number_count = 0;

	FILE *input_file = fopen("input.txt", "r");
	if (input_file == NULL)
	{
		printf("ERROR opening input file\n");
		exit(1);
	}
	while (fscanf(input_file, "%lf", &numbers[number_count]) == 1)
	{
		number_count++;
		if (number_count == MAX_NUMS)
			{
				break;
			}
	}

	fclose(input_file);

	printf("Monthly sales report for 2022:\n");
	printf("\n%10s %10s\n", "Month", "sales");
	for(int i = 0; i < 12; i++)
	{
		printf("%-10s %10.2f\n", months[i], numbers[i]);
	}

	double max = 0, min = numbers[0], avg = 0;
	int maxM = 0, minM = 0;

	for(int i = 0; i < 12; i++)
	{
		if(numbers[i] > max)
		{
			max = numbers[i];
			maxM = i;
		}
		if(numbers[i] < min)
		{
			min = numbers[i];
			minM = i;
		}
		avg += numbers[i];
		if(i == 11)
		{

			avg = avg / 12;
		}
	}

	printf("\nSales summary:\n");
	printf("%-10s %10.2f (%s)\n", "Minimum sales", min, months[minM]);
	printf("%-10s %10.2f (%s)\n", "Maximum sales", max, months[maxM]);
	printf("%-10s %10.2f\n\n", "Average sales", avg);

	double avgM = 0;
	printf("Six-Month Moving Average Report:\n");
	for(int i = 0; i < 7; i++)
	{
		for(int j = i; j < i + 6; j++)
		{
			avgM = numbers[j] + avgM;
		}
		avgM = avgM / 6;
		printf("%-10s- %-10s $%-10.2f\n", months[i], months[i+5], avgM);
		avgM = 0;
	}

	for (int i = 0; i < 11; i++)
	    {
	        int maxIndex = i;
	        for (int j = i + 1; j < 12; j++)
	        {
	            if (numbers[j] > numbers[maxIndex])
	            {
	                maxIndex = j;
	            }
	        }
	        if (maxIndex != i)
	        {
	            double temp = numbers[i];
	            numbers[i] = numbers[maxIndex];
	            numbers[maxIndex] = temp;

	            char *temp_month = months[i];
	            months[i] = months[maxIndex];
	            months[maxIndex] = temp_month;
	        }
	    }
	printf("\nSales Report(Highest to Lowest:\n");
	printf("%10s %10s\n", "Month", "Sales");
	for(int i = 0; i < 12; i++)
		{
			printf("%-10s %10.2f\n", months[i], numbers[i]);
		}


	return 0;
}
