// TODO error @ year 2027
// list cannot by in order 0 1 2 3 4 5 
// because then they would have the same people

// need to mod 6 but start on 1 not 0. IE % 6 + 1
var nameListShuffled = ["Kate", 
                        "David",
                        "Jeremy",
                        "Josh",
                        "Angela",
                        "Justin"];

var nameList = ["Angela",
                "David",
                "Joshua",
                "Justin",
                "Jeremy",
                "Kate"];
            
var nameListRotated; 
var year;

function rotateNames() {
    nameListRotated = new Array();
    year = Number(document.getElementById("year").value);
    if (year == "")
        year = new Date().getFullYear();
    var offset = Math.floor(year / (nameList.length - 1)) + 1;
    // if (year % nameList.length == 0)
    //     offset = 1;
    console.log("offset " + offset);
    // console.log("length " + nameList.length);
    console.log("year " + year);
    // console.log("offset " + offset);

    for (var i = 0; i < nameList.length; i++)
    {
        var j = (i + year + offset) % (nameList.length);
        console.log(j);
        nameListRotated[i] = nameListShuffled[j];
    }
}

function print()
{
    var tableObjectString = "<b>Year: " + year + "</b>";
    tableObjectString += "<table border=\"1\" id=\"names\">";
    tableObjectString += "<tr>";
    tableObjectString += "<th>They have</th>";
    tableObjectString += "<th>Them</th>";
    tableObjectString += "</tr>";
    for (var i = 0; i < nameListRotated.length; i++)
    {
        tableObjectString += "<tr>";
        tableObjectString += "<td>";
        tableObjectString += nameListShuffled[i];
        tableObjectString += "</td>";
        tableObjectString += "<td>";
        tableObjectString += nameListRotated[i];
        tableObjectString += "</td>";
        tableObjectString += "</tr>";
    }
    tableObjectString += "</table>";
    
    // TODO just have = for non testing purposes to keep it simple
    document.getElementById("table").innerHTML += tableObjectString;
}

function main() {
    // for (var i = 2019; i < 2055; i++)
    // {
    //     rotateNamesTest(i);
    // }
    rotateNames();
    print();
    // nameListRotated.toString();
    // nameListShuffled.toString();
    // document.getElementById("table").innerHTML = "You: \n" + nameListShuffled;
    // document.getElementById("table").innerHTML += "\n\nHave: \n" + nameListRotated;

}

// function rotateNamesTest(i) {
//     nameListRotated = new Array();
//     var year = i;
//     var offset = Math.floor(year / (nameList.length - 1)) + 1;
//     // if (year % nameList.length == 0)
//     //     offset = 1;
//     console.log("offset " + offset);
//     // console.log("length " + nameList.length);
//     console.log("year " + year);
//     // console.log("offset " + offset);

//     for (var i = 0; i < nameList.length; i++)
//     {
//         var j = (i + year + offset) % (nameList.length);
//         console.log(j);
//         nameListRotated[i] = nameListShuffled[j];
//     }
// }