package main

import "fmt"

type TwoInts struct {
	a int
	b int
}
type IntVector []int

func (v IntVector) Sum() (s int) {
	for _, x := range v {
		s += x
	}
	return
}

func main() {
	two1 := new(TwoInts)
	two1.a = 12
	two1.b = 10

	fmt.Printf("The sum is: %d\n", two1.AddThem())
	fmt.Printf("Add them to the param: %d\n", two1.AddToParam(20))

	two2 := TwoInts{3, 4}
	fmt.Printf("The sum is: %d\n", two2.AddThem())

	fmt.Println(IntVector{1, 2, 3}.Sum()) // 输出是6
}

func (tn *TwoInts) AddThem() int {
	return tn.a + tn.b
}

func (tn *TwoInts) AddToParam(param int) int {
	return tn.a + tn.b + param
}

//func (recv receiver_type) methodName(parameter_list) (return_value_list) { ... }
/*
如果方法不需要使用 recv 的值，可以用 _ 替换它，比如：

func (_ receiver_type) methodName(parameter_list) (return_value_list) { ... }
*/
