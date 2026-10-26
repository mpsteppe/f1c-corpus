// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479170
// Canonical corpus name: sub_479170
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_479170_00479170.c

void UnknownObject::CoordinateFileParser()
{
    // Parses a track data file into a coordinate linked list. Re-inits the object's list state to empty (head/tail/insert/count fields zeroed), frees any previously-built list, opens the file with the .rt extension via sub_587DB0(a2, aRt), then reads lines until the file's +12 flag byte has bit 0x10 set. Each line is parsed for NumCoordinates then Coordinate via sub_565760; matching lines allocate a 12-byte coordinate record and a 12-byte list node (data at +0, next at +4, owned flag at +8), appended after the tail. Finishes by closing the file with FileCloseWithLock.
    // CALL: Open the file: v10 = sub_587DB0(a2, aRt) using the .rt extension string (global 0x005BE690); the returned handle is kept in v10. [callee:0x00587DB0, global:0x005BE690, source:raw]
    // ASSIGNMENT: Load the previous list head v4 = this[0x164] (this[89]) so any prior coordinate list can be freed. [field:this:0x00000164, source:raw]
    // LOOP: Walk the old list following the +4 next pointer of each node referenced through *(this+0x168); for every node whose +8 byte is non-zero free the child data, and always free the node itself via FreeWrapper_7bcf (callee 0x00587BCF). [field:*(this+0x168):0x00000004, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Re-init the list state to empty: this[85] count, this[89] head, this[90] tail, this[91] insert pointer and this[92] node count are all zeroed. [field:this:0x00000154, field:this:0x00000164, field:this:0x00000168, field:this:0x0000016C, field:this:0x00000170, source:raw]
    // GUARD: When the file handle v10 is non-null and the file's flag byte at +12 has bit 0x10 clear, proceed into the line-parse loop; otherwise skip parsing. [source:raw]
    // LOOP: Parse loop: allocate a 12-byte coordinate record via OperatorNewNhMallocWrapper(12) (callee 0x00587C03), read one line into the 384-byte stack buffer v18 with FileReadUntilNewline(v18, 384, file) (callee 0x00587CA0), then repeat while the file's +12 flag byte still has bit 0x10 clear. [callee:0x00587C03, callee:0x00587CA0, source:raw]
    // CALL: Parse the line with sub_565760 (callee 0x00565760): first extract the coordinate count into v11 from the NumCoordinates token (global 0x005C71B0); when v11 > 0, extract the coordinate pair into v12 / v13[0] from the Coordinate token (global 0x005C71A4). [callee:0x00565760, global:0x005C71B0, global:0x005C71A4, source:raw]
    // GUARD: When both parses succeed (v11 > 0 and the Coordinate parse returns non-zero), build a list node: allocate 12 bytes via OperatorNewNhMallocWrapper(12), store the coordinate record pointer at node+0, next = 0 at node+4, and owned flag = 1 at node+8. [callee:0x00587C03, source:raw]
    // GUARD: Append node to the list: when the head this[0x164] (this[89]) already exists write the new node into the tail's +4 next slot, otherwise set head = insert = new node; then advance tail this[0x168] (this[90]) and node count this[0x170] (this[92]) and increment the coordinate count this[0x154] (this[85]). [field:this:0x00000164, field:this:0x00000168, field:this:0x0000016C, field:this:0x00000170, field:this:0x00000154, guard:0, source:raw]
    // RETURN: On the parse path, close the file with FileCloseWithLock (callee 0x00587D02) and return its result; when no file was opened the function returns the null handle. [callee:0x00587D02, source:raw]

    // Conservative worker pseudocode:
    //   int sub_479170(int this, int a2) {
    //     int file = sub_587DB0(a2, aRt);
    //     int node = this[89];
    //     while (node) { int next = *(int*)(node + 4); if (*(char*)(node + 8)) FreeWrapper_7bcf(*(void**)node); FreeWrapper_7bcf(node); node = next; }
    //     this[85] = 0; this[89] = 0; this[90] = 0; this[91] = 0; this[92] = 0;
    //     if (file && !(*(char*)(file + 12) & 0x10)) {
    //       do {
    //         int coord = OperatorNewNhMallocWrapper(12);
    //         FileReadUntilNewline(v18, 384, file);
    //         sub_565760(aNumcoordinates, &v11, 0, 0, 0);
    //         if (v11 > 0 && sub_565760(aCoordinate, &v12, v13, 0, 0)) {
    //           coord[0] = v12; coord[1] = v13[0];
    //           int ln = OperatorNewNhMallocWrapper(12);
    //           if (ln) { *(int*)ln = coord; *(int*)(ln + 4) = 0; *(char*)(ln + 8) = 1; } else ln = 0;
    //           if (this[89]) { *(int*)(this[90] + 4) = ln; } else { this[89] = ln; this[91] = ln; }
    //           this[90] = ln; this[92] += 1; this[85] += 1;
    //         }
    //       } while (!(*(char*)(file + 12) & 0x10));
    //       return FileCloseWithLock(file);
    //     }
    //     return file;
    //   }
    // UNRESOLVED: The owning object's class is unknown (packet owner is UnknownObject/UNKNOWN); the fields at this+0x154/0x164/0x168/0x16C/0x170 form a coordinate linked list, but the enclosing class is not established.
    // UNRESOLVED: sub_565760's exact contract (token-to-value parser returning success and an out value) is inferred from usage, not independently evidenced.
    // UNRESOLVED: The file object layout (flag byte at +12 bit 0x10 signaling end-of-file) is read from the handle returned by sub_587DB0; that handle's type is not evidenced.
    // UNRESOLVED: Caller FilePathResolverWithExtensionAppend (0x004793EC) is recorded; frame-path membership is NOT_FOUND so invocation frequency is unknown.
}
