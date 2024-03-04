import {Figure} from './figure.js'
import {Color} from './color.js'

export class Rectangle extends Figure {
    constructor(width, height, color) {
        super()
        this.type = 'Прямоугольник'
        this.width = width
        this.height = height
        this.color = new Color(color)
    }

    area() {
        return this.width * this.height
    }

    repr() {
        return `${this.type} ${this.color.color} цвета с длиной стороны ${this.width}, шириной стороны ${this.height}, площадью ${this.area()}`
    }
}