## ByteArrayToInt_00517f35 — ByteArrayBEToInt

**Summary:** Converts a 4-byte big-endian byte array to an integer value. Utility function.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5119E9 (005119e9), sub_511B7C (00511b7c), AnimationStateCheck (00517f72), sub_5188B4 (005188b4), sub_518C1E (00518c1e), sub_519019 (00519019)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | byte 0 (most significant byte in big-endian) |
| this | 0x1 | R | — | byte 1 |
| this | 0x2 | R | — | byte 2 |
| this | 0x3 | R | — | byte 3 (least significant byte) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None. Always succeeds; no validation.
