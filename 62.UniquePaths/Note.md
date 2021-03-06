# Note

## Baseline Solution

這個題目給定一個`m*n`的地圖，要求我們求出從左上角到右下角總共有幾種不重複的路徑。我在做這題的時候，第一個想到的作法跟之前做第39題`Combination Sum`時的方法一樣，使用遞迴的方式來窮舉所有可能性。具體作法為：在遞迴的程式中，使用一個只會跑兩次的回圈來依序往右再往下跑，假如到最右邊的話就不要再繼續往右跑，直接跳到往下；同理，如果走到最下面了，就不要繼續往下走，改成往右走。其中為了加快運算速度，我嘗試在走到邊緣的時候讓他們只跑一層的回圈。

> 不過因為之前那題可以透過裁減不可能的狀況，進而加快程式的運作時間；而這題沒辦法，每一步都要走到底，就需要花費很多時間，因而在LeeCode網站運算超時。我推論這個方法的時間複雜度為：`O(n^(m+n))`（因為一共`m+n`步左右可以走到終點，其中每一個節點都會有兩種可能性），非常恐怖。

<img width="685" alt="圖片" src="https://user-images.githubusercontent.com/55487740/155535199-72ddf5a0-d349-421b-8140-d70a9af5cfbf.png">

## Dynamic Programming Solution

其實從起點到`map[y][x]`的可能路徑數量為到`map[y-1][x]`、`map[y][x-1]`的可能路徑和，原因是從起點經過`map[y-1][x]`再到`map[y][x]`的可能路線數量相同，都只是在每一種可能路徑的最後再往下走一步而已。知道這點以後就可以發現這題可以改用Dynamic Programming的方式來完成：先建立一個大小為`(m+1)*(n+1)`的表，裡面各個元素代表從起點`map[1][1]`到該點的距離，而最上面那列跟最左邊那行都存放`0`，這是為了讓DP滿足條件。建好表之後先將到起點`map[1][1]`的可能路徑數`LUT[1][1]`設定為`1`，再來就可以使用兩層的for回圈來依序完成表中的各個數值，完成之後`LUT[m][n]`即為從起點到終點的可能路徑數量。這個方法的時間複雜度為`O(mn)`。

<img width="673" alt="圖片" src="https://user-images.githubusercontent.com/55487740/155539492-1ddfabad-4516-4f98-ba6e-a4620fc78495.png">

<img width="664" alt="圖片" src="https://user-images.githubusercontent.com/55487740/155539270-303b3b7c-5fb6-4723-8eab-014257e21950.png">

## Experiments

這次兩種解法的時間複雜度差非常多，可以藉此嘗試看看兩個的運行時間。經過測試之後可以發現第一種方法在地圖大小為`20*20`就跑不出來了，但第二種方法到大小為`10000*10000`的地圖都還能夠快速跑完，可見時間複雜度真的差很多！
