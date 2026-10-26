## SceneNodePositionGetter_0054b950 — Scene node position getter (lazy transform)

**Summary:** Lazily computes a scene node's world position transform via D3D device wrapper vtable+4 when cache flag is not set, then reads XYZ coordinates from node offsets 0xE8/0xEC/0xF0 into caller-provided output pointers.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleMainPhysicsUpdate (004441f0), AudioDSPStateUpdate (00448330), VTableDispatchWithNegation (004c8f80), Steward_Init (004d38f0), sub_55D5C0 (0055d5c0), sub_55ED10 (0055ed10), sub_560FE0 (00560fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x204 | R | — | Pointer to scene node (source of position data) |
| this | 0x218 | RW | — | Cached position data (written via D3D transform call) |
| this | 0x2EC | R | — | X coordinate (from node+0xE8) |
| this | 0x2F0 | R | — | Y coordinate (from node+0xEC) |
| this | 0x2F4 | R | — | Z coordinate (from node+0xF0) |

**Written-by note (persistence):**
- this 0x218: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If flag bit 0x20000000 at `node+20` is set (transform already cached), skips D3D recomputation. Otherwise computes transform, sets flag. Null-check on each output pointer — null skips that write.
