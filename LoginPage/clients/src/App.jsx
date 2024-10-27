import './App.css'
import Dashoboard from './Components/Dashboard/Dashboard'
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
    path: '/dashboard',
    element : <div><Dashoboard/></div>
  },
  {
    path: '/regsiter',
    element : <div><Register/></div>
  }
])
function App() {
  return (
    <div>
    <RouterProvider router={router}/>
    </div>
  )
}
export default App
