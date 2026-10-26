## sub_587ECE_00587ece — WhitespaceSkipAndStringToInt

**Summary:** Skips whitespace characters (tab/space category 8), then parses a decimal integer with optional sign prefix, returning the signed integer value.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** RaceCommentaryDirectorSystem (0040d4c0), DirectoryStringProcessingWithDecode (00461ed0), NetCommParseCommandLine (00463160), MultiplayerPasswordValidation (0046dd30), DeferredTextureObjectLoader (0046e1b0), UIListManagementHandler (0048a3c0), sub_493990 (00493990), ObjectHandleReader (004a1990), sub_4B1190 (004b1190), CareerStandingsStateLoader (004c03f0), SeasonScoring (004c0910), CareerSeasonStateFileReader (004c0b70), SessionConfigReader (004c11e0), SeasonScoringInfoUpdater (004c2a80), CompositeStringCompare (004c3890), ShortStringSet (004c69b0), MaterialShaderReactionEffectParser (004ca480), Steward_Restart (004d3cf0), TheSvmHdvVehicleFileParser (004f4270), sub_4FE350 (004fe350), sub_57CA10 (0057ca10), SingleFunctionCallWrapper_7f59 (00587f59), sub_5903DA (005903da), sub_5921F3 (005921f3)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Input string pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e69c8 | off_5E69C8 | R | CharTypeTable [DERIVED] |
| 005e6bd4 | cbMultiByte | R | CharTypeTableVersion [DERIVED] (also: CharTypeTableVersion (docs/08, 12, 20) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058c674 | CharacterEncodingConvertViaLookupTableFallback | Character type classification with encoding fallback |

**Guard conditions:** No early return guard. Always processes input string. Whitespace skip loop (category 8 test) and digit parse loop (category 4 test) run until non-matching character. Sign detection (0x2D='-', 0x2B='+') handled before digit loop.
