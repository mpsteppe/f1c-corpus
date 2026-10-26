## AmbientSoundPlayback_004c9840 — AmbientSoundLoadAndPlay

**Summary:** Loads an ambient sound file ("pithorn.wav" from "ambient" subdirectory) and initializes playback with volume, pan, and fade settings. Called once to start ambient audio.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x0 | R | — | vtable pointer of loaded sound object; used to check if already playing and to stop it |
| this | 0x1C | RW | 0 | Pointer to loaded ambient sound object; nil means not loaded/stopped |
| this | 0x38 | RW | — | unknown from this function |
| this | 0x3C | RW | — | unknown from this function |
| this | 0x40 | RW | — | unknown from this function |

**Written-by note (persistence):**
- this 0x1C: Written once per call with sound object handle or zeroed if sound was already playing. Survives until next call replaces it.
- this 0x38: Not written in this function
- this 0x3C: Not written in this function
- this 0x40: Not written in this function

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005c6784 | aSSS_0 | R | sFormatPath [DERIVED] |
| 005d3448 | aAmbient | R | AmbientString [DERIVED] |
| 005d347c | aPithornWav | R | PithornWavString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3e0 | dword_5EC3E0 | R | AudioDirBasePath [DERIVED] |
| 007cf530 | flt_7CF530 | R | AmbientVolumeScale [DERIVED] |
| 007cf554 | flt_7CF554 | R | AudioVolume_VolumeFade [DERIVED] |
| 007cf578 | dword_7CF578 | R | AudioVolumeFactor [DERIVED] |
| 008ac4c4 | dword_8AC4C4 | R | InitStatus [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | Copies application directory path into a managed string buffer (path construction) |
| 00587bcf | FreeWrapper_7bcf | Frees a heap-allocated buffer (path string cleanup) |
| 0058815f | StringFormatWithBufferOverflowCheck | Safely formats the full ambient sound file path: "%s%s%s" (base + "ambient" + "pithorn.wav") |

**Guard conditions:** Checks `dword_8AC4C4` (InitStatus) — if zero, function returns 0 immediately (system not initialized). After loading sound object, checks if sound is already playing via vtable call at offset 20 (0x14) — if playing, stops it and clears handle at this+0x1C.
