# UIPlatformAndOptions

Scope: `ui_platform_and_options`  
Trust: `DERIVED`

DERIVED grouping of eight validated functions in the ui_platform_and_options scope. Four functions are Win32 platform concerns: a message pump (0x0057E410), a window procedure that swallows the custom message 6666 and defers everything else to DefWindowProcA (0x0057AEA0), and teardown of a hidden async-socket message window (0x0057E530, DERIVED owner AsyncSocketWindowSubsystem per packet). Three functions are session/network thread concerns: two __thiscall wrappers that delegate a field at this+0x0 to mutex-guarded thread suspend/resume helpers (0x0057A910, 0x0057A920, callers in the session/retry layer), and a routine that initializes two mutex-protected state bytes in a 40-byte slot and then creates a CREATE_SUSPENDED worker thread with raised priority (0x00585470, called from NetworkConnectionThread 0x0057FC80). One function is a UI state toggle (0x005414C0) flipping the integer field at this+0x1148 between 0 and 1 and returning the new value; one is an unsigned-integer-to-string conversion in a caller-supplied base (0x00596C20). Owners for everything except AsyncSocketWindowSubsystem remain UNKNOWN in the packet and are proposed as GUESS classes; class boundaries are defensible per-function groupings, not attested source layout.

## Function roles

- `0x005414C0` **UiToggleStateObject** — Toggles the integer UI-state field at this+0x1148 between 0 and 1 and returns the new value; trivial __thiscall complement-and-store.
- `0x0057A910` **MutexGuardedThreadWrapper** — Delegates the DWORD at this+0x0 to the mutex-guarded thread suspend helper ThreadSuspendWithMutexWaitLock and returns its result.
- `0x0057A920` **MutexGuardedThreadWrapper** — Delegates the DWORD at this+0x0 to the mutex-guarded thread resume helper ThreadResumeWithMutexWait and returns its result.
- `0x0057AEA0` **Ignore6666WindowProc** — Win32 window procedure that returns 0 immediately for the custom message 6666 and forwards every other message to DefWindowProcA, returning its result.
- `0x0057E410` **WindowsMessagePump** — Runs the standard Win32 message pump: PeekMessageA loop, GetMessageA (break on WM_QUIT), TranslateMessage, DispatchMessageA.
- `0x0057E530` **AsyncSocketWindowSubsystem** — Destroys the hidden async-socket message window (DestroyWindow on dword_8D3E28), unregisters its window class via UnregisterClassA with the HINSTANCE at this+0x774, clears the global handle to 0, and returns 1 (or 0 when the handle was already zero).
- `0x00585470` **WorkerThreadSlotManager** — Initializes two mutex-protected state bytes in the 40-byte worker slot (first cleared, second set), then creates a CREATE_SUSPENDED worker thread with raised priority and stores the handle back into the slot.
- `0x00596C20` **UnsignedIntegerToStringConverter** — Converts an unsigned integer into a null-terminated string in caller-supplied base a3, with optional leading '-' for the negate flag, emitting digits least-significant first and reversing the digit run in place.

## Proposed classes

### UiToggleStateObject

Owns a boolean UI-state flag at this+0x1148 that flips between 0 and 1 on every invocation of its toggle method.

Methods: `0x005414C0`

- `this+0x00001148` `int uiStateFlag` (read_write, GUESS)

### MutexGuardedThreadWrapper

Suspends and resumes a worker thread whose target/value is stored at this+0x0, delegating to mutex-guarded helpers named by raw source; callers sit in the session/network and retry layers.

Methods: `0x0057A910`, `0x0057A920`

- `this+0x00000000` `void* threadTarget` (read, GUESS)

### AsyncSocketWindowSubsystem

Owns the hidden async-socket message window: references the window handle global dword_8D3E28 and the registered class-name global 0x005E5374, and tears both down via DestroyWindow and UnregisterClassA using the HINSTANCE stored at this+0x774. The two globals are carried as class evidence and dependency refs rather than this-relative fields.

Methods: `0x0057E530`

- `this+0x00000774` `HINSTANCE hInstance` (read, DERIVED)

### WindowsMessagePump

Drains the Win32 message queue for its (unidentified) target window using PeekMessageA/GetMessageA, translating and dispatching each retrieved message; returns the last Peek/Get result.

Methods: `0x0057E410`


### Ignore6666WindowProc

Window procedure that swallows the custom message 6666 by returning 0 and forwards all other messages to DefWindowProcA unchanged.

Methods: `0x0057AEA0`


### WorkerThreadSlotManager

Creates a suspended worker thread after initializing two mutex-protected state bytes inside the 40-byte slot array; the start routine is the StartAddress global and the thread priority is raised to 1.

Methods: `0x00585470`


## Compatibility contracts

- **Win32MessageLoopSemantics** — A replacement message pump must enter a PeekMessageA do-while loop, retrieve each queued message with GetMessageA, break on a zero return (WM_QUIT), and process each message with TranslateMessage followed by DispatchMessageA; the pump returns the last PeekMessageA/GetMessageA result.
- **CustomMessage6666Swallow** — The window procedure must return 0 immediately when the message equals 6666 (swallowing it) and otherwise forward all four arguments to DefWindowProcA and return its result unchanged.
- **AsyncSocketWindowTeardown** — Teardown of the hidden async-socket message window: when the global window handle dword_8D3E28 is non-zero, DestroyWindow it, UnregisterClassA the class name with the HINSTANCE at this+0x774, clear the global handle to 0, and report 1; report 0 when the handle was already zero.
- **SuspendedWorkerThreadCreation** — Worker-thread creation must run only when the thread-handle slot is NULL and the StartAddress global is set; before CreateThread with creation flags 4 (CREATE_SUSPENDED) it must clear one state byte and set another inside the 40-byte slot, each under its own mutex (WaitForSingleObject accepting signaled or abandoned, then ReleaseMutex), store the new handle back into the slot, and raise the thread priority to 1 via SetThreadPriority.
- **UiStateToggleSemantics** — The UI state field at this+0x1148 must alternate between 0 and 1 on each call, with the new value stored back and returned to the caller.

## Unresolved

- Meaning of the custom window message 6666, which component posts it, and what the 0 return is intended to suppress is not attested anywhere in the packet.
- Whether Ignore6666WindowProc (0x0057AEA0) is the window procedure of the hidden async-socket window is not evidenced; the packet carries no window-registration link, so they are kept as separate GUESS classes.
- Semantic meaning of the toggled UI state field at this+0x1148 and identity of its owning object are not identified; whether the toggle is one of several mutually exclusive UI states depends on callers outside the packet.
- ThreadSuspendWithMutexWaitLock and ThreadResumeWithMutexWait have no callee addresses in the packet and are described from raw-source names only; their real side effects are unconfirmed and the DERIVED no-side-effect getter prelabels are outranked by raw source.
- Whether this+0x0 of the suspend/resume wrappers holds a thread object pointer, a thread handle, or a wrapper value consumed by the helpers is unknown.
- The 40-byte worker slot is processed only at index 0 in ThreadCreateWithMutexStateInit (loop bound i < 1); how other slots are used elsewhere is unknown.
- Identity of the StartAddress thread-start routine (global 0x00583D90) is not resolvable from the packet.
- The base a3 supplied to UintToBaseString is caller-defined; the packet's one caller (Base10NegativeSpecialCase 0x00596BF3) implies base 10 with negative special-casing, but the v7 + 87 branch permits other bases, and buffer capacity is not tracked.
- Which window procedure receives dispatched messages and whether WindowsMessagePump belongs to a specific subsystem is unknown; no caller or window-handle evidence is present.
