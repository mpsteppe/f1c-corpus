## ZeroPairInit_00502bea — ZeroTwoFields

**Summary:** Zeros two consecutive DWORD fields at offsets 0 and 4 in the struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkPacketSendReceive (0050070d), AudioSoundBufferSetup (005007ef)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | First DWORD field, zeroed |
| this | 0x4 | RW | 0 | Second DWORD field, zeroed |

**Written-by note (persistence):**
- this 0x0: Written once per call to 0
- this 0x4: Written once per call to 0

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None. Always zeros both fields.
