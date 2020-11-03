package main

import (
    "fmt"
    "net/http"
    "github.com/gorilla/mux"
)


func ArticlesCategoryHandler(w http.ResponseWriter, r *http.Request) {
    vars := mux.Vars(r)
    w.WriteHeader(http.StatusOK)
    fmt.Fprintf(w, "Category: %v\n", vars["category"])
}

func main() {
    r := mux.NewRouter()
    // r.HandleFunc("/",HomeHandler)
    // r.HandleFunc("/products/{key}", ProductHandler)
    r.HandleFunc("/articles/{category}/", ArticlesCategoryHandler)
    // r.HandleFunc("/articles/{category}/{id:[0-9]+}", ArticleHandler)
    // http.Handle("/",r)
    http.ListenAndServe(":80", r)
}
