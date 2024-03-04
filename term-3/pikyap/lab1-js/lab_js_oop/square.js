import {Rectangle} from './rectangle.js'

export class Square extends Rectangle {
	constructor(side, color) {
		super(side, side, color)
		this.type = 'Квадрат'
	}

	repr() {
		return `${this.type} ${this.color.color} цвета с длиной стороны ${this.width}, площадью ${this.area()}.`
	}
}