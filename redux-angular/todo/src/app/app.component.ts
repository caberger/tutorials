import { Component } from '@angular/core'
import { store } from '../model/store.js'

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
        console.log("init...", store.getState())
    }
}

