const readline = require('node:readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

  

function merge(...objects) {
    return objects.reduce((result, obj) => {
        for (const key in obj)
            if (!(key in result))
                result[key] = obj[key];
        return result;
    }, {});
}

// Пример использования
// const obj1 = {a: 1, b: 2};
// const obj2 = {b: 3, c: 4};
// const obj3 = {c: 5, d: 6};

// const mergedObj = merge(obj1, obj2, obj3);
// console.log(mergedObj); // {a: 1, b: 2, c: 4, d: 6}

async function input(prompt) {
    console.log(prompt);
    return (await rl[Symbol.asyncIterator]().next()).value;
}

async function main() {
    let running = true
    let objects = []

    while (running) {
        const k = await input('Enter attribute\'s name')
        const v = await input('Enter attribute\'s val')
        const ob = {}
        ob[k] = v

        running = await input('Add one more object? (y/n)') == 'y'
        console.log(merge(...objects))

    }
    rl.close()

}

main()