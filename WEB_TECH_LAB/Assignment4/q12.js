const textArea = document.getElementById('textArea');
const wordCount = document.getElementById('wordCount');
const warning = document.getElementById('warning');

textArea.addEventListener('input', () => {
    const text = textArea.value.trim();
    
    let count = 0;
    if (text.length > 0) {
        const words = text.split(/\s+/);
        count = words.length;
    }

    wordCount.textContent = count;

    if (count > 100) {
        warning.style.display = 'block';
    } else {
        warning.style.display = 'none';
    }
});
