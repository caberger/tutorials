import { Component } from '@angular/core'
import {store, storeObservable} from "../model/store"
import {State} from "../model/state"
import {addTodo} from "../model/actions"
import {map, distinctUntilChanged} from "rxjs/operators"

@Component({
    selector: 'app-root',
    templateUrl: './app.component.html',
    styleUrls: ['./app.component.scss']
})
export class AppComponent {
    title = "Redux Demo"
    counter = 0

    get todos() {
        return store.getState().todos
    }
    add(id: number, text: string) {
        store.dispatch(addTodo(id, text))
    }
    ngOnInit() {
        const todos = map((state:State) => state.todos)
        todos(storeObservable).pipe(distinctUntilChanged()).subscribe(todos => console.log("todos changed", todos))
    }
    click() {
        this.counter++
        this.add(this.counter, `clicks: ${this.counter}`)
    }
}

