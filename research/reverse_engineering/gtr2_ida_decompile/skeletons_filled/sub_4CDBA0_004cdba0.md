## sub_4CDBA0_004cdba0 — guarded state advance with flag toggle and post predicate

**Summary:** `__thiscall` sequencing routine, sibling of the other guarded advance: returns -1 if the byte at this+0x64 is set; otherwise advances the state machine (0→1, 2→3, and 4→1 or 4→3 depending on sub_4CD720) through virtual slot +0x2C, then fetches the flag dword via virtual +0xA4 and toggles it (`*v2 = (*v2 == 0)`) when present; afterwards a non-zero result from virtual +0x90 returns -1, otherwise sub_4CD570 runs and the function returns 0.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | Vtable slot +0x2C; transition setter invoked with `this` and target state (1 or 3) |
| obj | 0x90 | R | — | Vtable slot +0x90; predicate — non-zero result aborts the routine with -1 |
| obj | 0xA4 | R | — | Vtable slot +0xA4; getter returning a pointer to the flag dword that is toggled (or null to skip the toggle) |
| this | 0x0 | R | — | Vtable pointer used to resolve slots +0x2C, +0x90 and +0xA4 |
| this | 0x64 | R | — | Byte flag; if non-zero the function returns -1 immediately (no state changes) |
| this | 0x84 | R | — | State index (this[33]) driving the switch (only 0, 2 and 4 act) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004cdc20 | jpt_4CDBB5 | R | Jump table for the this[0x84] switch dispatch |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cd570 | sub_4CD570 | Final helper executed on the success path (after the +0x90 predicate passes); specific effect not inferable (unknown) |
| 004cd720 | sub_4CD720 | Predicate consulted in state 4: non-zero selects transition target 3, zero selects 1 |

**Guard conditions:** Immediate block if the byte at this+0x64 is non-zero → return -1. Switch: case 0 → set state 1; case 2 → set state 3; case 4 → set 3 if sub_4CD720() non-zero else set 1; other states do nothing. The flag toggle executes only when the +0xA4 getter returns non-null. Then virtual +0x90 is called and only a zero result lets sub_4CD570 run (return 0); a non-zero result blocks and returns -1.
