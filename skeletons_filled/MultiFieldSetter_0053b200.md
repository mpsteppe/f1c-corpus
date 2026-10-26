## MultiFieldSetter_0053b200 — SetPositionScaleAndOne

**Summary:** Copies three input parameters (position/scale components) into primary fields at offsets 4, 8, 0xC and duplicate reference fields at 0x58, 0x5C, 0x60. Sets field at 0x64 to 1.0f. Part of 3D transformation/position initialization.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_54B570 (0054b570), VertexBufferTransform (0054c6c0), TextureLayerFlagSet (00558c60), sub_558E70 (00558e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | primary position/scale X, set to a2 |
| this | 0x8 | RW | — | primary position/scale Y, set to a3 |
| this | 0xC | RW | — | primary position/scale Z, set to a4 |
| this | 0x58 | RW | — | duplicate/backup of X component |
| this | 0x5C | RW | — | duplicate/backup of Y component |
| this | 0x60 | RW | — | duplicate/backup of Z component |
| this | 0x64 | RW | 1065353216 → 1.0f | initialized to 1.0 (identity scale or w component) |

**Written-by note (persistence):**
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x58: recalc every frame — external poke does NOT persist
- this 0x5C: recalc every frame — external poke does NOT persist
- this 0x60: recalc every frame — external poke does NOT persist
- this 0x64: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — function always executes fully.
