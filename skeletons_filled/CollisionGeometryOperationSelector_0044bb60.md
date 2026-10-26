## CollisionGeometryOperationSelector_0044bb60 — CollisionGeometryOperationRouter

**Summary:** Dispatches collision geometry processing pipeline based on operation ID (0=animation-only, 1=animation+contact+sweep, 2=full pipeline with bezier tessellation); always returns result of sweep-and-prune AABB overlap detection.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneTrackFileLoader (0044c0e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004492b0 | CollisionShapeInit | Initializes collision shape structure for bezier tessellation pipeline |
| 00449340 | PhysicsBufferFree | Frees physics pipeline buffer after tessellation |
| 00449700 | CollisionContactResponse | Computes contact response from processed collision data |
| 004497e0 | SweepAndPruneAABBOverlapDetection | Runs sweep-and-prune broadphase AABB overlap detection, returns result (likely overlap count or flag) |
| 0044acb0 | AnimationPlaybackSequence | Processes animation-driven collision mesh generation |
| 0044b370 | BezierPatchTessellation | Tessellates Bezier patches into collision triangle mesh output |

**Guard conditions:** 
1. `dword_8AFE88 != 0` (collision geometry handle) — PASS: processing possible, check operation ID. BLOCKED: no handle, skip all pipeline calls, only run final sweep/prune.
2. `a2 == 0` — PASS: run animation-only path (AnimationPlaybackSequence), then skip to final sweep/prune.
3. `a2 == 1` — PASS: run animation + contact response + sweep/prune.
4. `a2 == 2` — PASS: run full pipeline (shape init + animation + contact + bezier tessellation + sweep/prune).
