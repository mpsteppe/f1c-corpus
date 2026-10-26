## sub_4CADA0_004cada0 — BlendModeStringToEnum

**Summary:** Converts a blend mode string to a D3DBLEND enum value (1=ZERO, 2=ONE, 3=SRCCOLOR, etc.). Logs unknown blend mode warning via DebugLogWrite if unmatched. Called from material/reaction effect parser.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MaterialShaderReactionEffectParser (004ca480)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d3624 | aDDevF119992002_25 | R | SourcePath_25 [DERIVED] |
| 005d36e4 | aUnknownBlendMo | R | UnknownBlendModeString [DERIVED] |
| 005d370c | aInvdstalpha | R | InverseDestAlphaString [DERIVED] |
| 005d3718 | aDstalpha | R | DstalphaString [DERIVED] |
| 005d3724 | aInvdstcolor | R | InvdstcolorString [DERIVED] |
| 005d3730 | aDstcolor | R | Str_DstColor [DERIVED] |
| 005d373c | aInvsrcalpha | R | StringInvSrcAlpha [DERIVED] |
| 005d3748 | aSrcalpha | R | SrcalphaString [DERIVED] |
| 005d3754 | aInvsrccolor | R | InvSrcColorString [DERIVED] |
| 005d3760 | aSrccolor | R | SrcColorString [DERIVED] |
| 005d376c | aOne | R | OneStr [DERIVED] |
| 005d3770 | aZero | R | ZeroString [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | String tokenization/parsing helper for detecting unknown blend mode |
| 004d7aa0 | DebugLogWrite | Writes blend mode name to debug log when mode is unrecognized |
| 00588410 | sub_588410 | String comparison/hash lookup against known blend mode names |

**Guard conditions:** Entry gate: calls sub_588410 with `aZero` string — if it returns false (string not recognized as valid blend mode), returns 1 (D3DBLEND_ZERO) immediately. Otherwise cascades through remaining mode names to find specific match.
