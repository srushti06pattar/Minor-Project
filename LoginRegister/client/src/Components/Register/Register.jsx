import React from 'react';
import './Register.css';
import '../../App.css';

import { Link } from 'react-router-dom';

// Importing assets
import video from '../../LoginAssets/video.mp4';
import logo from '../../LoginAssets/fox.png';

// Importing icons
import { FaUserShield } from 'react-icons/fa';
import { BsFillShieldLockFill } from 'react-icons/bs';
import { AiOutlineSwapRight } from 'react-icons/ai';
import { MdMarkEmailRead } from 'react-icons/md';

const Register = () => {
  return (
    <div className="registerPage flex">
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
          <span className="text"> Have an Account?</span>
          <Link to={'/'}>
            <button className="btn">Login</button>
          </Link>
          </div>
        </div>

        <div className="formDiv flex">
          <div className="headerDiv">
            <img src={logo} alt="Logo" />
            <h3>Let Us Know You!</h3>
          </div>

          <form action="" className="form grid">
          <div className="inputDiv">
              <label htmlFor="email">Email</label>
              <div className="input flex">
                <MdMarkEmailRead className="icon" />
                <input type="email" id="email" placeholder="Enter Email" />
              </div>
            </div>

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
              <span>Register</span>
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

export default Register;
