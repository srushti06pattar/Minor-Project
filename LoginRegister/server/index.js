// our dependiecies
const express= require('express')
const app = express()
const mysql =require('mysql')
const cors = require('cors')

//let us run the server.
app.listen(3002, ()=>{
    console.log('server is running on port 3002')
})

//let us create our database (mysql)
const db= mysql .createConnection({
    user: 'root',
    host:'localhost',
    password: '',
    database: ''

})