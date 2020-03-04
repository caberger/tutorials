import Observable from "../../rx"
import {createStore} from "redux"

import reducer from "../reducers"

export const store = createStore(reducer, window.__REDUX_DEVTOOLS_EXTENSION__ && window.__REDUX_DEVTOOLS_EXTENSION__())
export const stateObservable = Observable.from(store)
