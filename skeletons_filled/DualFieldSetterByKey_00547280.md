## DualFieldSetterByKey_00547280 — Set this+0x8C or this+0x90 by key comparison

**Summary:** If a3 == 4096 (0x1000), stores a2 in this+0x8C. If a3 == 8192 (0x2000), stores a2 in this+0x90. Key-value config setter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4CEF30 (004cef30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8C | RW | — | field set when key (a3) == 0x1000 |
| this | 0x90 | RW | — | field set when key (a3) == 0x2000 |

**Written-by note (persistence):**
- this 0x8C: overwritten when a3==0x1000; persists until next call with matching key
- this 0x90: overwritten when a3==0x2000; persists until next call with matching key

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If a3 == 0x1000: PASSES, writes this+0x8C = a2. If a3 == 0x2000: PASSES, writes this+0x90 = a2. Otherwise BLOCKED: neither field written.
