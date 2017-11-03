// assign04.js
// the scripts for Java Calculator
//*************************************************************//

function autoCompute () {
    // get APR, loan term, and loan amount
    var APR = document.getElementById("APR");
    var loanTerm = document.getElementById("loanTerm");
    var loanAmount = document.getElementById("loanAmount");
    var monthlyPayment = document.getElementById("monthlyPayment");
    var dom = document.getElementById("form");
    var num;
    numFilledOut = 0;
    for (i = 0; i < dom.inputs.length; i++)
    {
        if (dom.inputs[i].value != ""){
            numFilledOut++;
        }
        if (numFilledOut == dom.inputs.length) {
        var monthlyInterest = APR.value / 1200;
        num = loanAmount.value * monthlyInterest * (Math.pow((1 + monthlyInterest), (loanTerm.value * 12))) / (Math.pow((1 + monthlyInterest), (loanTerm.value * 12)) - 1);
        num = num.toFixed(2);
        // caluculate monthly payment ? amount * APR (ex. .06) * term / (12 * term) = monthly payment
        monthlyPayment.innerHTML = "$" + num;
        }
        else{
            num = "";
            monthlyPayment.innerHTML = num;
        }
    }
}

function manuallyCompute () {
    // get APR, loan term, and loan amount
    var APR = document.getElementById("APR");
    var loanTerm = document.getElementById("loanTerm");
    var loanAmount = document.getElementById("loanAmount");
    var monthlyPayment = document.getElementById("monthlyPayment");
    var dom = document.getElementById("form");
    var num;
    numFilledOut = 0;
    for (i = 0; i < dom.inputs.length; i++)
    {
        if (dom.inputs[i].value == "") {
            num = "Please Enter APR, Loan-Amount, And Loan-Term :)";
            monthlyPayment.innerHTML = num;
            dom.inputs[i].focus();
            return;
        }
        if (dom.inputs[i].value != ""){
            numFilledOut++;
        }
        if (numFilledOut == dom.inputs.length) {
            var monthlyInterest = APR.value / 1200;
            num = loanAmount.value * monthlyInterest * (Math.pow((1 + monthlyInterest), (loanTerm.value * 12))) / (Math.pow((1 + monthlyInterest), (loanTerm.value * 12)) - 1);
            num = num.toFixed(2);
        // caluculate monthly payment ? amount * APR (ex. .06) * term / (12 * term) = monthly payment
        monthlyPayment.innerHTML = "$" + num;
        }
        else{
            num = "";
            monthlyPayment.innerHTML = num;
        }
    }
} 

function focusOnForm () {
    var firstField = document.getElementById("APR");
    firstField.focus();
    document.getElementById("monthlyPayment").innerHTML = "";
}