## LargeConstructor_0048eaa0 — UI Slider Widget Constructor

**Summary:** Constructs a UI slider widget: calls base-class initializer (ShortComputation_5e30) then sets slider-specific fields — zeroes a large float/int region, assigns default slider range (min=1, max=4, current=0.5), marks an invalid/unset ID (-1), and sets a step count (10).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_66f0 (004766f0), sub_477410 (00477410), SeasonDatabaseObjectFactory (0047f440), sub_493FC0 (00493fc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_5A4550, UISlider vtable) |
| this | 0xE0 | RW | 0 | float field 1 (zero-initialized, possibly animation state) |
| this | 0xE4 | RW | 0 | float field 2 (zeroed) |
| this | 0xE8 | RW | 0 | float field 3 (zeroed) |
| this | 0xEC | RW | 0 | float field 4 (zeroed) |
| this | 0xF0 | RW | 0 | float field 5 (zeroed) |
| this | 0xF4 | RW | 0 | float field 6 (zeroed) |
| this | 0xF8 | RW | 0 | float field 7 (zeroed) |
| this | 0xFC | RW | 0 | float field 8 (zeroed) |
| this | 0x100 | RW | 1 | slider minimum value |
| this | 0x104 | RW | 4 | slider maximum value |
| this | 0x108 | RW | 1056964608 → 0.5f | slider current/default value |
| this | 0x10C | RW | 0 | unknown int/float field (zeroed) |
| this | 0x110 | RW | 0 | unknown int/float field (zeroed) |
| this | 0x114 | RW | 0 | unknown int/float field (zeroed) |
| this | 0x118 | RW | 0 | unknown int/float field (zeroed) |
| this | 0x11C | RW | 0 | unknown int/float field (zeroed) |
| this | 0x120 | RW | 0 | unknown int/float field (zeroed) |
| this | 0x124 | RW | 0 | unknown int/float field (zeroed) |
| this | 0x128 | RW | 0 | unknown int/float field (zeroed) |
| this | 0x12C | RW | 0 | unknown int/float field (zeroed) |
| this | 0x130 | RW | 0 | unknown int/float field (zeroed) |
| this | 0x134 | RW | 0 | unknown int/float field (zeroed) |
| this | 0x138 | RW | 0 | unknown int/float field (zeroed) |
| this | 0x13C | RW | 0 | unknown int/float field (zeroed) |
| this | 0x140 | RW | 0 | unknown int/float field (zeroed) |
| this | 0x144 | RW | 0 | unknown int/float field (zeroed) |
| this | 0x148 | RW | 0 | unknown int/float field (zeroed) |
| this | 0x14C | RW | 0 | unknown int/float field (zeroed) |
| this | 0x150 | RW | 0 | unknown int/float field (zeroed) |
| this | 0x154 | RW | 0 | unknown int/float field (zeroed) |
| this | 0x158 | RW | 0 | unknown int/float field (zeroed) |
| this | 0x15C | RW | 0 | unknown int/float field (zeroed) |
| this | 0x160 | RW | 0 | unknown int/float field (zeroed) |
| this | 0x164 | RW | 0 | unknown int/float field (zeroed) |
| this | 0x168 | RW | 0 | unknown int/float field (zeroed) |
| this | 0x16C | RW | 0 | unknown int/float field (zeroed) |
| this | 0x170 | RW | 18446744073709551615 | object/entity ID (-1 = invalid/unset) |
| this | 0x174 | RW | 0 | unknown int field (zeroed) |
| this | 0x178 | RW | 10 | slider step count / number of discrete positions |
| this | 0x17C | RW | 1 | enabled flag (BYTE, 1 = enabled) |
| this | 0x17D | RW | 0 | padding/flag byte (zeroed) |
| this | 0x17E | RW | 0 | padding/flag byte (zeroed) |
| this | 0x17F | RW | 0 | padding/flag byte (zeroed) |

**Written-by note (persistence):**
- this 0x0: once at construction — external poke does NOT survive (vtable set once)
- this 0xE0: once at construction — external poke does NOT survive
- this 0xE4: once at construction — external poke does NOT survive
- this 0xE8: once at construction — external poke does NOT survive
- this 0xEC: once at construction — external poke does NOT survive
- this 0xF0: once at construction — external poke does NOT survive
- this 0xF4: once at construction — external poke does NOT survive
- this 0xF8: once at construction — external poke does NOT survive
- this 0xFC: once at construction — external poke does NOT survive
- this 0x100: once at construction — external poke does NOT survive
- this 0x104: once at construction — external poke does NOT survive
- this 0x108: once at construction — external poke does NOT survive
- this 0x10C: once at construction — external poke does NOT survive
- this 0x110: once at construction — external poke does NOT survive
- this 0x114: once at construction — external poke does NOT survive
- this 0x118: once at construction — external poke does NOT survive
- this 0x11C: once at construction — external poke does NOT survive
- this 0x120: once at construction — external poke does NOT survive
- this 0x124: once at construction — external poke does NOT survive
- this 0x128: once at construction — external poke does NOT survive
- this 0x12C: once at construction — external poke does NOT survive
- this 0x130: once at construction — external poke does NOT survive
- this 0x134: once at construction — external poke does NOT survive
- this 0x138: once at construction — external poke does NOT survive
- this 0x13C: once at construction — external poke does NOT survive
- this 0x140: once at construction — external poke does NOT survive
- this 0x144: once at construction — external poke does NOT survive
- this 0x148: once at construction — external poke does NOT survive
- this 0x14C: once at construction — external poke does NOT survive
- this 0x150: once at construction — external poke does NOT survive
- this 0x154: once at construction — external poke does NOT survive
- this 0x158: once at construction — external poke does NOT survive
- this 0x15C: once at construction — external poke does NOT survive
- this 0x160: once at construction — external poke does NOT survive
- this 0x164: once at construction — external poke does NOT survive
- this 0x168: once at construction — external poke does NOT survive
- this 0x16C: once at construction — external poke does NOT survive
- this 0x170: once at construction — external poke does NOT survive
- this 0x174: once at construction — external poke does NOT survive
- this 0x178: once at construction — external poke does NOT survive
- this 0x17C: once at construction — external poke does NOT survive
- this 0x17D: once at construction — external poke does NOT survive
- this 0x17E: once at construction — external poke does NOT survive
- this 0x17F: once at construction — external poke does NOT survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a4550 | off_5A4550 | R | VTable_UISlider [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485e30 | ShortComputation_5e30 | base-class constructor (initializes UI widget base, offsets 0x0-0xDF) |

**Guard conditions:** None — this is a straight-line constructor with no conditional branches.
