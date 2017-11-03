// assign05r.js
// the scripts for Java Calculator
//*************************************************************//
document.body.onload = focusOnForm;
document.getElementById("form").onsubmit=validateFields;
document.getElementById("form").onreset=focusOnForm;
document.getElementById("phonenum").onblur=validatePhone;
document.getElementById("cardnum").onblur=validateCardNum;
document.getElementById("cardexp").onblur=validateExpiration;
document.getElementById("product1").onclick=buyProduct1;
document.getElementById("product2").onclick=buyProduct2;
document.getElementById("product3").onclick=buyProduct3;
document.getElementById("product4").onclick=buyProduct4;
document.getElementById("product5").onclick=buyProduct5;