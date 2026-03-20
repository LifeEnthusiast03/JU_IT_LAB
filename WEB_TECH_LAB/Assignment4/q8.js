const quoteDisplay = document.getElementById('quoteDisplay');

const quotes = [
    'The only way to do great work is to love what you do.',
    'Innovation distinguishes between a leader and a follower.',
    'Life is what happens when you are busy making other plans.',
    'The future belongs to those who believe in the beauty of their dreams.',
    'It is during our darkest moments that we must focus to see the light.',
    'The way to get started is to quit talking and begin doing.',
    'Do not go where the path may lead, go instead where there is no path.'
];

let currentIndex = 0;

function displayQuote() {
    quoteDisplay.textContent = quotes[currentIndex];
    currentIndex = (currentIndex + 1) % quotes.length;
}

displayQuote();

setInterval(displayQuote, 4000);
