## ObjectInitWithVTableFlagSet_005993eb — ObjectInitFieldsWithFlagCheck

**Summary:** Initializes object fields: zeroes this+0x2C, sets this+0x28 to a2, sets this+0x30 flag byte to 32. Calls StructFieldInitWithConditionalCall. If a2 is NULL, sets bit 2 on flag at this+0x4 and calls sub_59A5FE. Optionally calls sub_59A8FA if a3 is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LocaleObjectConstructorWithVtableInit (005989d7), ObjectConstructorWithVTableSetupAndSEH (00598af5)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | flag/status bitfield — bit 2 set if a2 is NULL |
| this | 0x28 | RW | — | initialized to a2 parameter; checked for null to trigger alternate path |
| this | 0x2C | RW | 0 | zeroed on init |
| this | 0x30 | RW | 32 | flag byte initialized to 0x20 |

**Written-by note (persistence):**
- this 0x28: written once during init; external poke would corrupt handle reference
- this 0x2C: written once during init; external poke would corrupt state
- this 0x30: written once during init; external poke would corrupt flag byte

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059a5fe | sub_59A5FE | handle null a2 case — sets up alternate state |
| 0059a8fa | sub_59A8FA | finalize initialization if a3 flag is set |
| 0059a948 | StructFieldInitWithConditionalCall | initialize struct fields with conditional logic |

**Guard conditions:** if a2 (this+0x28) is NULL, set bit 2 on flag at this+0x4 and call sub_59A5FE. If a3 flag is non-zero, call sub_59A8FA at end instead of returning result.
