const searchInput = document.getElementById('searchInput');
const productList = document.getElementById('productList');
const noProductMessage = document.getElementById('noProductMessage');

const products = [
    'Apple iPhone 13',
    'Samsung Galaxy S21',
    'Sony Headphones Pro',
    'Dell Laptop XPS 15',
    'Apple MacBook Air',
    'Canon Camera EOS',
    'Nintendo Switch',
    'iPad Pro 12.9',
    'Google Pixel 6',
    'LG Smart TV 55',
    'Sony PlayStation 5',
    'Microsoft Xbox Series X',
    'Lenovo ThinkPad',
    'ASUS Monitor 27',
    'WD External Hard Drive'
];

function initializeProducts() {
    products.forEach((product) => {
        const li = document.createElement('li');
        li.textContent = product;
        li.dataset.product = product.toLowerCase();
        productList.appendChild(li);
    });
}

function filterProducts(searchTerm) {
    const term = searchTerm.toLowerCase();
    const productItems = productList.querySelectorAll('li');
    let visibleCount = 0;

    productItems.forEach((item) => {
        const productName = item.dataset.product;
        if (productName.includes(term)) {
            item.style.display = 'block';
            visibleCount++;
        } else {
            item.style.display = 'none';
        }
    });

    if (visibleCount === 0) {
        noProductMessage.style.display = 'block';
    } else {
        noProductMessage.style.display = 'none';
    }
}

searchInput.addEventListener('oninput', () => {
    filterProducts(searchInput.value);
});

searchInput.addEventListener('input', () => {
    filterProducts(searchInput.value);
});

initializeProducts();
