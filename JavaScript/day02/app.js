const dooly = document.querySelector('#dooly')
console.log(dooly)

// 이벤트리스터('이벤트의 이름', 함수{발생했을 때 실행할 액션})
dooly.addEventListener('click', function(e){
    alert('호이')
    console.log(e)
})

document.addEventListener('keydown', function(e){
    console.log(e.keyCode) // code x keyCode: unique identifier: keycode.info
    if (e.code === "Space") {
        alert("asdf")
    } else if (e.code == "ArrowRight") {
        dooly.style.marginRight = "50px"
    } else if (e.code == "ArrowLeft") {
        dooly.style.marginLeft = "50px"
    }
})