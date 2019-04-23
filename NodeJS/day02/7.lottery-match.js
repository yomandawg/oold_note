var _ = require('lodash')

const luckyNumbers = [29, 32, 44, 24, 2, 41]

var numbers = _.range(1, 46)
var myPicks = _.sampleSize(numbers, 6)

// 랜덤으로 생성한 6개의 숫자가 luckyNumbers와 얼마나 매칭하는지 카운트를 반환하는 함수
const match = (lucky, myNumbers) => {
    let cnt = 0
    for (myNum of myNumbers) {
        if (_.includes(lucky, myNum)) {
            cnt += 1
        }
    }
    return cnt
}

console.log(luckyNumbers)
console.log(myPicks)
console.log(match(luckyNumbers, myPicks))