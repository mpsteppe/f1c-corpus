## FilePathNameLookup_005622c0 — PacketFileSystemDispatch

**Summary:** Dispatch incoming network packet or file path request. If packet starts with ';' (ASCII 59), call vtable function pointer at this[63]. Otherwise iterate through scene file data pointer table, call sub_562530 for each, and accumulate result strings through case-based buffer init routines.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkPacketReceive (00561e30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Socket or network context pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0056250c | jpt_562391 | R | Jump table for dispatch cases |
| 005e4cd4 | off_5E4CD4 | R | SceneFileDataPtr [DERIVED] |
| 005e4dfc | off_5E4DFC | R | NetworkSocketPtr [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00562530 | sub_562530 | Lookup file path by name |
| 00562610 | sub_562610 | File/buffer operation |
| 005626b0 | StackBufferZeroInitWithCallback | Zero-init stack buffer with callback |
| 00562830 | StackBufferZeroInitWithVTableCall | Zero-init stack buffer with vtable call |
| 00562890 | BufferZeroInitWithVirtualMethodCall | Zero-init stack buffer with virtual method call |
| 005628f0 | LargeStackStructZeroInitWithVtableCall | Zero-init large stack struct with vtable call |
| 00562950 | sub_562950 | Process matched file path result |
| 005629b0 | sub_5629B0 | Finalize/compose output from accumulated buffers |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 59 (';') | First byte of data: if ';', use direct vtable dispatch path; else use iterative file lookup path |

**Guard interpretation:** When data[0] == ';' (59 decimal), the function calls a vtable-based handler directly (bytecode/command path). Otherwise it iterates scene file data pointers, building responses via sub_562530 and buffer init functions.
