import { Component, ChangeDetectorRef } from '@angular/core'
import {store, stateObservable} from "../model/store"
import {State} from "../model/state"
import {addTodo} from "../model/actions"
import {map, distinctUntilChanged} from "rxjs/operators"
import {ToDo} from "../model/state/todo"

@Component({
    selector: 'app-root',
    templateUrl: './app.component.html',
    styleUrls: ['./app.component.scss']
})
export class AppComponent {
    title = "Redux - Angular Demo"
    counter = 0
    
    constructor(private changeDetector: ChangeDetectorRef) {
    }
    get todos() {
        return store.getState().todos
    }
    add(id: number, text: string) {
        store.dispatch(addTodo(id, text))
    }
    ngOnInit() {
        stateObservable
            .pipe(
                map((state:State) => state.todos),
                distinctUntilChanged()
            )
            .subscribe((todos:ToDo[]) => {
                console.log("todos changed", todos)
                this.changeDetector.markForCheck()
            })
    }
    click() {
        this.counter++
        this.add(this.counter, `clicks: ${this.counter}`)
    }
}

