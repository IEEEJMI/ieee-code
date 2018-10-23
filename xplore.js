const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

var num = -1;
var authors = [];
var author_citations = [];
var h_index = [];

rl.on('line', (input) => {
    if(num !== -1) {
        authors.push(input);
        num--;
        if(num===0) {
            // Parse strings of Authors
            authors.forEach((auth, i) => {
                authors[i] = JSON.parse(auth);
            });

            authors.forEach((_authors, i) => {
                _authors.authors.authors.forEach((auth) => {
                    if(authCountInitialized(auth.full_name)) {
                        var index = findIndexofAuth(auth.full_name);
                        if(index!==null) author_citations[index].citation_count.push(_authors.citing_paper_count);
                    } else {
                        author_citations.push({
                            "author_name" : auth.full_name,
                            "citation_count" : [ _authors.citing_paper_count ]
                        });
                    }
                })
            })

            author_citations.forEach((auth) => {
                auth.citation_count.sort((a, b) => { return (b-a) });
            });
            
            author_citations.forEach((auth) => {
                var h = 0;

                // Main h-index Logic
                for(var k=1 ; ; k++) {
                    var flag = 0;
                    for(var l=0; l<k; l++) {
                        if(auth.citation_count[l]>=k){
                            flag = 0;
                        } else {
                            flag = 1;
                        };
                    }
                    if(flag===1) break;
                        
                    h = k;
                }

                h_index.push({
                    "author_name" : auth.author_name,
                    "h" : h
                });
            });

            sortJSONArray(h_index);
            h_index.forEach((element) => {
                console.log(element.author_name, element.h);
            });

            rl.close();
        }
    } else {
        num = parseInt(input);
    }
});

function authCountInitialized(name) {
    var flag = 0;
    author_citations.forEach((auth) => {
        if(name===auth.author_name) flag = 1;
    });
    if(flag===1) return true;
    else return false;
}

function findIndexofAuth(name) {
    var flag = -1;
    author_citations.forEach((auth, i) => {
        if(name===auth.author_name) flag = i;
    });
    if(flag!== -1) return flag;
    else return null;
}

function sortJSONArray(arr) {
    arr.sort((a, b) => {
        if(b.h === a.h) {
            if(a.author_name < b.author_name) return -1;
            if(a.author_name > b.author_name) return 1;
            return 0;
        } 
        return (b.h - a.h);
    });
}