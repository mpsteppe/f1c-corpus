## EnumToFieldOffsetSetter_00554260 — EnumToFieldOffsetSetter

**Summary:** Maps an enum value (a2, range 1-14) to a specific field offset within `this` and conditionally sets it to a3 if different. Returns 1 if field was changed, 0 if skipped or invalid enum.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_553FC0 (00553fc0), sub_5542F0 (005542f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | — | Index-4 field, set when a2=5 maps to this[4] |

**Written-by note (persistence):**
- this 0x10: Written conditionally if different from a3; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005542b0 | jpt_55426C | R | Jump table for enum-to-field-offset switch |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 must be 1-6 or 13-14; all other values return 0. The target field is only written if the pointer is non-null and current value != a3. Mapping: 1→this[0], 2→this[1], 3→this[2], 4→this[5], 5→this[4], 6→this[7], 13→this[3], 14→this[4].
