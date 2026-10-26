// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00413710
// Canonical corpus name: TextAttributeLookup_3710
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextAttributeLookup_3710_00413710.c

void UnknownObject::TextAttributeLookup_3710()
{
    // Structural twin of TextAttributeLookup (004133b0): text attribute field lookup restricted to a single field selector. Fetches the attribute record at index a3 through LinkedListIndexedAccessor_56c0. Only when the record is non-null and a2 == 1 does it copy the string path and metadata from a record slot (record+0x34, or record+0x48 when a4==0) into the output struct at a1, with null path falling back to byte_5EA438. Regardless of the copy path, the output string is normalized to byte_5EA438 and the same sentinel test as 004133b0 decides the result: -1 when all output fields are default (string equals byte_5EA438, metadata == -1/-1, byte field == 0), else 1.
    // CALL: Fetch attribute record at index a3 via LinkedListIndexedAccessor_56c0. [callee:0x004156C0, source:raw]
    // GUARD: Only proceed to the copy path when the record is non-null and a2 == 1; every other case skips straight to the default-string/sentinel tail. [source:raw]
    // CALCULATION: Select record slot: record+0x34, or record+0x48 when a4==0. [source:raw]
    // ASSIGNMENT: Read string path pointer from the slot, falling back to the default string byte_5EA438 when the slot pointer is null. [global:0x005EA438, source:raw]
    // CALL: Copy the selected path string into the output buffer via StringCopyWithBufferRealloc. [callee:0x00566650, source:raw]
    // ASSIGNMENT: Copy slot metadata into the output struct: out+0x08 = slot+0x08, out+0x0C = slot+0x0C, out+0x10 = slot+0x10 (byte). [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // CALL: Normalize the output string to the default byte_5EA438 via StringCopyWithBufferRealloc on the missing-record or out-of-range path. [callee:0x00566650, global:0x005EA438, source:raw]
    // GUARD: Sentinel test on the output struct: string at out+0x00 equals byte_5EA438 (falling back to the default when the pointer is null) and out+0x08 == -1 and out+0x0C == -1 and out+0x10 == 0. [field:this:0x00000000, guard:0, guard:1, global:0x005EA438, source:raw]
    // RETURN: Return -1 when every output field still holds its default sentinel value, otherwise 1. [guard:0, guard:1, source:raw]

    // Conservative worker pseudocode:
    //   record = LinkedListIndexedAccessor_56c0(a3);
    //   if (record && a2 == 1) {
    //       slot = record + (a4 ? 52 : 72);
    //       path = *(char**)slot; if (!path) path = byte_5EA438;
    //       StringCopyWithBufferRealloc(path);
    //       out->meta1 = *(slot + 8); out->meta2 = *(slot + 12); out->flag = *(slot + 16);
    //   }
    //   StringCopyWithBufferRealloc(byte_5EA438);
    //   if (strcmp(out->path, byte_5EA438) == 0 && out->meta1 == -1 && out->meta2 == -1 && out->flag == 0)
    //       return -1;
    //   return 1;
    // UNRESOLVED: FreeWrapper_7bcf and dword_5EA5E8 appear in the packet's callee/global tables but not in the decompiled body; their use may be inside StringCopyWithBufferRealloc.
    // UNRESOLVED: Why this twin accepts only a2 == 1 while 004133b0 accepts a2 0 or 1, and what distinguishes the record slot layout here (+0x34/+0x48) from the twin's, is not established by the packet.
    // UNRESOLVED: The meaning of the metadata fields (offsets 8, 12, 16) and the sentinel convention (-1/-1/0) is not established by the packet.
}
