// assign04r.js
// Registers the event handlers. Doesn't work with IE8

document.getElementById("calculate").onclick = manuallyCompute;
document.body.onload = focusOnForm;
document.getElementById("form").onreset = focusOnForm;
document.getElementById("loanTerm").onchange = autoCompute;
document.getElementById("loanAmount").onchange = autoCompute;
document.getElementById("APR").onchange = autoCompute;
