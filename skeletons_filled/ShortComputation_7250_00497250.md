## ShortComputation_7250_00497250 — ByteFieldSetter_0x25

**Summary:** Stores incoming byte parameter `a2` to field at offset 0x25. Returns the stored value. Simple setter called by many callers.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AutoJoinRetryLoop (004637a0), sub_46BF10 (0046bf10), sub_46DC60 (0046dc60), CarCrashDamageProcessing (00496030), sub_496E90 (00496e90), LinkedListSearchWithAction (004974a0), sub_4A0A80 (004a0a80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x25 | RW | — | Byte field storing a state/flag value |

**Written-by note (persistence):**
- this 0x25: Written unconditionally each call. External poke does not survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — writes field and returns unconditionally.
