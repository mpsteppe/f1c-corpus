## sub_50FD4E_0050fd4e — CPU SSE/SSE2 feature detection via CPUID

**Summary:** Detects SSE and SSE2 instruction set support using CPUID leaf 1. Returns a bitmask: bit 2 (0x4) for SSE, bit 3 (0x8) for SSE2. Uses SEH to guard against CPUID faults on pre-Pentium CPUs.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** OSVersionDetection (0050fdf3)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0050fd9a | loc_50FD9A | R | code address referenced within function (likely SEH continuation target) |
| 0059c724 | loc_59C724 | R | code address referenced within function (likely SEH filter/target) |
| 005ade74 | aGenuineintel | R | "GenuineIntel" string — expected CPUID leaf 0 vendor string for Intel CPUs |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | installs structured exception handler to catch CPUID faults on older CPUs |

**Guard conditions:** CPUID leaf 0 EAX (max leaf) must be > 0 — if 0, function returns 0 immediately (no features detected). Otherwise proceeds to CPUID leaf 1 and checks EDX feature bits.
