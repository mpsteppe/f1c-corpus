## YouHaveBeenBootedHandler_00461d20 — BootMessageDisplayHandler

**Summary:** Decrements a boot timer each frame; when timer expires and not already shown, renders "You have been booted" message to screen UI.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_f070 (0049f070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x30 | RW | 1 | Boot message shown flag (set to 1 after first render) |
| obj | 0x380 | RW | — | Boot countdown timer (decremented each frame) |
| obj | 0x3FB8 | R | — | COM interface pointer for delegation call |
| this | 0x0 | R | — | This pointer dereference |

**Written-by note (persistence):**
- obj 0x30: set to 1 once on first display; persists for session
- obj 0x380: decremented each frame; persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5d54 | aYouHaveBeenBoo | R | "You have been booted" message string |
| 005ec4c0 | byte_5EC4C0 | R | Empty string buffer (check source) |
| 005ec4cc | byte_5EC4CC | RW | Message display buffer (target for the boot message) |
| 007cd204 | dword_7CD204 | R | Resource dispatch target for text rendering |
| 008afe90 | dbl_8AFE90 | R | Frame delta (used as decrement step for timer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | Check if message buffer is empty (no existing message) |
| 0045bd10 | TextLineWrappingAndRendering | Render "You have been booted" to UI |
| 00461cd0 | SessionStateCheck | Check session state (must be 1-3 to proceed) |
| 0057a900 | SingleDelegationCall_a900 | Query COM object status (0 = disconnected/booted) |

**Guard conditions:** Blocked when session state (obj+0x3FC4) is <=0 or >3. Blocked when delegation call returns non-zero (not booted). Blocked when shown flag (obj+0x30) is already set. Message copy guarded by BinarySearchInStringTable returning non-zero (buffer empty).
