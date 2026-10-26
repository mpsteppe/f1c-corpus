## SceneNodeVisibilityToggle_0054fb40 — SceneNodeVisibilityToggle

**Summary:** Sets or clears the visibility flag (bit 6, 0x40) on a scene render node based on a boolean parameter.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ShortComputation_e770 (0040e770), SwitchBasedStateHandler (0040f380), sub_40FE50 (0040fe50), VehicleGraphicsSceneLoader (004dfce0), AIRacingLinePathFollowing (004e9ca0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x204 | R | — | pointer to scene render node (this[129]) |
| this | 0x218 | RW | — | visibility/state result (updated via returned node pointer) |

**Written-by note (persistence):**
- this 0x218: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always executed. If a2 is non-zero → set visibility (bit 6). If a2 is zero → clear visibility (bit 6). Returns node pointer.
