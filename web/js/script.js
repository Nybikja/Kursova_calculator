const itemsList = document.getElementById("items_list");

let items = []

const itemTemplate = ({id, example}) => `
<li id="${id}" class="item-card">
  <div>
    <p>${example}</p>
  </div>
</li>
`

const refetchAllItems = () => {
    getExamples();
}

const renderItemsList = (items) => {
    itemsList.innerHTML = "";
    for (const item of items) {
        console.log(item)
        addItemToPage(item);
    }
}

const addItemToPage = ({id, example}) => {
    itemsList.insertAdjacentHTML(
        "afterbegin",
        itemTemplate({id, example})
    );
};

function getDataFromServer(id) {
    const btn = document.getElementById(id);
    if (btn.className === 'buttonCalc') {
        sendCommandToServer("button_" + id)
    }
}

function getExamples() {
    fetch("http://127.0.0.1:5000/calculator")
        .then(res => res.json())
        .then(out => renderItemsList(out))
}


function sendCommandToServer(command) {
    fetch("http://127.0.0.1:5000/calculator", {
        method: 'POST',
        mode: 'cors',
        cache: 'no-cache',
        credentials: 'same-origin',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify(command)
    }).then(function (response) {
        if (response.status !== 200) {
            console.log('Error');
        } else console.log(response)
    })
}

refetchAllItems()

