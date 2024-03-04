<script>
  import Task from './Task.svelte'

  let newTaskName = ''
  let tasks = []


  // Функция добавления новой задачи
  function addNewTask() {
    if (!newTaskName.trim())
      return
    tasks = [...tasks, newTaskName]  // Нельзя просто использовать tasks.push(newTaskName), т.к. Svelte не поймет, что нужно обновить DOM
    newTaskName = ''
  }
</script>

<main>
  <h1>Simple TODO App in Svelte</h1>

  <!--Форма, в которой пользователь вводит текст новой задачи. Мы используем форму, чтобы при нажатии Enter автоматически нажималась кнопка и выполнялся on click ивент-->
  <!--С помощью конструкции on: обрабатываем событие submit, параллельно используя модификатор обработчика событий preventDefault, который 
  помогает не обновлять страницу при отправке формы. -->
  <form id="input-line" on:submit|preventDefault={() => {}}>
    <!--Для того, чтобы иметь возможность использовать введеный пользователем текст задачи, используем binding в Svelte.
    bind:value = {newTaskName} -- При изменении аттрибута value тега <input> меняется и newTaskname (название новой задачи).
    То же самое работает и в обратную сторону. То есть при изменении newTaskName меняется value <input>-->
    <input maxlength="30" class="task-input" placeholder="Enter your task here..." bind:value={newTaskName}/>
    <button id="add-task-btn" on:click={addNewTask} hidden>Add</button>
  </form>

  <!--Выводим список задач, используя конструкцию фреймворка Svelte each-->
  <ul id="tasks">
    {#each tasks as task}
      <Task taskText={task}/>
    {/each}
  </ul>
</main>

<style>
  #input-line {
    display: flex;
    gap: 10px
  }

  .task-input {
    display: inline-block;
    width: var(--task-div-length);
    height: 50px;
    font-size: 40px;
    font-family: Helvetica;
    font-weight: 500;
    border: 1px solid #4d4d4d;
    padding: 0.5rem;
    background-color: #242424;
  }

  #add-task-btn {
    display: inline-block;
    height: 65px;
    width: 100px;
    border-radius: 3px;
    display: none;
  }

  #tasks {
    gap:0;
    margin:0;
    padding:0;
  }

</style>
