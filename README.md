# bfmalloc - brute force malloc implementation

This is a simple implementation of malloc and free. It is not intended to be used in production, but rather to demonstrate how malloc works.

I designed this for a friend who had issues with malloc. It's a fairly simple solution around NULL-returning malloc, and it's not very efficient. It's also not thread-safe.

## Usage

```c
#include "bfmalloc.h"

// bfmalloc does not return an error, it blocks the current thread until malloc stops returning NULL
int main() {
    void *ptr = bfmalloc(100);
    // do stuff with ptr
    free(ptr); // bfmalloc is just malloc itself, so you can use free
}
```

There is also an asynchronous implementation of `bfmalloc` called `bfmalloc_async`. This function was written by Copilot and I don't know how it works. Exact same API as `bfmalloc`.

```c
#include "bfmalloc.h"

// bfmalloc_async does not return an error either I assume, it doesn't block the current thread until malloc stops returning NULL
int main() {
    void *ptr = bfmalloc_async(100);
    // do stuff with ptr
    free(ptr); // bfmalloc is just malloc itself, so you can use free
}
```

## License
This project is licensed under WTFPL. See LICENSE for more information.