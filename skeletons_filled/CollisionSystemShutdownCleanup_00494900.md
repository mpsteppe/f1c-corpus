## CollisionSystemShutdownCleanup_00494900 — Shut down rendering surface system

**Summary:** Cleans up all rendering surface allocations and collision sound handles during system shutdown. Destructs A/B/S buffers and collision sound objects via ResourceCascadeCleanup/DestructorWithConditionalFreeFlagClear, then frees memory and zeros globals.

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
| 005502c0 | DestructorWithConditionalFreeFlagClear | Frees internal surface buffer data without freeing the allocation itself |
| 005539f0 | ResourceCascadeCleanup | Cascading cleanup of resource sub-objects |
| 00557470 | EmptyStub_7470 | Pre-free callback or no-op stub for data payload |
| 00587bcf | FreeWrapper_7bcf | Frees surface allocation |

**Guard conditions:** Each surface group is only cleaned up if its global pointer is non-null. Five surface groups are processed independently: collision sounds (dword_7CDE0C), S-buffer (dword_7CDE04), surface 2 (dword_7CDE18), B-buffer (dword_7CDE10), texture ref 3 (dword_7CDE24), A-buffer (dword_7CDE1C), and sound handle (dword_7CDE28). Each group's associated "dest surface" pointer (dword_7CDE08/14/20/2C) is zeroed unconditionally after cleanup.
