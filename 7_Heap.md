Binary Heap
>Min Heap: min value at the root<br/>
Max Heap: max value at the root<br/>
<br/>Root's index is 1 in an array. Arr[0] remains blank.<br/>
<br/>

Insert (Min heap)
>(1) &nbsp; add at the end of the tree (new index)
<br/>(2) &nbsp; if key < parent's key &nbsp;&nbsp; -> &nbsp; swap
<br/>Time complexity : O(logn)<br/>
<br/>

Remove (Min heap)
>(1) &nbsp; remove key at root
<br/>(2) &nbsp; move the last node to root
<br/>(3) &nbsp; 小的小孩比我小 &nbsp;&nbsp; -> &nbsp; swap<br/>
<br/>

Heap Sort
>in-place algorithm<br/>not stable but can be stable<br/>Time complexity: O(nlogn)<br/>
