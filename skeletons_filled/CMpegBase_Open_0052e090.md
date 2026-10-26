## CMpegBase_Open_0052e090 — CMpegBaseOpen

**Summary:** Opens CMpegBase audio decoder: checks and handles deferred deactivation flag, initializes buffer state and sync word, validates audio device settings, then computes buffer timing, performance state, and buffer sizes. Core initialization for MPEG audio playback.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x248C | R | — | buffer size (from timing calc) |
| this | 0x24A0 | RW | — | computed division result (frames per buffer) |
| this | 0x24A4 | RW | 0 | bitstream buffer pointer (cleared to 0) |
| this | 0x24B0 | RW | — | total buffer byte size (frames × frame_size) |
| this | 0x24D4 | R | — | initial timing value (set to 1) |
| this | 0x24D8 | R | — | timing quotient from AudioNetworkBufferTimingCalc |
| this | 0x24DC | R | — | timing remainder from AudioNetworkBufferTimingCalc |
| this | 0x24E0 | R | — | sample_rate / 100 from AudioNetworkBufferTimingCalc |
| this | 0x24EC | RW | 1 | deferred deactivation flag (checked and cleared) |
| this | 0x24F0 | RW | — | sync word (set from a2 parameter) |

**Written-by note (persistence):**
- this 0x24A0: written once per open; external poke overwritten each open
- this 0x24A4: written once to 0; external poke overwritten each open
- this 0x24B0: written once per open; external poke overwritten each open
- this 0x24EC: cleared to 0 then set to 1; external poke overwritten each open
- this 0x24F0: written once per open; external poke overwritten each open

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005da564 | aSDS_0 | R | format string "SDS" |
| 005da574 | aDDevAudiodevSh | R | audio device path string |
| 005da5e0 | aAudioAssert | R | audio assert message string |
| 005da674 | aCmpegbaseOpenG | R | "CMpegBase::Open" caller string for assert |
| 005da714 | off_5DA714 | R | assert/halt function pointer |
| 005da718 | off_5DA718 | R | file stream vtable pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052da10 | sub_52DA10 | unknown — audio decoder sub-initialization |
| 0052de40 | ArithmeticComparison_de40 | validate audio device configuration |
| 0052de60 | AudioNetworkBufferTimingCalc | compute audio buffer timing parameters |
| 0052e080 | F_64BitIntegerDivision | 64-bit division for buffer size computation |
| 0052e2f0 | LapPerformanceStateReset | reset lap/performance timing state |
| 0052e320 | DeferredDeactivation | handle pending deactivation request |
| 0052e4e0 | sub_52E4E0 | unknown |
| 0052e520 | HaltAssertHandler | assert failure / halt handler |

**Guard conditions:** if flag at offset 0x24EC (deferred deactivation) is non-zero, calls DeferredDeactivation first; returns -1 if ArithmeticComparison_de40 validation fails (assert displayed)
