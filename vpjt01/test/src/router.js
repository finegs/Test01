import Vue from "vue";
import VueRouter from "vue-router"
import Home from "./views/Home.vue"
import About from "./views/About.vue"


Vue.use(ViewRouter)

const router  = VueRouter ({
    mode:"history",
    routes: [
        {path:"/", component:Home},
        {path:"/about", component:About}
    ]
});