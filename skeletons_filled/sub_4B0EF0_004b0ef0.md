## sub_4B0EF0_004b0ef0 — SessionConfigSlotActivate

**Summary:** Activates one of six configuration slots (indexed 1-6) by copying per-slot parameter values into the active/current fields, clamping each against stored min/max bounds; special-cases slot 1 and 2 for an additional control field, then calls sub_4B1190 to apply the configuration globally.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionConfigWriteback (00461900), SessionInit (004a06e0), PlayerFileInit (004b0540)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C4 | RW | — | active config param group 1 — copied from slot source at this+4*(9*a2+369), clamped to [0x5CC, 0x5D0] |
| this | 0x5CC | R | — | min bound for config param group 1 |
| this | 0x5D0 | R | — | max bound for config param group 1 |
| this | 0x7F8 | RW | — | active config param group 2 — copied from slot at this+36*a2+2040, clamped to [0x800, 0x804] |
| this | 0x800 | R | — | min bound for config param group 2 |
| this | 0x804 | R | — | max bound for config param group 2 |
| this | 0x8F4 | RW | — | active config param group 3 — copied from slot at this+36*a2+2292, clamped to [0x8FC, 0x900] |
| this | 0x8FC | R | — | min bound for config param group 3 |
| this | 0x900 | R | — | max bound for config param group 3 |
| this | 0x9F0 | RW | — | active config param group 4 — copied from slot at this+36*a2+2544, clamped to [0x9F8, 0x9FC] |
| this | 0x9F8 | R | — | min bound for config param group 4 |
| this | 0x9FC | R | — | max bound for config param group 4 |
| this | 0xAEC | RW | — | active config param group 5 — copied from slot at this+36*a2+2796, clamped to [0xAF4, 0xAF8] |
| this | 0xAF4 | R | — | min bound for config param group 5 |
| this | 0xAF8 | R | — | max bound for config param group 5 |
| this | 0xBE8 | RW | — | active config param group 6 — copied from slot at this+36*a2+3048, clamped to [0xBF0, 0xBF4] |
| this | 0xBF0 | R | — | min bound for config param group 6 |
| this | 0xBF4 | R | — | max bound for config param group 6 |
| this | 0xCE4 | RW | — | active byte config param — copied from slot at this+24*a2+3300, byte-clamped to [0xCE6, 0xCE7] |
| this | 0xCE6 | R | — | min bound for byte config param |
| this | 0xCE7 | R | — | max bound for byte config param |
| this | 0x1C54 | RW | 7 | special control value: set to 1 for slot 1, 7 for slot 2, clamped to [0x1C5C, 0x1C60] |
| this | 0x1C5C | R | — | min bound for special control value |
| this | 0x1C60 | R | — | max bound for special control value |
| this | 0x1F78 | RW | — | active config param group 8 — copied from slot at this+36*a2+8204, clamped to [0x1F80, 0x1F84] |
| this | 0x1F80 | R | — | min bound for config param group 8 |
| this | 0x1F84 | R | — | max bound for config param group 8 |
| this | 0x200C | RW | — | active config param group 9 — copied from slot at this+36*a2+8456, clamped to [0x2014, 0x2018] |
| this | 0x2014 | R | — | min bound for config param group 9 |
| this | 0x2018 | R | — | max bound for config param group 9 |
| this | 0x2108 | RW | — | active config param group 10 — copied from slot at this+36*a2+8708, clamped to [0x2110, 0x2114] |
| this | 0x2110 | R | — | min bound for config param group 10 |
| this | 0x2114 | R | — | max bound for config param group 10 |
| this | 0x2204 | RW | — | active float config param — copied from slot at this+36*a2+8960, float-clamped to [0x220C, 0x2210] |
| this | 0x220C | R | — | min bound for float config param |
| this | 0x2210 | R | — | max bound for float config param |
| this | 0x2300 | RW | — | active config param group 12 — copied from slot at this+36*a2+9212, manually clamped to [0x2308, 0x230C] |
| this | 0x2308 | R | — | min bound for config param group 12 |
| this | 0x230C | R | — | max bound for config param group 12 |
| this | 0x23FC | RW | — | active config param group 13 — copied from slot at this+36*a2+9464, clamped to [0x2404, 0x2408] |
| this | 0x2404 | R | — | min bound for config param group 13 |
| this | 0x2408 | R | — | max bound for config param group 13 |
| this | 0x24F8 | RW | — | active config param group 14 — copied from slot at this+36*a2+9932, clamped to [0x2500, 0x2504] |
| this | 0x2500 | R | — | min bound for config param group 14 |
| this | 0x2504 | R | — | max bound for config param group 14 |
| this | 0x26CC | RW | — | active config param group 15 — copied from slot at this+36*a2+10184, manually clamped to [0x26D4, 0x26D8] |
| this | 0x26D4 | R | — | min bound for config param group 15 |
| this | 0x26D8 | R | — | max bound for config param group 15 |
| this | 0x27C8 | RW | — | active config param group 16 — additional parameter written during slot activation (possibly via sub_4B1190 side effect), clamped to [0x27D0, 0x27D4] |
| this | 0x27D0 | R | — | min bound for config param group 16 |
| this | 0x27D4 | R | — | max bound for config param group 16 |

**Written-by note (persistence):**
- this 0x5C4: once per activation — overwritten each time a slot is selected, external poke does NOT survive
- this 0x7F8: once per activation — overwritten each slot change, external poke does NOT survive
- this 0x8F4: once per activation — overwritten each slot change, external poke does NOT survive
- this 0x9F0: once per activation — overwritten each slot change, external poke does NOT survive
- this 0xAEC: once per activation — overwritten each slot change, external poke does NOT survive
- this 0xBE8: once per activation — overwritten each slot change, external poke does NOT survive
- this 0xCE4: once per activation — overwritten each slot change, external poke does NOT survive
- this 0x1C54: conditional — set to 1 (slot 1) or 7 (slot 2) only, not written for slots 3-6, external poke does NOT survive next activation of slot 1/2
- this 0x1F78: once per activation — overwritten each slot change, external poke does NOT survive
- this 0x200C: once per activation — overwritten each slot change, external poke does NOT survive
- this 0x2108: once per activation — overwritten each slot change, external poke does NOT survive
- this 0x2204: once per activation — overwritten each slot change, external poke does NOT survive
- this 0x2300: once per activation — overwritten each slot change, external poke does NOT survive
- this 0x23FC: once per activation — overwritten each slot change, external poke does NOT survive
- this 0x24F8: once per activation — overwritten each slot change, external poke does NOT survive
- this 0x26CC: once per activation — overwritten each slot change, external poke does NOT survive
- this 0x27C8: once per activation — overwritten each slot change, external poke does NOT survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004646c0 | FloatClamp | clamp a float value between min and max bounds in-place |
| 00464720 | ByteClamp | clamp a byte value between min and max bounds in-place |
| 0047f1f0 | ClampByRange | clamp an int value between min and max bounds in-place |
| 004b1190 | sub_4B1190 | apply the activated configuration slot globally (param -1.0 suggests full apply) |

**Guard conditions:**
- a2 < 1 OR a2 >= 7 → BLOCKED (return 0): slot index out of valid range (valid slots: 1-6)
- a2 ∈ [1, 6] → PASS: proceeds to activate the slot
- a2 == 1 → special path: sets this+0x1C54 to 1
- a2 == 2 → special path: sets this+0x1C54 to 7
- a2 ∈ [3, 6] → normal path: this+0x1C54 not modified (retains previous value)
