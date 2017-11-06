// projects.js
// the scripts for Projects page
//*************************************************************//

function expandText (id) {
     // expand the text by making display=inline of div expanded(id)
     if (document.getElementById(id).style.display == "none")
     {
     document.getElementById(id).style.display = "inline";
     //document.getElementById(id + "Link1.1").innerHTML = "<u>Less...</u>"
     document.getElementById(id + "Link").style.display = "none";
     }
     else if (document.getElementById(id).style.display != "none")
     {
        document.getElementById(id).style.display = "none";
        //document.getElementById(id + "Link1.2").innerHTML = "<u>More...</u>"
        document.getElementById(id + "Link").style.display = "inline";
     }
     
}

function sort () {
var inputs = document.querySelectorAll("input[name='sortBy']");
if (inputs[0].checked == true)
{
    document.getElementById("type").disabled = true;    
document.getElementById("item0").style.order = 1;
document.getElementById("item1").style.order = 2;
document.getElementById("item2").style.order = 3;
document.getElementById("item3").style.order = 4;
document.getElementById("item4").style.order = 5;
}
if (inputs[1].checked == true)
{
    document.getElementById("type").disabled = true;    
document.getElementById("item0").style.order = 4;
document.getElementById("item1").style.order = 3;
document.getElementById("item2").style.order = 2;
document.getElementById("item3").style.order = 1;
document.getElementById("item4").style.order = 5;
}
if (inputs[2].checked == true)
{
    document.getElementById("type").disabled = false;
    if (document.getElementById("type").selectedIndex == "0")
    {
        document.getElementById("item0").style.order = 1;
        document.getElementById("item2").style.order = 2;
        document.getElementById("item4").style.order = 3;
        // What I don't care about. C++ is what needs to appear first
        document.getElementById("item1").style.order = 4;
        document.getElementById("item3").style.order = 5;        
    }
    if (document.getElementById("type").selectedIndex == "1")
    {
        document.getElementById("item3").style.order = 1;
        // What I don't care about. Web is what needs to appear first
        document.getElementById("item0").style.order = 3;
        document.getElementById("item2").style.order = 4;
        document.getElementById("item4").style.order = 5;
        document.getElementById("item1").style.order = 2;
    }
    
}


}