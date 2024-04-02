const readline = require('readline');


const produtos = [
  { codigo: 1, nome: "Cachorro Quente", preco: 4.00 },
  { codigo: 2, nome: "X-Salada", preco: 4.50 },
  { codigo: 3, nome: "X-Bacon", preco: 5.00 },
  { codigo: 4, nome: "Torrada Simples", preco: 2.00 },
  { codigo: 5, nome: "Refrigerante", preco: 1.50 }
];

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function imprimirTabelaProdutos() {
  console.log("Código | Produto          | Preço");
  console.log("---------------------------------");
  produtos.forEach(prod => {
    console.log(`${prod.codigo}      | ${prod.nome.padEnd(16)} | R$ ${prod.preco.toFixed(2)}`);
  });
  console.log("---------------------------------");
}


function calcularTotal(codigo, quantidade) {
  const produto = produtos.find(prod => prod.codigo === codigo);
  if (!produto) {
    return "Produto não encontrado.";
  }
  const total = produto.preco * quantidade;
  return `Total: R$ ${total.toLocaleString('pt-BR', { minimumFractionDigits: 2 })}`;
}

function fazerPedido() {
  imprimirTabelaProdutos();
  rl.question('Digite o código do produto (ou "sair" para encerrar): ', (codigo) => {
    if (codigo.toLowerCase() === 'sair') {
      console.log('Pedido encerrado.');
      console.log("---------------------------------");
      rl.close();
    } else {
      rl.question('Digite a quantidade desejada: ', (quantidade) => {
        const resultado = calcularTotal(parseInt(codigo), parseInt(quantidade));
        console.log(resultado);
        console.log("---------------------------------");
        fazerPedido(); 
      });
    }
  });
}

fazerPedido();
