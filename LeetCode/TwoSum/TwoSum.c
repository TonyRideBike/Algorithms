#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* twoSum(int* nums, int numsSize, int target);

#define DEBUG1 1
#define DEBUG2 0

int main(int argc, char *argv[]) {
    int numbers[5] = {-1, -2, -3, -4, -5};
    int target = -8;
    int* result;
    result = twoSum(numbers, 4, target);
    printf("%d, %d", result[0], result[1]);
}

int* twoSum(int* nums, int numsSize, int target) {
    int* tempArray = (int*)malloc(sizeof(int) * target);
    memset(tempArray, 0, (sizeof(int)) * target);
    static int result[2] = {0};
    for(int i=0; i<numsSize; i++)
    {
        #if DEBUG1
        printf("i=%d\n", i);
        printf("nums[i]=%d\n", nums[i]);
        printf("target=%d\n", target);
        for(int j=0; j<=target; j++) {
            printf("tempArray[%d]=%d\n", j, tempArray[j]);
        }
        printf("tempArray[nums[i]]=%d\n", tempArray[nums[i]]);
        #endif
        if(tempArray[nums[i]] != 0) {
            printf("got it!\n");
            result[0] = (tempArray[nums[i]]);
            result[1] = i+1;
            return result;
        }
        tempArray[target-nums[i]] = i+1;
    }
    return result;
}
