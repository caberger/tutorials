import {createStore} from "redux"
import reducer from "./reducers"

export const store = createStore(reducer)
console.log("state is", store.getState())

//export default store
