import { createApp, h } from 'vue'
import App from './App.vue'
import { 
    BootstrapVue, 
    IconsPlugin 
} from 'bootstrap-vue'
import router from './router'

// Make BootstrapVue available throughout your project
Vue.use(BootstrapVue)
// Optionally install the BootstrapVue icon components plugin
Vue.use(IconsPlugin)


// Import Bootstrap an BootstrapVue CSS files (order is important)
import 'bootstrap/dist/css/bootstrap.css'
import 'bootstrap-vue/dist/bootstrap-vue.css'

Vue.config.productionTip = false

new Vue({
    router,
    render: h=>h(App),
}).$mount('#app')

createApp(App).mount('#app')