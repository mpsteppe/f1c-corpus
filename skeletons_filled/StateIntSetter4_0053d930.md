## StateIntSetter4_0053d930 — Conditional state integer quad-setter

**Summary:** Sets four state fields at offsets 0x1508-0x1514 from parameters a2-a5, each only when the value is >= 0 (allowing partial update by passing -1).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderUISystemGlobalInit (0053c360), sub_53DB90 (0053db90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1508 | RW | — | state int 1 — set from a2 if a2 >= 0 |
| this | 0x150C | RW | — | state int 2 — set from a3 if a3 >= 0 |
| this | 0x1510 | RW | — | state int 3 — set from a4 if a4 >= 0 |
| this | 0x1514 | RW | — | state int 4 — set from a5 if a5 >= 0 |

**Written-by note (persistence):**
- this 0x1508: written if a2 >= 0; persists until next write or reset
- this 0x150C: written if a3 >= 0; persists until next write or reset
- this 0x1510: written if a4 >= 0; persists until next write or reset
- this 0x1514: written if a5 >= 0; persists until next write or reset

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Each field written only if corresponding argument >= 0. Passing -1 skips that field.
