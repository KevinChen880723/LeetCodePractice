# Note for TwoSum

## Baseline Function

Firstly, in the program, I sort the series, then check every number in `nums` sequentially. When checking every value, I search the corresponding paired number from the end of the series. When searching the corresponding number, I set the different start points determined in the last iteration because the number I checked in the new iteration is bigger than the previous iteration.
