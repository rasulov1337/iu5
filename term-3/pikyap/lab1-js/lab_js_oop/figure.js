export class Figure {
    area() {
        if (this.constructor == Figure)
            throw new Error("Abstract class can't be instantiated.")
    }
}