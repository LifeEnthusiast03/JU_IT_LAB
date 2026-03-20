const searchInput = document.getElementById('searchInput');
const productsContainer = document.getElementById('productsContainer');

let allProducts = [];

fetch('products.json')
    .then((response) => response.json())
    .then((data) => {
        allProducts = data;
        displayProducts(allProducts);
    });

searchInput.addEventListener('input', (e) => {
    const searchTerm = e.target.value.toLowerCase();
    const filtered = allProducts.filter((product) =>
        product.name.toLowerCase().includes(searchTerm)
    );
    displayProducts(filtered);
});

function displayProducts(products) {
    productsContainer.innerHTML = '';

    if (products.length === 0) {
        const noProducts = document.createElement('div');
        noProducts.className = 'no-products';
        noProducts.textContent = 'No products found';
        productsContainer.appendChild(noProducts);
        return;
    }

    products.forEach((product) => {
        const card = document.createElement('div');
        card.className = 'product-card';

        const name = document.createElement('h3');
        name.textContent = product.name;

        const category = document.createElement('p');
        category.textContent = 'Category: ' + product.category;

        const price = document.createElement('p');
        price.className = 'price';
        price.textContent = '$' + product.price.toFixed(2);

        card.appendChild(name);
        card.appendChild(category);
        card.appendChild(price);

        productsContainer.appendChild(card);
    });
}
