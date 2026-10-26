## TextureLayerFlagSet_00558c60 — TextureLayerDirtyFlagSetter

**Summary:** Sets the 0x1000 dirty/update flag on a texture layer entry at given index (bounds-checked), and clears a related dirty tracking flag on the parent.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleCollisionSpark (004cb620), WheelRenderObjectPerFrameUpdate (004cb860), ParticleTrailEmitter (004cbc50), ParticleInstanceUpdate (004cc1d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | RW | — | parent flags (clears bit 0x10000 dirty tracking) |
| this | 0x2C | R | — | array element count limit |
| this | 0x34 | R | — | texture layer data array pointer |

**Written-by note (persistence):**
- this 0x20: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053b200 | MultiFieldSetter | copies multiple data fields into texture layer entry |

**Guard conditions:** If index a2 >= element count (this[11]) → skip and return null (BLOCKED: out of bounds). PASSES: index within bounds → set flag 0x1000 on entry, call MultiFieldSetter, clear parent flag.
