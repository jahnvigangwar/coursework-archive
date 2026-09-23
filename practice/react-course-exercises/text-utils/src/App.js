import './App.css';
import About from './components/About';
import Alert from './components/Alert';
import Navbar from './components/Navbar';
import TextForm from './components/TextForm';
import React, {useState} from 'react'

import {
  BrowserRouter as Router,
  Switch,
  Route,
  Link
} from "react-router-dom";

function App() {
  const [mode, setMode] = useState('light'); 
  const [alert, setAlert] = useState(null);

  const showAlert = (message, type) =>{
      setAlert({
        msg: message,
        type: type
      })
      setTimeout(() => {
        setAlert(null);
      }, 1500);

  }

  const toggleMode = () =>{
    if(mode === 'light')
    {
      setMode('dark');
      document.body.style.backgroundColor = 'black';
      showAlert("Dark Mode has been enabled", "success");
    }
    else
    {
      setMode('light');
      document.body.style.backgroundColor = 'white';
      showAlert("Light Mode has been enabled", "success");
    }
  }
  
  return (
    <>
    <Router>
    {/* <Navbar title="textUtills" aboutText="About Us"/>; */}
    <Navbar title="textUtills" mode = {mode} toggleMode = {toggleMode} />
    <Alert alert={alert} />

    <Switch>
          <Route exact path="/about">
            <About/>
          </Route>
          <Route exact path="/">
            <div className="container my-3">
            <TextForm Alert={showAlert} heading="Enter your text here"  mode = {mode} />
            </div>
          </Route>
     </Switch>
    </Router>
    </>
  );
}

export default App;
