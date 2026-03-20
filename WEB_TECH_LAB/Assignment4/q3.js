const expenseName = document.getElementById('expenseName');
const expenseAmount = document.getElementById('expenseAmount');
const addBtn = document.getElementById('addBtn');
const totalExpense = document.getElementById('totalExpense');
const expenseList = document.getElementById('expenseList');

let expenses = [];

addBtn.addEventListener('click', addExpense);
expenseAmount.addEventListener('keypress', (e) => {
    if (e.key === 'Enter') {
        addExpense();
    }
});

function addExpense() {
    const name = expenseName.value.trim();
    const amount = parseFloat(expenseAmount.value.trim());

    if (name === '') {
        alert('Please enter expense name!');
        return;
    }

    if (isNaN(amount) || amount <= 0) {
        alert('Please enter a valid amount!');
        return;
    }

    const expense = {
        id: Date.now(),
        name: name,
        amount: amount
    };

    expenses.push(expense);
    updateUI();
    expenseName.value = '';
    expenseAmount.value = '';
    expenseName.focus();
}

function updateUI() {
    updateTotal();
    updateExpenseList();
}

function updateTotal() {
    const total = expenses.reduce((sum, expense) => sum + expense.amount, 0);
    totalExpense.textContent = total.toFixed(2);
}

function updateExpenseList() {
    expenseList.innerHTML = '';

    const lastFive = expenses.slice(-5).reverse();

    if (lastFive.length === 0) {
        expenseList.innerHTML = '<li>No expenses yet</li>';
        return;
    }

    lastFive.forEach((expense) => {
        const li = document.createElement('li');
        li.textContent = expense.name + ' - $' + expense.amount.toFixed(2);
        expenseList.appendChild(li);
    });
}
