## CloudSceneObjectRandomSelector_004fc2f0 — SelectRandomCloudSceneObjects

**Summary:** Iterates cloud scene objects, separates into two groups by name pattern, randomly selects one from each group using LCG, and copies their data (31 bytes) to output slots.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FC550 (004fc550)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x6F | RW | 0 | flag/state for first selected cloud (reset after copy) |
| this | 0xA3 | RW | 0 | flag/state for second selected cloud (reset after copy) |

**Written-by note (persistence):**
- this 0x6F: conditional — written to 0 after first random selection; external poke survives until next call
- this 0xA3: conditional — written to 0 after second random selection; external poke survives until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d6f08 | aClouds | R | aClouds [DERIVED] |
| 005d6f30 | aCloudr | R | CloudRString [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587dd0 | sub_587DD0 | copy memory block (31 bytes) between objects |
| 005884ed | RandLCGRandomNumberGenerator | LCG random number generator |
| 00588640 | sub_588640 | compare string against cloud name pattern (6 chars) |

**Guard conditions:** Count (a2+280) <= 0 → skip entirely. First category count (v4) <= 0 → skip first random selection. Second category count (v9) <= 0 → skip second random selection. v4/v9 >= 256 guard prevents overflow of candidate arrays.
