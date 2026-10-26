## ScalePropagate_004e2ca0 — ScalePropagate

**Summary:** Propagates a new scale value to scene graph children when scale changes. Computes scale ratio and updates velocity scaling on child nodes. Part of vehicle transform/scale system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleRespawnReset (004e0800), sub_4F0D20 (004f0d20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x44 | R | — | Secondary child node pointer (at offset 0x44 of scene graph node) |
| this | 0x4 | R | — | Pointer to scene graph node |
| this | 0x970 | RW | — | Current scale value — compared against new scale, replaced on change |

**Written-by note (persistence):**
- this 0x970: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e2a00 | SceneGraphChildVelocityScaling | Updates velocity scale factor on child scene graph nodes |

**Guard conditions:** Checks a2 != this+0x970 (new scale != current scale). If equal, skips entire update. PASSES: scale changed -> propagate. BLOCKED: scale unchanged.
