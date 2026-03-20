const generateBtn = document.getElementById('generateBtn');
const verifyBtn = document.getElementById('verifyBtn');
const pinInput = document.getElementById('pinInput');
const gameContainer = document.getElementById('gameContainer');
const message = document.getElementById('message');
const attemptsDisplay = document.getElementById('attempts');

let generatedPin = null;
let attempts = 3;

generateBtn.addEventListener('click', generatePin);
verifyBtn.addEventListener('click', verifyPin);
pinInput.addEventListener('keypress', (e) => {
    if (e.key === 'Enter') {
        verifyPin();
    }
});

function generatePin() {
    generatedPin = Math.floor(Math.random() * 9000 + 1000);
    attempts = 3;
    pinInput.value = '';
    message.textContent = '';
    attemptsDisplay.textContent = attempts;
    gameContainer.style.display = 'block';
    pinInput.focus();
}

function verifyPin() {
    const userPin = pinInput.value.trim();

    if (userPin === '') {
        message.textContent = 'Please enter a PIN!';
        message.style.color = 'red';
        return;
    }

    if (userPin.length !== 4 || isNaN(userPin)) {
        message.textContent = 'PIN must be 4 digits!';
        message.style.color = 'red';
        return;
    }

    attempts--;

    if (userPin == generatedPin) {
        message.textContent = 'Correct PIN! You won!';
        message.style.color = 'green';
        pinInput.disabled = true;
        verifyBtn.disabled = true;
        return;
    }

    if (attempts === 0) {
        message.textContent = 'Game Over! The correct PIN was: ' + generatedPin;
        message.style.color = 'red';
        pinInput.disabled = true;
        verifyBtn.disabled = true;
        attemptsDisplay.textContent = '0';
        return;
    }

    message.textContent = 'Wrong PIN! Try again.';
    message.style.color = 'orange';
    attemptsDisplay.textContent = attempts;
    pinInput.value = '';
    pinInput.focus();
}
