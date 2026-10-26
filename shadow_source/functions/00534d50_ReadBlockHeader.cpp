// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00534D50
// Canonical corpus name: sub_534D50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_534D50_00534d50.c

void UnknownObject::ReadBlockHeader()
{
    // Reads the next protocol block from a buffered stream: consumes up to two magic bytes compared against dword_5DA780, then when both match parses a block header (type byte required to equal 8, flags byte with upper bits 0xE0 clear) and skips payload bytes selected by flag bits 0x2/0x4/0x8/0x10. On header failure sets the status field this[0x38] to -3; on magic mismatch rewinds the buffer read pointer this[0x0] and bumps the consumed-byte counter this[0x4]; when the diverging byte was not end-of-stream also raises the EOF/error flag this[0x58] to 1. Final status is (this[0x4] == 0).
    // LOOP: Read stream bytes via sub_534E70, comparing each against the magic entry dword_5DA780[i]; stop when a byte mismatches or both magic bytes (v2 == 2) have matched. [callee:0x00534E70, global:0x005DA780, source:raw]
    // STATE_TRANSITION: When both magic bytes matched, parse the block header: read a type byte (v4) and a flags byte (v6) from the stream; the low flag bits of v6 select which payload fields follow. [callee:0x00534E70, source:raw]
    // GUARD: If the type byte is not 8 or the flags byte has any bit of the 0xE0 mask set, the header is malformed: set the status field this[0x38] to -3 and skip all payload parsing. [field:this:0x00000038, source:raw]
    // CALL: Skip the six fixed header bytes that follow the type/flags bytes. [callee:0x00534E70, source:raw]
    // GUARD: When flag bit 4 is set, read a 2-byte little-endian length into v9 and skip that many payload bytes, stopping early if a -1 (end marker) byte is read. [callee:0x00534E70, source:raw]
    // GUARD: When flag bit 8 is set, skip bytes until a zero byte or a -1 (end marker) is read. [callee:0x00534E70, source:raw]
    // GUARD: When flag bit 0x10 is set, skip bytes until a zero byte or a -1 (end marker) is read. [callee:0x00534E70, source:raw]
    // GUARD: When flag bit 2 is set, skip two more bytes. [callee:0x00534E70, source:raw]
    // ASSIGNMENT: After the flagged payload skips, set the status field this[0x38] to -3 when the mode flag this[0x3C] is non-zero, else to 0. [field:this:0x00000038, field:this:0x0000003C, guard:1, source:raw]
    // STATE_TRANSITION: When at least one magic byte matched but the stream diverged (v2 non-zero), rewind the read pointer by one: decrement this[0x0] and increment the consumed-byte counter this[0x4]. [field:this:0x00000000, field:this:0x00000004, source:raw]
    // STATE_TRANSITION: When the diverging byte was not -1 (stream not exhausted), rewind one more byte, increment this[0x4], and raise the EOF/error flag this[0x58] to 1. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000058, source:raw]
    // ASSIGNMENT: Evaluate whether the buffer is empty (this[0x4] == 0), store that boolean into the status field this[0x38], and return it. [field:this:0x00000004, field:this:0x00000038, guard:0, source:raw]

    // Conservative worker pseudocode:
    //   v2 = 0;
    //   while ((b = read_byte(this)) == dword_5DA780[v2]) { if (++v2 == 2) break; }
    //   if (v2 == 2) {
    //     type = read_byte(this); flags = read_byte(this);
    //     if (type != 8 || (flags & 0xE0)) { this[14] = -3; }
    //     else {
    //       skip 6 bytes;
    //       if (flags & 4) { len = read_byte(this) | (read_byte(this) << 8); while (len-- && read_byte(this) != -1); }
    //       if (flags & 8) while ((b = read_byte(this)) != 0 && b != -1);
    //       if (flags & 0x10) while ((b = read_byte(this)) != 0 && b != -1);
    //       if (flags & 2) { read_byte(this); read_byte(this); }
    //       this[14] = this[15] ? -3 : 0;
    //     }
    //     return last_read;
    //   }
    //   if (v2) { this[0]--; this[1]++; }
    //   if (b != -1) { this[0]--; this[1]++; this[22] = 1; }
    //   result = (this[1] == 0); this[14] = result; return result;
    // UNRESOLVED: Guard this[0x4] == 0 (buffer-empty refill) is recorded by the fact table but does not appear as an explicit branch in the decompiled body; it surfaces here only as the final status computation.
    // UNRESOLVED: The flag-bit payload layout (0x2/0x4/0x8/0x10) and the -1 end-marker convention are inferred from usage; no format documentation is available.
    // UNRESOLVED: Owner is unknown: callers sub_534B10 and BufferedFileReader suggest a buffered file/stream reader context, but no class is evidenced.
    // UNRESOLVED: The 6-byte fixed header skip is assumed constant; its fields are unnamed.
}
