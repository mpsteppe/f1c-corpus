## CollisionContactDetection_0054f2f0 — Collision Contact Detection Per Frame

**Summary:** Per-frame collision contact detection: iterates over triangle list, depth-tests triangle vertices against line segments via D3D device, performs 2D point-in-triangle test to confirm contact, and stores contact data (world position, penetration distance, triangle source) for physics response. Returns number of contacts detected.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SceneBatchRenderCheck (0054f5c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1E8) | 0x0 | RW | 1 | contact entry active flag (set to 1 when contact detected, skip if == 6) |
| *(this+0x1E8) | 0x18 | R | — | collision identifier (a2 parameter stored per-contact) |
| *(this+0x1E8) | 0x28 | R | — | pointer to collision data source (a3 parameter) |
| *(this+0x1E8) | 0x2C | R | — | owner this-pointer stored per-contact |
| *(this+0x1E8) | 0x30 | R | — | loop iteration index stored per-contact |
| *(this+0x1E8) | 0x34 | RW | — | triangle source pointer (index list for vertex lookup) |
| *(this+0x1E8) | 0x38 | RW | — | reserved/zeroed (lerp parameter, stored as 0.0) |
| *(this+0x1E8) | 0x3C | RW | — | contact point X coordinate (local/triangle space) |
| *(this+0x1E8) | 0x40 | RW | — | contact point Y coordinate |
| *(this+0x1E8) | 0x44 | RW | — | contact point Z coordinate |
| *(this+0x1E8) | 0x48 | RW | — | world-space contact position X |
| *(this+0x1E8) | 0x4C | RW | — | world-space contact position Y |
| *(this+0x1E8) | 0x50 | RW | — | world-space contact position Z |
| *(this+0x1E8) | 0x58 | RW | — | penetration distance from segment start to contact |
| *(this+0x1E8) | 0x5C | RW | — | post-distance field (padding or secondary distance) |
| *(this+0x1E8) | 0x60 | RW | — | additional contact data field |
| *(this+0x1E8) | 0x64 | RW | — | additional contact data field |
| *(this+0x1E8) | 0x68 | RW | — | additional contact data field |
| *(this+0x1E8) | 0x6C | RW | — | additional contact data field |
| *(this+0x1E8) | 0x70 | RW | — | additional contact data field |
| this | 0x1E0 | R | — | pointer to contact segment-list struct (contains count and segment array) |
| this | 0x1E4 | R | — | triangle count (from a3 parameter, guard for loop entry) |
| this | 0x1E8 | R | — | pointer to contact output entry buffer |
| this | 0x204 | R | — | pointer to collision mesh geometry data (vertex/normal arrays) |
| this | 0x2EC | R | — | collision system internal data |
| this | 0x2F0 | R | — | collision system internal data |
| this | 0x2F4 | R | — | collision system internal data |

**Written-by note (persistence):**
- *(this+0x1E8) 0x0: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x34: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x38: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x3C: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x40: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x44: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x48: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x4C: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x50: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x58: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x5C: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x60: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x64: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x68: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x6C: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x70: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054eb40 | F_2D3DTrianglePointTest | 2D point-in-triangle test: determines if contact point lies within projected triangle |
| 00559a30 | SingleFunctionCallWrapper_9a30 | collision contact callback notifier: invokes registered handler for detected contact |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x1E8) | 0x0 | != | 6 | skip entries of type 6 (already-processed or invalid contact slot) |
| this | 0x1E4 | > | 0 | must have at least one triangle to process; returns 0 immediately if <= 0 |

**Guard interpretation:** Entry blocked (returns 0) when triangle count <= 0 — no collision geometry to test. Individual contact slots of type 6 are skipped during iteration (inner loop continue) because they represent already-processed or disabled entries. All other types proceed through depth-test and point-in-triangle check; type 1 entries (new contacts) get written with collision data.
