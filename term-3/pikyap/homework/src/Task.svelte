<script>
    export let taskText  // Переменная, которую нужно заполнить при создании экземпляра Task. Это текст задачи.
    let taskDone = false  // Зачеркнутый ли стиль у текста нашей задачи? (применяется при нажатии на чекбокс).

    let hideX = true  // Вспомогательная переменная, отвечающая за появления кнопки удалить задачу рядом с задачей.
    let deleteSelf = false  // Была ли удалена текущая задача?
</script>

<!-- Конструкция class:название_класса={true/false} позволяет применить определенный класс на какой-либо тег HTML.
В данном случае мы используем его для скрытия задачи, если она была удалена.-->
<main class:hidden={deleteSelf}>
    <!-- Так как события on:hover нет в Svelte, то пришлось использовать on:mouseover и mouseout, что выполняет ту же самую работу.
    Когда мышка над задачей, то справа от нее должен появиться крест, чтобы пользователь мог удалить ее. Поэтому при наведении делаем
    hideX = false, а когда мышь не на элементе -- hideX = true. -->
    <div id="task-n-cross" on:mouseover={() => hideX = false} on:mouseout={() => hideX = true}>
        <div id="content-in-box">
            <!-- Если задача выполнена, то применяем класс strike к <p> -->
            <p class:strike={taskDone}>{taskText}</p>
            <!-- Если на чекбокс нажали, то задача выполнена => taskDone = true. Если снова нажали, то отменяем действие. 
            Для обработки этого события используем конструкцию on:событие-->
            <input type="checkbox" on:click={() => taskDone = !taskDone}>
        </div>
        <!--Создаем button, внутри которой находится img. Для обработки события on:click используем button (Иначе нельзя).-->
        <button id="transparent-btn" class:hidden={hideX} on:click={() => deleteSelf = true}>
            <img id="x-img" src="./public/x-lg.svg" alt="delete task">
        </button>
    </div>
</main>

<!--Стили для этого компонента-->
<style>
    #content-in-box {
        display: flex;
        justify-content: space-between;
        align-items: center;
        width: var(--task-div-length);
        height: 50px;
        font-size: 40px;
        font-family: Helvetica;
        font-weight: 500;
        border-radius: 5px;
        border: 1px solid #4d4d4d;
        padding: 0.5rem;
        background-color: #242424;
        margin: 0;
        border-radius: 0;
    }

    #content-in-box:hover {
        background-color: #333333;
        transition: background-color 0.3;
    }


    input {
        min-width: 50px;
        max-width: 50px;
        height: 50px;
    }

    .strike {
        text-decoration: line-through;
    }

    #x-img {
        width: 40px;
        height: 40px;
    }

    .hidden {
        display: none;
    }


    #transparent-btn {
        background: none;
        border: none;
        margin: 0;
        padding: 0;
        position: absolute;
        right: -20px;
    }

    #transparent-btn:hover {
        filter: invert(1);
        transition: 0.3s all;
    }

    #task-n-cross {
        display: flex;
        gap: 15px;
        align-items: center;
        position: relative;
    }
</style>