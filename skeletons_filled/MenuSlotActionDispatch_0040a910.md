## MenuSlotActionDispatch_0040a910 — Menu Slot Selection Dispatch

**Summary:** Matches a2 against stored slot entries (8 fixed + variable array), dispatches ViewCameraModeDispatch with corresponding mode index (0-8), and optionally calls virtual update callback at vtable+16. Stores variable array index in this[15] when a variable entry matches.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionPhaseDispatchWithCascadeChecks (0040d1b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x10 | R | — | Sub-object for vtable variable-check (cast context) |
| this | 0x0 | R | — | Vtable pointer (calls vtable+16 for update callback) |
| this | 0x10 | R | — | Slot entry 0 (mode 0 dispatch) |
| this | 0x14 | R | — | Slot entry 1 (mode 1 dispatch) |
| this | 0x18 | R | — | Slot entry 2 (mode 2 dispatch) |
| this | 0x1C | R | — | Slot entry 3 (mode 3 dispatch) |
| this | 0x20 | R | — | Base of variable-length slot array (stride 200, mode 4 dispatch) |
| this | 0x24 | R | — | Slot entry 5 (mode 5 dispatch) |
| this | 0x28 | R | — | Slot entry 6 (mode 6 dispatch) |
| this | 0x2C | R | — | Slot entry 7 (mode 7 dispatch) |
| this | 0x30 | R | — | Slot entry 8 (mode 8 dispatch) |
| this | 0x38 | R | — | Variable array entry count (loop bound) |
| this | 0x3C | RW | — | Last matched variable array index (set when variable slot selected) |

**Written-by note (persistence):**
- this 0x3C: Written conditionally when a variable array entry matches. External poke survives until next variable match overwrites it.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00409440 | ViewCameraModeDispatch | Dispatches camera view mode by slot index (0-8) |

**Guard conditions:** a2 must be non-null. Fixed entries compared in order (this[4], this[5], this[6], this[7], this[9], this[10], this[11], this[12]). Variable array searched only if no fixed match, with loop bound this[14] (offset 0x38). a3 flag controls whether virtual callback at vtable+16 fires after dispatch.
