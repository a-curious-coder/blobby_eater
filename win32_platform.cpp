#include <windows.h>

bool running = true;

LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;
    switch(uMsg)
    {
        case WM_CLOSE:
        case WM_DESTROY:
        {
            running = false;
        } break;
        default:
        {
            result = DefWindowProc(hwnd, uMsg, wParam, lParam);
        } break;
    }
    return result;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    // Create Window
    WNDCLASS wc = {};
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpszClassName = "MyFirstGame";
    wc.lpfnWndProc = window_callback;

    // Register Window
    RegisterClass(&wc);

    // Create Window
    HWND window = CreateWindow(wc.lpszClassName, "My First Game", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, hInstance, 0);

    while(running)
    {
        // Input
        MSG message;
        while(PeekMessage(&message, window, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
        // Simulate

        // Render

    }
    return 0;
}