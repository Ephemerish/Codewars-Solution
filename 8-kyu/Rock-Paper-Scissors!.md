## Description:
**Rock Paper Scissors**

Let's play! You have to return which player won! In case of a draw return `Draw!`.

### Examples(Input1, Input2-- > Output) :

    "scissors", "paper" --> "Player 1 won!"
    "scissors", "rock" --> "Player 2 won!"
    "paper", "paper" --> "Draw!"

**Kata's link:** [Rock Paper Scissors!](https://www.codewars.com/kata/5672a98bdbdd995fad00000f/cpp)

## Best Practices

**First:**
```cpp
#include <string>

std::string rps(const std::string& p1, const std::string& p2)
{
    if(p1 == p2)
      return "Draw!";
    if( ( p1[0] == 's' && p2[0] == 'p' )||
        ( p1[0] == 'p' && p2[0] == 'r' )||
        ( p1[0] == 'r' && p2[0] == 's' ) )
        return "Player 1 won!";
    return "Player 2 won!";
}
```

**Second:**
```cpp
#include <string>
#include <unordered_map>

namespace {
  std::unordered_map<std::string,std::string> win_map = {{"rock", "scissors"}, {"scissors", "paper"}, {"paper", "rock"}};
}

std::string rps(const std::string& p1, const std::string& p2)
{
  if (p1 == p2) {
    return "Draw!";
  }

  if (win_map[p1] == p2) {
    return "Player 1 won!";
  } else {
    return "Player 2 won!";
  }
}
```

## My Solutions
```cpp
#include <string>

std::string rps(const std::string& p1, const std::string& p2)
{
    if (p1 == "paper" && p2 == "rock")
        return "Player 1 won!";
    else if (p1 == "rock" && p2 == "paper")
        return "Player 2 won!";

    else if (p1 == "scissors" && p2 == "paper")
        return "Player 1 won!";
    else if (p1 == "paper" && p2 == "scissors")
        return "Player 2 won!";

    else if (p1 == "rock" && p2 == "scissors")
        return "Player 1 won!";
    else if (p1 == "scissors" && p2 == "rock")
        return "Player 2 won!";

    else if (p1 == p2)
        return "Draw!";
}
```