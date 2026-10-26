// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00548E80
// Canonical corpus name: SelfCopyStringWithOffset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SelfCopyStringWithOffset_00548e80.c

void UnknownObject::CopyStringToInternalBuffer()
{
    // Copies the character string at a2 into the internal buffer at this+8 (self-overlap-safe byte copy that terminates on the null terminator), calls sub_589901 to normalize the copied buffer, then stores a3 into the dword at this+4 and returns a3.
    // CALCULATION: Compute the fixed distance v6 = (this + 8) - a2 between the destination buffer this+8 and the source a2; this distance is used to write each source byte to its mirrored position in the destination. [source:raw]
    // LOOP: do-while loop reads one byte at a time from a2, writes it to the corresponding position of the buffer at this+8, and continues until a copied byte is zero (null terminator). [source:raw]
    // CALL: Call sub_589901 on the internal buffer at this+8 for string normalization (e.g. case folding). [callee:0x00589901, source:raw]
    // ASSIGNMENT: Store the caller-supplied value a3 into the dword at this+4. [field:this:0x00000004, source:raw]
    // RETURN: Return a3 unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_548E80(char* this, const char* src, int value) {
    //     char* v3 = (char*)src;
    //     char* dst = this + 8;
    //     int delta = dst - src;
    //     char ch;
    //     do { ch = *v3; v3[delta] = ch; ++v3; } while (ch);
    //     sub_589901(this + 8);
    //     *(int*)(this + 4) = value;
    //     return value;
    //   }
    // UNRESOLVED: Whether a2 overlaps the buffer at this+8 (self-copy) is caller-dependent; the copy is written so overlap is safe.
    // UNRESOLVED: Meaning of a3 stored at this+4 (index or metadata supplied by caller sub_55A790) is unknown.
    // UNRESOLVED: Exact normalization performed by sub_589901 is unknown.
}
