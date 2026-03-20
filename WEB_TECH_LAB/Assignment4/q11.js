const decreaseBtn = document.getElementById('decreaseBtn');
const increaseBtn = document.getElementById('increaseBtn');
const sizeDisplay = document.getElementById('sizeDisplay');
const body = document.body;

const sizes = ['size-small', 'size-medium', 'size-large', 'size-xlarge'];
const sizeNames = ['Small', 'Medium', 'Large', 'X-Large'];
let currentSizeIndex = 1;

const savedSize = localStorage.getItem('fontSize');
if (savedSize) {
    currentSizeIndex = parseInt(savedSize);
    applySizeClass();
}

decreaseBtn.addEventListener('click', () => {
    if (currentSizeIndex > 0) {
        currentSizeIndex--;
        saveSizeAndApply();
    }
});

increaseBtn.addEventListener('click', () => {
    if (currentSizeIndex < sizes.length - 1) {
        currentSizeIndex++;
        saveSizeAndApply();
    }
});

function saveSizeAndApply() {
    localStorage.setItem('fontSize', currentSizeIndex.toString());
    applySizeClass();
}

function applySizeClass() {
    sizes.forEach((size) => body.classList.remove(size));
    body.classList.add(sizes[currentSizeIndex]);
    sizeDisplay.textContent = sizeNames[currentSizeIndex];
}
