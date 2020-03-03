/*
 * action types
 */
export const ADD_TODO = 'ADD_TODO'
export const TOGGLE_TODO = 'TOGGLE_TODO'
export const SET_VISIBILITY_FILTER = 'SET_VISIBILITY_FILTER'

export class TodoAction {
    type: string
    constructor(type: string) {
        this.type = type
    }
}
export class AddTodoAction extends TodoAction {
    id: number
    text: string

    constructor(id: number, text: string) {
        super(ADD_TODO)
        this.id = id
        this.text = text
    }
}
export class ToggleToDoAction extends TodoAction {
    index: number
    constructor(index: number) {
        super(TOGGLE_TODO)
        this.index = index
    }
}

/*
 * action creators
 */
export function addTodo(id: number, text: string) : any {
  return {type: ADD_TODO, id, text}
}
export function toggleTodo(index: number): any {
  return {type: TOGGLE_TODO, index}
}

