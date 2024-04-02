const produtos = [
  { codigo: 1, nome: "Cachorro Quente", preco: 4.00 },
  { codigo: 2, nome: "X-Salada", preco: 4.50 },
  { codigo: 3, nome: "X-Bacon", preco: 5.00 },
  { codigo: 4, nome: "Torrada Simples", preco: 2.00 },
  { codigo: 5, nome: "Refrigerante", preco: 1.50 }
];

document.addEventListener("DOMContentLoaded", function() {
  const tableBody = document.getElementById("products-table");

  produtos.forEach(produto => {
    const row = document.createElement("tr");
    row.innerHTML = `
      <td>${produto.codigo}</td>
      <td>${produto.nome}</td>
      <td>${produto.preco.toFixed(2)}</td>
    `;
    tableBody.appendChild(row);
  });

  const form = document.getElementById("pedido-form");
  form.addEventListener("submit", function(event) {
    event.preventDefault(); 

    const codigoInput = document.getElementById("codigo");
    const quantidadeInput = document.getElementById("quantidade");
    const resultadoDiv = document.getElementById("resultado");

    const codigo = parseInt(codigoInput.value);
    const quantidade = parseInt(quantidadeInput.value);

    const resultado = calcularTotal(codigo, quantidade);
    resultadoDiv.textContent = resultado;
  });
});

function calcularTotal(codigo, quantidade) {
  const produto = produtos.find(prod => prod.codigo === codigo);
  if (!produto) {
    return "Produto não encontrado.";
  }
  const total = produto.preco * quantidade;
  return `Total: R$ ${total.toLocaleString('pt-BR', { minimumFractionDigits: 2 })}`;
}
