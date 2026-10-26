## ArithmeticComparison_7390_00547390 — Field selector getter

**Summary:** Reads one of two fields (offset 0x8C or 0x90) based on selector constant `a3` (4096 or 0x2000). Writes selected value to output pointer `*a2` and returns it.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CollisionDetectionSystem (004ea970)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8C | R | — | Value returned when selector is 4096 (0x1000) |
| this | 0x90 | R | — | Value returned when selector is 0x2000 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No early return. When `a3 == 4096` (0x1000) → writes `this[0x8C]`. When `a3 == 0x2000` → writes `this[0x90]`. Otherwise returns `a3` untouched with no write.
