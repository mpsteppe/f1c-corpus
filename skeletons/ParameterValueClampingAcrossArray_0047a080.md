## ParameterValueClampingAcrossArray_0047a080 — Distribute and clamp value across array of structures

**Summary:** After setup, fetches a value from the game command interface, checks enable flag at 0x100, retrieves a dynamic value via vtable call, then iterates an array (13 elements, 108 bytes each) setting each element's first field to the value and clamping it to bounds from fields at offsets 8 and 12.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xB4 | R | — | parameter index for value fetch from command interface (via dword_7CD8C0) |
| this | 0x0 | R | — | vtable pointer; used to call virtual function at offset 180 to retrieve runtime value |
| this | 0x100 | R | — | enable flag; if non-zero, clamping logic proceeds |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd8c0 | dword_7CD8C0 | R | game command dispatch interface pointer; called with command 8 to get source object |
| 007d1448 | unk_7D1448 | R | start of array of 27-dword structures iterated for clamping |
| 007d17a8 | flt_7D17A8 | R | end sentinel pointer for array iteration |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466910 | SetupValueDisplayFormatter | initializes formatter/dispatching state on this |
| 00490190 | ZeroCheckGetter | validates source object v2 (returns non-zero if valid) |

**Guard conditions:** 
- v2 (source object from command dispatch) == NULL — BLOCKS entire clamping body
- this+0x100 byte == 0 — BLOCKS iteration (feature disabled)
- ZeroCheckGetter(v2) returns 0 — BLOCKS array iteration (invalid source)
- Values: if v4 <= v3[0] -> clamp to v5 upper bound; else -> clamp to v4 lower bound
