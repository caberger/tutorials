/*
 * action types
 */
export const ADD_TODO = 'ADD_TODO'
export const TOGGLE_TODO = 'TOGGLE_TODO'

/*
 * action creators
 */
export function addTodo(id, text) {
  return {type: ADD_TODO, id, text}
}
export function toggleTodo(index) {
  return {type: TOGGLE_TODO, index}
}

