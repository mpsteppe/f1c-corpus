## UITextFieldInitialization_00470300 — UITextFieldTypeBasedInit

**Summary:** Initializes a UI text field based on type selector at offset 0x304 (values 0x1AF-0x1B5): selects and associates a track DB buffer (track DB byte, track DB buffer, multiplayer password, track data, or track name), sets string pointer at 0x2FC to a placeholder, and configures mode flag at 0x2E8. Configures text field for different track-related inputs.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE5 | RW | 1 | byte flag set to 1 for password-mask case (0x1B3) |
| this | 0x2E8 | RW | 0 | mode/state field set per type (0 or 2 for track data) |
| this | 0x2FC | RW | — | string pointer set to placeholder text (password mask string) |
| this | 0x304 | R | — | type selector read to select initialization branch |

**Written-by note (persistence):**
- this 0xE5: set to 1 in case 0x1B3; otherwise unchanged (init value 1 persists)
- this 0x2E8: set per case (0 or 2); overwritten each call
- this 0x2FC: set to placeholder string in cases 0x1AF/0x1B0; otherwise unchanged

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004703e0 | jpt_470317 | R | jump table for switch on type selector |
| 005c6e2c | aWwwwwwwwwwwwww | R | placeholder/mask string for password text field type 0x1AF |
| 005c6e40 | aWwwwwwwwwwwwww_0 | R | placeholder/mask string for password text field type 0x1B0 |
| 007cd818 | byte_7CD818 | RW | TrackDB_Byte_7CD818 [DERIVED] — buffer for type 0x1AF |
| 007cd834 | byte_7CD834 | RW | TrackDB_Buffer_7CD834 [DERIVED] — buffer for type 0x1B0 |
| 007cd850 | byte_7CD850 | RW | MultiClientPassword [DERIVED] — buffer for type 0x1B1 |
| 007cd860 | unk_7CD860 | R | TrackDataBuffer [DERIVED] — buffer for type 0x1B2 |
| 007cd880 | byte_7CD880 | RW | TrackNameBuffer [DERIVED] — buffer for type 0x1B5 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048b7e0 | UtilityFunction_b7e0 | associate text field with a buffer (length varies: 15, 26, or 32) |
| 0048b8f0 | BoundedFieldSetter | set bounded field value (called with 0xA0=160 for type 0x1B3) |

**Guard conditions:** Switch on value at this+0x304: cases 0x1AF (431) through 0x1B5 (437) each handle a specific track DB buffer type; all cases fall through to return 0. Default also returns 0.
