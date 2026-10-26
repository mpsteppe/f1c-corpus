## InputBindingDispatch_0046d270 — Input binding dispatch

**Summary:** Calls sound system method, initializes input buffer with default values, creates two UI binding objects (IDs 39 and 41), activates one and deactivates the other, then refreshes game state. Part of input binding/UI dispatch system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x1C | R | — | vtable offset 28 — function that creates/gets UI objects by ID |
| this | 0x40 | R | — | pointer to vtable-based object used for creating UI binding elements |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea618 | flt_5EA618 | W | input buffer/state initialized with default values |
| 005eb10c | dword_5EB10C | R | SoundSystemPtr — engine interface for sound system update |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 — game state pointer passed to refresh function |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004186a0 | BufferInitWith10fDefaults | initializes buffer at flt_5EA618 with 0x10 bytes of default values |
| 0047c360 | sub_47C360 | sets activation state on a UI binding object (1 = activate, 0 = deactivate) |

**Guard conditions:** If dword_5EB10C (SoundSystemPtr) is non-null, calls vtable method offset 12 on it. If v2 (binding object ID 39) is non-null, activates it via sub_47C360(param=1). If v3 (binding object ID 41) is non-null, deactivates it via sub_47C360(param=0). No early-exit guard; function always proceeds through all steps.
