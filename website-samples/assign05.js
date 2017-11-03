// assign05.js
// the scripts for Java Calculator
//*************************************************************//
var total = 0;

function validateFields() {
    var numFilledOut = 0;
    var dom = document.getElementById("form");
    var validPhone = validatePhone();
    var validCardNum = validateCardNum();
    var validExpiration = validateExpiration();
    if (validPhone == true && validCardNum == true && validExpiration == true) {
        for (i = 0; i < dom.inputs.length; i++) {
            if (dom.inputs[i].value == "") {
                dom.inputs[i].focus();
                return false;
            }
            if (dom.inputs[i].value != "") {
                numFilledOut++;
            }
            if (numFilledOut == dom.inputs.length) {
                return true;
            }
        }
    } else {
        return false;
    }
}

function focusOnForm() {
    var firstElement = document.getElementById("firstname");
    firstElement.focus();
}

function validatePhone() {
    var errorMessage = document.getElementById("errPhoneInvalid").style;
    var phone = document.getElementById("phonenum");
    var pos = phone.value.search(/^\d{3}-?\d{3}-?\d{4}$/);
    if (pos != 0) {
        errorMessage.visibility = "visible";
        phone.focus();
        return false;
    } else {
        errorMessage.visibility = "hidden";
        return true;
    }
}

function validateCardNum() {
    var errorMessage = document.getElementById("errCardNum").style;
    var DOM = document.getElementById("cardnum");
    var pos = DOM.value.search(/^\d{16}$/);
    if (pos != 0) {
        errorMessage.visibility = "visible";
        DOM.focus();
        return false;
    } else {
        errorMessage.visibility = "hidden";
        return true;
    }
}

function validateExpiration() {
    var errorMessage = document.getElementById("errCardExp").style;
    var DOM = document.getElementById("cardexp");
    var pos = DOM.value.search(/^\d{2}\/20\d{2}$/);
    var year = DOM.value.substring(3, 7);
    var month = DOM.value.substring(0,2);
    if (pos != 0) {
        errorMessage.visibility = "visible";
        DOM.focus();
        return false;
    }
    if (year <= 2011) {
        DOM.focus();
        errorMessage.visibility = "visible";
        return false;
    }
    if (month < 1 || month > 12) {
        DOM.focus();
        errorMessage.visibility = "visible";
        return false;
    } else {
        errorMessage.visibility = "hidden";
        return true;
    }
}

function buyProduct1() {
    total = Number(total);
    var price = document.getElementById("product1");
    if (price.checked == true)
        total += Number(price.value);
    if (price.checked == false)
        total -= Number(price.value);
    total = total.toFixed(2);
    document.getElementById("carttotal").innerHTML = "$" + total;
}

function buyProduct2() {
    total = Number(total);
    var price = document.getElementById("product2");
    if (price.checked == true)
        total += Number(price.value);
    if (price.checked == false)
        total -= Number(price.value);
    total = total.toFixed(2);
    document.getElementById("carttotal").innerHTML = "$" + total;
}

function buyProduct3() {
    total = Number(total);
    var price = document.getElementById("product3");
    if (price.checked == true)
        total += Number(price.value);
    if (price.checked == false)
        total -= Number(price.value);
    total = total.toFixed(2);
    document.getElementById("carttotal").innerHTML = "$" + total;
}

function buyProduct4() {
    total = Number(total);
    var price = document.getElementById("product4");
    if (price.checked == true)
        total += Number(price.value);
    if (price.checked == false)
        total -= Number(price.value);
    total = total.toFixed(2);
    document.getElementById("carttotal").innerHTML = "$" + total;
}

function buyProduct5() {
    total = Number(total);
    var price = document.getElementById("product5");
    if (price.checked == true)
        total += Number(price.value);
    if (price.checked == false)
        total -= Number(price.value);
    total = total.toFixed(2);
    document.getElementById("carttotal").innerHTML = "$" + total;
}