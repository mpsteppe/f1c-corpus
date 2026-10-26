// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B1E20
// Canonical corpus name: ConfigKeyValueWrite
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConfigKeyValueWrite_004b1e20.c

void UnknownObject::ConfigKeyValueWrite()
{
    // Writes one config key/value pair into an output buffer a2. The value field at this+0x14 is converted to text (with float formatting) into a 256-byte stack scratch buffer, the key prefix string aSS_6 is written, the key name from this+0xC (defaulting to byte_5EA438 when null) is conditionally written via aS_8, and the pair is terminated with word_5C30B4. Returns constant 0.
    // ASSIGNMENT: Initialize the 256-byte stack serialization buffer v5 with a zero first byte, making it an empty string. [source:raw]
    // CALL: Format the value at this+0x14 (interpreted as a float) into the stack buffer v5 via StringFormatCopyWithFloat. Note: this+0x14 is not present in the packet field list; its existence and type are grounded only in source:raw. [callee:0x004A1A00, source:raw]
    // CALL: Write the string literal aSS_6 (0x005CD13C) into the output buffer a2 using a length-checked write. [callee:0x00566C30, global:0x005CD13C]
    // GUARD: Load the key/name pointer from this+0xC; when it is null, fall back to the global default string byte_5EA438. [field:this:0x0000000C, global:0x005EA438]
    // GUARD: When the (possibly defaulted) key/name string has nonzero length, write the string literal aS_8 (0x005D23A8) into a2. [callee:0x00566C30, global:0x005D23A8]
    // CALL: Write the terminator literal word_5C30B4 into a2, closing the serialized key/value pair. [callee:0x00566C30, global:0x005C30B4]
    // RETURN: Return the constant value 0. [source:raw]

    // Conservative worker pseudocode:
    //   char buf[256];
    //   buf[0] = 0;
    //   StringFormatCopyWithFloat(buf, (float*)(this + 0x14));
    //   BufferWriteWithStringLengthCheck(a2, &aSS_6);
    //   const char* name = *(const char**)(this + 0xC);
    //   if (!name) name = (const char*)&byte_5EA438;
    //   if (strlen(name)) BufferWriteWithStringLengthCheck(a2, &aS_8);
    //   BufferWriteWithStringLengthCheck(a2, &word_5C30B4);
    //   return 0;
    // UNRESOLVED: v5 is populated by StringFormatCopyWithFloat but its contents are never written to a2 in this function body; the value conversion appears dead here, so value emission must occur elsewhere or is omitted.
    // UNRESOLVED: The value field at this+0x14 (float) is not in the packet field list; only +0xC is listed.
    // UNRESOLVED: String contents of aSS_6, aS_8, word_5C30B4 and byte_5EA438 are unknown from the packet; semantics of the emitted sequence are DERIVED from ABI name only.
}
