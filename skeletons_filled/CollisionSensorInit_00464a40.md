## CollisionSensorInit_00464a40 — Collision sensor initializer

**Summary:** Initializes collision sensor fields: sets sensor detection value to near -FLT_MAX, clears collision flag byte to 0, zeros contact count.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LargeStructInitialization (00464c10), sub_464D30 (00464d30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x68 | RW | 0 | Contact counter (initialized to 0) |
| this | 0x6C | RW | 0 | Collision detection flag byte (initialized to 0) |
| this | 0x71 | RW | — | Sensor detection value (initialized to -9.9999997e37 = near -FLT_MAX) |

**Written-by note (persistence):**
- this 0x68: set to 0 once at init
- this 0x6C: set to 0 once at init
- this 0x71: set to near -FLT_MAX once at init

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f130 | flt_59F130 | R | DefaultSensorValue [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always initializes all three fields.
