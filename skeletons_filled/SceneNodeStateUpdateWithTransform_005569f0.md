## SceneNodeStateUpdateWithTransform_005569f0 — SceneNodeFullUpdateWithWorldTransform

**Summary:** Performs full scene node state update including world-matrix transform, collision detection, bounding-box computation, bone transform copies, and optional deferred rendering setup. Called for animation nodes that have a transform property. Part of scene graph animation/rendering update system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AnimationDispatchWithSkipFlag (00556980)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x204 | R | — | pointer to animation channel linked list head |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f24 | dword_8B8F24 | R | D3D device wrapper / scene manager singleton vtable |
| 008b8f28 | dword_8B8F28 | R | unknown context/state pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b570 | sub_54B570 | setup/check for animation dispatch |
| 0054d7a0 | CollisionContactStateDetection | detect collision contact state for the scene node |
| 0054d9f0 | MeshBoundingBoxComputation | compute mesh bounding box (if not already computed) |
| 00551760 | LinkedListTraversalWithConditionalTimerUpdate | traverse and update linked list with timer check |
| 00556d60 | sub_556D60 | finalize scene node update / return result |
| 0055d5c0 | sub_55D5C0 | handle rendering state update or deferred draw |
| 0055ed10 | sub_55ED10 | handle additional scene node processing (materials/shaders) |

**Guard conditions:** 
1. `!*(_DWORD *)(a2 + 428)` (bounding box not yet computed) → call MeshBoundingBoxComputation
2. `(*(_DWORD *)(a3 + 20) & 0x20000000) == 0` (world transform not yet set) → D3D vtable call to upload transform, set flag bit. PASSES: transform already set → skip
3. `(v5 & 4) != 0 && (v5 & 8) == 0` (visible but bone copy not done) → set flag bit 8, copy 8 bone transforms via D3D vtable
4. `(result & 5) != 0` (node is active/visible) → enter final update path with sub_556D60
   Sub-guard: `(result & 0x20) == 0` → allow sub_55ED10 and sub_55D5C0 calls