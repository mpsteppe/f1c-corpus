## CollisionSystemShutdownCleanup_00494900 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VidMan_Exit (004fad00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cde04 | dword_7CDE04 | RW | Surface1ResourceHandle [DERIVED] |
| 007cde08 | dword_7CDE08 | W | DestSurface [DERIVED] (also: ` — Destination surface/context) |
| 007cde0c | dword_7CDE0C | RW | CollisionSoundHandles (x8) [DERIVED] |
| 007cde10 | dword_7CDE10 | RW | RendererSurfaceHandle [DERIVED] (also: renderer device/surface handle) |
| 007cde14 | dword_7CDE14 | W | CollisionSoundSurface2 [DERIVED] |
| 007cde18 | dword_7CDE18 | RW | SurfaceRef2 [DERIVED] (also: � surface 2 refs) |
| 007cde1c | dword_7CDE1C | RW | SubsystemInstancePtr [DERIVED] (also: ` -- subsystem instance pointer) |
| 007cde20 | dword_7CDE20 | W | SurfaceObjectRef [DERIVED] |
| 007cde24 | dword_7CDE24 | RW | TexSurfaceRef3 [DERIVED] (also: � surface 3 refs) |
| 007cde28 | dword_7CDE28 | RW | Dword_SoundHandle [DERIVED] |
| 007cde2c | dword_7CDE2C | W | CollisionSoundHandle [DERIVED] (also: ` — collision sound/event resource handles) |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005502c0 | DestructorWithConditionalFreeFlagClear | [LLM] |
| 005539f0 | ResourceCascadeCleanup | [LLM] |
| 00557470 | EmptyStub_7470 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
