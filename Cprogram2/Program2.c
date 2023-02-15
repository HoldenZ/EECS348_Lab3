#include <stdio.h>

int main() {
    int score;
    while (1)
    {
    	printf("Enter 0 or 1 to STOP\n");
        printf("Enter The NFL score: ");
        scanf("%d", &score);

        if (score <= 1)
        {
        	printf("Program Terminated");
            break;
        }

        printf("Possible combinations of scoring plays:\n");

        for (int td = 0; td * 6 <= score; td++)
        {
                    for (int fg = 0; fg * 3 <= score - td * 6; fg++)
                    {
                        for (int safety = 0; safety * 2 <= score - td * 6 - fg * 3; safety++)
                        {
                            for (int tdconv = 0; tdconv * 8 <= score - td * 6 - fg * 3 - safety * 2; tdconv++)
                            {
                                for (int td_fg = 0; td_fg * 7 <= score - td * 6 - fg * 3 - safety * 2 - tdconv * 8; td_fg++)
                                {
                                    if (td * 6 + fg * 3 + safety * 2 + tdconv * 8 + td_fg * 7 == score) {
                                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", tdconv, td_fg, td, fg, safety);
                                    }
                                }
                            }
                        }
                    }
                }

                printf("\n");
            }

            return 0;
        }
