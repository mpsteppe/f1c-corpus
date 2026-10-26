// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00493F50
// Canonical corpus name: sub_493F50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_493F50_00493f50.c

void UnknownObject::InitializeOscParserState()
{
    // Zero-initializes the OSC script parser state structure: clears the leading dwords and control bytes, installs the default log file path strings ("Log\\osc.information" at this+140 and "Log\\osc.err" at this+268), zeroes the counter/token/nesting dwords near this+0x18C and the trailing flag bytes at this+0x198/0x199/0x19A, then returns the object pointer.
    // ASSIGNMENT: Zero the leading dwords at this+0x0, this+0x4 and this+0x8. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008]
    // ASSIGNMENT: Zero the byte at this+0xC. [field:this:0x0000000C]
    // CALL: Copy the information log path string (aLogOscInformat) into the string buffer at this+140. [global:0x005AC80C, source:raw]
    // CALL: Copy the error log path string (aLogOscErr) into the string buffer at this+268. [global:0x005AC820, source:raw]
    // ASSIGNMENT: Zero the dwords at this+0x18C, this+0x190, this+0x194 and this+0x19C (parser counters / state dwords). [field:this:0x0000018C, field:this:0x00000190, field:this:0x00000194, field:this:0x0000019C]
    // ASSIGNMENT: Zero the trailing flag bytes at this+0x198, this+0x199 and this+0x19A. [field:this:0x00000198, field:this:0x00000199, field:this:0x0000019A]
    // RETURN: Return the initialized object pointer (this). [source:raw]

    // Conservative worker pseudocode:
    //   void* sub_493F50(OscParserState* this) {
    //     *(int*)(this + 0x0) = 0;
    //     *(int*)(this + 0x4) = 0;
    //     *(int*)(this + 0x8) = 0;
    //     *(byte*)(this + 0xC) = 0;
    //     strcpy(this + 140, "Log\\osc.information");
    //     strcpy(this + 268, "Log\\osc.err");
    //     *(int*)(this + 0x18C) = 0;
    //     *(int*)(this + 0x190) = 0;
    //     *(int*)(this + 0x194) = 0;
    //     *(int*)(this + 0x19C) = 0;
    //     *(byte*)(this + 0x198) = 0;
    //     *(byte*)(this + 0x199) = 0;
    //     *(byte*)(this + 0x19A) = 0;
    //     return this;
    //   }
    // UNRESOLVED: The concrete field meanings (file handles, stream pointers, token counters) are labeled from the structure's apparent OSC-parser role; no packet evidence names them individually.
    // UNRESOLVED: Whether this+0xC is a flag or a short/packed field is not decidable from the initialization alone.
}
