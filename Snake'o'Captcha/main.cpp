#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;


struct pos
{
    int x;
    int y;
};

class cFruit
{
    private:
        int x;
        int y;

    public:
        cFruit()
        {
            x = sf::Randomizer::Random(0,19);
            y = sf::Randomizer::Random(0,19);
        }

        int xVal()
        {
            return x;
        }

        int yVal()
        {
            return y;
        }

        void draw(sf::RenderWindow & App)
        {
            App.Draw(sf::Shape::Circle(x*10+5,y*10+5,5.0,sf::Color(255,0,0)));
        }

        void generate()
        {
                x = sf::Randomizer::Random(0,38);
                y = sf::Randomizer::Random(0,38);
        }

        ~cFruit() {}
};

class cFruit2
{
    private:
        int x;
        int y;

    public:
        cFruit2()
        {
            x = sf::Randomizer::Random(0,38);
            y = sf::Randomizer::Random(0,38);
        }

        int xVal()
        {
            return x;
        }

        int yVal()
        {
            return y;
        }

        void draw(sf::RenderWindow & App)
        {
            App.Draw(sf::Shape::Circle(x*10+5,y*10+5,5.0,sf::Color::White));
        }

        void generate()
        {
                x = sf::Randomizer::Random(0,38);
                y = sf::Randomizer::Random(0,38);
        }

        ~cFruit2() {}
};
class cFruit3
{
    private:
        int x;
        int y;

    public:
        cFruit3()
        {
            x = sf::Randomizer::Random(0,19);
            y = sf::Randomizer::Random(0,19);
        }

        int xVal()
        {
            return x;
        }

        int yVal()
        {
            return y;
        }

        void draw(sf::RenderWindow & App)
        {
            App.Draw(sf::Shape::Circle(x*10+5,y*10+5,5.0,sf::Color::Blue));
        }

        void generate()
        {
                x = sf::Randomizer::Random(0,38);
                y = sf::Randomizer::Random(0,38);
        }

        ~cFruit3() {}
};
class cFruit4
{
    private:
        int x;
        int y;

    public:
        cFruit4()
        {
            x = sf::Randomizer::Random(0,38);
            y = sf::Randomizer::Random(0,38);
        }

        int xVal()
        {
            return x;
        }

        int yVal()
        {
            return y;
        }

        void draw(sf::RenderWindow & App)
        {
            App.Draw(sf::Shape::Circle(x*10+5,y*10+5,5.0,sf::Color::Green));
        }

        void generate()
        {
                x = sf::Randomizer::Random(0,38);
                y = sf::Randomizer::Random(0,38);
        }

        ~cFruit4() {}
};
class cFruit5
{
    private:
        int x;
        int y;

    public:
        cFruit5()
        {
            x = sf::Randomizer::Random(0,38);
            y = sf::Randomizer::Random(0,38);
        }

        int xVal()
        {
            return x;
        }

        int yVal()
        {
            return y;
        }

        void draw(sf::RenderWindow & App)
        {
            App.Draw(sf::Shape::Circle(x*10+5,y*10+5,5.0,sf::Color::Magenta));
        }

        void generate()
        {
                x = sf::Randomizer::Random(0,38);
                y = sf::Randomizer::Random(0,38);
        }

        ~cFruit5() {}
};
class cFruit6
{
    private:
        int x;
        int y;

    public:
        cFruit6()
        {
            x = sf::Randomizer::Random(0,38);
            y = sf::Randomizer::Random(0,38);
        }

        int xVal()
        {
            return x;
        }

        int yVal()
        {
            return y;
        }

        void draw(sf::RenderWindow & App)
        {
            App.Draw(sf::Shape::Circle(x*10+5,y*10+5,5.0,sf::Color::Yellow));
        }

        void generate()
        {
                x = sf::Randomizer::Random(0,38);
                y = sf::Randomizer::Random(0,38);
        }

        ~cFruit6() {}
};
class cFruit7
{
    private:
        int x;
        int y;

    public:
        cFruit7()
        {
            x = sf::Randomizer::Random(0,38);
            y = sf::Randomizer::Random(0,38);
        }

        int xVal()
        {
            return x;
        }

        int yVal()
        {
            return y;
        }

        void draw(sf::RenderWindow & App)
        {
            App.Draw(sf::Shape::Circle(x*10+5,y*10+5,5.0,sf::Color::Cyan));
        }

        void generate()
        {
                x = sf::Randomizer::Random(0,38);
                y = sf::Randomizer::Random(0,38);
        }

        ~cFruit7() {}
};
class cSnake
{
    private:
        pos body[400];
        int x;
        int y;
        int direction;
        int length;

    public:
        cSnake()
        {
            x = 10;
            y = 10;
            body[0].x = x;
            body[0].y = y;
            direction = sf::Randomizer::Random(1,4);
            length = 1;
        }

        void move()
        {
             if(bodyHit())
                *this = cSnake();


            for(int i=length-1;i > 0;i--)
            {
                    body[i].x = body[i-1].x;
                    body[i].y = body[i-1].y;
            }

            body[0].x = x;
            body[0].y = y;

            switch(direction)
            {
                case 1:
                y--;
                break;

                case 2:
                y++;
                break;

                case 3:
                x++;
                break;

                case 4:
                x--;
                break;
            }

        }

        void setDirection(int dir)
        {
                direction = dir;
        }

        void draw(sf::RenderWindow & App)
        {
            for(int i=0;i<length;i++)
                App.Draw(sf::Shape::Rectangle(body[i].x*10+1,body[i].y*10+1,body[i].x*10+9,body[i].y*10+9,sf::Color(127,255,142,128)));
            App.Draw(sf::Shape::Rectangle(body[0].x*10+1,body[0].y*10+1,body[0].x*10+9,body[0].y*10+9,sf::Color(127,255,142)));
        }

        void addBodyPiece()
        {
            length++;
        }

        bool eatFruit(cFruit & fruit)
        {
            if(x == fruit.xVal() && y == fruit.yVal())
                return true;
            else
                return false;
        }

        bool wallHit()
        {
            if(y == -1 || y == 54 || x == -1 || x == 80)
                return true;
            else
                return false;
        }

        bool bodyHit()
        {
            for(int i=1;i<length;i++)
                if(body[i].x == x && body[i].y == y)
                    return true;

            return false;
        }

        bool fruitCollision(cFruit & fruit)
        {
            for(int i=0;i<length;i++)
                if(body[i].x == fruit.xVal() && body[i].y == fruit.yVal())
                    return true;

            return false;
        }

        ~cSnake() {}
};

int main()
{
    sf::RenderWindow App(sf::VideoMode(800,540),"Snake'o'Captcha");


    cSnake snake;
    cFruit fruit;
    cFruit2 fruit2;
    cFruit3 fruit3;
    cFruit4 fruit4;
    cFruit5 fruit5;
    cFruit6 fruit6;
    cFruit7 fruit7;

    while(App.IsOpened())
    {

        if(snake.eatFruit(fruit))
        {
            system ("START www.google.com");
            return 0;
        }

        sf::Event Event;
        while(App.GetEvent(Event))
        {
            if(Event.Type == sf::Event::Closed)
                App.Close();

            if((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
                App.Close();

            if(App.GetInput().IsKeyDown(sf::Key::Up))
                snake.setDirection(1);

            if(App.GetInput().IsKeyDown(sf::Key::Down))
                snake.setDirection(2);

            if(App.GetInput().IsKeyDown(sf::Key::Right))
                snake.setDirection(3);

            if(App.GetInput().IsKeyDown(sf::Key::Left))
                snake.setDirection(4);

            if(App.GetInput().IsKeyDown(sf::Key::P))
                while(App.GetInput().IsKeyDown(sf::Key::P))
                {
                     sf::Event Event;
                     App.GetEvent(Event);
                }
        }

        snake.move();

        if(snake.wallHit())
            snake = cSnake();


        App.Clear();
        snake.draw(App);
        fruit.draw(App);
        fruit3.draw(App);
        fruit4.draw(App);
        fruit5.draw(App);
        fruit6.draw(App);
        fruit7.draw(App);
        App.Display();

        sf::Sleep(0.1);
    }

    return 0;
}
