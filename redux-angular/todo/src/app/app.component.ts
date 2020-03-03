import { Component } from '@angular/core'
import { store } from '../model/store.js'
import {Store} from 'redux'
import {addTodo} from "../model/actions"


@Component({
    selector: 'app-root',
    templateUrl: './app.component.html',
    styleUrls: ['./app.component.scss']
})
export class AppComponent {
    title = 'todo'

    todos() {
        get:
        {
            return store.getState().todos
        }
    }
    ngOnInit() {
        const tsStore:Store = store
        tsStore.subscribe(() => {console.log("state changed", store.getState())})
        console.log("init...", store.getState())
        store.dispatch(addTodo(1, "test"))
    }
}

