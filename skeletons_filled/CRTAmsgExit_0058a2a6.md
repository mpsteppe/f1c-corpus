## CRTAmsgExit_0058a2a6 — CRuntimeAssertMsgExit

**Summary:** C runtime assertion/error exit handler. Checks error display flag; if set, shows error dialog. Then processes the error code and calls registered exit function pointer with code 0xFF. Used by CRT stubs for allocation failures and runtime errors.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MemoryAllocationStub (00588156), CriticalSectionLazyInitEnter (0058dfea), TLSValueRetrievalWithInit (0058e0c7), sub_592AF4 (00592af4), sub_592BAD (00592bad), sub_592F2C (00592f2c), AmsgExitRuntimeError (00595733), NullTerminatedIntArrayCopyWithAlloc (00598502)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e65b0 | off_5E65B0 | R | PtrExitFunc [DERIVED] |
| 008d3ebc | dword_8D3EBC | R | ErrorDisplayFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00589cb5 | sub_589CB5 | unknown — not called in this function body |
| 005932ba | sub_5932BA | Display error/assertion dialog |
| 005932f3 | sub_5932F3 | Process/handle the exit error code |

**Guard conditions:** dword_8D3EBC == 1 → calls error display dialog. Always calls exit handler regardless.
