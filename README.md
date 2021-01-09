### [RU][1] Описание проекта на русском
[1]: https://github.com/udraugr/ft_select/new/master?readme=1#ft_select---%D1%82%D1%80%D0%B5%D0%BD%D0%B8%D1%80%D0%BE%D0%B2%D0%BE%D1%87%D0%BD%D1%8B%D0%B9-%D0%BF%D1%80%D0%BE%D0%B5%D0%BA%D1%82-%D0%BF%D0%BE-%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B5-%D1%81-termcup "RU"
### [EN][2] Description of the project in English
[2]: https://github.com/udraugr/ft_select/new/master?readme=1#ft_select---termcup-training-project "EN"

# FT_SELECT - тренировочный проект по работе с termcup
Это программа, которая получает в аргументы список файлов, внутри программы можно выбрать файлы и вывести.
Проект был выполнен в Школе Программирования 21 (филиал французкой школы "Ecole 42").

# Сборка проекта:
Для компиляции потребуется скачать библиотеку termcap. 
Для того, чтобы собрать проект, необходимо зайти в корневой каталог проекта и в терминале прописать команду **make**

# Запус проекта:
**./ft_select [list of files]**

# Функционал:
Рисует список файлов, с которыми можно взаимодействовать:
* **ECS** выйти из программы
* **SPACE** выбрать файл и переместится к следующему
* **DELETE** удаляет файл перед курсором
* **BACK INSERT** удаляет файл на котором находится курсор
* Стрелочки **вверх/вниз** премещают курсор вверх/вниз по списку
* Стрелочки **влево/вправо** перемещают курсор влево/вправо по списку
* **ENTER** вывести выбранные файлы
* **f** режим поиска файла, **enter** поиск
  
  *Пример*:
    ![find](https://github.com/udraugr/ft_select/blob/master/example_of_work/find.png)
    ![result](https://github.com/udraugr/ft_select/blob/master/example_of_work/result.png)

# Пример работы
1) запускаем с файлами(цвета различаются от типа файла)
![begin](https://github.com/udraugr/ft_select/blob/master/example_of_work/begin.png)
2) выбираем файлы
![choose](https://github.com/udraugr/ft_select/blob/master/example_of_work/choose.png)
3) нажимаем enter
![output](https://github.com/udraugr/ft_select/blob/master/example_of_work/output.png)

### Примечание:
Этот проект полностью написан в школе программирования 21, и принадлежит ей.


# FT_SELECT - termcup training project
This is a program that receives a list of files as arguments, inside the program you can select files and output.
The project was done at Programming School 21 (a branch of the French school "Ecole 42").

# Build the project:
To compile, you will need to download the termcap library.
In order to build the project, you need to go to the root directory of the project and in the terminal type the command **make**

# Run the project:
**./ft_select [list of files]**

# Functionality:
Draws a list of files that you can interact with:
* **ECS** exit the program
* **SPACE** selects a file and moves to the next
* **DELETE** deletes the file before the cursor
* **BACK INSERT** deletes the file where the cursor is
* **UP/DOWN ARROWS** moves cursor up/down through the list
* The **left/right arrows** move the cursor left/right through the list
* **ENTER** output the selected files
* **f** file search mode, **enter** search

  *Example*:
    ![find](https://github.com/udraugr/ft_select/blob/master/example_of_work/find.png)
    ![result](https://github.com/udraugr/ft_select/blob/master/example_of_work/result.png)

# Example work
1) start with the files (colors differ depending on the type of file)
![begin](https://github.com/udraugr/ft_select/blob/master/example_of_work/begin.png)
2) choose the files
![choose](https://github.com/udraugr/ft_select/blob/master/example_of_work/choose.png)
3) press enter
![output](https://github.com/udraugr/ft_select/blob/master/example_of_work/output.png)

### Note:
This project is done at programming School 21, and belongs to it.
