## MilesSoundSampleProcessorSetup_004060c0 — MilesSoundSampleProcessorSetup

**Summary:** Configures Miles Sound System sample processor and filter preferences on a sound sample handle. Sets sample processor callback and optionally applies filter preference when filter index is not -1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MilesAudioSamplePlaybackSetup (00405900)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x68) | 0x10 | R | — | Miles sample handle from sub-struct |
| this | 0x58 | R | — | pointer to sample info structure |
| this | 0x60 | R | — | filter index (compared to -1) |
| this | 0x64 | R | — | sample processor type/value parameter |
| this | 0x68 | R | — | pointer to filter preference data buffer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e3a8 | _AIL_set_sample_processor@12 | R | Miles API to attach sample processing function to a sample |
| 0059e3ac | _AIL_set_filter_sample_preference@12 | R | Miles API to set filter sample preference on a sample |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404fc0 | sub_404FC0 | resolves filter preference string from numeric index |

**Guard conditions:** checks this[22] (offset 0x58) != NULL, then checks *(this[22]+16) != NULL — if either check fails, returns early without calling any Miles API. Additionally checks this[24] (offset 0x60) != -1 to conditionally call AIL_set_filter_sample_preference; if -1, skips filter setup.
