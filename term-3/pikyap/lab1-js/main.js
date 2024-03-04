import {Square} from './lab_js_oop/square.js'
import {Circle} from './lab_js_oop/circle.js'
import {Rectangle} from './lab_js_oop/rectangle.js'


function main() {
	console.log(new Rectangle(3, 2, "Синего").repr())
	console.log(new Circle(5, "Зеленого").repr())
	console.log(new Square( 5, "Красного").repr())
}

main()