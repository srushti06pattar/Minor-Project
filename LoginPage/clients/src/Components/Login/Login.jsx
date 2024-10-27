import React from 'react'
import './Login.css'
import {Link} from 'react-router-dom'
import video from '../../LoginAssets/video.mp4'

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
      </div>
    </div>
  )
}
export default Login
