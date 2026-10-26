## UIMessageDispatch_00494f10 — Dispatch UI message with optional string table lookup

**Summary:** Dispatches a UI message via sub_53D2E0. When a6 flag is set, looks up the message string in a binary string table (byte_5EC4C0) and copies the translated/buffered version to byte_5EC4CC before dispatch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MediaBufferPlaybackManager (0048d9d0), UITextDialogRendering (00495bd0), sub_496E90 (00496e90), BitmapDraw (004980d0), BitmapDraw_81f0 (004981f0), BitmapDrawWithAlpha (004982c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | Looks up message string in binary string table for translation |
| 0053d2e0 | sub_53D2E0 | Dispatches/processes the UI message |

**Guard conditions:** If a6 flag is zero, skips string table lookup entirely and dispatches original message directly. If BinarySearchInStringTable returns 0 (string not found in table), message is still dispatched using original string (not copied to buffer). If a2 is null, buffer is emptied (null-terminated to empty string).
