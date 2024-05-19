export class ProductComponent {
    constructor(parent) {
        this.parent = parent
    }

    getHTML(data) {
        let current_val = localStorage.getItem(data.title)
        if (!current_val) {
            current_val = '0'
        }
        
        fetch('http://localhost:8000/increment/' + data.id)
        return (
            `
                <div class="card mb-3" style="width: 540px;">
                    <div class="row g-0">
                        <div class="col-md-4">
                            <img src="${data.src}" class="img-fluid" alt="картинка">
                        </div>
                        <div class="col-md-8">
                            <div class="card-body">
                                <h5 class="card-title">${data.title}</h5>
                                <p class="card-text">${data.text}</p>
                                <p class="card-text">Просмотров: ${current_val}</p>
                            </div>
                        </div>
                    </div>
                </div>
            `
        )
    
    }

    render(data) {
        const html = this.getHTML(data)
        this.parent.insertAdjacentHTML('beforeend', html)
    }
}