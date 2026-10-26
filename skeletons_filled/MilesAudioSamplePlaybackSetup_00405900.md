## MilesAudioSamplePlaybackSetup_00405900 — AudioSamplePlaybackSetup

**Summary:** Sets up Miles audio sample playback — checks collision/spatial response first, then on first call allocates sample handle via spatial query, configures sample file and loop count (infinite vs single based on mode), and optionally applies 3D sound positioning update.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | Loop mode flag (1 = infinite loop, else single play) |
| this | 0x58 | RW | — | Pointer to sample handle struct (allocated on first call) |
| this | 0x5C | RW | — | Sample file reference pointer (passed to AIL_set_sample_file) |
| this | 0x60 | RW | — | Filter preference data |
| this | 0x64 | RW | 0 | State field, initialized to 0 |
| this | 0x68 | R | — | Sample processor state (read by MilesSoundSampleProcessorSetup) |

**Written-by note (persistence):**
- this 0x58: set once on first call (allocated handle pointer, persists until freed)
- this 0x5C: set once on first call (file reference, persists until released)
- this 0x60: set once on first call (filter preference, persists)
- this 0x64: set once on first call (0, persists)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e3e0 | _AIL_set_sample_file@12 | R | Set sample file for playback |
| 0059e3e8 | _AIL_set_sample_loop_count@8 | R | Set sample loop count (0=infinite, 1=once) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00405b90 | F_3DSoundPositioningUpdate | Update 3D sound position when caller requests spatial update |
| 00405e60 | PhysicsCollisionResponseComputation | Compute spatial/collision response for audio positioning |
| 004060c0 | MilesSoundSampleProcessorSetup | Configure sample processor and filter for the sample |
| 004070e0 | SpatialQueryWithWeightedDistanceSelection | Allocate sample handle struct via spatial distance query |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x14 | == | 1 | Loop mode flag — 1 = continuous/infinite loop |

**Guard interpretation:** Function returns 2 if sample handle is uninitialized. If PhysicsCollisionResponseComputation returns non-zero → blocked (returns 1). If this[22] (sample handle) is null → first-time init: allocates via SpatialQueryWithWeightedDistanceSelection. If allocation fails → blocked (returns 1). On loop mode check: this[5]==1 → AIL_set_sample_loop_count(0) infinite; else → AIL_set_sample_loop_count(1) single play. If a7 (v9) is non-zero → calls F_3DSoundPositioningUpdate and clears ready byte; if zero → leaves ready byte set (=1).
