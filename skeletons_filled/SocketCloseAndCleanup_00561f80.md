## SocketCloseAndCleanup_00561f80 — SocketCloseAndCleanup

**Summary:** Close primary and secondary sockets, reset handles to -1, clear flags. Optionally free socket struct if not the default singleton. Call WSACleanupThunk at the end.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BooleanFlagResetWithSideEffects (0045d240)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | -1 (0xFFFFFFFF) | Primary socket handle |
| this | 0x4 | RW | -1 (0xFFFFFFFF) | Secondary socket handle |
| this | 0xD8 | RW | 0 | Last activity timestamp (reset on close) |
| this | 0xE4 | R | — | Flag indicating socket is active (checked before closesocket) |

**Written-by note (persistence):**
- this 0x0: set to -1 after close; survives until next socket creation
- this 0x4: set to -1 after close; survives until next socket creation
- this 0xD8: reset to 0 after close; cleared on each close

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e4cf8 | unk_5E4CF8 | R | DefaultSocketStruct [DERIVED] |
| 005e4dfc | off_5E4DFC | R | NetworkSocketPtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058aa6f | sub_58AA6F | Free/release socket struct memory |
| 0059865a | closesocket | Close Windows socket handle |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | != | -1 (0xFFFFFFFF) | Socket is valid; skip closesocket if invalid |

**Guard interpretation:** Primary socket handle (this[0]) must not be -1 AND this[57] (active flag) must be non-zero for closesocket. Secondary socket (this[1]) closed if != -1 and != primary socket.
