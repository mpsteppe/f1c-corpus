## StructCopy_004145c0 — Struct32ByteCopy

**Summary:** Copies 8 DWORDs (32 bytes) from source struct (a2) to destination struct (this). Plain field-by-field copy with no transformation. Used as a helper for array entry insertion and compaction.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** InsertDriverTableEntry (00418560), ArraySlotCompactionWithGapFilling (00418ac0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Copied field 0 |
| this | 0x4 | RW | — | Copied field 1 |
| this | 0x8 | RW | — | Copied field 2 |
| this | 0xC | RW | — | Copied field 3 |
| this | 0x10 | RW | — | Copied field 4 |
| this | 0x14 | RW | — | Copied field 5 |
| this | 0x18 | RW | — | Copied field 6 |
| this | 0x1C | RW | — | Copied field 7 |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x1C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always copies all 8 DWORDs unconditionally.
