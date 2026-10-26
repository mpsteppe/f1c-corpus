## SentinelFieldInit_004c9d50 — SentinelFieldInit

**Summary:** Initializes three fields (at offsets 0x0, 0x4, 0x44) to -1 (0xFFFFFFFF) sentinel value, indicating invalid/empty state. Called from sub_4CB120.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4CB120 (004cb120)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 18446744073709551615 | First sentinel field (index/handle), initialized to -1 = invalid |
| this | 0x4 | RW | 18446744073709551615 | Second sentinel field (index/handle), initialized to -1 = invalid |
| this | 0x44 | RW | 18446744073709551615 | Third sentinel field (index/handle), initialized to -1 = invalid |

**Written-by note (persistence):**
- this 0x0: Written once with -1. Survives until overwritten elsewhere.
- this 0x4: Written once with -1. Survives until overwritten elsewhere.
- this 0x44: Written once with -1. Survives until overwritten elsewhere.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None. Always writes all three fields unconditionally.
