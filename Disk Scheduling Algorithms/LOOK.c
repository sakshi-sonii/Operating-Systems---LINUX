#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void look(int tracks[], int n, int head, char direction)
{
    sort(tracks, n);
    int i, seek_count = 0;
    int distance, cur_track;
    int left[n], right[n];
    int left_count = 0, right_count = 0;
    
    for (i = 0; i < n; i++)
    {
        if (tracks[i] < head)
            left[left_count++] = tracks[i];
        if (tracks[i] > head)
            right[right_count++] = tracks[i];
    }
    
    if (direction == 'l')
    {
        for (i = left_count - 1; i >= 0; i--)
        {
            cur_track = left[i];
            printf("%d -> ", cur_track);
            seek_count += abs(cur_track - head);
            head = cur_track;
        }
        for (i = 0; i < right_count; i++)
        {
            cur_track = right[i];
            printf("%d -> ", cur_track);
            seek_count += abs(cur_track - head);
            head = cur_track;
        }
    }
    else if (direction == 'r')
    {
        for (i = 0; i < right_count; i++)
        {
            cur_track = right[i];
            printf("%d -> ", cur_track);
            seek_count += abs(cur_track - head);
            head = cur_track;
        }
        for (i = left_count - 1; i >= 0; i--)
        {
            cur_track = left[i];
            printf("%d -> ", cur_track);
            seek_count += abs(cur_track - head);
            head = cur_track;
        }
    }
    
    printf("\nTotal head movement: %d\n", seek_count);
}

int main()
{
    int n, head;
    char direction;
    
    printf("Enter the number of tracks: ");
    scanf("%d", &n);
    
    int tracks[n];
    printf("Enter the track positions:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tracks[i]);
    }
    
    printf("Enter the head position: ");
    scanf("%d", &head);
    
    printf("Enter the direction (l for left, r for right): ");
    scanf(" %c", &direction);
    
    printf("\nHead movement trace:\n");
    look(tracks, n, head, direction);
    
    return 0;
}
