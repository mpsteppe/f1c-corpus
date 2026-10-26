## TLSValueRetrievalWithInit_0058e0c7 — _getptd: per-thread data retrieval with lazy init

**Summary:** CRT `_getptd` (get per-thread data) implementation that retrieves the thread-local storage data block via TlsGetValue, lazily allocating a 116-byte structure and initializing it with thread ID and vtable on first access per thread. Preserves GetLastError across the call.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TLSFieldSetter (005884e0), RandLCGRandomNumberGenerator (005884ed), sub_5897CA (005897ca), SEHExceptionHandlerTrampolineSetup (0058a42f), TLSOffsetGetter (0058afcf), TLSOffsetGetter_afd8 (0058afd8), sub_592787 (00592787), sub_592924 (00592924), sub_5934E1 (005934e1), FontGlyphRender (00593694), SEHWrapperAroundCRTFunctionCall (005938b4), SEHWrapperDispatchingToHandlerFunction (00593c9c), sub_597388 (00597388)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e14c | TlsGetValue | R | Win32 TlsGetValue function pointer |
| 0059e150 | SetLastError | R | Win32 SetLastError function pointer |
| 0059e158 | TlsSetValue | R | Win32 TlsSetValue function pointer |
| 0059e15c | GetCurrentThreadId | R | Win32 GetCurrentThreadId function pointer |
| 0059e188 | GetLastError | R | Win32 GetLastError function pointer |
| 005e6d40 | dwTlsIndex | R | TLS index for CRT per-thread data block |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a2a6 | CRTAmsgExit | Fatal exit (0x10) if TLS allocation or TlsSetValue fails |
| 0058ab58 | sub_58AB58 | Allocate 116-byte per-thread data structure (1 element, size 116) |
| 0058e0b4 | TwoFieldInitializer_e0b4 | Initialize vtable at +0x50 and field at +0x14 to 1 |

**Guard conditions:** If TlsGetValue returns NULL (first call on thread), allocates new 116-byte structure via sub_58AB58. If allocation or TlsSetValue fails, calls CRTAmsgExit(0x10) (fatal out-of-memory/init error). Preserves and restores GetLastError value transparently.
