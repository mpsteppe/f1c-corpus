## AudioMixerDeviceInit_004c85d0 — Audio mixer device initialisation

**Summary:** Initialises audio mixer device: creates AudioMixerPtr via InitStatus vtable dispatch (offset 96), sets initial volume from global flt_7CF380, and marks the sound device as active (this[16]=1) with no fade state (this[20]=0).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalSoundRenderDispatchOnParamCheck (00404970), sub_485B90 (00485b90), SystemOSAPICall (004a03f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | 1 | active flag — set to 1 when mixer device initialised |
| this | 0x14 | RW | 0 | fade/transition state — reset to 0 on init |

**Written-by note (persistence):**
- this 0x10: set to 1 unconditionally on successful init; persists as active flag
- this 0x14: set to 0 on init; persists as fade state

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cf380 | flt_7CF380 | R | RenderFadeAlpha [DERIVED] (also: ` -- unknown float global) |
| 008ac4c4 | dword_8AC4C4 | R | InitStatus [DERIVED] |
| 008ac4c8 | dword_8AC4C8 | RW | AudioMixerPtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Guard: if AudioMixerPtr already exists (dword_8AC4C8 non-zero), skip creation and skip field writes. If InitStatus is NULL, return 0 (failure). Otherwise create AudioMixerPtr from InitStatus, then set volume and init fields.
