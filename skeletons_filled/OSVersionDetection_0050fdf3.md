## OSVersionDetection_0050fdf3 — OS version and CPU feature detection

**Summary:** Detects OS platform (Win9x vs NT) and queries CPU instruction set support (SSE, SSE2, 3DNow!) based on a ProcessorFeature ID. Uses IsProcessorFeaturePresent API on NT; falls back to direct CPUID detection on Win9x or when the API fails.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_50FEA7 (0050fea7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e198 | GetVersionExA | R | OS version info API |
| 0059e22c | IsProcessorFeaturePresent | R | Windows API for CPU feature queries |
| ff00000000005370 | byte_FF00000000005370 | W | unknown — decompiler artifact (indirect reference) |
| ff00000000005371 | byte_FF00000000005371 | R | unknown — decompiler artifact (indirect reference) |
| ff00000000005372 | byte_FF00000000005372 | R | unknown — decompiler artifact (indirect reference) |
| ff00000000005373 | byte_FF00000000005373 | R | unknown — decompiler artifact (indirect reference) |
| ff00000000005374 | byte_FF00000000005374 | R | unknown — decompiler artifact (indirect reference) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050fd16 | CPUID3DNowDetection | detects 3DNow! CPU feature via CPUID |
| 0050fd4e | sub_50FD4E | detects SSE/SSE2 CPU features via CPUID |

**Guard conditions:** Flow depends on GetVersionExA success, OS platform ID (1=Win9x, 2=NT), version comparison (Win98 SE cutoff: major=4, minor>=10, build>=0x55D), and ProcessorFeature ID (6=SSE, 7=3DNow!, 10=SSE2). On NT with API success: uses IsProcessorFeaturePresent directly. On fallback paths: uses CPUID helper functions, returning 0 when v4 flag indicates legacy OS or failure.
