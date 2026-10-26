# BF-05: Import/Export Table Analysis

**Status:** DONE (2026-07-16)

## Summary

- **11 DLLs imported**, 0 exports
- No plugin export interface — plugins load via LoadLibrary/GetProcAddress

## DLL Imports

### Graphics: **d3d8.dll** (1 import)
- `Direct3DCreate8` — **DirectX 8, NOT DirectX 9**
- Proxy DLL target: **d3d8.dll** (not d3d9 as Opus assumed)

### Input: **DINPUT8.dll** (1 import)
- `DirectInput8Create` — DirectInput 8
- Secondary proxy target for button limit fixes

### Audio: **mss32.dll** (34 imports) — Miles Sound System
- Full Miles API: streams, samples, filters, DSP, WAV info
- `_AIL_set_DirectSound_HWND` — DirectSound backend

### Video: **binkw32.dll** (13 imports) — Bink Video
- Full Bink playback: open, decode frames, copy to buffer, sound
- `_BinkOpenMiles` / `_BinkOpenDirectSound` — audio routing through Miles

### Video: **AVIFIL32.dll** (3 imports)
- `AVIFileRelease`, `AVIStreamRelease`, `AVIFileExit`
- AVI playback alongside Bink

### Network: **WSOCK32.dll** (26 imports, by ordinal)
- WinSock 1.1 API — old-style socket networking
- All imported by ordinal number (common for WSOCK32)

### System: **KERNEL32.dll** (121 imports)
Key findings:
- `CreateThread` / `SuspendThread` / `ResumeThread` — **game IS multi-threaded** (contradicts some assumptions)
- `QueryPerformanceCounter` / `QueryPerformanceFrequency` — high-res timing
- `LoadLibraryA` / `GetProcAddress` — **dynamic DLL loading** (plugin mechanism)
- `OutputDebugStringA` — debug output path (hookable for logging)
- `CreateMutexA` — cross-process synchronization
- `SetPriorityClass` / `SetThreadPriority` — priority management
- `GetSystemInfo` — CPU detection
- `GlobalMemoryStatus` — RAM detection

### System: **USER32.dll** (27 imports)
- Standard Win32 window management
- `GetKeyboardState` / `ToAsciiEx` — keyboard input (alongside DirectInput)
- `ClipCursor` — cursor confinement
- No `SetTimer` — timing is manual via QPC

### Other
- **ADVAPI32.dll** (18 imports) — Registry access + security token checks
- **GDI32.dll** (1 import) — `GetStockObject` only
- **SHELL32.dll** (1 import) — `SHGetSpecialFolderPathA` (user paths)

## DLL Proxy Strategy

**Primary target: d3d8.dll**
- Only 1 export to forward (`Direct3DCreate8`)
- Returns IDirect3D8 interface — wrap the vtable for full rendering control
- Community already uses d3d8/d3d9 proxies on F1C (proven approach)

**Secondary target: dinput8.dll**
- Only 1 export (`DirectInput8Create`)
- Wrap IDirectInputDevice8 for button limit removal, input remapping

**Plugin loading: via LoadLibraryA**
- Game uses `LoadLibraryA` + `GetProcAddress` for dynamic loading
- Existing custom DLL in game directory uses this path
- Can inject hooks via DLL_PROCESS_ATTACH in any loaded DLL

## Threading Model

`CreateThread` import confirms the game creates worker threads.
`SuspendThread`/`ResumeThread` suggests thread synchronization during loading.
`CriticalSection` APIs (Enter/Leave/Init/Delete) confirm shared-state protection.
Our Frida trace showed single-threaded physics+AI+render on thread 4688 —
worker threads likely handle I/O, audio, or network, not simulation.
