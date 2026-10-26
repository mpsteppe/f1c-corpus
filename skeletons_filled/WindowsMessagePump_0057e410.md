## WindowsMessagePump_0057e410 — StandardMessageLoop

**Summary:** Standard Windows message pump: PeekMessage → GetMessage → TranslateMessage → DispatchMessage loop. Processes available window messages until WM_QUIT or no messages remain. Returns result from last PeekMessage/GetMessage call.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e25c | PeekMessageA | R | user32 import — check message queue without blocking |
| 0059e260 | GetMessageA | R | user32 import — retrieve message from queue |
| 0059e264 | TranslateMessage | R | user32 import — translate virtual-key messages |
| 0059e268 | DispatchMessageA | R | user32 import — dispatch message to window procedure |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Entry condition: PeekMessageA must return non-zero (message available in queue). If no messages pending, function returns immediately.
