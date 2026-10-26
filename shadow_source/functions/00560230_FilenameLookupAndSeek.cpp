// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00560230
// Canonical corpus name: sub_560230
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_560230_00560230.c

void UnknownObject::FilenameLookupAndSeek()
{
    // Looks up a filename in a packed resource table and seeks to its data entry. Copies the caller filename into a local buffer, strips any directory path up to the last backslash (character 92), normalizes the name via sub_589901, then linearly scans the 256-byte table entries (starting at this[74], name at entry+20) for a strcmp match. On success stores the found entry index at this[73] and calls sub_587F64 to seek the file handle this[4] to the entry's data offset. Returns 0 on success and -2 when the table is empty or no entry matches.
    // CALL: Copy the input filename into the local buffer SrcStr with strcpy. [source:raw]
    // GUARD: When CRTStrrchr(a2, 92) finds a backslash, shift the basename after the last separator over the buffer, replacing the directory prefix. [callee:0x0058B050, source:raw]
    // CALL: Normalize the trimmed name in SrcStr with sub_589901 (case/format conversion of the searched name). [callee:0x00589901, source:raw]
    // GUARD: Read the entry count from this[70]; return -2 when it is not greater than zero. [field:this:0x00000118, source:raw]
    // LOOP: Scan the resource table starting at this[74] in 256-byte steps, comparing SrcStr against each entry name at entry+20 with strcmp; return -2 when the scan index reaches the entry count. [field:this:0x00000128, source:raw]
    // ASSIGNMENT: Store the matched entry index at this[73]. [field:this:0x00000124, source:raw]
    // CALL: Seek the file handle this[4] to the entry data offset this[71] + *(entry+4) via sub_587F64 with a zero third argument. [callee:0x00587F64, field:this:0x00000010, field:this:0x0000011C, source:raw]
    // RETURN: Return 0 on a successful lookup and seek. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_560230(this, filename) {
    //     CHAR buffer[256];
    //     strcpy(buffer, filename);
    //     if (CRTStrrchr(filename, 92)) {
    //       char *src = CRTStrrchr(filename, 92) + 1;
    //       char *dst = buffer;
    //       do { *dst++ = *src; } while (*src++);
    //     }
    //     sub_589901(buffer);
    //     count = this[70];
    //     if (count <= 0) return -2;
    //     entry = this[74];
    //     for (index = 0; strcmp(buffer, (char *)(entry + 20)); ) {
    //       ++index; entry += 256;
    //       if (index >= count) return -2;
    //     }
    //     this[73] = index;
    //     sub_587F64(this[4], this[71] + *(entry + 4), 0);
    //     return 0;
    //   }
    // UNRESOLVED: The resource-table entry layout (256-byte stride, name at +20, data offset at +4) is inferred from raw source only; the entry fields are not individually flagged by this packet.
    // UNRESOLVED: this[75] (0x12C) is listed as an accessed field but is not read or written anywhere in the raw source; its purpose is unknown.
    // UNRESOLVED: The meaning of the zero third argument passed to sub_587F64 is unknown.
}
