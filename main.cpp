#include <iostream>
#include <string>
#include <time.h>
#include <random>
class Player { // игрок
    int gold; // количество золота у игрока
    int cobalt; // количество кобальта у игрока
    int corporation; // номер корпорации игрока
    int ID; // ID игрока
    int *own; // номера систем, которыми владеет игрок
    int numberOfOwn; // количество систем, которыми владеет игрок
    std::string name; // имя игрока

public:
   /* Player(int id, std::string Name) { // конструктор
        gold = 0;
        cobalt = 0;
        corporation = 0;
        ID = id;
        name = Name;
    } */
    Player() { // конструктор
        gold = 0;
        cobalt = 0;
        corporation = 0;
        ID = 0;
        name = "";
        numberOfOwn = 0;
        own = new int[0];
    }

    void addSystemToPlayerPlayer(int id) { // добавляет в массив с системами, принадлежащими игроку, новую систему
            int i, array[numberOfOwn + 1];
            if (numberOfOwn != 0) {
                for (i = 0; i < numberOfOwn; i++) {
                    array[i] = own[i];
                }
            }
            own = new int[numberOfOwn + 1];
            for (i = 0; i < numberOfOwn; i++) {
                own[i] = array[i];
            }
            own[numberOfOwn] = id;
            numberOfOwn++;
    }
    bool deleteSystemFromPlayerPlayer(int id) { // убирает из массива с системами, принадлежащими игроку, систему
        int i = 0, array[numberOfOwn - 1], numberOfSystem = -1;
        bool find = true; // проверяет есть ли система в списке
        while (numberOfSystem == -1 && find) { // ищет в массиве нужный ID системы
            if (i >= numberOfOwn) { // счётчик превысил количество систем
                find = false;
            }
            if (own[i] == id) { // если нашли
                numberOfSystem = i;
            } else i++; // не нашли - продолжаем искать
        }
        if (find) {
            for (i = 0; i < numberOfSystem; i++) {
                array[i] = own[i];
            }
            for (i = numberOfSystem; i < numberOfOwn - 1; i++) {
                array[i] = own[i + 1];
            }
            own = new int[numberOfOwn - 1];
            for (i = 0; i < numberOfOwn - 1; i++) {
                own[i] = array[i];
            }


            numberOfOwn--;
        }


        return find;
    }
    void changeName(std::string Name) { // изменяет имя игрока
        name = Name;
    }
    void changeID(int id) { // изменяет ID игрока
        ID = id;
    }
    void changeCorporation(int Corporation) { // изменяет корпорацию игрока
        corporation = Corporation;
    }
    void addGold(int amount) { // добавляет/уменьшает количество золота игрока
        gold = gold + amount;
    }
    void addCobalt(int amount) { // добавляет/уменьшает количество кобальта игрока
        cobalt = cobalt + amount;
    }
    int getID() { // возвращает ID игрока
        return ID;
    }
    std::string getName() { // возвращает имя игрока
        return name;
    }
    int getNumberOfOwn() {
        return numberOfOwn;
    }
    int* getOwn() {
        return own;
    }
};
class System { // система
    bool gold; // добатывается ли в системе золото
    bool cobalt; // добывается ли в системе кобальт
    bool destroyed; // уничтожена ли система
    bool doubleRing; // является ли двойным кольцом
    bool war; // находится ли в состоянии войны
    std::string name; // название системы
    int player = 0; // номер игрока (в массиве + 1), которому принадлежит система (1 ... 4; 0 - никому)
public:
    System() { // конструктор
        gold = false;
        cobalt = false;
        destroyed = false;
        doubleRing = false;
        war = false;
        player = 0;
        name = "";
    }
    void links(int system) {

    }
    void changeSystemGold(bool Gold) { // меняет информацию о золоте
        gold = Gold;
    }
    void changeSystemCobalt(bool Cobalt) { // меняет информацию о кобальте
        cobalt = Cobalt;
    }
    void changeSystemDoubleRing(bool DoubleRing) { // меняет информацию о том является ли система Двойным Кольцом или нет
        doubleRing = DoubleRing;
    }
    void changeSystemName(std::string Name) { // меняет название системы
        name = Name;
    }
    void changeSystemPlayer(int pLayer) { // меняет номер игрока, которому принадлежит система
        player = pLayer;
    }
    void changeSystemWar(bool War) { // меняет информациюо том, что находится ли система в состоянии войны
        war = War;
    }

    bool getSystemGold() { // показывает добывается ли в системе золото
        return gold;
    }
    bool getSystemCobalt() { // показывает добывается ли в системе кобальт
        return cobalt;
    }
    bool getSystemDestroyed() { // показывает уничтожена ли система
        return destroyed;
    }
    bool getSystemDoubleRing() { // показывает является ли система Двойным Кольцом
        return doubleRing;
    }
    bool getSystemWar() { // показывает находится ли система в состоянии войны
        return war;
    }
    int getSystemPlayer() { // показывает какой игрок является владельцем системы
        return player;
    }
    std::string getSystemName() { // показывает название системы
        return name;
    }

    void destroy() { // уничтожение системы

    }
};
class Ship { // абстрактный класс корабль
    int NameOfPlayer; // имя игрока, которому принадлежит
    int ID; // ID корабля
    bool movement; // может ли двигаться
    bool shoot; // может ли стрелять
public:
    virtual bool attack() = 0;
};
class monitor: public Ship { // монитор
public:
    const int power = 2; // сила атаки
};
class reider: public Ship { // рейдер
public:
    const int power = 4;  // сила атаки
};
class transport: public Ship { // транспорт
    int desant = 0; // количество десантников на корабле
    int ID_Des[2]; // ID десантников, находящихся на корабле
public:
    const int power = 1;  // сила атаки
    void add (int ID_Desant){ // садит/высаживает десантников из транспортника

    }
};
class corvet: public Ship { // корвет
public:
    const int power = 2;  // сила атаки
};

class station { // абстрактный класс станция
public:
    virtual bool attack() = 0;
};
class mirror: public station { // станция "Зеркало"

};
class rocket: public station { // ракетная станция

};





void IdAndName(int numberOfPlayers, Player player[]) { // выводит ID и имя игроков
    int i;
    for (i = 1; i <= numberOfPlayers; i++) {
        std::cout << player[i-1].getID() << " ";
        std::cout << player[i-1].getName() << "\n";
    }
}
void showSystemOfPlayers(int numberOfPlayers, Player players[], System systemcards[48]) {
    int i, j;
    for (i = 1; i <= 48; i++) {
        std::cout << i << ". " << systemcards[i-1].getSystemName() << ", ID of player: " << systemcards[i-1].getSystemPlayer() << "\n";
    }
    for (i = 0; i < numberOfPlayers; i++) {
        std::cout << "Player:\nID: " << players[i].getID() << ", Name: " << players[i].getName();
        printf(", Собственность:\n");
        for (j = 1; j <= players[i].getNumberOfOwn(); j++) {
            std::cout << j << ". " << players[i].getOwn()[j-1] << "\n";
        }
    }
}
void Own(int numberOfPlayers, Player players[], System systemcards[48]) {
    int i, j, k;
    bool find[numberOfPlayers];
    for (i = 0; i < 48; i++) {
        for (j = 0; j < numberOfPlayers; j++) {
            find[j] = false;
        }
        std::cout << "\n\n" << i << ". номер игрока: " << (systemcards[i].getSystemPlayer() - 1) << "";
        for (j = 0; j < numberOfPlayers; j++) {
            std::cout << "\n игрок:" << j;
            for (k = 0; k < players[j].getNumberOfOwn(); k++) {
                if (players[j].getOwn()[k] == i) {
                    find[j] = true;
                    std::cout << ", номер в массиве игрока: " << k;
                }
            }

        }
        std::cout << "\n" << find[0];
        for (k = 1; k < numberOfPlayers; k++) {
            std::cout << " " << find[k];
        }
    }
}







System* addSystemsCards(int numberOfPlayers, Player players[]) { // создаёт системы и присваивает им владельцев
    System* systemCards = new System[48];
    int number, i, player[numberOfPlayers];
    bool k;
    for (i = 0; i < numberOfPlayers; i++) {
        player[i] = 0;
    }

    systemCards[0].changeSystemDoubleRing(true);
    systemCards[0].changeSystemCobalt(false);
    systemCards[0].changeSystemGold(false);
    systemCards[0].changeSystemName("Двойное кольцо");

    systemCards[1].changeSystemDoubleRing(false);
    systemCards[1].changeSystemCobalt(true);
    systemCards[1].changeSystemGold(false);
    systemCards[1].changeSystemName("Система Бовиса");


    systemCards[2].changeSystemDoubleRing(false);
    systemCards[2].changeSystemCobalt(true);
    systemCards[2].changeSystemGold(false);
    systemCards[2].changeSystemName("Борзая");

    systemCards[3].changeSystemDoubleRing(false);
    systemCards[3].changeSystemCobalt(true);
    systemCards[3].changeSystemGold(true);
    systemCards[3].changeSystemName("Жёлтая Сыпь");

    systemCards[4].changeSystemDoubleRing(false);
    systemCards[4].changeSystemCobalt(false);
    systemCards[4].changeSystemGold(true);
    systemCards[4].changeSystemName("Клешня");

    systemCards[5].changeSystemDoubleRing(false);
    systemCards[5].changeSystemCobalt(true);
    systemCards[5].changeSystemGold(false);
    systemCards[5].changeSystemName("Двойняшки");

    systemCards[6].changeSystemDoubleRing(false);
    systemCards[6].changeSystemCobalt(false);
    systemCards[6].changeSystemGold(true);
    systemCards[6].changeSystemName("Бродяга");

    systemCards[7].changeSystemDoubleRing(false);
    systemCards[7].changeSystemCobalt(true);
    systemCards[7].changeSystemGold(false);
    systemCards[7].changeSystemName("Система профессора Караулкина");

    systemCards[8].changeSystemDoubleRing(false);
    systemCards[8].changeSystemCobalt(true);
    systemCards[8].changeSystemGold(false);
    systemCards[8].changeSystemName("Эльфийские Крылья");

    systemCards[9].changeSystemDoubleRing(false);
    systemCards[9].changeSystemCobalt(false);
    systemCards[9].changeSystemGold(true);
    systemCards[9].changeSystemName("Рыба-Молот");

    systemCards[10].changeSystemDoubleRing(false);
    systemCards[10].changeSystemCobalt(true);
    systemCards[10].changeSystemGold(true);
    systemCards[10].changeSystemName("Синяя Туманность");

    systemCards[11].changeSystemDoubleRing(false);
    systemCards[11].changeSystemCobalt(false);
    systemCards[11].changeSystemGold(true);
    systemCards[11].changeSystemName("Звёздные Перекаты");

    systemCards[12].changeSystemDoubleRing(false);
    systemCards[12].changeSystemCobalt(true);
    systemCards[12].changeSystemGold(true);
    systemCards[12].changeSystemName("Одинокая");

    systemCards[13].changeSystemDoubleRing(false);
    systemCards[13].changeSystemCobalt(true);
    systemCards[13].changeSystemGold(false);
    systemCards[13].changeSystemName("Мотыльки");

    systemCards[14].changeSystemDoubleRing(false);
    systemCards[14].changeSystemCobalt(false);
    systemCards[14].changeSystemGold(true);
    systemCards[14].changeSystemName("Система Сомигнаса");

    systemCards[15].changeSystemDoubleRing(false);
    systemCards[15].changeSystemCobalt(false);
    systemCards[15].changeSystemGold(true);
    systemCards[15].changeSystemName("Система Кевиса");

    systemCards[16].changeSystemDoubleRing(false);
    systemCards[16].changeSystemCobalt(false);
    systemCards[16].changeSystemGold(true);
    systemCards[16].changeSystemName("Биг Мак");

    systemCards[17].changeSystemDoubleRing(false);
    systemCards[17].changeSystemCobalt(true);
    systemCards[17].changeSystemGold(false);
    systemCards[17].changeSystemName("Шпага");

    systemCards[18].changeSystemDoubleRing(false);
    systemCards[18].changeSystemCobalt(true);
    systemCards[18].changeSystemGold(true);
    systemCards[18].changeSystemName("Панцирь");

    systemCards[19].changeSystemDoubleRing(false);
    systemCards[19].changeSystemCobalt(false);
    systemCards[19].changeSystemGold(true);
    systemCards[19].changeSystemName("Паладин");

    systemCards[20].changeSystemDoubleRing(false);
    systemCards[20].changeSystemCobalt(true);
    systemCards[20].changeSystemGold(false);
    systemCards[20].changeSystemName("Красная Борода");

    systemCards[21].changeSystemDoubleRing(false);
    systemCards[21].changeSystemCobalt(false);
    systemCards[21].changeSystemGold(true);
    systemCards[21].changeSystemName("Фиолетовые Поля");

    systemCards[22].changeSystemDoubleRing(false);
    systemCards[22].changeSystemCobalt(true);
    systemCards[22].changeSystemGold(false);
    systemCards[22].changeSystemName("Подушка");

    systemCards[23].changeSystemDoubleRing(false);
    systemCards[23].changeSystemCobalt(true);
    systemCards[23].changeSystemGold(false);
    systemCards[23].changeSystemName("Яичница");

    systemCards[24].changeSystemDoubleRing(false);
    systemCards[24].changeSystemCobalt(true);
    systemCards[24].changeSystemGold(false);
    systemCards[24].changeSystemName("Кролик");

    systemCards[25].changeSystemDoubleRing(false);
    systemCards[25].changeSystemCobalt(false);
    systemCards[25].changeSystemGold(true);
    systemCards[25].changeSystemName("Песочные Часы");

    systemCards[26].changeSystemDoubleRing(false);
    systemCards[26].changeSystemCobalt(false);
    systemCards[26].changeSystemGold(true);
    systemCards[26].changeSystemName("Лобстер");

    systemCards[27].changeSystemDoubleRing(false);
    systemCards[27].changeSystemCobalt(true);
    systemCards[27].changeSystemGold(false);
    systemCards[27].changeSystemName("Система Кадашникова");

    systemCards[28].changeSystemDoubleRing(false);
    systemCards[28].changeSystemCobalt(false);
    systemCards[28].changeSystemGold(true);
    systemCards[28].changeSystemName("Геркулес");

    systemCards[29].changeSystemDoubleRing(false);
    systemCards[29].changeSystemCobalt(true);
    systemCards[29].changeSystemGold(false);
    systemCards[29].changeSystemName("Ожерелье");

    systemCards[30].changeSystemDoubleRing(false);
    systemCards[30].changeSystemCobalt(false);
    systemCards[30].changeSystemGold(true);
    systemCards[30].changeSystemName("Акула");

    systemCards[31].changeSystemDoubleRing(false);
    systemCards[31].changeSystemCobalt(false);
    systemCards[31].changeSystemGold(true);
    systemCards[31].changeSystemName("Бункер");

    systemCards[32].changeSystemDoubleRing(false);
    systemCards[32].changeSystemCobalt(true);
    systemCards[32].changeSystemGold(false);
    systemCards[32].changeSystemName("Тенисная Ракетка");

    systemCards[33].changeSystemDoubleRing(false);
    systemCards[33].changeSystemCobalt(true);
    systemCards[33].changeSystemGold(false);
    systemCards[33].changeSystemName("Красный Кисель");

    systemCards[34].changeSystemDoubleRing(false);
    systemCards[34].changeSystemCobalt(true);
    systemCards[34].changeSystemGold(false);
    systemCards[34].changeSystemName("Система Пика");

    systemCards[35].changeSystemDoubleRing(false);
    systemCards[35].changeSystemCobalt(true);
    systemCards[35].changeSystemGold(false);
    systemCards[35].changeSystemName("Доктор Нильс");

    systemCards[36].changeSystemDoubleRing(false);
    systemCards[36].changeSystemCobalt(false);
    systemCards[36].changeSystemGold(true);
    systemCards[36].changeSystemName("Кербер");

    systemCards[37].changeSystemDoubleRing(false);
    systemCards[37].changeSystemCobalt(true);
    systemCards[37].changeSystemGold(false);
    systemCards[37].changeSystemName("Глаз Владыки");

    systemCards[38].changeSystemDoubleRing(false);
    systemCards[38].changeSystemCobalt(true);
    systemCards[38].changeSystemGold(false);
    systemCards[38].changeSystemName("Плетта");

    systemCards[39].changeSystemDoubleRing(false);
    systemCards[39].changeSystemCobalt(false);
    systemCards[39].changeSystemGold(true);
    systemCards[39].changeSystemName("Каракатица");

    systemCards[40].changeSystemDoubleRing(false);
    systemCards[40].changeSystemCobalt(true);
    systemCards[40].changeSystemGold(true);
    systemCards[40].changeSystemName("Синий Крест");

    systemCards[41].changeSystemDoubleRing(false);
    systemCards[41].changeSystemCobalt(true);
    systemCards[41].changeSystemGold(true);
    systemCards[41].changeSystemName("Рифы");

    systemCards[42].changeSystemDoubleRing(false);
    systemCards[42].changeSystemCobalt(true);
    systemCards[42].changeSystemGold(false);
    systemCards[42].changeSystemName("Южные Врата");

    systemCards[43].changeSystemDoubleRing(false);
    systemCards[43].changeSystemCobalt(false);
    systemCards[43].changeSystemGold(true);
    systemCards[43].changeSystemName("Водоворот");

    systemCards[44].changeSystemDoubleRing(false);
    systemCards[44].changeSystemCobalt(false);
    systemCards[44].changeSystemGold(true);
    systemCards[44].changeSystemName("Закат");

    systemCards[45].changeSystemDoubleRing(false);
    systemCards[45].changeSystemCobalt(true);
    systemCards[45].changeSystemGold(false);
    systemCards[45].changeSystemName("Рой");

    systemCards[46].changeSystemDoubleRing(false);
    systemCards[46].changeSystemCobalt(false);
    systemCards[46].changeSystemGold(true);
    systemCards[46].changeSystemName("Паутина");

    systemCards[47].changeSystemDoubleRing(false);
    systemCards[47].changeSystemCobalt(true);
    systemCards[47].changeSystemGold(true);
    systemCards[47].changeSystemName("Капюшон");

    for (i = 1; i <= 48; i++) { // распределяет системы игрокам
        k = true; // показывает нужно ли отдавать какому-либо игроку систему
        while (k){
            number = rand() % numberOfPlayers + 1;
            if (player[number - 1] < (48 / numberOfPlayers)) { // количество систем у игрока должно быть < (количество систем)/(количество игроков)
                player[number - 1]++;
                systemCards[i-1].changeSystemPlayer(number);
                players[number - 1].addSystemToPlayerPlayer(i - 1);
                k = false;
            }
        }
    }
    return systemCards;
}
void begin(int numberOfPlayers, Player player[]) {

}
int main() {
    System* systemCards;
    int numberOfPlayers = 0, i, j, research = 0; // количество игроков, счётчик, счётчик, ход исследования Двойного Кольца
    printf("Введите количество игроков (от 2 до 4)\n");
    scanf("%i", &numberOfPlayers); // считывает количество игроков
    while ((numberOfPlayers < 2) || (numberOfPlayers > 4)) { // если введено неправильное количество игроков
        printf("Вы ввели неправильное количество игроков. Введите правильное количество игроков (от 2 до 4)\n");
        scanf("%i", &numberOfPlayers);
    }
    //Player* player = new Player[numberOfPlayers];
    Player player[numberOfPlayers];
    std::string name;
    srand(time(NULL));
    for (i = 1; i <= numberOfPlayers; i++) { // считывает и присваивает имена игроков, создаёт очерёдность хода
        printf("Введите имя %i-го игрока\n", i);
        std::cin >> name; // считывает имя
        if (i == 1) {
            player[0].changeName(name); // присваивает имя
            player[0].changeID(rand() % numberOfPlayers + 1); // считает каким, по номеру(ID), будет ходить 1-ый игрок
        }
        else {
            player[i-1].changeName(name); // присваивает имя
            while (player[i-1].getID() == 0) {
                player[i-1].changeID(rand() % numberOfPlayers + 1); // считает каким, по номеру(ID), будет ходить i-ый игрок
                for (j = i - 1; j >= 1; j--) { // проверяет не совпали ли номера(ID)
                    if (player[i-1].getID() == player[j-1].getID()) { // номера(ID) совпали => меняем ID(номера) на 0, чтобы повторить цикл
                        player[i-1].changeID(0);
                    }
                }
            }
        }
    }

    systemCards = addSystemsCards(numberOfPlayers, player);

    IdAndName(numberOfPlayers, player);
    showSystemOfPlayers(numberOfPlayers, player, systemCards);
    Own(numberOfPlayers, player, systemCards);
  /*  while (research < 10) {

    } */


    return 0;
}