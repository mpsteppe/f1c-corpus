## VehicleProjectedPosition_005694e0 — ComputeContactConstraintResponse

**Summary:** Computes collision contact constraint response: projects contact point (a2) relative to vehicle position (offsets 0x4/0xC/0x14) onto contact normal (a3), computes velocity along normal (a4), impulse correction (a5) using world-space inertia tensor (0xEC-0x12C), and optionally outputs body-space contact offset (a6). Part of collision detection physics pipeline.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** F_3DCollisionDetectionWithAABBTestAndContactResp (004ea040), CollisionDetectionSystem (004ea970)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | vehicle world position X |
| this | 0xC | R | — | vehicle world position Y |
| this | 0x14 | R | — | vehicle world position Z |
| this | 0x64 | R | — | body-space velocity / offset term X (used in v17) |
| this | 0x6C | R | — | body-space velocity / offset term Y (used in v18) |
| this | 0x74 | R | — | body-space velocity / offset term Z (used in v19) |
| this | 0x7C | R | — | inertia-related coefficient row 0 col 0 |
| this | 0x84 | R | — | inertia-related coefficient row 0 col 1 |
| this | 0x8C | R | — | inertia-related coefficient row 0 col 2 |
| this | 0xB4 | R | — | bias / restitution term added to impulse correction |
| this | 0xEC | R | — | world inertia row 0 col 0 |
| this | 0xF4 | R | — | world inertia row 0 col 1 |
| this | 0xFC | R | — | world inertia row 0 col 2 |
| this | 0x104 | R | — | world inertia row 1 col 0 |
| this | 0x10C | R | — | world inertia row 1 col 1 |
| this | 0x114 | R | — | world inertia row 1 col 2 |
| this | 0x11C | R | — | world inertia row 2 col 0 |
| this | 0x124 | R | — | world inertia row 2 col 1 |
| this | 0x12C | R | — | world inertia row 2 col 2 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If a6 (output offset buffer) is non-null, computes and stores body-space contact offset vector. If null, skips that output block. All other computation is unconditional.
