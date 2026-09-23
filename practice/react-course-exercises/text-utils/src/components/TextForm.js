import React, {useState} from 'react'

// 


export default function TextForm(props) {
    const handleUpClick = () => {
        //console.log("upper case was clicked " + text);
        let newText = text.toUpperCase();
        setText(newText); 
        props.Alert("converted to uppercase", "success");
    }
    const handleOnChange = (event) => {
        //console.log("on change");
        setText(event.target.value);
    }
    const handleClearClick = (event) => {
        //console.log("on change");
        setText(" ");
        props.Alert("text cleared", "success");
    }
        
    const handleLoClick = () => {
        let newText = text.toLowerCase();
        setText(newText);
        props.Alert("converted to lowercase", "success");
    }
    const [text, setText] = useState('Enter Text Here');
    //text = "new text"; // wromg way to change state 
    //setText("new Text"); // right way to chnge state
    return (
    <>
     <div className='container' style = {{ backgroundColor:props.mode === 'dark'? 'black': 'white', color:props.mode === 'dark'? 'white': 'black'}}>   
        <h1>{props.heading} </h1>
        <div className="mb-3">
        <textarea className="form-control" value={text} onChange={handleOnChange} id="myBox" rows="8" style = {{ backgroundColor:props.mode === 'dark'? 'black': 'white', color:props.mode === 'dark'? 'white': 'black'}} ></textarea>
        </div>
        <button className="btn btn-primary mx-2 my-3" onClick={handleUpClick}> Convert to Uppercase </button>
        <button className="btn btn-primary mx-2 my-3" onClick={handleLoClick}> Convert to Lowercase </button>
        <button className="btn btn-primary mx-2 my-3" onClick={handleClearClick}> Clear Text </button>
    </div>
    <div className="container my-3" style = {{ backgroundColor:props.mode === 'dark'? 'black': 'white', color:props.mode === 'dark'? 'white': 'black'}}>
        <h1>Your Text Summary</h1>
        <p>the text has {text.split(" ").length} words and {text.length} characters</p>
        <p> can be read in {0.008*  text.split(" ").length} minutes </p>
        <h2>Preview</h2>
        {text.length>0?text:"Enter something in the text box to preview"}
    </div>
    </>
   
  )
}
