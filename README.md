# game

## Style

Order of `#include` directives in header and source files:

`file.hpp`
```C++
#include "other_file.hpp"
#include "another_file.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>
#include <iostream>
#include <string>
```

`file.cpp`
```C++
#include "file.hpp"

#include "other_file.hpp"
#include "another_file.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>
#include <iostream>
#include <string>
```
