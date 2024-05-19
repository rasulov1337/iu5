"use strict"
import {ButtonComponent} from "../../components/button/index.js";
import {ProductCardComponent} from "../../components/product-card/index.js";
import {ProductPage} from "../product/index.js";


export class MainPage {
    constructor(parent) {
        this.parent = parent;
        this.latestID = 0;
    }
    
    
    get pageRoot() {
        return document.getElementById('main-page')
    }
        
    getHTML() {
        return (
            `
                <div id="main-page" class="d-flex flex-wrap"><div/>
            `
        )
    }
    
    render() {
        this.parent.innerHTML = ''
        const html = this.getHTML()
        this.parent.insertAdjacentHTML('beforeend', html)

        fetch('//localhost:8000/stocks')
        .then((res) => res.json())
        .then((data) => {
            data.forEach((item) => {
                const productCard = new ProductCardComponent(this.pageRoot)
                if (item.title === 'Калькулятор')
                    productCard.render(item, this.clickCalc.bind(this), this.delCard.bind(this))
                else
                    productCard.render(item, this.clickCard.bind(this), this.delCard.bind(this))
                this.latestID = item.id + 1
            })
        })

        // Кнопка для добавления новых карточек
        const btn = new ButtonComponent(this.parent, 'Добавить новую карточку')
        btn.render(this.addNewCard.bind(this))
    }

    clickCard(e) {
        const cardId = e.target.dataset.id
        const link = e.target.dataset
    
        const productPage = new ProductPage(this.parent, cardId, )
        productPage.render()
    }

    clickCalc() {
        open('pages/calc/main.html', '_self')
    }

    delCard(id) {
         fetch(`http://localhost:8000/stocks/${id}`, {method: 'DELETE'})
    }

    addNewCard() {
        if (!document.stats) {
            document.stats = {}
        }
        document.stats[this.latestID] = 0
        fetch('https://source.unsplash.com/random')
        .then((val) => {
            fetch('http://localhost:8000/stocks', {
            method: 'POST',
            headers: {
                'Accept': 'application/json',
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({
                id: this.latestID,
                src: val.url,
                title: 'Title' + this.latestID,
                text: 'Test' + this.latestID,
                visited_times: 0
            })
        })
        })
        
        this.latestID++
    }

    

}