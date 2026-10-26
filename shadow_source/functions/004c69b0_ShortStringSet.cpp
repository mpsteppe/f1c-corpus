// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C69B0
// Canonical corpus name: ShortStringSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortStringSet_004c69b0.c

void UnknownObject::ShortStringSet()
{
    // Sets a short-string field and its derived integer code. Points v3 at the inline 8-byte buffer at this + 4546 (offset 0x4708), copies at most 7 characters from a2 via sub_587DD0, null-terminates the buffer at *(v3 + 7) (this+0x470F), then computes a code from the string with sub_587ECE and stores it at this[4548] (this+0x4710). Returns the computed code. __thiscall, no guards.
    // ASSIGNMENT: Point v3 at the short-string buffer: v3 = this + 4546 (byte offset 0x4708). [source:raw]
    // CALL: Call sub_587DD0(this + 4546, a2, 7): bounded copy of the source string a2 into the buffer with a 7-character limit. [source:raw, callee:0x00587DD0]
    // ASSIGNMENT: Null-terminate the buffer: *((_BYTE *)v3 + 7) = 0 (this+0x470F), fixing the string at up to 7 characters. [source:raw, field:this:0x0000470F]
    // CALL: Call sub_587ECE(v3) to compute an integer code/hash from the short string. [source:raw, callee:0x00587ECE]
    // ASSIGNMENT: Store the computed code: this[4548] = result (this+0x4710). [source:raw, field:this:0x00004710]
    // RETURN: Return the computed code. [source:raw]
    // CALL: Called by NationalityDriverInfoLoader (0x004C78F0) to assign a short string and its derived code during driver info loading. [caller:0x004C78F0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C69B0(_DWORD *this, const char *src) {
    //     _DWORD *buf = this + 4546;
    //     sub_587DD0(buf, src, 7);
    //     *((_BYTE *)buf + 7) = 0;
    //     int code = sub_587ECE(buf);
    //     this[4548] = code;
    //     return code;
    //   }
    // UNRESOLVED: Exact behavior of sub_587DD0 (assumed bounded copy of at most 7 chars) and sub_587ECE (assumed string-to-code computation) are not defined in this packet.
    // UNRESOLVED: Semantic meaning of the 7-char short string and its code field (this+0x4710) depend on the caller NationalityDriverInfoLoader (0x004C78F0).
    // UNRESOLVED: The null terminator written at this+0x470F assumes the copy guarantees at most 7 bytes are written before it.
}
