## MemoryAllocation_31a0_004531a0 — Force-feedback device context initialization

**Summary:** Initializes a large force-feedback device context: zeroes multiple data regions, sets max-axis counts to 17 (three groups), creates 44 axis property structs via StructInitWithFixedValues, creates 44 {value, -1} sentinel pairs, and sets a self-reference pointer for circular list traversal.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 0 | Initialization state/flag |
| this | 0x27C | RW | 17 | Max axis/property count for group A |
| this | 0xD7C | RW | 1 | Activation flag (enabled) |
| this | 0xD80 | RW | 0 | Deactivation counter/state |
| this | 0xE08 | RW | 0 | Group initialization state |
| this | 0x107C | RW | 17 | Max axis/property count for group B |
| this | 0x1204 | RW | 0 | Group B state |
| this | 0x1478 | RW | 17 | Max axis/property count for group C |
| this | 0x1580 | RW | — | Self-pointer (circular/back-link to this object) |
| this | 0x22B0 | RW | 0 | 44-element array of {value, -1} pairs (index 0: value=0) |
| this | 0x22B4 | RW | 18446744073709551615 | 44-element array pair index 0: sentinel = -1 (0xFFFFFFFF) |
| this | 0x2410 | RW | 0 | Tail struct dword 0 |
| this | 0x2414 | RW | 0 | Tail struct dword 1 |
| this | 0x2418 | RW | 0 | Tail struct dword 2 |
| this | 0x241C | RW | 0 | Tail struct dword 3 |
| this | 0x2420 | RW | 0 | Tail struct dword 4 |
| this | 0x2424 | RW | 18446744073709551614 | Tail struct sentinel = -2 (0xFFFFFFFE) |
| this | 0x2428 | RW | 0 | Tail struct byte (end marker) |

**Written-by note (persistence):**
- all fields set once during init; external poke survives until reinit

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00452780 | StructInitWithFixedValues | Initializes each of 44 axis property structures with fixed values and sub-calls |

**Guard conditions:** none — unconditional full initialization
