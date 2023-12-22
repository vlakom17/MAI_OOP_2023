#include "npc.h"
#include "dragon.h"
#include "knight.h"
#include "frog.h"

#include <sstream>
#include <thread>
#include <mutex>
#include <chrono>
#include <queue>
#include <optional>
#include <array>

using namespace std::chrono_literals;
std::mutex print_mutex;


class TextObserver : public IFightObserver
{
private:
    TextObserver(){};

public:
    static std::shared_ptr<IFightObserver> get()
    {
        static TextObserver instance;
        return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver *) {});
    }

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override
    {
        if (win)
        {
            std::lock_guard<std::mutex> lck(print_mutex);
            std::cout << std::endl << "--------Murder --------" << std::endl;
            std::cout << "Killed" << std::endl;
            defender->print(); 
            std::cout << "by" << std::endl;
            attacker->print();
            defender->alive = false;
            
        }
    }
};


std::shared_ptr<NPC> factory(std::istream &is)
{
    std::shared_ptr<NPC> result;
    int type{0};
    if (is >> type)
    {
        switch (type)
        {
        case DragonType:
            result = std::make_shared<Dragon>(is);
            break;
        case KnightType:
            result = std::make_shared<Knight>(is);
            break;
        case FrogType:
            result = std::make_shared<Frog>(is);
            break;
        }
    }
    else
        std::cerr << "unexpected NPC type:" << type << std::endl;

    if (result)
        result->subscribe(TextObserver::get());

    return result;
}

std::shared_ptr<NPC> factory(NpcType type, int x, int y)
{
    std::shared_ptr<NPC> result;
    switch (type)
    {
    case DragonType:
        result = std::make_shared<Dragon>(x, y);
        break;
    case KnightType:
        result = std::make_shared<Knight>(x, y);
        break;
    case FrogType:
        result = std::make_shared<Frog>(x, y);
        break;
    default:
        break;
    }
    if (result)
        result->subscribe(TextObserver::get());

    return result;
}

// save array to file
void save(const set_t &array, const std::string &filename)
{
    std::ofstream fs(filename);
    fs << array.size() << std::endl;
    for (auto &n : array)
        n->save(fs);
    fs.flush();
    fs.close();
}

set_t load(const std::string &filename)
{
    set_t result;
    std::ifstream is(filename);
    if (is.good() && is.is_open())
    {
        int count;
        is >> count;
        for (int i = 0; i < count; ++i)
            result.insert(factory(is));
        is.close();
    }
    else
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
    return result;
}


std::ostream &operator<<(std::ostream &os, const set_t &array)
{
    for (auto &n : array)
        n->print();
    return os;
}

set_t fight(const set_t &array, size_t distance)
{
    set_t dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) && attacker->is_close(defender, distance) && defender->accept(attacker))
                dead_list.insert(defender);

    return dead_list;
}

struct print : std::stringstream
{
    ~print()
    {
        static std::mutex mtx;
        std::lock_guard<std::mutex> lck(print_mutex);
        std::cout << this->str();
        std::cout.flush();
    }
};

struct FightEvent
{
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

class FightManager
{
private:
    std::queue<FightEvent> events;
    std::shared_mutex mtx;

    FightManager() {}

public:
    static FightManager &get()
    {
        static FightManager instance;
        return instance;
    }

    void add_event(FightEvent &&event)
    {
        std::lock_guard<std::shared_mutex> lock(mtx);
        events.push(event);
    }

    void operator()()
    {
        while (true)
        {
            {
                std::optional <FightEvent> event;

                {
                    std::lock_guard<std::shared_mutex> lock(mtx);
                    if (!events.empty())
                    {
                        event = events.back();
                        events.pop();
                    }
                }

                if (event)
                {
                    try
                    {
                        if (event->attacker->is_alive())    
                            if (event->defender->is_alive()) 
                                if (event->defender->accept(event->attacker))
                                    event->defender->must_die();
                    }
                    catch (...)
                    {
                        std::lock_guard<std::shared_mutex> lock(mtx);
                        events.push(*event);
                    }
                }
                else
                    std::this_thread::sleep_for(500ms);
            }
        }
    }
};

int main()
{
    auto startTime = std::chrono::steady_clock::now(); // Запоминаем время начала выполнения программы
    srand(time(NULL));
    set_t array; 

    const int MAX_X{100};
    const int MAX_Y{100};
    const int DISTANCE{5};

    std::cout << "Generating ..." << std::endl;
    for (size_t i = 0; i < 50; ++i)
        array.insert(factory(NpcType(std::rand() % 3 + 1), std::rand() % MAX_X, std::rand() % MAX_Y));

    std::cout << "Starting list:" << std::endl << array;

    std::thread fight_thread(std::ref(FightManager::get()));

    std::thread move_thread([&array, MAX_X, MAX_Y, DISTANCE](){
        while (true){
            for (std::shared_ptr<NPC> npc : array){
                if (npc->is_alive()){
                    int step_x = 0;
                    int step_y = 0;

                // Узнаем тип существа и устанавливаем соответствующее расстояние передвижения
            switch (npc->get_type()){
                // Перемещение для Dragon
                case DragonType:
                    while(step_x + step_y != 5){
                        step_x = std::rand() % 6; 
                        step_y = std::rand() % 6;
                        int DAttack = std::rand() % 6 + 1;
                    }
                    break;
                case KnightType:
                // Перемещение для Knight
                    while(step_x + step_y != 3){
                        step_x = std::rand() % 4; 
                        step_y = std::rand() % 4;
                        int KAttack = std::rand() % 6 + 1;
                    }
                    break;
                case FrogType:
                // Перемещение для Frog
                    while(step_x + step_y != 1){
                        step_x = std::rand() % 2; 
                        step_y = std::rand() % 2;
                        int FAttack = std::rand() % 6 + 1;
                    }
                    break;
                default:
                    break;
            }
            // Фактическое перемещение NPC на заданный шаг
            npc->move(step_x, step_y, MAX_X, MAX_Y);
                }
            }
        for (std::shared_ptr<NPC> npc : array)
            for (std::shared_ptr<NPC> other : array){
                if ((other != npc) && (npc->get_type() != DragonType) && (npc->is_alive()) && (other->is_alive()) && (npc->is_close(other, DISTANCE))){
                    if (npc->x > other->y){
                    FightManager::get().add_event({npc, other});
                    std::this_thread::sleep_for(1s);
                    }
                }
                if ((other != npc) && (npc->get_type() == DragonType) && (npc->is_alive()) && (other->is_alive()) && (npc->is_close(other, 15))){
                    if(npc->x > other->y){
                    FightManager::get().add_event({npc, other});
                    std::this_thread::sleep_for(1s);
                    }
                }
            }
        }
    });

    while (true){
        const int grid{25}, step_x{MAX_X / grid}, step_y{MAX_Y / grid};{
            std::array<char, grid * grid> fields{0};
            for (std::shared_ptr<NPC> npc : array){
                auto [x, y] = npc->position();
                int i = x / step_x;
                int j = y / step_y;
                if (npc->is_alive()){
                    switch (npc->get_type()){
                        case DragonType:
                            fields[i + grid * j] = 'D';
                            break;
                        case KnightType:
                            fields[i + grid * j] = 'K';
                            break;
                        case FrogType:
                            fields[i + grid * j] = 'F';
                            break;
                        default:
                        break;
                    }
                }
                else
                fields[i + grid * j] = '.';
            }
            std::lock_guard<std::mutex> lck(print_mutex);
            for (int j = 0; j < grid; ++j){
                for (int i = 0; i < grid; ++i)
                {
                    char c = fields[i + j * grid];
                    if (c != 0)
                        std::cout << "[" << c << "]";
                    else
                        std::cout << "[ ]";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
          // Увеличиваем счетчик времени
        auto endTime = std::chrono::steady_clock::now(); // Запоминаем время завершения работы программы
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime); // Вычисляем прошедшее время
        if (duration.count() >= 30) {
            std::cout << "Программа отработала 30 секунд. Завершение программы:" << std::endl;
            std::this_thread::sleep_for(1s);
            std::cout << "Survivors" << std::endl;
           for (const auto& npc : array) {
            if (npc->is_alive()) {
                auto [x, y] = npc->position();
                if (npc->get_type() == 1) std::cout << "Dragon: {x:"<< x << ", y:" << y << "}" << std::endl;
                else if (npc->get_type() == 2) std::cout << "Knight: {x:"<< x << ", y:" << y << "}" << std::endl;
                else if (npc->get_type() == 3) std::cout << "Frog: {x:"<< x << ", y:" << y << "}" << std::endl;
            }
           }
    
            //move_thread.join();
            //fight_thread.join();
            return 0; // Прерываем выполнение после 30 секунд
        }
        std::this_thread::sleep_for(1s);
    };
    
}