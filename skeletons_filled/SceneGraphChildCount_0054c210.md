## SceneGraphChildCount_0054c210 — Linked list child node count

**Summary:** Counts nodes in a singly-linked list starting at `this[0x204]`, following next pointers at offset 0x10. Returns the count.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** GlobalVectorOffsetUpdate (0040e1f0), sub_448140 (00448140), AudioDSPStateUpdate (00448330), AnimationPlaybackSequence (0044acb0), PitCrewMeshLoader (004a2010), sub_4DD4E0 (004dd4e0), BoundingBoxComputation (004dd550), sub_4DD7C0 (004dd7c0), MaxSquaredMagnitudeSearch (004dd8f0), sub_4DE610 (004de610), VehicleGraphicsSceneLoader (004dfce0), SceneGraphChildVelocityScaling (004e2a00), PhysicsAudioVectorUpdate (004e2ad0), VertexClusteringLODGrouping (004e2d00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x214) | 0x10 | R | — | Next sibling pointer in linked list (traversal) |
| this | 0x204 | R | — | Head of child node linked list |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `this[0x204]` (list head) is null → returns 0 immediately.
