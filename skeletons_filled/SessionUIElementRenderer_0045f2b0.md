## SessionUIElementRenderer_0045f2b0 — NetworkUIElementEncodeSend

**Summary:** Encodes a UI element from session data (including variable-length payload for multiplayer), attaches it to a COM object, and dispatches it over the network. Called by UI update for session element rendering.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkUIUpdate (00462848)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3FB8 | R | — | COM interface pointer used for creating/sending UI element object |
| this | 0x3FD9 | R | — | UI element data byte count (only valid when session type == 7) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] — 7 indicates multiplayer session |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] — current session time for progress bar encoding |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b33b0 | ProgressBarEventEncode | Encode progress bar/session event with type 4, subtype 2 |
| 0057a680 | COMVTableCallVia0x60 | Create UI element object via COM vtable method at offset 0x60 |
| 0057a690 | VirtualMethodDispatch | Dispatch virtual method on the COM object |
| 0057a6a0 | NetworkSendDispatch | Send UI element data over network |

**Guard conditions:**
- dword_7C56A4 (SessionType) == 7 → read byte count from this+0x3FD9, copy data from this+0x3FDA (up to ~420 bytes).
- dword_7C56A4 != 7 → byte count = 0, data size = 1 (minimal payload).
- Always encodes progress bar event with session time.
- a2 == -1 → set v4[4] = 1 (flag on created object).
- a2 != -1 → call vtable method at offset 12 on created object with a2 as argument.
