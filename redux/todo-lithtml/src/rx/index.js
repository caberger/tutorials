/** configure only "usual" observable methods in order to get a slim package */
import {Observable} from "rxjs-es/Observable"
import "rxjs-es/add/observable/from"
import "rxjs-es/add/operator/map"
import "rxjs-es/add/operator/filter"
import "rxjs-es/add/operator/distinctUntilChanged"
import "rxjs-es/add/operator/share"

export default Observable
