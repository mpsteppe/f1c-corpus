// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042ED50
// Canonical corpus name: NameStringCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NameStringCopy_0042ed50.c

void UnknownObject::NameStringCopy()
{
    // Bounded string copy: copies up to 63 characters from a2 into the buffer at this+112 via sub_587DD0, writes a NUL terminator at v2[63] (field this+0xAF), and returns the copy result.
    // ASSIGNMENT: Set v2 = this + 112, the destination buffer pointer. [source:raw]
    // CALL: Call sub_587DD0(this + 112, a2, 63) to copy at most 63 characters from a2 into the destination buffer. [callee:0x00587DD0, source:raw]
    // ASSIGNMENT: Write a NUL terminator (0) at v2[63], the field at this+0xAF. [field:this:0x000000AF, source:raw]
    // RETURN: Return the sub_587DD0 result. [source:raw]

    // Conservative worker pseudocode:
    //   v2 = this + 112;
    //   result = sub_587DD0(this + 112, a2, 63);
    //   v2[63] = 0;
    //   return result;
    // UNRESOLVED: The destination buffer start (this + 112) is evidenced only by the source literal 112, not by a field record; only the terminator field this+0xAF is evidenced.
    // UNRESOLVED: Owning object type, source-call semantics of sub_587DD0, and the meaning of the copy length 63 are unknown.
}
