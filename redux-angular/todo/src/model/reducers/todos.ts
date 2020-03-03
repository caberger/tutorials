import {TodoAction, AddTodoAction, ToggleToDoAction} from "../actions"
import {ADD_TODO, TOGGLE_TODO} from "../actions"
import {ToDo} from "../state/todo"

export function todoReducer(state = [], action: TodoAction): ToDo[] {
    let st = state
    switch(action.type) {
        case ADD_TODO: {
            const addAction = action as AddTodoAction
            const todo = new ToDo(addAction.id, addAction.text)
            st = [...state, todo]
            break
        }
        case TOGGLE_TODO: {
            const toggleAction = action as ToggleToDoAction
            st = state.map(todo => todo.id == toggleAction.index ? {...todo, completed: !todo.completed} : todo)
            break
        }
    }
    return st
}

export default todoReducer