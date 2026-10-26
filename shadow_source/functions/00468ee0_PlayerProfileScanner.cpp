// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00468EE0
// Canonical corpus name: PlayerProfileScanner
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PlayerProfileScanner_00468ee0.c

void UnknownObject::PlayerProfileScanner()
{
    // Rebuilds the player-profile icon list: destroys the existing node list, sets the settings directory from dword_5EC440 (or the byte_5EA438 default), iterates every directory entry, formats "dir + name" paths, strips each to its directory and appends the icon filename (from byte_5EC4CC, refreshed via BinarySearchInStringTable against aProfileiconBmp), loads the icon via sub_497AD0 with aProfileiconDft fallback, appends icon+path nodes to the linked list, then finalizes head/cursor selection and calls SetupFileLoadAndFinalize(this).
    // CALL: __thiscall entry: destroy any existing linked list via LinkedListDestructionWithVTableCall(). [abi:lead, callee:0x0048D230]
    // LOOP: Walk the old node chain starting at head this+0x444: read next pointer at node+4, and when the node's +8 byte is nonzero and its data pointer is non-null call ConditionalFreeWithBit0Flag(data, 1), then FreeWrapper_7bcf(node). [field:this:0x00000444, callee:0x00404F70, callee:0x00587BCF]
    // ASSIGNMENT: Reset all list bookkeeping to 0: head this+0x444, tail this+0x448, cursor this+0x44C and count this+0x450. [field:this:0x00000444, field:this:0x00000448, field:this:0x0000044C, field:this:0x00000450]
    // ASSIGNMENT: Select the base directory path: dword_5EC440, or byte_5EA438 when dword_5EC440 is null, then call sub_565F80(aPlr_0, 1, path, 1). [global:0x005EC440, global:0x005EA438, global:0x005C6960, callee:0x00565F80]
    // CALL: Call sub_566380(2) to prepare the directory scan. [callee:0x00566380]
    // LOOP: Iterate directory entries via DirectoryEntryIterator(&unk_8AD3B0); each entry name drives one list-node build. [callee:0x005662D0, global:0x008AD3B0]
    // CALL: Format the full path into v21 with StringFormatWithBufferOverflowCheck(v21, aSS "%s%s", directory, entry name). [callee:0x0058815F, global:0x005BE860, global:0x005EC440, global:0x005EA438]
    // CALCULATION: Copy v21 into v20, compute strlen(v20), then truncate v20 at the last backslash (0x5C) so only the directory portion remains. [source:raw]
    // GUARD: When BinarySearchInStringTable(byte_5EC4C0, aProfileiconBmp, byte_5EC4CC) succeeds, refresh byte_5EC4CC by copying the aProfileiconBmp string into it. [callee:0x00423A00, global:0x005EC4C0, global:0x005C6950, global:0x005EC4CC]
    // ASSIGNMENT: Concatenate the icon filename: strcat(v20, byte_5EC4CC); load v15 = sub_497AD0(v20, 0); when that returns null fall back to sub_497AD0(aProfileiconDft, 0). [global:0x005EC4CC, callee:0x00497AD0, global:0x005C66F8]
    // CALL: Append the loaded icon v15 to the global list via LinkedListNodeAppend(v15). [callee:0x0048D2B0]
    // CALCULATION: Scan v21 backwards from its end to the last backslash (0x5C) to isolate the file name portion of the path. [source:raw]
    // ASSIGNMENT: Allocate an 8-byte node via OperatorNewNhMallocWrapper(8); initialize *v17 = 0, v17[1] = -1, then StringCopyWithBufferRealloc(v21) into the node. [callee:0x00587C03, callee:0x00566650]
    // ASSIGNMENT: Allocate a 12-byte node via OperatorNewNhMallocWrapper(12); on success set *v18 = v17 (icon node), *(v18+4) = 0 and *(v18+8) = 1. [callee:0x00587C03]
    // GUARD: List append or init: when the head this+0x444 is nonzero write v18 into tail->next (*(this+0x448)+4); otherwise set head this+0x444 = v18 and cursor this+0x44C = v18. Then tail this+0x448 = v18 and increment count this+0x450. [field:this:0x00000444, field:*(this+0x448):0x00000004, field:this:0x00000448, field:this:0x0000044C, field:this:0x00000450, guard:0]
    // CALL: Advance the directory iterator with LinkedListNodePeek(&unk_8AD3B0). [callee:0x00565F20]
    // CALL: Finish the directory scan with sub_565EB0(&unk_8AD3B0). [callee:0x00565EB0]
    // GUARD: Finalize the cursor: when count this+0x450 <= 0 set cursor this+0x44C = 0, otherwise set it to head this+0x444. [field:this:0x00000450, field:this:0x0000044C, field:this:0x00000444, guard:1]
    // RETURN: Return SetupFileLoadAndFinalize(this). [callee:0x00469630]

    // Conservative worker pseudocode:
    //   int PlayerProfileScanner(_DWORD* this) {
    //     LinkedListDestructionWithVTableCall();
    //     for (node = this[273]; node; node = *(int*)(node + 4)) {
    //       if (*(char*)(node + 8) && *(int*)node) ConditionalFreeWithBit0Flag(*(int*)node, 1);
    //       FreeWrapper_7bcf(node);
    //     }
    //     this[273] = this[274] = this[275] = this[276] = 0;
    //     dir = dword_5EC440 ? dword_5EC440 : byte_5EA438;
    //     sub_565F80(aPlr_0, 1, dir, 1);
    //     sub_566380(2);
    //     for (name = DirectoryEntryIterator(&unk_8AD3B0); name; name = DirectoryEntryIterator(&unk_8AD3B0)) {
    //       StringFormatWithBufferOverflowCheck(v21, "%s%s", dir, name);
    //       strip v20 down to its directory (truncate at last backslash);
    //       if (BinarySearchInStringTable(byte_5EC4C0, aProfileiconBmp, byte_5EC4CC)) copy aProfileiconBmp -> byte_5EC4CC;
    //       strcat(v20, byte_5EC4CC);
    //       icon = sub_497AD0(v20, 0);
    //       if (!icon) icon = sub_497AD0(aProfileiconDft, 0);
    //       LinkedListNodeAppend(icon);
    //       node8 = OperatorNewNhMallocWrapper(8); if (node8) { *node8 = 0; node8[1] = -1; StringCopyWithBufferRealloc(v21); }
    //       node12 = OperatorNewNhMallocWrapper(12);
    //       if (node12) { *node12 = node8; *(node12+4) = 0; *(node12+8) = 1; }
    //       if (this[273]) *(this[274] + 4) = node12; else { this[273] = node12; this[275] = node12; }
    //       this[274] = node12; ++this[276];
    //       LinkedListNodePeek(&unk_8AD3B0);
    //     }
    //     sub_565EB0(&unk_8AD3B0);
    //     this[275] = (this[276] <= 0) ? 0 : this[273];
    //     return SetupFileLoadAndFinalize(this);
    //   }
    // UNRESOLVED: Second argument a2 is never referenced in the body; purpose unknown.
    // UNRESOLVED: Exact path formats of aPlr_0 (extension filter) and aProfileiconBmp are string literals whose content is not established by this packet.
    // UNRESOLVED: guard:0 (this+0x44C == 0) is recorded by extraction but the raw source tests the head at this+0x444; the cursor offset association is a DERIVED reading.
    // UNRESOLVED: The two scan preps (sub_565F80, sub_566380) and teardown (sub_565EB0) accept unverified parameter semantics.
    // UNRESOLVED: Relationship between the 8-byte icon node and the 12-byte string node (icon and path) is only partially inferred from the init literals.
}
