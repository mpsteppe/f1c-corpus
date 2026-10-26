## sub_4ED2C0_004ed2c0 — Game window procedure (WndProc)

**Summary:** Win32 window procedure for the game window: feeds mouse moves/buttons/wheel into the input dispatcher, selects the cursor, blocks the screen-saver/monitor-power system commands, and handles focus, activation, resize, erase, close and destroy messages while keeping the app's active/pause flags in sync.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004ed5ec | jpt_4ED2E9 | R | Jump table for the first switch on the window message |
| 004ed608 | byte_4ED608 | R | Byte-index/lookup table used by the switch dispatch |
| 004ed618 | jpt_4ED597 | R | Jump table for the second switch on the window message |
| 006f14b8 | ShowWindow | R | Imported user32 ShowWindow |
| 006f14cc | PostQuitMessage | R | Imported user32 PostQuitMessage |
| 006f152c | DefWindowProcA | R | Imported user32 DefWindowProcA for unhandled messages |
| 006f1530 | SetForegroundWindow | R | Imported user32 SetForegroundWindow |
| 00757c10 | dword_757C10 | R | Number of render-window/device entries iterated on activation |
| 0075b2b9 | byte_75B2B9 | W | Focus flag: set to 1 on WM_SETFOCUS, 0 on WM_KILLFOCUS |
| 0091e088 | dword_91E088 | R | Array of per-window/device pointers; each entry +14824 is passed to FieldAccessor |
| 00b640c0 | dword_B640C0 | R | App state: 5 = active/paused handling, 7 = close allowed |
| 00b6413c | byte_B6413C | R | Flag that blocks the deactivation handler path |
| 00b6a328 | dword_B6A328 | R | Input/mouse state object passed to the input and cursor helpers |
| 00b6a3d4 | dword_B6A3D4 | R | Cursor array/index passed to CursorSelectorFromArray |
| 00b6cba8 | dword_B6CBA8 | R | App/exit-query object used by sub_473630 |
| 00b6f1b8 | dword_B6F1B8 | R | Main window handle used with SetForegroundWindow and ShowWindow |
| 00b6f1bc | byte_B6F1BC | RW | Window-active flag toggled by WM_ACTIVATE |
| 00b6f1bf | unk_B6F1BF | R | Unknown — not referenced in the visible decompiled body |
| 00b6f1c0 | byte_B6F1C0 | RW | Flag toggled (0 on activate, 1 on deactivate) around the sub_4304C0 call |
| 00be1204 | dword_BE1204 | R | Subsystem state checked against 2 before activation handling runs |
| 00be1d30 | byte_BE1D30 | R | Object handed to sub_540130/sub_540140 on activation/deactivation |
| 00fb1cf8 | dword_FB1CF8 | R | When zero, the main window is minimized on deactivation |
| 00fb27a4 | dword_FB27A4 | R | Base pointer whose +4813 byte is flipped 0/1 on activate/deactivate |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004304c0 | sub_4304C0 | Application activate/deactivate action invoked around the byte_B6F1C0 toggles |
| 0045dda0 | CursorSelectorFromArray [exact] | Selects/sets the window cursor on WM_SETCURSOR |
| 0045ee90 | sub_45EE90 | Feeds a mouse event into the input dispatcher (state, x, y, button id, down/up flag) |
| 004735a0 | sub_4735A0 | Query gating the in-state activation handling |
| 00473630 | sub_473630 | App/exit query checked at the top of the WM_ACTIVATE case |
| 004ed060 | sub_4ED060 | Shutdown call on WM_CLOSE when the app state equals 7 |
| 004ed2a0 | sub_4ED2A0 | Window resize/move handler on WM_MOVE/WM_SIZE |
| 004fb7d0 | FieldAccessor [exact] | Per-window field update on each entry during activation (object +14824) |
| 00540130 | sub_540130 | Deactivation-side call paired with sub_540140 |
| 00540140 | ShortComputation_8d70 [exact] | Activation-side call paired with sub_540130 |

**Guard conditions:** Mouse messages are translated for buttons 0/1/2/3 with explicit down/up flags (wheel direction is -1 when a3 <= 0 else 1); everything else falls through to DefWindowProcA. WM_SYSCOMMAND is swallowed (returns 0) only for (a3 & 0xFFF0) equal to 0xF100, 0xF140 or 0xF170 — any other system command is passed to DefWindowProcA. WM_CLOSE does nothing and returns 0 unless dword_B640C0 == 7, where sub_4ED060 runs. WM_ACTIVATE: if sub_473630(&dword_B6CBA8) is true the whole handler is skipped (returns 1); the activation branch runs only while byte_B6F1BC == 0 and the inner in-state handling requires dword_B640C0 == 5 AND !sub_4735A0() AND dword_BE1204 != 2 AND byte_B6F1C0 != 0; the deactivation branch runs only while byte_B6F1BC != 0, minimizes the window only when dword_FB1CF8 == 0, and its inner handling requires dword_B640C0 == 5 AND !sub_4735A0() AND dword_BE1204 != 2 AND byte_B6413C == 0. WM_SETFOCUS sets byte_75B2B9 = 1 and WM_KILLFOCUS clears it; both return 1. WM_ERASEBKGND returns 1 without painting.
