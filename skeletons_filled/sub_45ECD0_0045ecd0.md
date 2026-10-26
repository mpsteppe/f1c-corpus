## sub_45ECD0_0045ecd0 — AutoChatSpeechDataLoader

**Summary:** Loads auto-chat speech audio data from an audio stream file. Scans for labeled sections (autochat01 through autochat10), loads each matching section's name string, and builds a linked list of up to 10 autochat entries stored on the manager object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionTypeSetter (00463f70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1B780) | 0x0 | R | — | DWORD flags/active check in linked list node (node->flags at offset 8 of node struct) |
| *(this+0x1B784) | 0x4 | R | — | Next pointer in linked list traversal (node->next at offset 4 of node struct) |
| this | 0x1B780 | RW | 0 | Head pointer of autochat linked list (this[28128]) |
| this | 0x1B784 | RW | 0 | Tail pointer of autochat linked list (this[28129]) |
| this | 0x1B788 | RW | 0 | First-inserted node backup / tail copy (this[28130]) |
| this | 0x1B78C | RW | 0 | Autochat entry count (this[28131]) |

**Written-by note (persistence):**
- this 0x1B780: Once per call — old list freed then rebuilt from scratch. External poke does NOT survive re-call.
- this 0x1B784: Once per call — cleared then rebuilt. External poke does NOT survive re-call.
- this 0x1B788: Once per call — set during first insertion. External poke does NOT survive re-call.
- this 0x1B78C: Once per call — reset to 0 then incremented. External poke does NOT survive re-call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5de8 | aAutochat10 | R | AutoChat10String [DERIVED] |
| 005c5df4 | aAutochat09 | R | Autochat09Field [DERIVED] |
| 005c5e00 | aAutochat08 | R | Format_AutoChat [DERIVED] |
| 005c5e0c | aAutochat07 | R | String_AutoChat [DERIVED] |
| 005c5e18 | aAutochat06 | R | AutoChat06String [DERIVED] |
| 005c5e24 | aAutochat05 | R | Autochat05String [DERIVED] |
| 005c5e30 | aAutochat04 | R | AutoChatString [DERIVED] |
| 005c5e3c | aAutochat03 | R | String_AutoChat [DERIVED] |
| 005c5e48 | aAutochat02 | R | s_AutoChat02 [DERIVED] |
| 005c5e54 | aAutochat01 | R | AutoChat01 [DERIVED] |
| 005c5e60 | dword_5C5E60 | R | MenuResourcePtr [DERIVED] |
| 005c5e64 | dword_5C5E64 | R | Int_RenderState_5E64 [DERIVED] |
| 005c5e68 | dword_5C5E68 | R | Unknown_Renderer_5C5E68 [DERIVED] |
| 005c5e6c | dword_5C5E6C | R | Unknown_Dword_5C5E6C [DERIVED] |
| 005c5e70 | word_5C5E70 | R | Word_UIDataBuffer [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0220 | PathTruncationUtility | Truncate a path string to its directory portion (strip filename) |
| 005651b0 | sub_5651B0 | Check whether current audio chunk is of a type that should be skipped |
| 005654a0 | sub_5654A0 | Match current chunk label against an autochat name string (autochat01–10) |
| 00566650 | StringCopyWithBufferRealloc | Copy matched label string into a managed heap buffer for the list node |
| 005668b0 | ZeroInitSmallStruct | Zero-initialize the audio file handle/context struct (v14) |
| 005668d0 | SubCallWithConditionalFieldFree | Conditionally free a field in v14 and return final status |
| 00566b20 | AudioStreamOpen | Open an audio stream file from the constructed path for reading |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | Close the audio stream file handle if opened |
| 00566cc0 | ConditionalDispatchBasedOnFlag | Read next chunk from the open audio stream into v24 buffer |
| 00587bcf | FreeWrapper_7bcf | Free allocated memory with null-check |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate memory (operator new wrapper) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1B78C | >= | 10 | Autochat entry count — stops scanning after 10 entries loaded |

**Guard interpretation:** Loop termination guard: when the autochat entry count (this[28131]) reaches or exceeds 10, the while loop breaks. This limits the loaded autochat entries to a maximum of 10, even if more matching sections exist in the audio file. PASSES (loop continues): count < 10. BLOCKED (breaks out): count >= 10.
