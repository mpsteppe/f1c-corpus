## EngineTemperatureDebugDisplay_00470400 — ConfigFileDebugDisplayUpdater

**Summary:** Conditional debug display update: if type selector at offset 0x304 is 435 (0x1B3) and session state check passes, constructs a file path from default directory (byte_5EA438), formats a debug string, and sets a bounded field based on string length. Likely shows config file info on a debug screen.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x304 | R | — | type selector, compared to 435 (0x1B3) for guard |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory path [DERIVED] — first byte read for path construction |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] — passed to SessionStateCheckWrapper |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045bc10 | StringFormatWrapper | formatted string construction |
| 00461db0 | SessionStateCheckWrapper | check if session state allows debug display |
| 0048b8f0 | BoundedFieldSetter | set bounded field with (159 - strlen) |
| 004b0b20 | sub_4B0B20 | file/directory path operation (reads config from app dir) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x304 | == | 435 | type selector for this debug display branch |

**Guard interpretation:** Two guards must both pass: (1) this[193] at offset 0x304 must equal 435 (0x1B3), and (2) SessionStateCheckWrapper(dword_7CD25C) must return non-zero. If either fails, function returns immediately with no action.
