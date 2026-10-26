## MemoryCopy_cc00_0058cc00 — Optimized memcpy With Overlap Handling

**Summary:** Custom memcpy implementation with source/destination overlap detection and backward-copy fallback. Uses DWORD-aligned bulk copy with Duff's device-style switch fall-through for remainder bytes, providing optimized memory block transfer.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_58806E (0058806e), sub_5886A7 (005886a7), sub_588C7A (00588c7a), sub_588E4E (00588e4e), sub_58B5D4 (0058b5d4), sub_592DFA (00592dfa), InputStreamReadWithBufferedFill (00598cf9), OutputStreamWriteWithBufferFlushAbstraction (00598d6d), sub_5990AE (005990ae), BufferWriteWithNullTerminate (00599615), BufferAllocationWithSizeRounding (0059964a), sub_59A103 (0059a103), sub_59A9CA (0059a9ca)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | destination byte 0 (first byte of copy target) |
| this | 0x1 | RW | — | destination byte 1 (second byte in remainder copy) |
| this | 0x2 | RW | — | destination byte 2 (third byte in remainder copy) |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x1: recalc every frame — external poke does NOT persist
- this 0x2: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0058cc60 | byte_58CC60 | R | jump table entry for unaligned copy path dispatch |
| 0058cc70 | loc_58CC70 | R | code location: unaligned copy loop body |
| 0058cc9c | loc_58CC9C | R | code location: aligned DWORD copy entry point |
| 0058ccc0 | loc_58CCC0 | R | code location: copy completion/return |
| 0058ccdc | jpt_58CC5C | R | jump table base for alignment-dispatch on forward copy |
| 0058ccfc | loc_58CCFC | R | code location: Duff's device case for size-7 pre-loop |
| 0058cd04 | loc_58CD04 | R | code location: Duff's device case for size-6 |
| 0058cd0c | loc_58CD0C | R | code location: Duff's device case for size-5 |
| 0058cd14 | loc_58CD14 | R | code location: Duff's device case for size-4 |
| 0058cd1c | loc_58CD1C | R | code location: Duff's device case for size-3 |
| 0058cd24 | loc_58CD24 | R | code location: Duff's device case for size-2 |
| 0058cd2c | loc_58CD2C | R | code location: Duff's device case for size-1 |
| 0058cd3f | loc_58CD3F | R | code location: case-0 return path |
| 0058cd48 | jpt_58CC35 | R | jump table base for remainder-byte dispatch |
| 0058cd58 | loc_58CD58 | R | code location: remainder-byte case 0 |
| 0058cd60 | loc_58CD60 | R | code location: remainder-byte case 1 |
| 0058cd6c | loc_58CD6C | R | code location: remainder-byte case 2 |
| 0058cd80 | loc_58CD80 | R | code location: remainder-byte case 3 |
| 0058cde8 | byte_58CDE8 | R | jump table entry for backward-copy size dispatch |
| 0058cdf8 | byte_58CDF8 | R | jump table entry for overlap-reversal path |
| 0058ce90 | jpt_58CDC2 | R | jump table base for backward-copy remainder dispatch |
| 0058ce94 | loc_58CE94 | R | code location: backward remainder case 0 |
| 0058ce9c | loc_58CE9C | R | code location: backward remainder case 1 |
| 0058cea4 | loc_58CEA4 | R | code location: backward remainder case 2 |
| 0058ceac | loc_58CEAC | R | code location: backward remainder case 3 |
| 0058ceb4 | loc_58CEB4 | R | code location: backward DWORD loop body |
| 0058cebc | loc_58CEBC | R | code location: backward copy loop entry |
| 0058cec4 | loc_58CEC4 | R | code location: backward copy return |
| 0058ced7 | loc_58CED7 | R | code location: backward remainder byte cleanup |
| 0058cee0 | jpt_58CDE4 | R | jump table base for overlap-size dispatch |
| 0058cef0 | loc_58CEF0 | R | code location: overlap remainder case 3 |
| 0058cef8 | loc_58CEF8 | R | code location: overlap remainder case 2 |
| 0058cf08 | loc_58CF08 | R | code location: overlap remainder case 1 |
| 0058cf1c | loc_58CF1C | R | code location: overlap remainder case 0 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** from code — field, checked values, what PASSES vs what is BLOCKED
- **Overlap detection:** `a1 > (unsigned int)a2 && a1 < (unsigned int)&a2[a3]` — if destination overlaps source AND destination address is greater than source (forward overlap), PASSES: backward copy path used to avoid corruption. If no overlap or destination before source, BLOCKED: backward path skipped, forward copy used.
- **Alignment check:** `(a1 & 3) != 0` — if destination address is not DWORD-aligned, PASSES: alignment-specific jump table dispatch handles misaligned lead-in bytes. If aligned, BLOCKED: straight to bulk DWORD copy.
- **Size threshold for DWORD divide:** `a3 >> 2` (size in DWORDs) — used in switch statement. If >= 8 DWORDs, uses loop-based bulk copy. If < 8, uses Duff's device fall-through with switch-based dispatch. Both paths PASS (always copies), just use different optimization strategies.
- **Backward copy size:** `(v8 & 3) == 0` — if (dest + size - 4) is DWORD-aligned, PASSES: aligned backward DWORD loop. Otherwise BLOCKED: falls through to byte-by-byte backward copy via switch on `a3`.
