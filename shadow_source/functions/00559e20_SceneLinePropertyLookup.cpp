// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00559E20
// Canonical corpus name: sub_559E20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_559E20_00559e20.c

void UnknownObject::SceneLinePropertyLookup()
{
    // Scene line property lookup and value extraction. Scans the line buffer at this+0xC, counting '=' (0x3D) characters; a line with exactly one '=' is dispatched to StringTableLookup_9d10, otherwise sub_559D80 is used. If the chosen lookup returns 0, the function returns 0. On success the lookup result string (pointer at this+0x30C) is strcpy'd into a scratch buffer at this+0x18C, then sub_5897CA locates the '=' delimiter token inside the copy so the value substring can be collapsed in place into the caller-supplied lpSrcStr buffer (and, via a second delimiter scan, into a4). Returns 1 on success.
    // ASSIGNMENT: Initialize the equals-counter v5 to 0 before scanning the line buffer. [source:raw]
    // GUARD: Guard on the first byte of the line buffer at this+0xC: a zero byte (empty line) skips the count-based dispatch and goes directly to the sub_559D80 lookup. [field:this:0x0000000C, source:raw]
    // LOOP: do-while scan of the line buffer counting '=' (0x3D) characters until the terminating NUL byte is read. [field:this:0x0000000C, source:raw]
    // STATE_TRANSITION: Dispatch on the equals count: exactly one '=' selects the StringTableLookup_9d10 key=value path; otherwise (0 or >1 '=') the sub_559D80 path. [callee:0x00559D10, callee:0x00559D80, source:raw]
    // CALL: StringTableLookup_9d10(this, a2) is invoked when the line contains exactly one '=' character. [callee:0x00559D10, source:raw]
    // CALL: sub_559D80(this, a2) is the fallback lookup for empty lines or lines not shaped as a single key=value pair. [callee:0x00559D80, source:raw]
    // GUARD: Guard on the lookup result v8: a zero result aborts the function. [source:raw]
    // RETURN: Return 0 when the selected lookup fails. [source:raw]
    // ASSIGNMENT: strcpy the lookup result string (pointer held at this+0x30C) into the scratch buffer at this+0x18C. [field:this:0x0000030C, source:raw]
    // CALL: sub_5897CA(scratch buffer, asc_5D251C) locates the delimiter token ('=') inside the copied result string. [callee:0x005897CA, global:0x005D251C, source:raw]
    // GUARD: If the delimiter was found (v11) and the caller supplied lpSrcStr, extract the value substring. [source:raw]
    // LOOP: In-place collapse: shift the substring starting at the delimiter position down into the lpSrcStr buffer, copying characters until NUL. [source:raw]
    // CALL: sub_589901(lpSrcStr) processes the extracted first value. [callee:0x00589901, source:raw]
    // CALL: sub_5897CA(0, asc_5D251C) re-locates the delimiter from the global/current position to seed a second extraction. [callee:0x005897CA, global:0x005D251C, source:raw]
    // GUARD: If the second delimiter hit (v14) is non-null and a4 is supplied, perform a second value extraction into a4. [source:raw]
    // LOOP: In-place collapse of the second value substring from v14 down into the a4 buffer, copying until NUL. [source:raw]
    // CALL: sub_589901(a4) processes the extracted second value. [callee:0x00589901, source:raw]
    // RETURN: Return 1 to signal success after extraction. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_559E20(void *this, int a2, char *lpSrcStr, char *a4) {
    //     int equals = 0;
    //     BOOL ok;
    //     if (*(BYTE *)((BYTE *)this + 0xC)) {
    //       BYTE *p = (BYTE *)this + 0xC;
    //       while (*++p) if (*p == '=') ++equals;
    //       ok = (equals == 1) ? StringTableLookup_9d10(this, a2) : sub_559D80(this, a2);
    //     } else {
    //       ok = sub_559D80(this, a2);
    //     }
    //     if (!ok) return 0;
    //     strcpy((char *)this + 0x18C, *(const char **)((BYTE *)this + 0x30C));
    //     char *delim = sub_5897CA((char *)this + 0x18C, asc_5D251C);
    //     if (delim && lpSrcStr) {
    //       char *src = delim, *dst = lpSrcStr;
    //       do { *dst = *src; ++src; ++dst; } while (dst[-1]);
    //       sub_589901(lpSrcStr);
    //       delim = sub_5897CA(0, asc_5D251C);
    //       if (delim && a4) {
    //         char *src2 = delim, *dst2 = a4;
    //         do { *dst2 = *src2; ++src2; ++dst2; } while (dst2[-1]);
    //         sub_589901(a4);
    //       }
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: Exact behavior of sub_589901 (copy/trim variant) is not established by this function's evidence.
    // UNRESOLVED: The second sub_5897CA(0, asc_5D251C) call with a NULL first argument, and the purpose of extracting a second value into a4, are unclear.
    // UNRESOLVED: Role of a2 in both lookup paths is unknown here; the two lookups (StringTableLookup_9d10 vs sub_559D80) differ only by line shape.
    // UNRESOLVED: The scratch buffer at this+0x18C and the result pointer at this+0x30C (who allocates/owns the pointed-to string) are unresolved; 0x18C is not listed in the packet's fields table.
    // UNRESOLVED: Whether lpSrcStr/a4 alias the this+0x18C scratch buffer (in-place collapse) or are separate caller-owned buffers cannot be determined from this packet.
}
