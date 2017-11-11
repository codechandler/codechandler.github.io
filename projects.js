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
    var id = "projects";
    var url = "https://codechandler.github.io/projects.txt";
    httpRequest = false;
    httpRequest = new XMLHttpRequest();
    httpRequest.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
                writeData(this.responseText, id);
        }
        else {
        }
    };
    httpRequest.open("GET", url, true);
    httpRequest.send();
}

function writeData(responseText, id) {
    var myObj = JSON.parse(responseText);
    var displayText = "";
    var text = [];
    for (i=0; i<myObj.projects.length; i++) {
        displayText += "<div class=\"flex-item\" id=\"item";
        var date = myObj.projects[i].hidden.date;
        var rank = myObj.projects[i].hidden.rank;
        var type = myObj.projects[i].hidden.type;
        var title = myObj.projects[i].visible.title;
        var projectInfo = myObj.projects[i].visible.projectInfo;
        var primaryImg = myObj.projects[i].visible.primaryImg;
        var description = myObj.projects[i].visible.description;
        var secondaryImg = [];
        for (j=0; j<myObj.projects[i].visible.secondaryImg.length; j++) {
            secondaryImg[j] = myObj.projects[i].visible.secondaryImg[j];
        }
        var reference = myObj.projects[i].visible.links.reference;
        var ribbon = myObj.projects[i].visible.links.ribbon;
        
        displayText += rank + "\" style=\"order:" + Number(rank) + 1 + "\"> <h2>" + title + "</h2> <p>" + projectInfo + "</p> <div class=\"center\"> <img src=\"" + primaryImg + "\" alt=\"\" style=\"width:100%; height:auto\"> <a class=\"active\" id=\"expanded" + Number(rank) + 1 + "Link\" onclick=\"expandedText('expanded" + Number(rank) + 1 + "')\" style=\"color:blue;cursor:pointer;display:inline\"><u>More...</u></a></div><div id=\"expanded" + Number(rank) + 1 + "\" style=\"display:none\"><div class=\"center\">";
        for (k=0; k<secondaryImg.length; k++){
            displayText += "<img src=\"" + secondaryImg[k] + "\" alt=\"\" style=\"width:100%; height:auto\">";
        }  
        displayText += "<a class=\"active\" href=\"" + reference + "\"> <button type=\"button\" style=\"font-size:25px\">" + ribbon + "</button> </a> </div> <div class=\"active\" onclick=\"expandedText('expanded" + Number(rank) + 1 + "')\" style=\"color:blue;cursor:pointer\"><u>Less...</u></a> </div> </div> </div>"; 
        //displayText += date + rank + type + title + projectInfo + primaryImg + description + reference + ribbon;
    }
    alert(displayText);
    document.getElementById("projects").innerHTML = displayText;
}
