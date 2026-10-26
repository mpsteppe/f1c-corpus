// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00566A70
// Canonical corpus name: sub_566A70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_566A70_00566a70.c

void UnknownObject::OpenFileWithReadWriteMode()
{
    // File open helper. Optionally runs an attribute pre-check on the supplied name (a2) gated by a5, stores the mode arguments into this+0x0C and this+0x10, clears the local path buffer, and opens the file through sub_587DB0 choosing the read-mode path global unk_5E517C or the write-mode path global unk_5E5180 depending on this+0x0C. Stores the handle at this+0x00, zeroes the byte at this+0x18, and when the handle is valid copies the resolved path string into this+0x04 via StringCopyWithBufferRealloc. Returns whether the handle is non-null.
    // GUARD: When a5 is non-zero, FileAttributeCheckSequence(a2) must return non-zero to proceed; when a5 is zero the check is skipped and processing continues. [callee:0x005668F0, source:raw]
    // ASSIGNMENT: Store the mode arguments: this[3] (0x0C) = a4 and this[4] (0x10) = a3. [field:this:0x0000000C, field:this:0x00000010, source:raw]
    // CALL: sub_568620(1024) clears the 1024-byte local path buffer before it is used. [callee:0x00568620, source:raw]
    // GUARD: When this[3] (mode) is non-zero, sub_587DB0 opens using the read-mode path global unk_5E517C; otherwise it opens using the write-mode path global unk_5E5180. [field:this:0x0000000C, global:0x005E517C, global:0x005E5180, callee:0x00587DB0, source:raw]
    // ASSIGNMENT: Store the handle returned by sub_587DB0 at this+0x00 and derive the success flag from it being non-zero. [field:this:0x00000000, callee:0x00587DB0, source:raw]
    // ASSIGNMENT: Zero the byte at this+0x18 (offset 24) on the success path. [field:this:0x00000018, source:raw]
    // CALL: When the handle is valid, StringCopyWithBufferRealloc copies the resolved path buffer into this+0x04. [callee:0x00566650, source:raw]
    // RETURN: Return the handle-validity flag on the success path; on the early attribute-check exit, return the FileAttributeCheckSequence result. [callee:0x005668F0, caller:0x00409770, caller:0x0040BD10, source:raw]

    // Conservative worker pseudocode:
    //   bool OpenFileWithReadWriteMode(a2, a3, a4, a5) {
    //     if (!a5 || FileAttributeCheckSequence(a2)) {
    //       this[3] = a4;
    //       this[4] = a3;
    //       sub_568620(1024);
    //       if (this[3]) v7 = sub_587DB0(v9, &unk_5E517C);
    //       else        v7 = sub_587DB0(v9, &unk_5E5180);
    //       *this = v7;
    //       result = v7 != 0;
    //       *((_BYTE*)this + 24) = 0;
    //       if (v7) StringCopyWithBufferRealloc(this + 1, v9);
    //       return result;
    //     }
    //     return FileAttributeCheckSequence(a2);
    //   }
    // UNRESOLVED: The exact purpose of the a5-gated FileAttributeCheckSequence and what it verifies about the file is unknown.
    // UNRESOLVED: The distinct roles of a3 (stored at this+0x10) versus a4 (mode at this+0x0C) are not documented in this packet.
    // UNRESOLVED: The owning class behind this file-handle object is unknown.
}
