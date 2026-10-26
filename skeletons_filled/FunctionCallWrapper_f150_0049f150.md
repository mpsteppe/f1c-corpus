## FunctionCallWrapper_f150_0049f150 — SessionInitFlagSetter

**Summary:** Stores argument a2 into this+0x0 and sets global byte_8AD384 flag to 1 when a2==1 (session init complete). Returns bool indicating whether a2 equals 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** OnScreen_Restart (0049f000), ModeBasedDispatch (0049f790)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Mode/state value set from caller's dispatch result |

**Written-by note (persistence):**
- this 0x0: Overwritten each call with a2; survives in parent struct

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ad384 | byte_8AD384 | W | SessionInitCompleteFlag [DERIVED] — set to (a2 == 1) indicating session init completed |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always stores a2 to this+0x0 and updates global flag
