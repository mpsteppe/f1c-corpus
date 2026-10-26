// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045ECD0
// Canonical corpus name: sub_45ECD0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_45ECD0_0045ecd0.c

void UnknownObject::AutoChatSpeechDataLoader()
{
    // Loads auto-chat speech data from an audio stream file into a manager-held linked list. Frees any existing autochat list, rebuilds the stream file name from the current directory plus a constant suffix, opens the stream, scans its chunks, and for each chunk whose label matches one of the autochat01..autochat10 strings builds a (label buffer, list node) pair appended to the list, stopping once 10 entries are stored. Called by SessionTypeSetter (00463F70).
    // LOOP: Free the existing autochat list: walk nodes from the head this+0x1B780; each node carries a data pointer at node+0 (freed once for the inner allocation and once for the buffer object) and a next pointer at node+4; every node allocation is freed after its payload [field:*(this+0x1B780):0x00000000, field:*(this+0x1B784):0x00000004, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Clear list state on the manager: head this+0x1B780, tail this+0x1B784, first-inserted backup this+0x1B788 and entry count this+0x1B78C are all reset to zero [field:this:0x0001B780, field:this:0x0001B784, field:this:0x0001B788, field:this:0x0001B78C]
    // ASSIGNMENT: Initialize the file-path buffer v25: first character copied from byte_5EA438, the remaining 0x1FC bytes zeroed, and the trailing word/byte v26/v27 zeroed [global:0x005EA438, source:raw]
    // CALL: ZeroInitSmallStruct(v14) seeds the stream-context struct; PathTruncationUtility(v25, 511) truncates the current application directory path to its directory portion [callee:0x005668B0, callee:0x004B0220]
    // CALCULATION: Append the constant audio file suffix held at dword_5C5E60..dword_5C5E6C and word_5C5E70 to the directory path in v25, composing the full stream file name [global:0x005C5E60, global:0x005C5E64, global:0x005C5E68, global:0x005C5E6C, global:0x005C5E70]
    // CALL: AudioStreamOpen(v25, 1) opens the constructed audio stream file; the entire load proceeds only when it returns non-zero [callee:0x00566B20]
    // LOOP: Scan loop: while ConditionalDispatchBasedOnFlag(v24, 384) reads the next chunk from the stream into v24, the chunk label is inspected and a matching chunk produces an autochat entry [callee:0x00566CC0]
    // CALL: sub_5651B0(v18) inspects the current chunk; a non-zero result marks the chunk as one to skip before any label matching [callee:0x005651B0]
    // GUARD: Match the current chunk label with sub_5654A0 against the autochat strings from autochat01 (0x005C5E54) through autochat10 (0x005C5DE8); a match selects this chunk for loading [callee:0x005654A0, global:0x005C5E54, global:0x005C5E48, global:0x005C5E3C, global:0x005C5E30, global:0x005C5E24, global:0x005C5E18, global:0x005C5E0C, global:0x005C5E00, global:0x005C5DF4, global:0x005C5DE8]
    // CALL: Build the string entry: OperatorNewNhMallocWrapper(8) allocates a two-dword object initialized to 0 and -1, then StringCopyWithBufferRealloc(v15) copies the matched label into the managed buffer [callee:0x00587C03, callee:0x00566650]
    // CALL: Build the list node: OperatorNewNhMallocWrapper(12) allocates a node whose dword 0 points to the string entry, dword 1 (next) is 0 and the byte at node+8 is set to 1 [callee:0x00587C03]
    // ASSIGNMENT: Append the node to the list: when the head this+0x1B780 is non-zero the previous tail this+0x1B784 is linked to the new node, otherwise the node becomes the head and first-inserted backup this+0x1B788; the tail is updated and the entry count this+0x1B78C incremented [field:this:0x0001B780, field:this:0x0001B784, field:this:0x0001B788, field:this:0x0001B78C]
    // GUARD: Stop scanning once the entry count this+0x1B78C reaches 10 (0xA), capping the loaded autochat list at ten entries [guard:0, field:this:0x0001B78C]
    // CALL: ConditionalFileHandleCloseWithFlagDispatch(v14) closes the opened audio stream when a handle was acquired [callee:0x00566B90]
    // RETURN: SubCallWithConditionalFieldFree(v14) conditionally frees a context field and supplies the function's final status value [callee:0x005668D0]

    // Conservative worker pseudocode:
    //   int AutoChatSpeechDataLoader(void* this) {
    //     node = this[0x1B780/4];
    //     while (node) { nxt = node[1]; if (node[2]) { Free(node[0]); } Free(node); node = nxt; }
    //     this[0x1B780/4] = 0; this[0x1B784/4] = 0; this[0x1B788/4] = 0; this[0x1B78C/4] = 0;
    //     memset(v25, 0, sizeof(v25)); v25[0] = byte_5EA438[0];
    //     ZeroInitSmallStruct(v14); PathTruncationUtility(v25, 511);
    //     append dword_5C5E60..dword_5C5E6C, word_5C5E70 to v25;
    //     if (AudioStreamOpen(v25, 1)) {
    //       while (ConditionalDispatchBasedOnFlag(v24, 384)) {
    //         if (!sub_5651B0(v18) && (sub_5654A0(aAutochat01, v15) || ... || sub_5654A0(aAutochat10, v15))) {
    //           entry = new 8-byte object; entry[0] = 0; entry[1] = -1; StringCopyWithBufferRealloc(v15);
    //           newnode = new 12-byte node; newnode[0] = entry; newnode[1] = 0; newnode[2] = 1;
    //           if (this[0x1B780/4]) this[0x1B784/4][1] = newnode;
    //           else { this[0x1B780/4] = newnode; this[0x1B788/4] = newnode; }
    //           this[0x1B784/4] = newnode; ++this[0x1B78C/4];
    //           if (this[0x1B78C/4] >= 10) break;
    //         }
    //       }
    //       ConditionalFileHandleCloseWithFlagDispatch(v14);
    //     }
    //     return SubCallWithConditionalFieldFree(v14);
    //   }
    // UNRESOLVED: The exact content of the autochat file-name suffix globals dword_5C5E60..dword_5C5E6C and word_5C5E70 is not verifiable from this packet
    // UNRESOLVED: The semantics of sub_5651B0's chunk-type skip test and sub_5654A0's label match depend on the audio stream format, which is not defined here
    // UNRESOLVED: The meaning of the byte flag set to 1 at node+8 when a node is inserted (active/labeled marker) is inferred, not proven
    // UNRESOLVED: byte_7CE498 is flagged by packet globals but appears nowhere in the raw decompiled source; its role here is unknown
}
