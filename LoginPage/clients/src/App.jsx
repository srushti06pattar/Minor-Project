import './App.scss'
import Dashoboard from './Components/Dashboard/Dashoboard'
import Login from './Components/Login/Login'
import Register from './Components/Register/Register'

//Import router react dom

import{
  createBrowserRouter,
  RouterProvider
}from 'react-router-dom'

const router =createBrowserRouter([
  {
    path: '/',
    element : <div><Login/></div>
  },
  {
    path: '/',
    element : <div><Dashoboard/></div>
  },
  {
    path: '/',
    element : <div><Register/></div>
  }
])
function App() {
  return (
    <div>
    <Dashoboard/>
    <Login/>
    <Register/>
    </div>
  )
}
export default App
