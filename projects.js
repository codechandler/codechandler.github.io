// projects.js
// the scripts for Projects page
//*************************************************************//
// global variables
var httpRequest;

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

function fetchData() {
    alert("HELLOOOOOOO");
    var id = "projects";
    var url = "projects.txt";
    httpRequest = false;
    httpRequest = new XMLHttpRequest();
    httpRequest.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
                writeData(this.responseText, id);
        }
        else {
            alert("There was an error reaching the server");
        }
    };
    httpRequest.open("GET", url, true);
    httpRequest.send();
}

function writeData(responseText, id) {
    var myObj = JSON.parse(responseText);
    var displayText = "Testing...Testing 123";
    var text = [];
    for (i=0; i<myObj.projects.length; i++) {
        var date = myObj.projects[i].hidden.date;
        var rank = myObj.projects[i].hidden.rank;
        var type = myObj.projects[i].hidden.type;
        var title = myObj.projects[i].visible.title;
        var projectInfo = myObj.projects[i].visible.projectInfo;
        var primaryImg = myObj.projects[i].visible.primaryImg;
        var description = myObj.projects[i].visible.description;
        var secondaryImg = [];
        for (j=0; j<myObj.projects.visible.secondaryImg.length; i++) {
            secondaryImg[j] = myObj.projects[i].visible.secondaryImg[j];
        }
        var reference = myObj.projects[i].visible.links.reference;
        var ribbon = myObj.projects[i].visible.links.ribbon;
        alert(date + rank + type + title + projectInfo + primaryImg + description + reference + ribbon);

    }
    displayText += "";
    document.getElementById("projects").innerHTML = displayText;
}
