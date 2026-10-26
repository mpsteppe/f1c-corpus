## PhysicsStateZeroingResetForSuspension_0043e360 — Suspension and wheel physics state reset

**Summary:** Resets suspension and wheel physics state by zeroing per-wheel block pairs (4 iterations at 0x464 stride), a variable-length buffer list via pointer+offset, and two contiguous DWORD ranges (0xEC-0x118, 0x1F04-0x1F30).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xEC | RW | 0 | suspension state DWORD [0] |
| this | 0xF0 | RW | 0 | suspension state DWORD [1] |
| this | 0xF4 | RW | 0 | suspension state DWORD [2] |
| this | 0xF8 | RW | 0 | suspension state DWORD [3] |
| this | 0xFC | RW | 0 | suspension state DWORD [4] |
| this | 0x100 | RW | 0 | suspension state DWORD [5] |
| this | 0x104 | RW | 0 | suspension state DWORD [6] |
| this | 0x108 | RW | 0 | suspension state DWORD [7] |
| this | 0x10C | RW | 0 | suspension state DWORD [8] |
| this | 0x110 | RW | 0 | suspension state DWORD [9] |
| this | 0x114 | RW | 0 | suspension state DWORD [10] |
| this | 0x118 | RW | 0 | suspension state DWORD [11] |
| this | 0x348 | RW | 0 | per-wheel suspension block pair [0] (first of 4, stride 0x464) |
| this | 0x34C | RW | 0 | per-wheel suspension block pair [1] (first of 4, stride 0x464) |
| this | 0x15AC | R | — | count of variable-length buffer items to reset |
| this | 0x15B0 | R | — | pointer to variable-length buffer array |
| this | 0x1F04 | RW | 0 | secondary suspension state DWORD [0] |
| this | 0x1F08 | RW | 0 | secondary suspension state DWORD [1] |
| this | 0x1F0C | RW | 0 | secondary suspension state DWORD [2] |
| this | 0x1F10 | RW | 0 | secondary suspension state DWORD [3] |
| this | 0x1F14 | RW | 0 | secondary suspension state DWORD [4] |
| this | 0x1F18 | RW | 0 | secondary suspension state DWORD [5] |
| this | 0x1F1C | RW | 0 | secondary suspension state DWORD [6] |
| this | 0x1F20 | RW | 0 | secondary suspension state DWORD [7] |
| this | 0x1F24 | RW | 0 | secondary suspension state DWORD [8] |
| this | 0x1F28 | RW | 0 | secondary suspension state DWORD [9] |
| this | 0x1F2C | RW | 0 | secondary suspension state DWORD [10] |
| this | 0x1F30 | RW | 0 | secondary suspension state DWORD [11] |

**Written-by note (persistence):**
- this 0xEC-0x118: unconditional — all 12 DWORDs zeroed every call
- this 0x348-0x34C: unconditional — pair zeroed in 4-iteration loop
- this 0x1F04-0x1F30: unconditional — all 12 DWORDs zeroed every call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00569280 | Copy6DwordsToStructCall | copies 6 zero DWORDs (0x18 bytes) to target struct per iteration |

**Guard conditions:** Variable-length buffer loop guarded by this[0x15AC] > 0. If count ≤ 0, the entire buffer-zeroing block (qmemcpy + Copy6DwordsToStructCall) is skipped. All other field zeroing (per-wheel pairs, 0xEC-0x118, 0x1F04-0x1F30) executes unconditionally.
