const option1Btn = document.getElementById('option1');
const option2Btn = document.getElementById('option2');
const option3Btn = document.getElementById('option3');

const votes = {
    javascript: 0,
    python: 0,
    java: 0
};

option1Btn.addEventListener('click', () => {
    votes.javascript++;
    updateResults();
});

option2Btn.addEventListener('click', () => {
    votes.python++;
    updateResults();
});

option3Btn.addEventListener('click', () => {
    votes.java++;
    updateResults();
});

function updateResults() {
    const total = votes.javascript + votes.python + votes.java;

    const percent1 = total === 0 ? 0 : Math.round((votes.javascript / total) * 100);
    const percent2 = total === 0 ? 0 : Math.round((votes.python / total) * 100);
    const percent3 = total === 0 ? 0 : Math.round((votes.java / total) * 100);

    document.getElementById('votes1').textContent = votes.javascript;
    document.getElementById('votes2').textContent = votes.python;
    document.getElementById('votes3').textContent = votes.java;

    document.getElementById('percent1').textContent = percent1;
    document.getElementById('percent2').textContent = percent2;
    document.getElementById('percent3').textContent = percent3;

    document.getElementById('bar1').style.width = percent1 + '%';
    document.getElementById('bar2').style.width = percent2 + '%';
    document.getElementById('bar3').style.width = percent3 + '%';

    document.getElementById('totalVotes').textContent = total;
}
