import {ADD_TODO, TOGGLE_TODO} from "../actions"

const todoReducer = (state = [], action) => {
    let st = state
    switch(action.type) {
        case ADD_TODO: 
            st = [...state, {id: action.id, text: action.text}]
            break
        case TOGGLE_TODO: {
            st = state.map(todo => todo.id == action.index ? {...todo, completed: !todo.completed} : todo)
            break
        }
    }
    return st
}
export default todoReducer
