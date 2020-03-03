import {createStore} from "redux"
import reducer from "./reducers"
import {Observable, Observer} from "rxjs"
import {State} from "../model/state"

export const store = createStore(reducer, (window as any).__REDUX_DEVTOOLS_EXTENSION__ && (window as any).__REDUX_DEVTOOLS_EXTENSION__())
export const storeObservable = Observable.create((observer:Observer<State>) => store.subscribe(() => observer.next(store.getState())))
