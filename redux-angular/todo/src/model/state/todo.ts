export class ToDo {
    id = 0
    text = ""
    completed = false
    
    constructor(id: number, text: string) {
        this.id = id
        this.text = text
    }
}