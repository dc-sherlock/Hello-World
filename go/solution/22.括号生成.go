/*
 * @lc app=leetcode.cn id=22 lang=golang
 *
 * [22] 括号生成
 */

// @lc code=start
func generateParenthesis(n int) []string {
	length:=n*2
	map1:=map([byte]byte){')':'('}
	var res []string
	var str string
	for {
		for i:=0;i<length;i++ {
			str[i]='('
		}//生成所有可能的字符串
		if isVali(str) {//如果有效添加进去
			res=append(res,str)
		}
	}
	return res
	
}
func isValid(s string) bool {
	var stack []byte
	map1 := map[byte]byte{')': '('}
	for _, ch := range s {
		length := len(stack)
		if length > 0 {
			if _, ok := map1[byte(ch)]; ok {
				if stack[length-1] == map1[byte(ch)] {
					stack = stack[:length-1]
					continue
				}
			}
		}
		stack = append(stack, byte(ch))
	}
	return len(stack) == 0
}
// @lc code=end

