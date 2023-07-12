#include <stdio.h>
void fifoPageReplacement(int string_length, int frame_length, int string[], int frame[]);
int main()
{
    int string_length;
    int frame_length;
    int page_fault = 0;
    int first = 0;

    // taking input for string length
    printf("Enter the string length: ");
    scanf("%d", &string_length);
    int string[string_length];

    // taking input for string array
    for (int i = 0; i < string_length; i++)
    {
        printf("Enter the value of index %d: ", i);
        scanf("%d", &string[i]);
    }

    // taking input for frame length

    printf("Enter the frame length: ");
    scanf("%d", &frame_length);
    int frame[frame_length];
    for (int i = 0; i < frame_length; i++)
    {
        frame[i] = -1;
    }

    fifoPageReplacement(string_length, frame_length, string, frame);
}

void fifoPageReplacement(int string_length, int frame_length, int string[], int frame[])
{
    int page_fault = 0;
    int first = 0;
    printf("Incoming\t");
    for (int i = 1; i <= frame_length; i++)
    {
        printf("frame%d\t", i);
    }
    printf("\n");
    for (int i = 0; i < string_length; i++)
    {
        for (int j = 0; j < frame_length; j++)
        {
            // if the page is already present in frame then it  will skip it
            if (frame[j] == string[i])
            {
                // printf("Prsent in frame");
                break;
            }

            // doing leaner serach to check that if the page is not in frame
            if (string[i] != frame[j] && j == frame_length - 1)
            {
                page_fault++;             // increasing page fault by 1
                frame[first] = string[i]; // placing the page in frame here first is for replacement
                first++;
                if (first > frame_length - 1)
                {
                    first = 0;
                }
            }
        }

        // displaying frame
        printf("%d\t\t", string[i]);
        for (int j = 0; j < frame_length; j++)
        {
            if (frame[j] != -1)
            {
                printf("%d\t", frame[j]);
            }
            else
            {
                printf("-\t");
            }
        }
        printf("\n");
    }
    printf("Page fault is  %d ", page_fault);
}