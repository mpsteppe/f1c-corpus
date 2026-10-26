## PairArrayLinearSearch_00424e30 — PairArrayLinearSearch

**Summary:** Linear search for a duplicate command ID in the AI command queue. Iterates 8-byte {cmd, param} pairs in the queue buffer. Returns 1 if command ID a2 already exists, 0 if not found. Called by CommandQueueResponseHandler for deduplication.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CommandQueueResponseHandler (00429ee0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x44A8 | R | — | pointer to command queue array (8-byte {cmdID, param} pairs) |
| this | 0x44B0 | R | — | current queue index (number of entries to search) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If this[0x44B0] (queue index) < 0, returns 0 immediately (queue empty, no duplicate possible).
