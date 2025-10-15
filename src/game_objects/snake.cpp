#include "snake.h"

int Snake::head() const
{
    return 0;
}

int Snake::tail() const
{
    return body.size() - 1;
}

void Snake::moveNoHead()
{
    for (int i = body.size() - 1 ; i > 0; i--)
    {
        body[i] = body[i - 1];
    }
}

Snake::Snake(Direction startDireciton, int length, ...)
{
    va_list args;

    direction = startDireciton;
    this->length = length;

    va_start(args, length);

    for (int i = 0; i < length; i++)
    {
        Point<int> temp = va_arg(args, Point<int>);

        body.push_back(temp);
    }

    addedLength = 0;

    va_end(args);

}

Snake::Snake(Direction startDirection, std::vector<Point<int>> body)
{
    direction = startDirection;
    this->body = body;
    this->length = body.size();
    addedLength = 0;

}

size_t Snake::getLength() const
{
    return length;
}

Direction Snake::getDirection() const
{
    return direction;
}

std::vector<Point<int>> Snake::getBody() const
{
    return body;
}

Direction Snake::getProhibitedDirection()
{
    if (body[head()].X - 1 == body[1].X)
        return Direction::LEFT;

    if (body[head()].X + 1 == body[1].X)
        return Direction::RIGHT;

    if (body[head()].Y - 1 == body[1].Y)
        return Direction::UP;

    if (body[head()].Y + 1 == body[1].Y)
        return Direction::DOWN;

}

void Snake::setDirection(Direction direction)
{
    this->direction = direction;
}

void Snake::move()
{

    Point<int> headSnake = body[head()];

    switch (direction)
    {
    case UP:
    {
        if (addedLength > 0)
        {
            addedLength--;
            body.insert(body.begin(),Point<int>(body[head()].X, body[head()].Y - 1));
        }
        else
        {
            moveNoHead();
            body[head()] = Point<int>(headSnake.X, headSnake.Y - 1);
        }
        break;
    }
    case LEFT:
    {
        if (addedLength > 0)
        {
            body.insert(body.begin(), Point<int>(body[head()].X - 1, body[head()].Y));
            addedLength--;
        }
        else
        {
            moveNoHead();
            body[head()] = Point<int>(headSnake.X - 1, headSnake.Y);
        }
        break;
    }
    case DOWN:
    {
        if (addedLength > 0)
        {
            body.insert(body.begin(), Point<int>(body[head()].X, body[head()].Y + 1));
            addedLength--;
        }
        else
        {
            moveNoHead();
            body[head()] = Point<int>(headSnake.X, headSnake.Y + 1);
        }
        break;
    }
    case RIGHT:
    {
        if (addedLength > 0)
        {
            body.insert(body.begin(), Point<int>(body[head()].X + 1, body[head()].Y));
            addedLength--;
        }
        else
        {
            moveNoHead();
            body[head()] = Point<int>(headSnake.X + 1, headSnake.Y);
        }
        break;
    }
    default:
        break;
    }
}

void Snake::addLength(int addSize)
{
    addedLength = addSize;
    length += addSize;
}

void Snake::RemoveLength(int removeSize)
{
    for (int i = 0; i < removeSize; i++)
        body.erase(body.begin() + tail() - i);

    length -= removeSize;
}

Point<int> Snake::getHead()
{
    return body[0];
}
