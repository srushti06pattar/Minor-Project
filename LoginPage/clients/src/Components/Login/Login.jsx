import React from 'react'
import './Login.css'
import '../../App.scss'
import {Link,NavLink} from 'react-router-dom'
import video from '../../LoginAssets/video.mp4'
import Logo from '../../LoginAssets/logo.png'

//Import Icons
import {FaUserShield} from 'react-icons/fa'
import {BsFillShieldLockFill} from 'react-icons/bs'
import {AiOutlineSwapRight} from 'react-icons/ai'

const Login = () => {
  return (
    <div className="loginPage flex">
      <div className="container flex">
        <div className="videoDiv">
          <video src={video} autoPlay muted loop></video>

          <div className="textDiv">
            <h2 className="title">Create and shell Extradoniary Products</h2>
            <p>Adopt the peace of nature!</p>
          </div>
          
          <div className="footerDiv flex">
            <span className="text">Don't Have an Account?</span>
            <Link to={'/register'} >
            <button className='btn'>Sign Up</button>
            </Link>
          </div>
        </div>

        <div className="formDiv flex">
          <div className="header Div">
            <img src={Logo} alt='Login Logo'/>
            <h1>Welcome Back!</h1>
          </div>

          <form action='' className='form grid'>
            <span>Login Status will go here</span>
            <div className='inputDiv'>
              <label htmlFor='username'>UserName</label>
              <div className='inputflex'>
                <FaUserShield className="icon"/>
                <input type='text' id='username' placeholder='Enter Username'/>
              </div>
            </div>

            <div className='inputDiv'>
              <label htmlFor='password'>Password</label>
              <div className='inputflex'>
                <BsFillShieldLockFill className="icon"/>
                <input type='password' id='password' placeholder='Enter Password'/>
              </div>
            </div>

            <button type='submit' className='btn flex'>
              <span>Login</span>
              <AiOutlineSwapRight className ="icon"/>
            </button>
            <span className='forgot password'>
              Forgot Your Password? <a href=''>Click here</a>
            </span>
          </form>
        </div>
      </div>
    </div>
  )
}
export default Login
