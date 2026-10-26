## LargeStructZeroInit_00495190 — Screen UI Structure Initialization

**Summary:** Initializes a large screen/UI data structure (0x18EC+ bytes): zeros most fields, sets sentinel values (-1 for unsigned max), initializes sub-objects via helper constructors, and assigns a vtable pointer. Part of the screen-data initialization system called during game setup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ScreenDataStructInit (0047f370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_5AC998) |
| this | 0x4 | RW | 0 | field block — zeroed dword |
| this | 0x8 | RW | 0 | field block — zeroed dword |
| this | 0xC | RW | 0 | field block — zeroed dword |
| this | 0x10 | RW | 0 | field block — zeroed dword |
| this | 0x3C | RW | 0 | field block — zeroed dword |
| this | 0x40 | RW | 18446744073709551615 | sentinel value (-1 as uint64, "uninitialized" marker) |
| this | 0x58 | RW | 0 | field block — zeroed dword |
| this | 0x5C | RW | 0 | field block — zeroed dword |
| this | 0x60 | RW | 0 | field block — zeroed dword |
| this | 0x64 | RW | 0 | field block — zeroed dword |
| this | 0x68 | RW | 0 | field block — zeroed dword |
| this | 0x6C | RW | 0 | field block — zeroed dword |
| this | 0x70 | RW | 0 | field block — zeroed dword |
| this | 0x74 | RW | 0 | field block — zeroed dword |
| this | 0x78 | RW | 0 | field block — zeroed dword |
| this | 0x7C | RW | 0 | field block — zeroed dword |
| this | 0x80 | RW | 0 | field block — zeroed dword |
| this | 0x84 | RW | 0 | field block — zeroed dword |
| this | 0x88 | RW | 0 | field block — zeroed dword |
| this | 0x8C | RW | 0 | field block — zeroed dword |
| this | 0x90 | RW | 0 | field block — zeroed dword |
| this | 0x94 | RW | 0 | field block — zeroed dword |
| this | 0xF0 | RW | 0 | field block — zeroed dword (within memset region start) |
| this | 0xF4 | RW | 0 | field block — zeroed dword (within memset region) |
| this | 0xF8 | RW | 0 | field block — zeroed dword (within memset region) |
| this | 0xFC | RW | 0 | field block — zeroed dword (within memset region) |
| this | 0x1558 | RW | 0 | field block — zeroed dword (post-memset region) |
| this | 0x155C | RW | 18446744073709551615 | sentinel value (-1 as uint64, "uninitialized" marker) |
| this | 0x18AC | RW | 0 | field block — zeroed dword (post-sub-init region) |
| this | 0x18B0 | RW | 0 | field block — zeroed dword |
| this | 0x18B4 | RW | 0 | field block — zeroed dword |
| this | 0x18B8 | RW | 0 | field block — zeroed dword |
| this | 0x18BC | RW | 0 | field block — zeroed dword |
| this | 0x18C0 | RW | 0 | field block — zeroed dword |
| this | 0x18C4 | RW | 0 | field block — zeroed dword |
| this | 0x18C8 | RW | 0 | field block — zeroed dword |
| this | 0x18CC | RW | 0 | field block — zeroed dword |
| this | 0x18D0 | RW | 0 | field block — zeroed dword |
| this | 0x18D4 | RW | 0 | field block — zeroed dword |
| this | 0x18D8 | RW | 0 | field block — zeroed dword |
| this | 0x18DC | RW | 0 | field block — zeroed dword |
| this | 0x18E0 | RW | 0 | field block — zeroed dword |
| this | 0x18E4 | RW | 0 | field block — zeroed dword |
| this | 0x18E8 | RW | 0 | field block — zeroed dword |

**Written-by note (persistence):**
- this 0x0: written once during init — external poke does NOT persist (overwritten by vtable assignment)
- this 0x4: written once during init — external poke does NOT persist
- this 0x8: written once during init — external poke does NOT persist
- this 0xC: written once during init — external poke does NOT persist
- this 0x10: written once during init — external poke does NOT persist
- this 0x3C: written once during init — external poke does NOT persist
- this 0x40: written once during init — external poke does NOT persist
- this 0x58: written once during init — external poke does NOT persist
- this 0x5C: written once during init — external poke does NOT persist
- this 0x60: written once during init — external poke does NOT persist
- this 0x64: written once during init — external poke does NOT persist
- this 0x68: written once during init — external poke does NOT persist
- this 0x6C: written once during init — external poke does NOT persist
- this 0x70: written once during init — external poke does NOT persist
- this 0x74: written once during init — external poke does NOT persist
- this 0x78: written once during init — external poke does NOT persist
- this 0x7C: written once during init — external poke does NOT persist
- this 0x80: written once during init — external poke does NOT persist
- this 0x84: written once during init — external poke does NOT persist
- this 0x88: written once during init — external poke does NOT persist
- this 0x8C: written once during init — external poke does NOT persist
- this 0x90: written once during init — external poke does NOT persist
- this 0x94: written once during init — external poke does NOT persist
- this 0xF0: written once during init (memset) — external poke does NOT persist
- this 0xF4: written once during init (memset) — external poke does NOT persist
- this 0xF8: written once during init (memset) — external poke does NOT persist
- this 0xFC: written once during init (memset) — external poke does NOT persist
- this 0x1558: written once during init — external poke does NOT persist
- this 0x155C: written once during init — external poke does NOT persist
- this 0x18AC: written once during init — external poke does NOT persist
- this 0x18B0: written once during init — external poke does NOT persist
- this 0x18B4: written once during init — external poke does NOT persist
- this 0x18B8: written once during init — external poke does NOT persist
- this 0x18BC: written once during init — external poke does NOT persist
- this 0x18C0: written once during init — external poke does NOT persist
- this 0x18C4: written once during init — external poke does NOT persist
- this 0x18C8: written once during init — external poke does NOT persist
- this 0x18CC: written once during init — external poke does NOT persist
- this 0x18D0: written once during init — external poke does NOT persist
- this 0x18D4: written once during init — external poke does NOT persist
- this 0x18D8: written once during init — external poke does NOT persist
- this 0x18DC: written once during init — external poke does NOT persist
- this 0x18E0: written once during init — external poke does NOT persist
- this 0x18E4: written once during init — external poke does NOT persist
- this 0x18E8: written once during init — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac998 | off_5AC998 | R | VTable_TrackDB_5AC998 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00493f50 | sub_493F50 | initialize sub-object at this+5876 (secondary init constructor) |
| 00496560 | sub_496560 | final initialization pass on the full structure |
| 004999e0 | sub_4999E0 | initialize one 12-byte sub-object (called 4 times in loop) |
| 0049a180 | ZeroInitInt | zero-initialize an int field at this+6308 |

**Guard conditions:** No branch-based guards — the function is a straight-line initialization sequence: zero fields, memset a 0x1400-byte block, loop-initialize 4 sub-objects, memset another block, call sub-init constructors, zero remaining fields, assign vtable, call final init. No conditional branches.