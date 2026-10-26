## sub_47DAF0_0047daf0 — ReplayControlsMenuInit

**Summary:** Initializes replay/VCR playback control menu object; when mode parameter is 480 (0x1E0), populates a linked list with playback command strings (play, stop, scan, bookmark, etc.).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5A6B20 |
| this | 0xEC | RW | — | mode selector (480 = populate replay controls; other values skip) |

**Written-by note (persistence):**
- this 0x0: written once on construction; persists for object lifetime
- this 0xEC: set from parameter a2; controls which control set gets populated

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a6b20 | off_5A6B20 | R | off_5A6B20 [DERIVED] — vtable pointer for replay controls object |
| 005c72dc | aRemoveBookmark | R | Str_RemoveBookmark [DERIVED] — "Remove Bookmark" menu command string |
| 005c72ec | aDropBookmark | R | StringDropBookmark [DERIVED] — "Drop Bookmark" menu command string |
| 005c72fc | aForwardScanFas | R | ForwardScanFastString [DERIVED] — "Forward Scan Fast" menu command string |
| 005c7310 | aForwardScan | R | ForwardScanString [DERIVED] — "Forward Scan" menu command string |
| 005c7320 | aPlay | R | PlayString [DERIVED] — "Play" menu command string |
| 005c7328 | aStop | R | StopCmdString [DERIVED] — "Stop" menu command string |
| 005c7330 | aPlaybackwards | R | PlayBackwardsString [DERIVED] — "Play Backwards" menu command string |
| 005c7340 | aReverseScan | R | ReverseScanField [DERIVED] — "Reverse Scan" menu command string |
| 005c7350 | aReverseScanFas | R | UI_ReverseScanFast [DERIVED] — "Reverse Scan Fast" menu command string |
| 005c7364 | off_5C7364 | R | VTablePtr_5C7364 [DERIVED] — playback speed/frame-step command |
| 005c7368 | aBegin | R | BeginString [DERIVED] — "Begin" / go-to-start command string |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486f30 | LinkedListInsertWithNodeAllocation | insert a playback command string into the control list |
| 00488b00 | ConstructorInitVTable | base object constructor with vtable and sentinel value -1 |

**Guard conditions:** If a2 == 480 (0x1E0): populates full control list; any other value: skips list population, returns immediately.
