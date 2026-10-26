## GlobalManagerShutdownSequence_00485df0 — GlobalManagerShutdownSequence

**Summary:** Shuts down the game command dispatch system. Releases the global dispatch interface via its vtable, nulls the global pointer, and finalizes cleanup with a sub-call.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_485B90 (00485b90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd8c0 | dword_7CD8C0 | RW | GameCommandDispatchInterface [DERIVED] (also: ` — game command dispatch interface pointer) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004963d0 | sub_4963D0 | pre-release or pre-shutdown operation on dispatch interface |
| 004b0770 | sub_4B0770 | common cleanup or finalization routine (passes 1 as argument) |

**Guard conditions:** checks `dword_7CD8C0` (GameCommandDispatchInterface) != NULL before calling its vtable release method; if non-null, calls the first vtable entry (Release/Shutdown) with argument 1. After the call, always nulls the global and calls sub_4B0770 regardless.
