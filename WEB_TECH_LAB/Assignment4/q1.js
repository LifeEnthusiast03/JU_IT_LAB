const taskInput = document.getElementById('taskInput');
const addBtn = document.getElementById('addBtn');
const taskList = document.getElementById('taskList');
const pendingCount = document.getElementById('pendingCount');

let tasks = [];

addBtn.addEventListener('click', addTask);
taskInput.addEventListener('keypress', (e) => {
    if (e.key === 'Enter') {
        addTask();
    }
});

function addTask() {
    const taskText = taskInput.value.trim();

    if (taskText === '') {
        alert('Please enter a task!');
        return;
    }

    const task = {
        id: Date.now(),
        text: taskText,
        completed: false
    };

    tasks.push(task);
    renderTasks();
    taskInput.value = '';
    taskInput.focus();
}

function renderTasks() {
    taskList.innerHTML = '';

    if (tasks.length === 0) {
        taskList.innerHTML = '<li>No tasks yet</li>';
        updatePendingCount();
        return;
    }

    tasks.forEach((task) => {
        const li = document.createElement('li');
        
        if (task.completed) {
            li.classList.add('completed');
        }

        const checkbox = document.createElement('input');
        checkbox.type = 'checkbox';
        checkbox.checked = task.completed;
        checkbox.addEventListener('change', () => toggleCompletion(task.id));

        const taskSpan = document.createElement('span');
        taskSpan.textContent = task.text;

        const deleteBtn = document.createElement('button');
        deleteBtn.textContent = 'Delete';
        deleteBtn.addEventListener('click', () => deleteTask(task.id));

        li.appendChild(checkbox);
        li.appendChild(taskSpan);
        li.appendChild(deleteBtn);

        taskList.appendChild(li);
    });

    updatePendingCount();
}

function toggleCompletion(taskId) {
    const task = tasks.find((t) => t.id === taskId);
    if (task) {
        task.completed = !task.completed;
        renderTasks();
    }
}

function deleteTask(taskId) {
    tasks = tasks.filter((t) => t.id !== taskId);
    renderTasks();
}

function updatePendingCount() {
    const pending = tasks.filter((t) => !t.completed).length;
    pendingCount.textContent = pending;
}

renderTasks();
