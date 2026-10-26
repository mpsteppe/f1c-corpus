## VehicleAIControlFlag_004c7a70 — Vehicle AI control flag set/clear

**Summary:** Sets or clears bit 0 of the AI control flag at offset +0x48BC (this[4655]). When a2 is non-zero, sets the AI-controlled flag (bit 0 = 1); when zero, clears it (bit 0 = 0). Used during collision contact iteration to toggle AI override.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionContactIteration (00460dd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x48BC | RW | — | AI control flag bitset; bit 0 indicates AI-controlled |

**Written-by note (persistence):**
- this 0x48BC: updated unconditionally; persists until next write

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — read-modify-write always executes based on a2 value
