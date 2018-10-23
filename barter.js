const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

var number_of_rates = -2;
var number_of_queries = -1;
var rates = [];
var queries = [];

rl.on('line', (input)=>{
    if(number_of_rates >= 0){
        if(number_of_rates > 0) inputRates(input);
        if(number_of_rates!== -1) number_of_rates--;
    } else if (number_of_rates!== -1) {
        number_of_rates = parseInt(input);
    }

    if(number_of_rates === -1){
        if(number_of_queries !== -1){
            var q = input.split(' ');
            queries.push({
                "from" : q[0],
                "to" : q[1]
            });
            if(number_of_queries!==0) number_of_queries--;
            if(number_of_queries === 0) {
                queries.forEach((element) => {
                    console.log(findExchangeRate(element.from, element.to));
                });
                rl.close();
            }
        } else {
            number_of_queries = parseInt(input);
        }
    }
});

function inputRates(input) {
    var commodity = input.split(' ');
    if(existsInTable(rates, commodity[0])){
        var i = findIndexByKey(rates, commodity[0]);
        rates[i].xrates.push({
            "key" : commodity[1],
            "value" : parseInt(commodity[2]) % 998244353
        });
    } else {
        rates.push({
            "key" : commodity[0],
            "xrates" : [
                {
                    "key" : commodity[1],
                    "value" : parseInt(commodity[2]) % 998244353
                }
            ]
        });
    }
    rates.forEach((element, i) => {
        element.xrates.forEach((element_xchange, l) => {
            if (element_xchange.key === commodity[0]) {
                rates[i].xrates.push({
                    "key" : commodity[1],
                    "value" : (element_xchange.value * commodity[2]) % 998244353
                });
            }
        })
    });
}

function existsInTable(arr, name) {
    var flag = false;
    arr.forEach((element) => { if(element.key===name) flag = true });
    return flag;
}

function findIndexByKey(arr, name) {
    var ind = null;
    arr.forEach((element, index) => { if(element.key===name) ind = index });
    return ind;
}

function findExchangeRate(from, to) {
    if(from===to) return 1;
    var fromIndex = findIndexByKey(rates, from);
    var val = -1;
    if(fromIndex!==null)
        rates[fromIndex].xrates.forEach((element) => { if (element.key===to) val = parseInt(element.value) });
   
    return val % 998244353;
}