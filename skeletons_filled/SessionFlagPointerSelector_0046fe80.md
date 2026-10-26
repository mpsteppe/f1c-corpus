## SessionFlagPointerSelector_0046fe80 — SessionFlagPointerSelectorInit

**Summary:** UI component constructor: calls UIComponentInit5, initializes fields (0xEC=0, 0xF0=-1), sets vtable to off_5A01A0, then selects and stores a pointer to one of six session state structures at 0xE8 based on index parameter a2 (1-6). Returns initialized object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5A01A0 |
| this | 0xE8 | RW | 0 | pointer to selected session state structure (set per a2 index) |
| this | 0xEC | RW | 0 | unknown flag/field, initialized to 0 |
| this | 0xF0 | RW | 18446744073709551615 | unknown field, initialized to -1 (0xFFFFFFFF) |

**Written-by note (persistence):**
- this 0x0: set once to vtable off_5A01A0; overwritten if external code changes vtable
- this 0xE8: set once from switch on a2; overwritten if external code writes to this pointer field
- this 0xEC: set once to 0; survives unless external code modifies it
- this 0xF0: set once to -1; survives unless external code modifies it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0046ff20 | jpt_46FEAA | R | jump table for switch on a2 |
| 005a01a0 | off_5A01A0 | R | vtable pointer assigned to this object |
| 007ceb64 | unk_7CEB64 | R | session state structure pointer (selected by a2=1) |
| 007ceb7c | unk_7CEB7C | R | session state structure pointer (selected by a2=2) |
| 007ceb94 | unk_7CEB94 | R | session state structure pointer (selected by a2=3) |
| 007cebac | unk_7CEBAC | R | session state structure pointer (selected by a2=4) |
| 007cebc4 | byte_7CEBC4 | R | FormationLap [DERIVED] — session state flag (selected by a2=5) |
| 007cebdc | unk_7CEBDC | R | updateMemoryValuesBeforeQualy [CONFIRMED] — session state data (selected by a2=6) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048fe60 | UIComponentInit5 | base UI component initialization |

**Guard conditions:** switch on a2: cases 1-6 each assign a specific session state pointer to this[58]; default (including 0, <1, >6) assigns null pointer.
