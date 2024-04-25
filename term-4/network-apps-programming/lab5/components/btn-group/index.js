export class ButtonGroup {
    constructor(parent) {
        this.parent = parent;
    }

    addListeners(listener) {
        document
            .getElementById("back")
            .addEventListener("click", listener);
        document.getElementById("close").addEventListener("click", () => { window.open("https://i.pinimg.com/originals/c9/ea/65/c9ea654eb3a7398b1f702c758c1c4206.jpg", '_blank').focus() });
    }

    getHTML() {
        return (
            `
            <div class="btn-group" role="group" aria-label="Простой пример">
                <button type="button" id="back" class="btn btn-primary">Назад</button>
                <button type="button" id="close" class="btn btn-primary">Открыть в новой вкладке</button>
            </div>           
             `
        )
    }

    render(listener) {
        const html = this.getHTML()
        this.parent.insertAdjacentHTML('afterend', html)
        this.addListeners(listener)
    }
}