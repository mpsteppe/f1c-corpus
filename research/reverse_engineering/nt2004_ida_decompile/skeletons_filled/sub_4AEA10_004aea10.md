## sub_4AEA10_004aea10 — ReplaySaveLoadScreen

**Summary:** Displays the replay save/load UI screen — renders a loading animation with fade-in effect while fetching replay data, or shows the saved replay thumbnail/text. Manages replay file loading and presentation.

**Called by:** sub_4AD050 (004ad050), sub_4BA730 (004ba730)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x16C) | 0x10 | R | — | Replay texture/image pointer (non-null check before rendering fallback animation) |
| this | 0x16C | R | — | Pointer to replay-UI object holding the replay thumbnail/texture surface |
| this | 0x494 | RW | 0 | Active/in-progress flag: 1 while screen is loading/displaying, 0 when done or aborted |

**Written-by note (persistence):**
- this 0x494: written once per invocation (set to 1 at entry, 0 at exit). An external poke to 0 would force early return on next call; poke to 1 would be overwritten on next call since the guard checks the value first.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54dc | flt_5D54DC | R | Float constant used in render calls (likely color/intensity) |
| 005d54e0 | flt_5D54E0 | R | Float constant used in render calls |
| 005d5580 | flt_5D5580 | R | Float constant used in render calls |
| 005d6498 | flt_5D6498 | R | Float constant used in render calls |
| 005ea25c | flt_5EA25C | R | Float constant used in render calls |
| 005ea260 | flt_5EA260 | R | Float constant used in render calls |
| 005fb7e8 | Format | R | Format string `%s%s` for path concatenation |
| 00601114 | aOptionsMas | R | String `Options.mas` — settings/config filename |
| 00608ff0 | a2003euro24 | R | String `2003Euro24` — font or style resource name |
| 00608ffc | aSavingreplay00 | R | String `Savingreplay0000.tga` — replay thumbnail/screenshot filename |
| 006152e8 | dword_6152E8 | R | Screen width (used to center replay display) |
| 006152ec | dword_6152EC | R | Screen height (used to center replay display) |
| 00629120 | byte_629120 | R | First byte used as path prefix when dword_62A098 is null |
| 0062a098 | dword_62A098 | R | Pointer to base game directory string (for building full paths) |
| 00765b00 | unk_765B00 | R | Format string for `%s%s` |
| 007d4458 | byte_7D4458 | R | Unknown global flag |
| 007da988 | dword_7DA988 | R | Handle/context for config file parsing (passed to sub_5924D0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004aaf50 | sub_4AAF50 | Render filled rectangle/sprite at given position with size and color |
| 004ab0e0 | sub_4AB0E0 | Render rectangle during loading animation fade-in |
| 004ab400 | sub_4AB400 | Present/flip rendered frame to screen |
| 004ab570 | sub_4AB570 | Acquire render-device context handle |
| 004ad050 | sub_4AD050 | Check replay-loading state; returns -1 when load fails |
| 004ad970 | sub_4AD970 | Load/create a texture resource from file (e.g. Savingreplay0000.tga) |
| 004b07c0 | sub_4B07C0 | Retrieve child object from loaded resource (gets replay thumbnail texture) |
| 004cf510 | nullsub_6 | No-op/cleanup stub |
| 004d20d0 | sub_4D20D0 | Play sound effect (fade/transition sound) |
| 00505d00 | sub_505D00 | Render text string centered on screen with given font and formatting |
| 0057b5d0 | StructZeroInit_8ba0 [exact] | Zero-initialize high-precision timer structure |
| 0057b610 | QPCTimerInitialization [exact] | Initialize QueryPerformanceCounter timer |
| 0057b690 | TimerResetUsingQueryPerformanceCounter [exact] | Reset the QPC timer to zero |
| 0057b7c0 | sub_57B7C0 | Read elapsed time from QPC timer |
| 005924d0 | sub_5924D0 | Load/parse settings/config file (Options.mas) |
| 00592750 | sub_592750 | Free/release config file resource |
| 00592cd0 | F_3DVectorBlend [structural] | Look up named resource/font by string identifier |
| 005a3ff0 | sub_5A3FF0 | Final render of text/replay data onto screen after loading complete |
| 005a41f0 | sub_5A41F0 | Measure text dimensions (width, height) for centering |
| 005be8bc | __ftol | Float-to-long conversion (used in animation math) |
| 005beab0 | _strncpy | Copy Source filename into local buffer |
| 005beec8 | _sprintf | Build full path string by concatenating directory + filename |

**Guard conditions:** `this[0x494]` (byte at offset 1172) checked at entry. If non-zero (already active), function returns immediately (prevents reentrant calls). If zero, sets to 1 and proceeds. Additionally, if `Source` is NULL or empty string, or if `!a3` and replay load check returns -1, jumps to cleanup (sets flag back to 0 and returns).

**String literals referenced (deterministic):**

- `%s%s`
- `Options.mas`
- `2003Euro24`
- `Savingreplay0000.tga`
- `Savingreplay0000.tga`
