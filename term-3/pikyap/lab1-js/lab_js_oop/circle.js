import {Figure} from './figure.js'
import {Color} from './color.js'

export class Circle extends Figure {
    constructor(radius, color) {
        super()
        this.type = 'Круг'
        this.radius = radius
        this.color = new Color(color)
    }

    area() {
        return Math.PI * this.radius * this.radius
    }

    repr() {
        return `${this.type} ${this.color.color} цвета радиусом ${this.radius} площадью ${this.area()}`
    }
}