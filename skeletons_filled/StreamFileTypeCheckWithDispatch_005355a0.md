## StreamFileTypeCheckWithDispatch_005355a0 — Stream file close with write flush

**Summary:** Closes a file stream: if mode is 'w' (write), flushes remaining buffered data via FileReadLoop, copies state, then calls FileHandleDestructorWithModeCheck for cleanup. File I/O system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_423890 (00423890), TripleFieldCleanup (00491f60), SceneFileTEAMDIRVEHDIRNOTSPINWriter (004ddf90), TheSvmHdvVehicleFileParser (004f4270), ConditionalFileHandleCloseWithFlagDispatch (00566b90), VehiclePhysicsJointSystemLoader (0056d930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | Target buffer pointer (this[2]); pSrc for copy in write mode |
| this | 0x40 | R | — | File handle for read (this[16]) |
| this | 0x4C | R | — | Compressed data size field (this[19]) |
| this | 0x5C | R | — | Mode byte at offset +92: checked against 'w' (119) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005352d0 | FileReadLoop | Flush remaining buffered data before close |
| 005355f0 | ArithmeticComparison_55f0 | Copy/sync remaining byte count between buffers |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x5C | == | 119 | Mode byte at +92: 'w' (write mode) triggers flush path |

**Guard interpretation:** If `this` is NULL → return -2. If mode == 'w' (119) AND FileReadLoop succeeds → perform ArithmeticComparison_55f0 twice (sync remaining data). Then always call FileHandleDestructorWithModeCheck for final cleanup. Mode != 'w' bypasses flush logic entirely.
