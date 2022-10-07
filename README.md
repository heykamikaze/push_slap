# push_slap


push_swap: Ecole42 project, the main goal is to get aquaintant with sorting alorithms. Ints on the stack are sorted with the limited set of instructions.


push_swap_bonus: tester that checks if the instructios offered by the user sort the ints entered.


Execution: ./push_swap

`make`

`./push_swap *ints to sort* `


![img](https://github.com/heykamikaze/push_slap/blob/master/src/push_swap_pic.png)


Execution: ./checker

`./checker *ints to sort* `

`*commands to exec`

`KO output means the commands haven't sorted the stack`

`OK output means the stack has been sorted`


![img](https://github.com/heykamikaze/push_slap/blob/master/src/KO_checker.png)


| instructions  | Description   |
|:-------------:|---------------|
| sa            | swap first two elements of stack A |
| sb            | swap first two elements of stack B |
| ss            | sa and sb at the same time |
| pa            | pops the first elememt on B and puts it on top of A |
| pb            | pops the first elememt on A and puts it on top of B |
| ra            | rotates stuck A up by one|
| rb            | rotates stuck B up by one |
| rr            | rotates both A and B up by one |
| rra           | rotates stuck A down by one |
| rrb           | rotates stuck B down by one |
| rrr           | rotates both A and B down by one |



Graphic representation of sorting algorithm in progress: 


![gif](https://github.com/heykamikaze/push_slap/blob/master/src/ezgif.com-gif-maker%20(1).gif)
