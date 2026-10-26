## ConditionalObjectCleanup_00464670 — Network object cleanup on game exit

**Summary:** Conditionally cleans up two object pointers: VTableCall + pointer reset at +0x3FB8 if nonzero, then flag reset + NetworkCleanup + pointer reset at +0x1B79C if nonzero. Called on game exit.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameExit (0042db20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3FB8 | RW | 0 | Network object pointer; cleaned up and zeroed |
| obj | 0x417C | R | — | Argument passed to VTableCallViaOffset0x7c during cleanup |
| obj | 0x1B79C | RW | 0 | Secondary network object pointer; cleaned up and zeroed |
| this | 0x0 | R | — | Pointer to object |

**Written-by note (persistence):**
- obj 0x3FB8: unconditional clear to 0 on game exit
- obj 0x1B79C: unconditional clear to 0 on game exit

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a8b0 | VTableCallViaOffset0x7c | Calls virtual function at vtable offset 0x7c on object |
| 0057ab20 | PointerCheckWithFallback | Validates pointer with fallback handling |

**Guard conditions:** Checks if pointer at obj+0x3FB8 is nonzero. If zero, skips VTableCall/PointerCheckWithFallback/clear. Also checks if pointer at obj+0x1B79C (after base offset) is nonzero; if zero, skips NetworkCleanup/clear.
