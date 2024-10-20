import React from 'react';
import './Login.css';
import '../../App.css';

import { Link } from 'react-router-dom';

// Importing assets
import video from '../../LoginAssets/video.mp4';
import logo from '../../LoginAssets/fox.png';

// Importing icons
import { FaUserShield } from 'react-icons/fa';
import { BsFillShieldLockFill } from 'react-icons/bs';
import { AiOutlineSwapRight } from 'react-icons/ai';

const Login = () => {
  return (
    <div className="loginPage flex">
      <div className="container flex">

        <div className="videoDiv">
          <video autoPlay muted loop>
            {/* Add multiple sources for better browser compatibility */}
            <source src={video} type="video/mp4" />
            <source src="../../LoginAssets/video.webm" type="video/webm" />
            Your browser does not support the video tag.
          </video>
          <div className="textDiv">
            <h2 className="title">Create and Shell Extraordinary Products</h2>
            <p>Adopt the peace of the nature</p>
          </div>
          <div className="footerDiv flex">
          <span className="text">Don't Have an Account?</span>
          <Link to={'/register'}>
            <button className="btn">Sign up</button>
          </Link>
          </div>
        </div>

        <div className="formDiv flex">
          <div className="headerDiv">
            <img src={logo} alt="Logo" />
            <h3>Welcome Back</h3>
          </div>

          <form action="" className="form grid">
            <span className='showMessage'>Login status will go here</span>

            <div className="inputDiv">
              <label htmlFor="username">Username</label>
              <div className="input flex">
                <FaUserShield className="icon" />
                <input type="text" id="username" placeholder="Enter username" />
              </div>
            </div>

            <div className="inputDiv">
              <label htmlFor="password">Password</label>
              <div className="input flex">
                <BsFillShieldLockFill className="icon" />
                <input type="password" id="password" placeholder="Enter password" />
              </div>
            </div>

            <button type="submit" className="btn flex">
              <span>Login</span>
              <AiOutlineSwapRight className="icon" />
            </button>

            <span className="forgotpassword">
              Forgot Your Password? <a href="#">Click here</a>
            </span>
          </form>
        </div>
        
      </div>
    </div>
  );
};

export default Login;
