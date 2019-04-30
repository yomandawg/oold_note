// class

class Car {
    constructor(option) {
        this.title = option.title // this === self
    }

    drive() {
        return 'Vrooom'
    }
}

// new XMLHttpRequest 클래스 인스턴스 생성(new)

const car = new Car({ title: 'A6' })
console.log(car.title) // A6
console.log(car.drive()) // Vrooom
console.log(typeof car)


// class 상속
class Audi extends Car {
    constructor(option) {
        super(option) // { title: 'A6', color: 'red' } super === 상속받은 부모 클래스에 넘겨줌
        this.color = option.color
    }
    honk() {
        return 'Baaaaaaam'
    }
    drive() { // override
        return 'Vroooooooooooooooooom'
    }
}

const audi = new Audi({title: 'A8', color: 'black'})
console.log(audi.drive()) // Vroooooooooooooom
console.log('Before', audi.honk()) 

// overriding a method outside the class
audi.honk = () => {
    return 'Bam'
}

console.log('After ', audi.honk()) // Baaaaaaam

console.log(car instanceof Car) // true
console.log(audi instanceof Car) // true - extends: Car의 instance 중 하나다라고 해도 돼
console.log(car instanceof Audi) // false
console.log(audi instanceof Audi) // true