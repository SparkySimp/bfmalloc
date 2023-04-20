#include <stdlib.h>

void *bfmalloc(size_t size) {
    // while allocation returns NULL, try again
    void *ptr = NULL;
    while ((ptr = malloc(size)) == NULL) ;
    return ptr;
}

// if we're on linux or macOS, we can implement an asynchronous version ofc *bfmalloc
#if defined(__linux__) || defined(__APPLE__)
#include <pthread.h>

void *bfmalloc_async(size_t size) {
    // implement bfmalloc asynchronously
    void *ptr = NULL;
    pthread_t thread;
    pthread_create(&thread, NULL, bfmalloc, (void *)size);
    pthread_join(thread, &ptr);

    return ptr;
}

// implement async version of bfmalloc for windows
#elif defined(_WIN32) || defined(__CYGWIN__) || defined(_WIN64)
#include <windows.h>

void *bfmalloc_async(size_t size) {
    // implement bfmalloc asynchronously
    void *ptr = NULL;
    HANDLE thread = CreateThread(NULL, 0, bfmalloc, (void *)size, 0, NULL);
    WaitForSingleObject(thread, INFINITE);
    GetExitCodeThread(thread, (LPDWORD)&ptr);
    CloseHandle(thread);

    return ptr;
}
#endif
