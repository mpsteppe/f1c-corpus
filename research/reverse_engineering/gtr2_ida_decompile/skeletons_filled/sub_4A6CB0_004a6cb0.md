## sub_4A6CB0_004a6cb0 — online chat-room join / lobby chat setup

**Summary:** Multiplayer (CINet) lobby chat routine: sends the window name as a chat line, builds a chat-room name from the selected game mode (MAIN-NOV / MAIN-SP / MAIN-SIM) plus the localized "NEWS_LANGUAGE" text, joins that chat room, assembles the "CHATBOX - ..." caption string, and, if the chat control is active, drains pending chat messages.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x30) | 0x1C | R | — | Vtable slot (offset 0x1C) of the UI control object reached through this[12]; virtual predicate invoked with control IDs 26 and 34 to test whether those controls are active |
| this | 0x30 | R | — | this[12] — pointer to the UI dialog/control object whose virtual slot at +0x1C is queried |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f138c | ?GetChatRoomMessage@CINet@@QAEXPAD@Z | R | CINet method (thunk pointer): fetches a chat-room message into the supplied buffer |
| 006f1390 | ?GetPendingChat@CINet@@QAEXXZ | R | CINet method: processes queued incoming chat |
| 006f13bc | ?JoinChatRoom@CINet@@QAEJPAD@Z | R | CINet method: joins the chat room named by the built string |
| 006f13c4 | ?ChatTo@CINet@@QAEXPAD@Z | R | CINet method: sends a chat line to the given target name |
| 006f16bc | WindowName | R | Chat target/window name string passed to ChatTo |
| 006f5848 | aNewsLanguage | R | "NEWS_LANGUAGE" locale key, looked up to obtain the local language display name |
| 006fbe80 | word_6FBE80 | R | Locale key string passed to the string lookup (sub_41D840) when completing the chatbox caption |
| 006fc0f4 | aChatbox | R | "CHATBOX - " prefix used to start the caption string |
| 006fef60 | word_6FEF60 | R | Literal-pool entry adjacent to the mode strings; exact use unknown |
| 006fef62 | byte_6FEF62 | R | Literal-pool entry adjacent to the mode strings; exact use unknown |
| 006fef64 | aSS_14 | R | Format-string fragment ("%s (%s)") used by sprintf to compose room name |
| 006fef6c | aMainNov | R | "MAIN-NOV" mode-name string (rookie/novice mode) |
| 006fef78 | aMainSp | R | "MAIN-SP" mode-name string |
| 006fef80 | aMainSim | R | "MAIN-SIM" mode-name string |
| 0091cc38 | byte_91CC38 | R | Language/localization lookup context passed to sub_41D840 |
| 00b6cbb0 | dword_B6CBB0 | R | Global CINet instance used as `this` for all chat operations |
| 00b71f90 | dword_B71F90 | R | Game-mode selector: 0 = MAIN-NOV, 1 = MAIN-SP, 2 = MAIN-SIM |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041d840 | sub_41D840 | Localized-string lookup by key (e.g. "NEWS_LANGUAGE", "CHATBOX - ") |
| 004d0ac0 | sub_4D0AC0 | Auxiliary routine invoked when the chat control (ID 34) is active |
| 00615860 | StringCopyWithBufferRealloc [structural] | Applies/stores the fully built caption string |
| 00631761 | _sprintf | Formats buffer strings: mode name, and "%s (%s)" room name |

**Guard conditions:** Two virtual guards on the control object `this[12]` (slot +0x1C). First call with **26**: if it returns 0, the whole chat-join path is skipped (early exit returning 0); if nonzero, room name is built and the room joined. Mode selection inside: `dword_B71F90 == 1` → "MAIN-SP"; `== 2` → "MAIN-SIM"; `== 0` → "MAIN-NOV"; any other value leaves `Buffer` unwritten. Second call with **34**: only when nonzero are sub_4D0AC0, GetChatRoomMessage and GetPendingChat executed. Return value is always 0.

**String literals referenced (deterministic):**

- `NEWS_LANGUAGE`
- `NEWS_LANGUAGE`
- `CHATBOX - `
- `%s (%s)`
- `MAIN-NOV`
- `MAIN-SP`
- `MAIN-SIM`
