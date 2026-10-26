## ShortComputation_e5a0_0052e5a0 — CopyAudioBufferPointer

**Summary:** Copies audio buffer pointer from dword_8B0118 into D3D buffer struct (dword_8B0110[0]) and returns the old D3D buffer address. Quick pointer assignment for audio data routing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0052e5c0 | loc_52E5C0 | R | unknown |
| 008b0110 | dword_8B0110 | R | D3D buffer struct (old pointer returned) |
| 008b0118 | dword_8B0118 | R | audio output buffer pointer (value written to dword_8B0110) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587b3e | BooleanToIntConversion | unknown — not directly referenced in C body |

**Guard conditions:** none — no branches in function body
