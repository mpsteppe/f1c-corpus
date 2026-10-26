## SoundAudioPlayback_004c8650 — Sound audio playback manager (fade/advance)

**Summary:** Manages audio playback each frame: handles volume fade-in (state 1) and fade-out (state 2+), advances to next track in the playlist linked list, or picks a new track from scene index when the list is exhausted. Communicates with AudioMixerPtr for actual playback control.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_404B60 (00404b60), sub_485B90 (00485b90), sub_4B9890 (004b9890), sub_4F9480 (004f9480)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x8)+0x0) | 0x0 | R | — | first field of current playlist node (pointer to data) |
| *(this+0x8) | 0x0 | R | — | current playlist node pointer |
| *(this+0x8) | 0x4 | R | — | next playlist node pointer |
| this | 0x0 | R | — | linked list head for playlist |
| this | 0x8 | RW | — | current playlist cursor (advanced on track change) |
| this | 0xC | R | — | linked list item count (checked for <= 0 to decide source) |
| this | 0x10 | R | — | active flag (checked before any playback) |
| this | 0x14 | RW | 0 | fade state (0=no fade, 1=fade in, 2+=fade out) |
| this | 0x18 | R | — | fade speed multiplier for volume transitions |

**Written-by note (persistence):**
- this 0x8: updated when advancing to next track; persists as playlist cursor
- this 0x14: updated each frame during fade; persists as fade state

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005acdec | dword_5ACDEC | R | ScreenColorTable [DERIVED] |
| 005d3254 | dword_5D3254 | R | SceneIndexCounter [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007cf380 | flt_7CF380 | R | RenderFadeAlpha [DERIVED] (also: ` -- unknown float global) |
| 008ac4c0 | dword_8AC4C0 | RW | Unknown_AnimCounter [DERIVED] |
| 008ac4c8 | dword_8AC4C8 | R | AudioMixerPtr [DERIVED] |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | copy file path string with buffer reallocation |
| 00587bcf | FreeWrapper_7bcf | free allocated memory buffer |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC | <= | 0 | playlist item count — if zero or negative, track source switches from playlist to scene index |

**Guard interpretation:** BLOCKED from playlist iteration: count <= 0 (empty playlist). Instead, pick next track from scene index counter. PASSES: count > 0, advance cursor through playlist linked list.
