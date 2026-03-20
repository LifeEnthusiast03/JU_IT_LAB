const loginForm = document.getElementById('loginForm');
const usernameInput = document.getElementById('username');
const emailInput = document.getElementById('email');
const passwordInput = document.getElementById('password');
const usernameError = document.getElementById('usernameError');
const emailError = document.getElementById('emailError');
const passwordError = document.getElementById('passwordError');
const successMessage = document.getElementById('successMessage');

loginForm.addEventListener('submit', (e) => {
    e.preventDefault();
    
    usernameError.textContent = '';
    emailError.textContent = '';
    passwordError.textContent = '';
    successMessage.style.display = 'none';

    let isValid = true;

    if (!validateUsername(usernameInput.value)) {
        usernameError.textContent = 'Username must be at least 5 characters';
        isValid = false;
    }

    if (!validateEmail(emailInput.value)) {
        emailError.textContent = 'Please enter a valid email';
        isValid = false;
    }

    if (!validatePassword(passwordInput.value)) {
        passwordError.textContent = 'Password must be at least 8 characters';
        isValid = false;
    }

    if (isValid) {
        successMessage.style.display = 'block';
        loginForm.reset();
    }
});

function validateUsername(username) {
    const usernameRegex = /^.{5,}$/;
    return usernameRegex.test(username);
}

function validateEmail(email) {
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    return emailRegex.test(email);
}

function validatePassword(password) {
    const passwordRegex = /^.{8,}$/;
    return passwordRegex.test(password);
}
