// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A1200
// Canonical corpus name: sub_4A1200
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A1200_004a1200.c

void UnknownObject::CreateGameWindow()
{
    // Creates the main game window via Win32: formats a title from the game name and version, fills two WNDCLASSEX structs (primary cube-realtime class and an optional message-window class), registers them, and creates the window(s) through CreateWindowExA. When the message-window mode flag is set it also creates a child message window; otherwise it creates a single simple window. Clips the cursor to the window and shows it. Returns 0 on success, 1 if a class registration fails.
    // CALL: Obtain the desktop window handle used as the reference for window centering and client rect math. [global:0x0059E2A0]
    // ASSIGNMENT: Fill the primary WNDCLASSEX struct: cbSize 48, style 64, instance from hinst, class name aCuberealtime, WndProc at the byte following loc_4A155F, icon from LoadIconA, background brush from GetStockObject, all other members zero. [global:0x007CE270, global:0x007CE274, global:0x007CE278, global:0x007CE27C, global:0x007CE280, global:0x007CE284, global:0x007CE288, global:0x007CE28C, global:0x007CE290, global:0x007CE294, global:0x007CE298, global:0x007CE29C, global:0x007CE2A0, global:0x005CD0A4, global:0x004A1560, global:0x0059E280, global:0x0059E064]
    // CALL: Format the window title into a local buffer using the "%s v%0.3f" format with the game title string and the version float read from dword_7C56B0. [callee:0x0058815F, global:0x005C6620, global:0x005CD098, global:0x007C56B0]
    // GUARD: Branch on the message-window mode flag byte: non-zero enters the message-window path, zero uses the simple single-window path. [global:0x005EC4A4]
    // ASSIGNMENT: Fill the secondary WNDCLASSEX struct for the message window: cbSize 48, zero style, instance from hinst, class name ClassName, same WndProc, icon from LoadIconA, background brush from GetStockObject. [global:0x007CE2A8, global:0x007CE2AC, global:0x007CE2B0, global:0x007CE2B4, global:0x007CE2B8, global:0x007CE2BC, global:0x007CE2C0, global:0x007CE2C4, global:0x007CE2C8, global:0x007CE2CC, global:0x007CE2D0, global:0x007CE2D4, global:0x005CD090, global:0x004A1560, global:0x0059E280, global:0x0059E064]
    // CALL: Register the message-window class; return 1 immediately if registration fails. [global:0x0059E284]
    // CALL: Read the desktop client rect, then compute a centered window origin from the requested width/height. [global:0x0059E288]
    // CALL: Adjust the window rectangle for the chosen style (fullscreen borderless style when message-window mode is at least 2, otherwise a windowed style). [global:0x0059E28C]
    // CALL: Create the main message window via CreateWindowExA with the ClassName and formatted title, storing the handle in the hWnd global. [global:0x0059E290, global:0x005CD090, global:0x007CE2DC]
    // CALL: Register the primary cube-realtime class; return 1 immediately if registration fails. [global:0x0059E284]
    // CALL: Create the child cube-realtime window under the main window and store its handle in dword_7CE2E0, then release the cursor clip. [global:0x0059E290, global:0x005CD0A4, global:0x007CE2E0, global:0x0059E294]
    // ASSIGNMENT: Simple path: set the icon from the default LoadIconA resource, register the primary class, create a single cube-realtime window, assign its handle to both hWnd and dword_7CE2E0, and clip the cursor to the full client rect. [global:0x0059E280, global:0x0059E284, global:0x0059E290, global:0x005CD0A4, global:0x007CE2E0, global:0x007CE2DC, global:0x0059E294]
    // CALL: Show the main window with the show command and set the window-created flag byte. [global:0x0059E298, global:0x007CE2E4]
    // RETURN: Return 0 on successful window creation. [source:raw]

    // Conservative worker pseudocode:
    //   // Create the game window; width/height supplied by the caller.
    //   DesktopWindow = GetDesktopWindow();
    //   fillPrimaryClass(stru_7CE270, aCuberealtime);   // cbSize 48, style 64, icon, bg brush
    //   format(WindowName, "%s v%0.3f", aF1Challenge990, *(float*)&dword_7C56B0);
    //   if (byte_5EC4A4) {
    //     fillSecondaryClass(stru_7CE2A8, ClassName);
    //     if (!RegisterClassExA(&stru_7CE2A8)) return 1;
    //     computeCenteredRect(GetClientRect(DesktopWindow));
    //     AdjustWindowRectEx(&rect, fullscreenOrWindowedStyle, 0, 1);
    //     hWnd = CreateWindowExA(1, ClassName, WindowName, style, x, y, w, h, 0, 0, hinst, 0);
    //     if (!RegisterClassExA(&stru_7CE270)) return 1;
    //     dword_7CE2E0 = CreateWindowExA(0, aCuberealtime, 0, 0x52000000, 0, 0, nWidth, nHeight, hWnd, 0, hinst, 0);
    //     ClipCursor(0);
    //   } else {
    //     stru_7CE270.hIcon = LoadIconA(0, 0x7F00);
    //     if (!RegisterClassExA(&stru_7CE270)) return 1;
    //     dword_7CE2E0 = CreateWindowExA(8, aCuberealtime, WindowName, 0x80000000, 0, 0, nWidth, nHeight, 0, 0, hinst, 0);
    //     hWnd = dword_7CE2E0;
    //     ClipCursor(&fullClientRect);
    //   }
    //   ShowWindow(hWnd, 1);
    //   byte_7CE2E4 = 1;
    //   return 0;
    // UNRESOLVED: The raw source references a block of write globals at far-addresses that do not appear anywhere in the function body; they are assumed to be disassembly artifacts and their provenance is unresolved.
    // UNRESOLVED: The window procedure code at loc_4A155F is outside this function; only its entry byte is referenced here.
    // UNRESOLVED: The exact visual/modal role of the secondary message window and its parent relationship is inferred, not confirmed.
}
