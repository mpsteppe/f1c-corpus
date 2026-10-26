## ModeDependentSubsystemCall_004a2770 — PitCrewMeshLoadWithMode

**Summary:** Sets mode byte and parameter, loads a pit crew mesh via PitCrewMeshLoader, then conditionally adjusts runtime flags based on the stored mode. Only manipulates flags when the 3D sound source handle at 0x64 is non-null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitCrewAnimationLoader (004a2a90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2 | RW | — | mode/type byte for pit crew animation element, stored from caller parameter a2 |
| this | 0x48 | RW | — | DWORD parameter stored from caller a3, used by mesh loader |
| this | 0x64 | R | — | guard: sound source handle, if non-null the flag manipulation runs |

**Written-by note (persistence):**
- this 0x2: unconditional write from parameter a2
- this 0x48: unconditional write from parameter a3

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a2010 | PitCrewMeshLoader | loads pit crew mesh geometry data into the struct |
| 0054c030 | FlagFieldBitManipulation | sets flag bits based on stored mode (1,1,0,0 for mode != 0; 0,0,0,0 for mode == 0) |

**Guard conditions:** Guard at this[0x64] (sound source handle): if non-null, proceed to flag manipulation based on this[0x2] mode byte. If null, skip flag manipulation and return mesh loader result (mode byte and 0x48 still written regardless).
