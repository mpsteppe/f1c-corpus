## CameraDirectorResetInit_0040da30 — CameraDirectorResetInit

**Summary:** Resets camera director state: saves and clears a byte flag at 0xA0, sets state to 1, zeroes counters, conditionally dispatches an in-progress session phase and updates player/vehicle index globals, then ensures the sub-struct pointer at 0x88 is valid (re-initializes existing or allocates new), falling back to error state -1 on allocation failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Steward_Restart (004d3cf0), Steward_Post (004d4600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x24 | RW | 0 | flag in sub-struct pointed by this+0x4, cleared if byte at 0xA0 was set |
| this | 0x0 | RW | 1 (then possibly -1) | state field, set to 1, then -1 if sub-struct allocation fails |
| this | 0x4 | R | — | pointer to camera director sub-object |
| this | 0x84 | RW | 0 | counter/state field, cleared |
| this | 0x88 | RW | — | pointer to allocated or existing sub-struct, reused or newly created |
| this | 0x8C | RW | 0 | counter field, cleared |
| this | 0x90 | RW | 0 | session phase ID, read for dispatch then cleared |
| this | 0x94 | RW | 18446744073709551615 | vehicle/player index, read for global update then reset to -1 |
| this | 0x98 | RW | 0 | counter field, cleared |
| this | 0x9C | RW | 0 | counter field, cleared |
| this | 0xA0 | RW | 0 | byte flag, saved for conditional clear then zeroed |

**Written-by note (persistence):**
- *(this+0x4) 0x24: conditional write (only if byte at 0xA0 was non-zero) — 0 — survives unless re-triggered
- this 0x0: unconditional write to 1, then conditionally to -1 if sub-struct allocation fails — survives
- this 0x84: unconditional write, 0 — survives
- this 0x88: conditional write (only when new allocation needed) — pointer — survives
- this 0x8C: unconditional write, 0 — survives
- this 0x90: unconditional write, 0 — survives
- this 0x94: unconditional write, -1 (after possible use) — survives
- this 0x98: unconditional write, 0 — survives
- this 0x9C: unconditional write, 0 — survives
- this 0xA0: unconditional write, 0 — survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c54dc | dword_7C54DC | W | CurrentPlayerIndex [CONFIRMED], written with this+0x94 value |
| 007c54e0 | dword_7C54E0 | W | postProcessInput [CONFIRMED], written with vehicle pointer from dword_7C54F0[this+0x94] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT], indexed by this+0x94 to retrieve vehicle pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d1b0 | SessionPhaseDispatchWithCascadeChecks | dispatches in-progress session phase if value at offset 0x90 was non-zero |
| 0040d470 | SimpleSetterWithSubCall | initializes a newly allocated 48-byte sub-struct and sets it up |
| 0040d490 | StructFieldInit | re-initializes an existing sub-struct if pointer at 0x88 was already valid |
| 00567f10 | F_9PointerArrayCleanup | cleans up pointer array at offset 0x4C |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 48 bytes for a new sub-struct when pointer at 0x88 is null |

**Guard conditions:**
- byte at this+0xA0 non-zero → clears flag at *(this+0x4)+0x24. Zero (already clear) → skip.
- dword at this+0x90 non-zero → dispatches session phase. Zero → skip.
- dword at this+0x94 >= 0 → updates CurrentPlayerIndex (dword_7C54DC) and PostProcessInput (dword_7C54E0) from VehiclePtrArray. Negative (-1) → skip.
- dword at this+0x88 non-zero → reuse via StructFieldInit. Null → allocate 48 bytes via OperatorNewNhMallocWrapper, init via SimpleSetterWithSubCall, store in this+0x88.
- if this+0x88 is null after allocation attempt → set *this = -1 (error state).
