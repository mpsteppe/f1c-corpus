## sub_500EAC_00500eac — DebugSetMuteLazyInit

**Summary:** Lazily loads the D3D8 DebugSetMute function from d3d8.dll or d3d8d.dll and calls it to suppress/enable D3D debug output during surface operations. Caches function pointer for subsequent calls.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SurfaceBlitOperation (0050099c), D3DTextureSurfaceLockCopy (00506559), sub_506971 (00506971)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0c8 | LoadLibraryA | R | Kernel32 LoadLibraryA import |
| 0059e0cc | GetProcAddress | R | Kernel32 GetProcAddress import |
| 0059e21c | GetModuleHandleA | R | Kernel32 GetModuleHandleA import |
| 005adb24 | aD3d8dDll | R | D3D8DllString [DERIVED] — "d3d8.dll" string |
| 005adb30 | aDebugsetmute | R | DebugsetmuteString [DERIVED] — "DebugSetMute" function name |
| 005adb40 | ModuleName | R | GPUMemoryModuleName [DERIVED] |
| 008b0090 | dword_8B0090 | RW | Cached DebugSetMute pointer from d3d8d.dll (debug DLL variant) |
| 008b0094 | DebugSetMute | RW | Cached DebugSetMute pointer from d3d8.dll (retail DLL variant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If DebugSetMute (retail) already cached → call with a1 (1=mute ON, 0=mute OFF). If dword_8B0090 (debug) already cached → call directly. Otherwise load d3d8.dll first (retail path), then d3d8d.dll (debug path), cache whichever is found.
