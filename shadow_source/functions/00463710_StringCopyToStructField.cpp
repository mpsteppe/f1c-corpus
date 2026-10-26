// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00463710
// Canonical corpus name: StringCopyToStructField
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCopyToStructField_00463710.c

void UnknownObject::StringCopyToStructField()
{
    // Copies the source string a2 into a fixed 32-byte buffer at obj+0x1B0, where obj is the target pointer held at this[0] (offset 0x0) plus 432. The copy is performed by sub_587DD0 with a max length of 31, followed by a forced null terminator at obj+0x1CF (+31). When a2 is null the copy is skipped and the first byte at obj+0x1B0 is zeroed instead (empty string). Returns the result of the copy helper on the non-null path and *this on the null path.
    // GUARD: Branch on a2 (source pointer) being non-null: non-null selects the copy path, null selects the zero-first-byte path. [source:raw]
    // CALCULATION: Compute the destination as v3 = *this + 432, resolving through this[0] to the buffer at obj+0x1B0. [source:raw, field:this:0x00000000, field:obj:0x000001B0]
    // CALL: Copy up to 31 characters from a2 into the destination buffer via sub_587DD0. [source:raw, callee:0x00587DD0]
    // ASSIGNMENT: Force a null terminator by writing 0 to the byte at v3 + 31, i.e. obj+0x1CF. [source:raw, field:obj:0x000001CF]
    // ASSIGNMENT: Null-source path: zero the first byte of the destination buffer at *this + 432 (obj+0x1B0) to make an empty string. [source:raw, field:this:0x00000000, field:obj:0x000001B0]
    // RETURN: Return: the copy path returns sub_587DD0's result; the null path returns *this. [source:raw, field:this:0x00000000]

    // Conservative worker pseudocode:
    //   int sub_463710(int *this, char *source) {
    //     if (source) {
    //       char *dest = (char *)(*this + 432);
    //       int r = sub_587DD0(dest, source, 31);
    //       dest[31] = 0;
    //       return r;
    //     } else {
    //       *(char *)(*this + 432) = 0;
    //       return *this;
    //     }
    //   }
    // UNRESOLVED: sub_587DD0's exact contract (strncpy-like bounded copy returning the destination pointer) is inferred from the 31-char bound and the caller-supplied terminator.
    // UNRESOLVED: The target object sits behind a pointer at this+0; the object type and the purpose of the +0x1B0 string field are unidentified.
    // UNRESOLVED: The 32-byte buffer size is inferred from the 31-char copy bound plus the explicit +31 terminator.
}
