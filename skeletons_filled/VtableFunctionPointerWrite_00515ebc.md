## VtableFunctionPointerWrite_00515ebc — UIScreenStateMachineStore

**Summary:** Stores the global UIScreenStateMachine pointer into the first dword of the sub-object at this+0x18C, then returns the sub-object pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x18C) | 0x0 | RW | — | first dword of sub-object, receives UIScreenStateMachine pointer |
| this | 0x18C | R | — | pointer to sub-object that stores state machine reference |

**Written-by note (persistence):**
- *(this+0x18C) 0x0: written once with external pointer, survives until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00515df2 | UIScreenStateMachine | R | current screen state machine pointer, stored into sub-object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No conditional branches — always executes unconditionally.
