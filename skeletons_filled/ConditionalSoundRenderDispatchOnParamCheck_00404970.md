## ConditionalSoundRenderDispatchOnParamCheck_00404970 — ConditionalAudioRenderDispatch

**Summary:** Conditionally triggers audio render setup and mixer initialization when a struct parameter (field at 0x20) equals 1 and the render fade alpha is positive.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_404B60 (00404b60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | R | — | dword condition flag enabling audio render dispatch (checked == 1) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea4e8 | flt_5EA4E8 | R | RandomOffsetFlag [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 007cf380 | flt_7CF380 | R | RenderFadeAlpha [DERIVED] (also: ` -- unknown float global) |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00408420 | ReciprocalWithSignCheck | computes reciprocal of a float with sign validation |
| 0040d360 | ShortComputation_d360 | performs short arithmetic computation with given parameters |
| 004c85d0 | AudioMixerDeviceInit | initializes audio mixer device with a scene name |
| 004c8830 | sub_4C8830 | configures audio parameter (3.0) on mixer |
| 004d8840 | ConditionalIndexSetter | conditionally sets an index/parameter to 1 |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | == | 1 | dword enabling audio/render setup |

**Guard interpretation:** Field at this+0x20 == 1 PASSES (enters render setup: runs computations, checks flt_7CF380 > 0.0 to optionally init audio mixer). Field != 1 BLOCKED (entire render dispatch skipped).
