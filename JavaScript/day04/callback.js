const fs = require('fs') // import fileSystem

// readFile('경로/파일명', encoding, 콜백function(에러, 내용물){})
fs.readFile(__dirname + '/test.md', 'utf8', (socks, jik) => {
    console.log(socks || jik)
})
// 순정 buffer => test.md 의 binary 표현