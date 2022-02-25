# Note

## Dynamic Programming Solution

這題給問我們如果要爬一個有`n`個階梯的梯子，若規定每次只能選擇移動一步或兩步，則有幾種不同的行走方式。一開始做也想說要用窮舉的方法來暴力破解，不過後來想到這題可以用DP，思路為：如果已經知道所有可以爬到第`n-1`階的可能性，那麼其實爬到第`n`階也是差不多

<img width="659" alt="圖片" src="https://user-images.githubusercontent.com/55487740/155653735-a2b2a4f8-654e-46a2-bac3-0da9d756d207.png">
