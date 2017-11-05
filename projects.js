// projects.js
// the scripts for Projects page
//*************************************************************//

function expandText (id) {
     // expand the text by making display=inline of div expanded(id)
     if (document.getElementById(id).style.display == "none")
     {
     document.getElementById(id).style.display = "inline";
     }
     else if (document.getElementById(id).style.display != "none")
     {
        document.getElementById(id).style.display = "none";
     }
     
}