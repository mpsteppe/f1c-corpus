## SwitchBasedGlobalLookup_004d7fa0 — SwitchBasedGlobalLookup

**Summary:** Simple selector-to-pointer lookup: returns one of 4 global resource/context pointers indexed by input (1→dword_8AD38C, 2→dword_8AD390, 3→dword_8AD394, default→dword_8AD388). Used by UI text rendering to select render context.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UITextRenderWithScale (004d7e40), CenteredPosition (004d7f20), SizeComputationWithSubtraction (004d7f60), DrawYellowTextAtFixedScreenPosition (004dc250)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004d7fd0 | jpt_4D7FA9 | R | jump table for switch statement |
| 008ad388 | dword_8AD388 | R | default/fallback resource handle (File_MusicTrackPtr) |
| 008ad38c | dword_8AD38C | R | resource handle for selector 1 |
| 008ad390 | dword_8AD390 | R | resource handle for selector 2 (AudioHandleArray) |
| 008ad394 | dword_8AD394 | R | resource handle for selector 3 (AudioEmitter3) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — all switch cases covered, no validation or null check.
