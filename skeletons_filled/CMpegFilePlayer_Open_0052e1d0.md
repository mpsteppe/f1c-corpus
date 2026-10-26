## CMpegFilePlayer_Open_0052e1d0 — CMpegFilePlayer_Open

**Summary:** Opens/initializes an MPEG file player by validating file format magic, computing audio buffer sizes via 64-bit integer division, setting up network buffer timing, and activating the underlying audio stream device. Part of the audio/video playback system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x2D34)+0x0) | 0xC | R | — | vtable entry at offset 12 of the audio stream device object (virtual method to activate stream) |
| *(this+0x2D34) | 0x0 | R | — | vtable pointer of the audio stream device object |
| obj | 0xC | R | — | vtable entry at offset 12 of this player object (virtual open/validate method) |
| this | 0x0 | R | — | vtable pointer of the MPEG file player object |
| this | 0x248C | R | — | buffer size multiplier constant (used in final allocation computation) |
| this | 0x24A0 | RW | — | computed buffer size result (from 64-bit division quotient) |
| this | 0x24A4 | RW | — | encoding/format flags (bits 6-7 extracted from file header byte at offset 0x33) |
| this | 0x24B0 | RW | — | final buffer allocation size (quotient * multiplier from 0x248C) |
| this | 0x24D4 | R | — | audio sample rate or buffer base value (first operand in 64-bit division) |
| this | 0x24D8 | R | — | audio buffer parameter (second operand in multiplication chain) |
| this | 0x24DC | R | — | audio buffer parameter (added in multiplication chain) |
| this | 0x24E0 | R | — | audio buffer parameter (multiplied in chain) |
| this | 0x24EC | RW | 1 | boolean: player-active flag (set to 1 on open; if already set, triggers deferred deactivation) |
| this | 0x2D34 | R | — | pointer to audio stream device object (used for virtual method dispatch) |
| this | 0x2D38 | R | — | parameter value passed to audio stream device activation call |
| this | 0x2D3C | RW | 1 | boolean: audio stream active flag (set to 1 after stream activation) |

**Written-by note (persistence):**
- this 0x24A0: written once on open — external poke survives until next open/close
- this 0x24A4: written once on open — external poke survives until next open/close
- this 0x24B0: written once on open — external poke survives until next open/close
- this 0x24EC: written once on open (set to 1) — persists as player-active sentinel; survives external poke
- this 0x2D3C: written once on open (set to 1) — persists as stream-active sentinel; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005da564 | aSDS_0 | R | sSDS_Format [DERIVED] |
| 005da574 | aDDevAudiodevSh | R | AudioDevicePath [DERIVED] |
| 005da5e0 | aAudioAssert | R | StrAudioAssert [DERIVED] |
| 005da698 | aCmpegfileplaye_1 | R | CmpegfileplayeString [DERIVED] |
| 005da6c4 | aCmpegfileplaye_0 | R | Str_CMPEGFilePlaye [DERIVED] |
| 005da714 | off_5DA714 | R | AssertHaltFuncPtr [DERIVED] |
| 005da718 | off_5DA718 | R | FileStreamVTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052da10 | sub_52DA10 | initialize MPEG player internal state / reset buffers |
| 0052de40 | ArithmeticComparison_de40 | compare file format magic (byte-swapped) against expected value |
| 0052de60 | AudioNetworkBufferTimingCalc | compute audio network buffer timing parameters |
| 0052e080 | F_64BitIntegerDivision | 64-bit integer division for buffer size computation |
| 0052e2f0 | LapPerformanceStateReset | reset lap performance tracking state |
| 0052e320 | DeferredDeactivation | deactivate previously active player before re-opening |
| 0052e4e0 | sub_52E4E0 | unknown (called during player state init chain) |
| 0052e520 | HaltAssertHandler | assertion failure handler (halts on invalid format/magic) |

**Guard conditions:** Player-active sentinel (this+0x24EC): if already set, triggers DeferredDeactivation before continuing — BLOCKS double-open. File format validation (a2): if a2 != 0, byte-swaps and compares against expected magic via ArithmeticComparison_de40 — mismatch BLOCKS with assert + return -1. Null-magic path: if a2 == 0, calls virtual method at this+0xC — non-zero return BLOCKS with assert + return -1. Both failure paths return -1; success path returns 0 after stream activation.