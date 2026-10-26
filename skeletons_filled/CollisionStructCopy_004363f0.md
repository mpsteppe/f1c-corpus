## CollisionStructCopy_004363f0 — Collision data struct copy with zeroing

**Summary:** Copies a collision result struct from a source to a destination, then zeroes output impulse/force fields. If source has zero type byte, skip copy and just return. Part of collision response pipeline.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_43BC20 (0043bc20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Collision type byte (copied from source) |
| this | 0x4 | RW | — | Copied collision data (position/impulse parameter) |
| this | 0x8 | RW | — | Copied collision data |
| this | 0xC | RW | — | Copied collision data |
| this | 0x10 | RW | — | Copied collision data |
| this | 0x14 | RW | — | Copied collision data |
| this | 0x18 | RW | — | Copied collision data |
| this | 0x1C | RW | — | Copied collision data |
| this | 0x20 | RW | — | Copied collision data |
| this | 0x24 | RW | — | Copied collision data |
| this | 0x28 | RW | — | Copied collision data |
| this | 0x2C | RW | — | Copied collision data |
| this | 0x30 | RW | — | Copied collision data |
| this | 0x44 | RW | — | Copied collision data |
| this | 0x48 | RW | — | Copied collision data |
| this | 0x4C | RW | 0 | Zeroed output impulse/force field |
| this | 0x50 | RW | 0 | Zeroed output impulse/force field |
| this | 0x54 | RW | 0 | Zeroed output impulse/force field |
| this | 0x58 | RW | 0 | Zeroed output impulse/force field |
| this | 0x5C | RW | 0 | Zeroed output impulse/force field |
| this | 0x60 | RW | 0 | Zeroed output impulse/force field |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x1C: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x24: recalc every frame — external poke does NOT persist
- this 0x28: recalc every frame — external poke does NOT persist
- this 0x2C: recalc every frame — external poke does NOT persist
- this 0x30: recalc every frame — external poke does NOT persist
- this 0x44: recalc every frame — external poke does NOT persist
- this 0x48: recalc every frame — external poke does NOT persist
- this 0x4C: recalc every frame — external poke does NOT persist
- this 0x50: recalc every frame — external poke does NOT persist
- this 0x54: recalc every frame — external poke does NOT persist
- this 0x58: recalc every frame — external poke does NOT persist
- this 0x5C: recalc every frame — external poke does NOT persist
- this 0x60: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If source byte at offset 0 is zero, skip struct copy (only write type byte), zero output fields.
