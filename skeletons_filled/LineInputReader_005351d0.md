## LineInputReader_005351d0 — Line-input reader from buffered file

**Summary:** Reads characters from a buffered file stream into buffer `a2` until newline (0x0A) or max length `a3`, null-terminates the string, returns pointer to buffer. Returns 0 if no characters read. File I/O / text parsing system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_423890 (00423890), sub_491FB0 (00491fb0), SceneFileTEAMDIRVEHDIRNOTSPINWriter (004ddf90), PerWheelBrakeSuspensionDataLoader (004f2c60), FenderAeroSetupSectionReader (004f3090), TheSvmHdvVehicleFileParser (004f4270), ConditionalDispatchBasedOnFlag (00566cc0), VehiclePhysicsJointSystemLoader (0056d930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | File context handle passed to BufferedFileReader |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00534f90 | BufferedFileReader | Read one byte from buffered file stream into buffer |

**Guard conditions:** If `a2` (output buffer) is NULL → return 0. If `a3 <= 0` (max length) → return 0. Loop exits when: buffer full (`--v6 <= 0`), read fails (< 1 byte), or character read is newline (0x0A). If `a2 == v3` (no bytes written) AND `v6 > 0` (not from max length) → return 0. Otherwise return `a2` (pointer to populated string).
