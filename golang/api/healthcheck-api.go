package main

import (
    "fmt"
    "net/http"

    "github.com/gorilla/mux"
)

func main() {

    r := mux.NewRouter()

    r.HandleFunc("/server/{user}/{sim}", func(w http.ResponseWriter, r *http.Request) {
        vars := mux.Vars(r)
        user := vars["user"]
        sim := vars["sim"]

        fmt.Fprintf(w, "Requested health check for \n  user: [%s] \n  sim: [%s]\n", user, sim)
        fmt.Printf("Requested health check for \n  user: [%s] \n  sim: [%s]\n", user, sim)
    }).Methods("GET")

    http.ListenAndServe(":80", r)
}
