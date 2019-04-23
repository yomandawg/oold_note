var _ = require('lodash')

var numbers = _.range(1, 46); // range function from 'lodash'
// console.log(numbers)

var picks = _.sampleSize(numbers, 6) // 6개 random 추출
console.log(`행운의 번호는 ${picks}`)