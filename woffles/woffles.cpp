// woffles.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "woffles.h"


#define MAX_LOADSTRING 100

// Global Variables:
HANDLE hWaitHandle;

HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

BOOL CALLBACK EnumWindowsProc(
    _In_ HWND hwnd,
    _In_ LPARAM lParam)
{
    auto foundItYet = false;
    LPWSTR lpClassName = (LPWSTR)GlobalAlloc(GMEM_FIXED | GMEM_ZEROINIT, 8192);

    if (RealGetWindowClass(hwnd, lpClassName, 1024) > 0)
    {
        if (0 == lstrcmpi(TEXT("SiliconStudio Inc."), lpClassName))
        {
            // remove border, caption, etc
            LONG lWindowStyle = GetWindowLong(hwnd, GWL_STYLE);
            lWindowStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU);
            SetWindowLong(hwnd, GWL_STYLE, lWindowStyle);

            // force window to "fullscreen windowed"
            HMONITOR hmon = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);
            MONITORINFO monitorInfo = { sizeof(monitorInfo) };
            if (!GetMonitorInfo(hmon, &monitorInfo))
            {
                OutputDebugString(TEXT("GetMonitorInfo Failed, could not set full-screen."));
            }
            else
            {
                SetWindowPos(
                    hwnd,
                    (HWND)0,
                    monitorInfo.rcMonitor.left,
                    monitorInfo.rcMonitor.top,
                    monitorInfo.rcMonitor.right - monitorInfo.rcMonitor.left,
                    monitorInfo.rcMonitor.bottom - monitorInfo.rcMonitor.top,
                    SWP_FRAMECHANGED | SWP_SHOWWINDOW);
            }
            foundItYet = true;
            MessageBox(hwnd, TEXT("FIND THIS USEFUL? BITCOIN DONATE!\r\n\r\n15YCvZ8idVcTkfGdb5CyQMdRgREx5mgMSQ\r\n\r\nPROBLEMS? mailto:woffles@mrshaunwilson.com\r\n\r\nSOURCE CODE? www.github.com/wilson0x4d/woffles"), TEXT("woffles@mrshaunwilson.com"), MB_OK);
        }
    }

    GlobalFree((HGLOBAL)lpClassName);

    if (foundItYet)
    {
        if (hWaitHandle != (HANDLE)0)
        {
            // TODO: threadproc SetEvent(hWaitHandle);
        }
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
   
    hWaitHandle = CreateMutex(NULL, TRUE, TEXT("derpwoffles0x4d"));
    try
    {
        if (hWaitHandle == (HANDLE)0)
        {
            return FALSE;
        }

        OutputDebugString(TEXT(">> WAITING"));
        OutputDebugString(TEXT("\r\n"));
        Sleep(3000);
        OutputDebugString(TEXT(">> SCANNING"));
        OutputDebugString(TEXT("\r\n"));

        EnumWindows(EnumWindowsProc, (LPARAM)0);

        // TODO: threadproc WaitForSingleObject(hWaitHandle, INFINITE);
    }
    catch (...)
    {
        // NOP
    }
    OutputDebugString(TEXT(">> DONE"));
    ReleaseMutex(hWaitHandle);
    return TRUE;
}
