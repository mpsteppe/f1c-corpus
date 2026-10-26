## StateResetWithCallback_00537000 — StateResetCallbackInvoke

**Summary:** Resets object state by zeroing pointers and restoring a saved state value from backup. Conditionally invokes vtable callbacks or IndirectCallViaVTable0x24 based on current state (modes 4, 5, or 6). Optionally calls and updates a function pointer result. Part of object lifecycle/state management system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ArithmeticComparison_5620 (00535620), sub_5357E0 (005357e0), MultiBlockAllocator (00537070), TripleVTableCall (00537ce0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | state field checked for modes 4/5/6, triggers different callbacks |
| this | 0x28 | R | — | saved state backup value, preserved before reset and restored to 0x30 |
| this | 0x30 | RW | — | restored state field, written from saved backup (0x28) during reset |

**Written-by note (persistence):**
- this 0x30: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00539f60 | IndirectCallViaVTable0x24 | indirect function call through vtable offset 0x24, invoked when state==6 |

**Guard conditions:**
- `a3 != NULL` → write a1[15] into *a3 (store callback result pointer)
- `a1[0] == 4 || a1[0] == 5` → invoke callback on a2 via vtable offset 0x24
- `a1[0] == 6` → call IndirectCallViaVTable0x24
- `a1[14] (callback ptr) != NULL` → call it (result,0,0), store result into a1[15] and *(a2+48)
- BLOCKED: no early returns; all conditions are optional actions within the function
