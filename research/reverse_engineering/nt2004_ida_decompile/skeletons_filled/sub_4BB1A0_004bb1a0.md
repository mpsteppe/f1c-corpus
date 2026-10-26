## sub_4BB1A0_004bb1a0 — Main Window Creation (WinMain / App Startup)

**Summary:** Creates the main game window and optional launcher/splash window. Registers two window classes ("CUBERealtime" for the render window, and optionally "CUBEApp" for a launcher window), creates windows with appropriate styles, clips cursor to window bounds, and shows the window.

**Called by:** sub_527B50 (00527b50)

**Struct fields accessed:** none (pure Windows API function)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004bb540 | sub_4BB540 | R | Window procedure for both window classes |
| 005d509c | GetStockObject | R | IAT: GetStockObject (background brush) |
| 005d52b4 | ClipCursor | R | IAT: ClipCursor (confine mouse) |
| 005d52b8 | CreateWindowExA | R | IAT: CreateWindowExA |
| 005d52bc | AdjustWindowRectEx | R | IAT: AdjustWindowRectEx |
| 005d52c0 | GetClientRect | R | IAT: GetClientRect |
| 005d52c4 | RegisterClassExA | R | IAT: RegisterClassExA |
| 005d52d8 | LoadIconA | R | IAT: LoadIconA |
| 005d52e0 | GetDesktopWindow | R | IAT: GetDesktopWindow |
| 005d52e4 | GetWindowRect | R | IAT: GetWindowRect |
| 005d52f4 | ShowWindow | R | IAT: ShowWindow |
| 005fcc0c | aS_0 | R | Format string: "%s" |
| 00600720 | aNascarThunderT | R | Window title: "NASCAR Thunder TM 2004" |
| 006098e8 | ClassName | R | Window class name for launcher window |
| 006098f0 | aCuberealtime | R | Window class name: "CUBERealtime" |
| 0062a154 | byte_62A154 | R | Flag: use launcher window (two-window mode) |
| 00764d70 | dword_764D70 | R | App instance / startup parameter |
| 00766198 | stru_766198 | RW | WNDCLASSEX for render window class |
| 0076619c | byte_76619C | W | WNDCLASSEX.cbSize (48) |
| 007661a0 | byte_7661A0 | W | WNDCLASSEX.style |
| 007661a4 | byte_7661A4 | W | WNDCLASSEX.lpfnWndProc |
| 007661a8 | byte_7661A8 | W | WNDCLASSEX.cbClsExtra (0) |
| 007661ac | byte_7661AC | W | WNDCLASSEX.cbWndExtra (0) |
| 007661b0 | byte_7661B0 | W | WNDCLASSEX.hInstance |
| 007661b4 | byte_7661B4 | W | WNDCLASSEX.hIcon |
| 007661b8 | byte_7661B8 | W | WNDCLASSEX.hIconSm (0) |
| 007661bc | byte_7661BC | W | WNDCLASSEX.hCursor (0) |
| 007661c0 | byte_7661C0 | W | WNDCLASSEX.hbrBackground |
| 007661c4 | byte_7661C4 | W | WNDCLASSEX.lpszMenuName (0) |
| 007661c8 | hinst | R | HINSTANCE of the application |
| 007661d0 | stru_7661D0 | RW | WNDCLASSEX for launcher window class |
| 007661d4 | byte_7661D4 | W | Launcher WNDCLASSEX.cbSize (48) |
| 007661d8 | byte_7661D8 | W | Launcher WNDCLASSEX.style |
| 007661dc | byte_7661DC | W | Launcher WNDCLASSEX.lpfnWndProc |
| 007661e0 | byte_7661E0 | W | Launcher WNDCLASSEX.cbClsExtra (0) |
| 007661e4 | byte_7661E4 | W | Launcher WNDCLASSEX.cbWndExtra (0) |
| 007661e8 | byte_7661E8 | W | Launcher WNDCLASSEX.hInstance |
| 007661ec | byte_7661EC | W | Launcher WNDCLASSEX.hIcon |
| 007661f0 | byte_7661F0 | W | Launcher WNDCLASSEX.hIconSm |
| 007661f4 | byte_7661F4 | W | Launcher WNDCLASSEX.hCursor (0) |
| 007661f8 | byte_7661F8 | W | Launcher WNDCLASSEX.lpszMenuName (0) |
| 007661fc | byte_7661FC | W | Launcher WNDCLASSEX.hbrBackground |
| 00766200 | Rect | R | Global RECT for storing window position |
| 00766214 | hWndParent | RW | Parent/launcher window handle |
| 00766218 | dword_766218 | RW | Main render window handle |
| 0076621c | byte_76621C | W | Window visible flag |
| ff00000000005e2b | byte_FF00000000005E2B | RW | WNDCLASSEX field (filler byte) |
| ff00000000005e2c | byte_FF00000000005E2C | RW | WNDCLASSEX field (filler byte) |
| ff00000000005e2d | byte_FF00000000005E2D | RW | WNDCLASSEX field (filler byte) |
| ff00000000005e2e | byte_FF00000000005E2E | RW | WNDCLASSEX field (filler byte) |
| ff00000000005e47 | byte_FF00000000005E47 | W | Launcher WNDCLASSEX field |
| ff00000000005e48 | byte_FF00000000005E48 | W | Launcher WNDCLASSEX field |
| ff00000000005e49 | byte_FF00000000005E49 | W | Launcher WNDCLASSEX field |
| ff00000000005e4a | byte_FF00000000005E4A | W | Launcher WNDCLASSEX field |
| ff00000000005e4b | byte_FF00000000005E4B | W | Launcher WNDCLASSEX field |
| ff00000000005e4c | byte_FF00000000005E4C | W | Launcher WNDCLASSEX field |
| ff00000000005e4d | byte_FF00000000005E4D | W | Launcher WNDCLASSEX field |
| ff00000000005e4e | byte_FF00000000005E4E | W | Launcher WNDCLASSEX field |
| ff00000000005e4f | byte_FF00000000005E4F | W | Launcher WNDCLASSEX field |
| ff00000000005e50 | byte_FF00000000005E50 | W | Launcher WNDCLASSEX field |
| ff00000000005e51 | byte_FF00000000005E51 | W | Launcher WNDCLASSEX field |
| ff00000000005e52 | byte_FF00000000005E52 | W | Launcher WNDCLASSEX field |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004634f0 | sub_4634F0 | Check startup parameter / display mode |
| 005beec8 | _sprintf | Format window title string |

**Guard conditions:** The `byte_62A154` flag controls two-window mode (launcher + render window) vs single-window mode. In two-window mode, both "CUBEApp" (launcher) and "CUBERealtime" (render) window classes are registered and created. In single-window mode, only "CUBERealtime" is created with WS_POPUP style. sub_4634F0 determines if window should be hidden (SW_HIDE) or shown (SW_SHOW).
