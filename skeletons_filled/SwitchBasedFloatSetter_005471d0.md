## SwitchBasedFloatSetter_005471d0 — Float field setter by channel index

**Summary:** Converts integer a3 to normalized float (multiply by 1/255, approx 0.0039215689) and stores in one of four float fields (this+0x50/0x60/0x70/0x80) based on a2 channel index (1-4). Color/alpha channel configuration.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConstructorInputControlInit (00546250)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x50 | RW | — | float field set when a2==2 (channel 2, e.g. red) |
| this | 0x60 | RW | — | float field set when a2==1 (channel 1, e.g. green) |
| this | 0x70 | RW | — | float field set when a2==3 (channel 3, e.g. blue) |
| this | 0x80 | RW | — | float field set when a2==4 (channel 4, e.g. alpha) |

**Written-by note (persistence):**
- this 0x50: set when a2==2; persists until next explicit write
- this 0x60: set when a2==1; persists until next explicit write
- this 0x70: set when a2==3; persists until next explicit write
- this 0x80: set when a2==4; persists until next explicit write

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00547224 | jpt_5471DA | R | jump table for switch/case dispatch |
| 0059e460 | flt_59E460 | R | AlphaScaleFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Switch on a2 (1-4). If a2=1: writes this+0x60. a2=2: writes this+0x50. a2=3: writes this+0x70. a2=4: writes this+0x80. Default (a2 outside 1-4): BLOCKED, returns early without writing any field.
