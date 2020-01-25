Binary Heap
>Min Heap: min value at the root<br/>
Max Heap: max value at the root<br/>
<br/>Root's index is 0 in an array.<br/>
<br/>
Insert (Min heap)
>1. add at the end of the tree (new index)<br/>
2. if key < parent's key  ->  swap<br/>
Time complexity : O(logn)<br/>
<br/>
Remove (Min heap)
>1. remove key at root<br/>
2. move the last node to root<br/>
3. 小的小孩比我小  ->  swap<br/>
<br/>
Heap Sort
>in-place algorithm<br/>
not stable but can be stable<br/>
Time complexity: O(nlogn)<br/>
