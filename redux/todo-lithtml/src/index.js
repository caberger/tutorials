import {html, render} from "lit-html"
import {stateObservable, store} from "./model/store"
import {addTodo} from "./model/actions"

class ReduxDemo extends HTMLElement {
    constructor() {
        super()
        this.count = 0
        this.attachShadow({mode: 'open'})
    }
    connectedCallback() {
        stateObservable
            .distinctUntilChanged()
            .subscribe(state => this.render(state))
        this.render()
    }
    render(state) {
        render(this.todos(state ? state.todos : []), this.shadowRoot)
    }
    todos(todos) {
        const lines = todos.map(todo => html`<li>${todo.text}</li>`)
        return html`
            <button @click=${this.click}>Add ToDo</button>
            <ul>
                ${lines}
            </ul>
        `
    }
    click(e) {
        let count = store.getState().todos.length + 1
        store.dispatch(addTodo(this.count, `clicks: ${count}`))
    }
}
customElements.define("redux-demo", ReduxDemo)

