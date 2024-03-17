import { ProductCardComponent } from "../../components/product-card/index.js";
import { ProductPage } from "../product/index.js";
import { ajax } from "../../modules/ajax.js";
import { urls } from "../../modules/urls.js";
import { myID as ID } from "../../modules/consts.js";
import { SortSelect } from "../../components/sort-select/index.js";

export class MainPage {
    constructor(parent) {
        this.parent = parent;
    }

    getData(sortType='id_asc') {
        ajax.post(urls.getFriendsList(ID), (data) => {
                //this.renderData(data.response.items.filter((e) => e.sex == 1 && e.city?.title == 'Москва'));
                this.renderData(data.response.items)
        });
    }

    renderData(items) {
        items.forEach((item) => {
            const productCard = new ProductCardComponent(this.pageRoot)
            productCard.render(item, this.clickCard.bind(this))
        })
    }
    get pageRoot() {
        return document.getElementById("main-page");
    }

    getHTML() {
        return `
                <div id="main-page" class="d-flex flex-wrap"><div/>
            `;
    }

    clickCard(e) {
        const cardId = e.target.dataset.id;
        console.log("pressed ", cardId);

        const productPage = new ProductPage(this.parent, cardId);
        productPage.render();
    }

    handler(sortType) {
        Array.from(document.getElementsByClassName('card')).forEach((item) => {
            item.remove()
        })
        this.getData(sortType)
    }

    render() {
        this.parent.innerHTML = ''

        const html = this.getHTML()
        this.parent.insertAdjacentHTML('beforeend', html)

        const selectOption = new SortSelect(this.pageRoot);
        selectOption.render(this.handler.bind(this));
    
        this.getData()
    }
}
