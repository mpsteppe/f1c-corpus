## PropertyValueSetterWithRefreshOnChange_00554700 — PropertyValueSetterWithRefreshOnChange

**Summary:** Updates property values via virtual dispatch on a device object. If a2 is non-null, reads a2[8] and a2[1] and updates this[1254]/this[1255] with change notification (vtable+332/304). If null, resets to 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioBufferFormatSetup (00541120), sub_5550E0 (005550e0), sub_55C070 (0055c070), sub_55C860 (0055c860), sub_55CF50 (0055cf50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0x130 | R | — | Field at device object +0x130 used in vtable+332 call |
| *(this+0x1100) | 0x14C | R | — | Field at device object +0x14C used in vtable+304 call |
| this | 0x0 | RW | — | Result / return value accumulator |
| this | 0x1100 | R | — | Pointer to device object (this[1088]) |
| this | 0x1398 | RW | 0 | Current value of a2[8] (this[1254]) |
| this | 0x139C | RW | — | Current value of a2[1] (this[1255]) |

**Written-by note (persistence):**
- this 0x0: Updated from dispatch return values; external poke survives
- this 0x1398: Updated when a2[8] changes; external poke survives
- this 0x139C: Updated when a2[1] changes and != -1; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If a2 is null → reset this[1254]=0, dispatch zero to vtable+332. If a2 is non-null: update this[1254] only when a2[8] differs; update this[1255] only when a2[1] differs AND a2[1] != -1.
