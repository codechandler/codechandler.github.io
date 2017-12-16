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
// Sort by Featured
if (inputs[0].checked == true)
{
    document.getElementById("type").disabled = true;    
document.getElementById("item0").style.order = 1;
document.getElementById("item1").style.order = 2;
document.getElementById("item2").style.order = 3;
document.getElementById("item3").style.order = 4;
document.getElementById("item4").style.order = 5;
}
// Sort by Date (Newest First)
if (inputs[1].checked == true)
{
    document.getElementById("type").disabled = true;    
document.getElementById("item0").style.order = 4;
document.getElementById("item1").style.order = 3;
document.getElementById("item2").style.order = 2;
document.getElementById("item3").style.order = 1;
document.getElementById("item4").style.order = 5;
}
// Sort by Type
if (inputs[2].checked == true)
{
    document.getElementById("type").disabled = false;
    // Sort by C++
    if (document.getElementById("type").selectedIndex == "0")
    {
        document.getElementById("item0").style.order = 1;
        document.getElementById("item2").style.order = 2;
        document.getElementById("item4").style.order = 3;
        // What I don't care about. C++ is what needs to appear first
        document.getElementById("item1").style.order = 4;
        document.getElementById("item3").style.order = 5;        
    }
    // Sort by Web
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
    // split key = ` (backwards quotation)
    var projects = responseText.split("`");
    for (x in projects) {  projects[x] = JSON.parse(projects[x]); }
    var displayText = "";
    var text = [];
    for (i=0; i<projects.length; i++) {
        displayText += "<div class=\"flex-item\" id=\"item";
        var date = projects[i].hidden.date;
        var rank = projects[i].hidden.rank;
        var type = projects[i].hidden.type;
        var title = projects[i].visible.title;
        var projectInfo = projects[i].visible.projectInfo;
        var primaryImg = projects[i].visible.primaryImg;
        var description = projects[i].visible.description;
        var secondaryImg = [];
        for (j=0; j<projects[i].visible.secondaryImg.length; j++) {
            secondaryImg[j] = projects[i].visible.secondaryImg[j];
        }
        var reference = [];
        var ribbon = [];
        
        for (l=0; l<projects[i].visible.links.length; l++) {
        k = 0; 
        reference[k] = projects[i].visible.links[l];
        ribbon[k] = projects[i].visible.links[l+1];
        l++; 
        k++;
        }

        var order = Number(rank) + 1; 
        displayText += rank + "\" style=\"order:" + order + "\"> <h2>" + title + "</h2> <p style=\"font-family:ariel\">" + "&emsp;&emsp;" + projectInfo + "</p> <div class=\"center\"> <img src=\"" + primaryImg + "\" alt=\"\" style=\"width:100%; height:auto\"> <div class=\"center\">";
        for(m=0; m<reference.length; m++)
        displayText += "<a class=\"active\" href=\"" + reference[m] + "\"> <button type=\"button\" class=\"button\" style=\"font-size:15px\">" + ribbon[m] + "</button>  </a> ";
        if (description != '' || secondaryImg.length != 0){
        displayText += "</div> <a class=\"active\" id=\"expanded" + order + "Link\" onclick=\"expandText('expanded" + order + "')\" style=\"color:blue;cursor:pointer;display:inline\"><u>More...</u></a></div><div id=\"expanded" + order + "\" style=\"display:none\"> <p style=\"font-family:ariel\">" + "&emsp;&emsp;" + description + "</p> <div class=\"center\">"; 
        for (k=0; k<secondaryImg.length; k++){
            displayText += "<img src=\"" + secondaryImg[k] + "\" alt=\"\" style=\"width:100%; height:auto\">";
        } 
        displayText += "</div> <div class=\"center\"> <a> <div class=\"active\" onclick=\"expandText('expanded" + order + "')\" style=\"color:blue;cursor:pointer\"><u>Less...</u></a> </div> </div> </div> </div>";
    }
        else {
            displayText += "</div> </div> </div> </div>";
        }
    }
    console.log(displayText);
    document.getElementById("projects").innerHTML = displayText;
}
