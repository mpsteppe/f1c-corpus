// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B1600
// Canonical corpus name: PathPathRegistryWriter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PathPathRegistryWriter_004b1600.c

void UnknownObject::PathRegistryBulkCopy()
{
    // Copies six string pointers held in this (this[2019], this[2021], this[2023], this[105], this[107], this[109]) through StringCopyWithBufferRealloc, falling back to byte_5EA438 when a pointer is null. Returns the result of the final copy.
    // GUARD: v2 = this[2019] (this+0x1F8C); if null, fall back to byte_5EA438. [field:this:0x00001F8C, global:0x005EA438, source:raw]
    // CALL: StringCopyWithBufferRealloc(v2) copies the first path string into a reallocated buffer. [callee:0x00566650, source:raw]
    // GUARD: v3 = this[2021] (this+0x1F94); if null, fall back to byte_5EA438. [field:this:0x00001F94, global:0x005EA438, source:raw]
    // CALL: StringCopyWithBufferRealloc(v3) copies the second path string into a reallocated buffer. [callee:0x00566650, source:raw]
    // GUARD: v4 = this[2023] (this+0x1F9C); if null, fall back to byte_5EA438. [field:this:0x00001F9C, global:0x005EA438, source:raw]
    // CALL: StringCopyWithBufferRealloc(v4) copies the third path string into a reallocated buffer. [callee:0x00566650, source:raw]
    // GUARD: v5 = this[105] (this+0x1A4); if null, fall back to byte_5EA438. [field:this:0x000001A4, global:0x005EA438, source:raw]
    // CALL: StringCopyWithBufferRealloc(v5) copies the fourth path string into a reallocated buffer. [callee:0x00566650, source:raw]
    // GUARD: v6 = this[107] (this+0x1AC); if null, fall back to byte_5EA438. [field:this:0x000001AC, global:0x005EA438, source:raw]
    // CALL: StringCopyWithBufferRealloc(v6) copies the fifth path string into a reallocated buffer. [callee:0x00566650, source:raw]
    // GUARD: v7 = this[109] (this+0x1B4); if null, fall back to byte_5EA438. [field:this:0x000001B4, global:0x005EA438, source:raw]
    // RETURN: Return StringCopyWithBufferRealloc(v7), the result of copying the sixth path string. [callee:0x00566650, source:raw]

    // Conservative worker pseudocode:
    //   if (this[2019] == NULL) this[2019] = byte_5EA438; StringCopyWithBufferRealloc(this[2019]);
    //   if (this[2021] == NULL) this[2021] = byte_5EA438; StringCopyWithBufferRealloc(this[2021]);
    //   if (this[2023] == NULL) this[2023] = byte_5EA438; StringCopyWithBufferRealloc(this[2023]);
    //   if (this[105]  == NULL) this[105]  = byte_5EA438; StringCopyWithBufferRealloc(this[105]);
    //   if (this[107]  == NULL) this[107]  = byte_5EA438; StringCopyWithBufferRealloc(this[107]);
    //   if (this[109]  == NULL) this[109]  = byte_5EA438;
    //   return StringCopyWithBufferRealloc(this[109]);
    // UNRESOLVED: byte_5EA438 is used as the null fallback string, but its contents and purpose (default directory/file path) are DERIVED from the existing analysis and not evidenced by the packet.
    // UNRESOLVED: The meaning of the six string fields as network/session path pointers is DERIVED from the callers (AutoJoinRetryLoop, MultiplayerSessionJoinHandler); the packet does not evidence their purpose.
}
