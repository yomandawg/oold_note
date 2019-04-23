// 아재 판독기
const age = prompt("나이를 말해줘")

// 만약 30 이상이면 => 아재
// 20 이상이면 => 학식
// 8 이상이면 => 급식
// else => 유식
if (age > 29) {
    alert('아재');
} else if (age > 19) {
    alert('학식'); 
} else if (age > 7) {
    alert('급식');
} else {
    alert('유식');
}
// string과 int비교: type coercion == implicit coercion, implicit type casting
