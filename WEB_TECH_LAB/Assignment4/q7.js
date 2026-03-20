const colorInput = document.getElementById('colorInput');
const saveBtn = document.getElementById('saveBtn');
const clearBtn = document.getElementById('clearBtn');
const message = document.getElementById('message');

const savedColor = localStorage.getItem('favoriteColor');
if (savedColor) {
    colorInput.value = savedColor;
    document.body.style.backgroundColor = savedColor;
    message.textContent = 'Color loaded from storage';
}

saveBtn.addEventListener('click', () => {
    const color = colorInput.value;
    localStorage.setItem('favoriteColor', color);
    document.body.style.backgroundColor = color;
    message.textContent = 'Color saved!';
});

clearBtn.addEventListener('click', () => {
    localStorage.removeItem('favoriteColor');
    document.body.style.backgroundColor = 'white';
    colorInput.value = '#ffffff';
    message.textContent = 'Color cleared!';
});
