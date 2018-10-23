const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

var inp = 3;
var N, M;
var A = [], B = [];

rl.on('line', (input)=>{
    if(inp===3) {
        N = input.split(' ')[0];
        M = input.split(' ')[1];
        inp--;
    } else if(inp===2) {
        let t_A = input.split(' ');
        t_A.forEach(element => {
            A.push(element);
        });
        inp--;
    } else if(inp===1) {
        let t_B = input.split(' ');
        t_B.forEach(element => {
            B.push(element);
        });
        main();
        rl.close();
    }
});

function main() {
  var C = [];
  for(var i=0; i<N; i++){
    let set = [];
    for(var j=0; j<M; j++)
      set.push(A[i] * B[j]);
    C.push(set);
  }

  var sums = [];
  for(let s_X=0; s_X<N; s_X++){
    for(let s_Y=0; s_Y<M; s_Y++){
      for(let e_X=s_X; e_X<N; e_X++){
        for(let e_Y=s_Y; e_Y<N; e_Y++){
          // Sum the Rectangle
          var sum=0;
          for(let i=s_X; i<=e_X; i++){
            for(let j=s_Y; j<=e_Y; j++){
              sum+=C[i][j];
            }
          }
          sums.push(sum);
        }
      }
    }
  }

  let max = sums[0];
  for(let m=0; m<sums.length; m++)
    if(sums[m]>max) max = sums[m];
  
  console.log(max);
}

