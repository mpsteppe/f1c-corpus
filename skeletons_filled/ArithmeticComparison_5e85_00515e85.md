## ArithmeticComparison_5e85_00515e85 — ArithCompareSetup

**Summary:** Initializes arithmetic comparison sub-object accessed via main object (a1). Stores UIScreenStateMachine pointer, clears two byte flags, sets active flag to 1, dispatches virtual init calls, then clears result state field.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x18C) | 0x0 | RW | — | pointer to UIScreenStateMachine stored here |
| *(this+0x18C) | 0x10 | RW | 0 | byte flag, cleared on init |
| *(this+0x18C) | 0x11 | RW | 0 | byte flag, cleared on init |
| *(this+0x18C) | 0x14 | RW | 1 | active/enabled flag, set to 1 |
| *(this+0x190) | 0x0 | R | — | first entry in function dispatch table, called during init |
| obj | 0x10 | R | — | vtable function at offset 0x10 (4th entry), virtual init call |
| this | 0x0 | R | — | vtable pointer for polymorphism |
| this | 0x8C | RW | 0 | result/completion state dword, cleared to 0 |
| this | 0x18C | R | — | pointer to embedded arithmetic comparison sub-object |
| this | 0x190 | R | — | pointer to function dispatch table |

**Written-by note (persistence):**
- *(this+0x18C) 0x0: written once with external pointer, survives until overwritten
- *(this+0x18C) 0x10: written once (0), could be externally modified
- *(this+0x18C) 0x11: written once (0), could be externally modified
- *(this+0x18C) 0x14: written once (1), could be externally modified
- this 0x8C: written once (0), could be externally modified

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00515df2 | UIScreenStateMachine | R | current screen state machine instance, stored into sub-object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No conditional branches — function always executes all steps unconditionally.
