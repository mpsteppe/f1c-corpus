## sub_4B9AC0_004b9ac0 — AudioSampleLookupAndPlay

**Summary:** Looks up an audio sample entry from a linked list using a float position/distance parameter, then selects and plays the appropriate sample with pitch modulation and stereo positioning based on field comparisons at +36 and +146.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4F0430 (004f0430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | pointer to linked list head for audio data |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acd04 | flt_5ACD04 | R | TrackPositionRefreshSentinel [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b72a0 | LinkedListTraversalWithFilter | traverse audio data linked list filtering by position |
| 004b8790 | FloatGetter | get current float value when sentinel is passed |
| 005000c0 | PassthroughWrapper_00c0 | pass-through audio sample for processing |
| 005001d0 | FieldCompareConstant | compare field at offset +36 against constant |
| 005001f0 | FloatComparisonCheck | compare float field at offset +36 |
| 00500210 | AudioSamplePlaybackWithPitchModulationAndStereoP | play audio sample with pitch modulation and stereo positioning |

**Guard conditions:** if LinkedListTraversalWithFilter returns NULL → blocked, return 0. If a4 equals sentinel value -9.9999997e37 → replace with FloatGetter result (not a guard, just fallback fetch).
