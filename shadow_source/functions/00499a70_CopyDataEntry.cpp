// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499A70
// Canonical corpus name: DataEntryCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DataEntryCopy_00499a70.c

void UnknownObject::CopyDataEntry()
{
    // Data-entry assignment with a self-assignment guard. Returns -1 immediately if source a2 equals destination this (self-copy). Otherwise takes the source string pointer *a2, falling back to the default string byte_5EA438 when it is NULL, copies it via StringCopyWithBufferRealloc, then copies the identifier/value field at this+0x8 from a2+0x8. Returns 0 on success.
    // GUARD: If a2 == this, reject the self-assignment and return -1 without copying. [function:0x00499A70, source:raw]
    // ASSIGNMENT: v4 = *a2; read the source string pointer. When *a2 is NULL, substitute the default string byte_5EA438. [global:0x005EA438, function:0x00499A70, source:raw]
    // CALL: StringCopyWithBufferRealloc(v4); copy the resolved source string (or the byte_5EA438 default when the source string was NULL) with buffer reallocation. [callee:0x00566650, global:0x005EA438, function:0x00499A70, source:raw]
    // ASSIGNMENT: this[2] = a2[2]; copy the data value/identifier field at this+0x8 from the source at a2+0x8. [field:this:0x00000008, function:0x00499A70, source:raw]
    // RETURN: Return 0 on the successful copy path. [function:0x00499A70, source:raw]

    // Conservative worker pseudocode:
    //   int CopyDataEntry(char** this, char** a2) {
    //     if (a2 == this) return -1;
    //     char* src = *a2;
    //     if (!src) src = byte_5EA438;
    //     StringCopyWithBufferRealloc(src);
    //     this[2] = a2[2];
    //     return 0;
    //   }
    // UNRESOLVED: byte_5EA438 is treated as a default directory/string fallback, but its exact content is not confirmed by the packet.
    // UNRESOLVED: StringCopyWithBufferRealloc's destination is an implicit member or global of the owning object; the destination buffer offset is not evidenced.
    // UNRESOLVED: The meaning of the copied field at this+0x8 is unknown (data value/identifier by convention only).
    // UNRESOLVED: The owning object type is unknown; the sole caller is sub_495B60 (00495b60).
}
