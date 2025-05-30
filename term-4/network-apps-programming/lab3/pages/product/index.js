import {ProductComponent} from "../../components/product/index.js";
import {BackButtonComponent} from "../../components/back-button/index.js";
import {MainPage} from "../main/index.js";
import { ButtonGroup } from "../../components/btn-group/index.js";

export class ProductPage {
    constructor(parent, id) {
        this.parent = parent
        this.id = id
    }

    getData() {
        return {
            id: 1,
            src: "https://i.pinimg.com/originals/c9/ea/65/c9ea654eb3a7398b1f702c758c1c4206.jpg",
            title: `Фотография ${this.id}`,
            text: "Такой фотографии вы еще не видели"
        }
    }

    get pageRoot() {
        return document.getElementById('product-page')
    }

    getHTML() {
        return (
            `
                <div id="product-page"></div>
            `
        )
    }

    clickBack() {
        const mainPage = new MainPage(this.parent)
        mainPage.render()
    }

    render() {
        this.parent.innerHTML = ''
        const html = this.getHTML()
        this.parent.insertAdjacentHTML('beforeend', html)
    
        //const backButton = new BackButtonComponent(this.pageRoot)
        //backButton.render(this.clickBack.bind(this))

        const buttonGroup = new ButtonGroup(this.pageRoot)
        buttonGroup.render(this.clickBack.bind(this))
    
        const data = this.getData()
        const stock = new ProductComponent(this.pageRoot)
        stock.render(data)
    }
    


    
    
}