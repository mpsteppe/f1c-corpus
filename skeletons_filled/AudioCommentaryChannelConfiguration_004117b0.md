## AudioCommentaryChannelConfiguration_004117b0 — CommentaryChannelParamLookup

**Summary:** Returns audio commentary channel configuration parameters based on channel index. Channel 0 returns default commentary values (2 DWORDs + 2 pointers). Channel 1 returns TV commentary values. Invalid index (>1) returns 1 (error). Used to configure commentary audio output settings.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneGraphQuery (004116c0), GlobalVTableDispatchWithQuery (00411740)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005bf8c8 | dword_5BF8C8 | R | AudioDefaultFieldValue [DERIVED] — default commentary value DWORD 0 |
| 005bf8cc | dword_5BF8CC | R | AudioAltFieldValue [DERIVED] — default commentary value DWORD 1 |
| 005bf8d0 | dword_5BF8D0 | R | AudioCommentaryTvValue1 [DERIVED] — TV commentary value DWORD 0 |
| 005bf8d4 | dword_5BF8D4 | R | AudioCommentaryTvValue2 [DERIVED] — TV commentary value DWORD 1 |
| 005bf8d8 | off_5BF8D8 | R | AudioCommentaryPwsPtr [DERIVED] — default commentary pointer to PWS resource |
| 005bf8e0 | off_5BF8E0 | R | Ptr_s_Audio_Commentary_Pws [DERIVED] — default commentary second pointer |
| 005bf8e8 | off_5BF8E8 | R | AudioCommentaryTvPtr [DERIVED] — TV commentary pointer to PWS resource |
| 005bf8f0 | off_5BF8F0 | R | CommentaryAudioPtr_Tv [DERIVED] — TV commentary second pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if a1 > 1 → return 1 (invalid channel). If a1 == 0 → default params. If a1 == 1 → TV params.
