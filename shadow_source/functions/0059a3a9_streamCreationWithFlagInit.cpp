// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A3A9
// Canonical corpus name: StreamCreationWithFlagInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StreamCreationWithFlagInit_0059a3a9.c

void UnknownObject::streamCreationWithFlagInit()
{
    // Stream object construction. Stores the handle/pointer parameter a2 at this+40 (this+0x28), resets an init flag at this+44 (this+0x2C) to 0, writes a single space byte (value 32) through the stream via SingleByteWriteViaStream storing the 16-bit result at this+48 (this+0x30), initializes remaining struct fields via StructFieldInitWithConditionalCall(this), opens the stream via sub_59A5FE when the stored handle at this+0x28 is null (setting bit 2 on flags at this+4), and finally finalizes construction via sub_59A8FA(this) when a3 is non-zero.
    // ASSIGNMENT: Reset the init flag to 0: *(this+44) = 0 (this+0x2C). [field:this:0x0000002C]
    // ASSIGNMENT: Store the parameter a2 at this+40 (this+0x28): the stream handle/pointer field. [field:this:0x00000028]
    // CALL: Write a single space byte (value 32) through the stream via SingleByteWriteViaStream and store its 16-bit result at this+48 (this+0x30). [callee:0x0059B208, field:this:0x00000030]
    // CALL: Initialize remaining struct fields via StructFieldInitWithConditionalCall(this); the returned result is retained for the exit path. [callee:0x0059A948]
    // GUARD: If the stored handle at this+0x28 is null, open/create the stream. [field:this:0x00000028]
    // CALCULATION: Set bit 2 on the flags word at this+4: v5 = *(this+4); LOBYTE(v5) = v5 | 4. [field:this:0x00000004]
    // CALL: Open the stream: sub_59A5FE(v5, 0) using the modified flag word; its result replaces the retained result. [callee:0x0059A5FE]
    // GUARD: If a3 is non-zero, finalize construction by returning sub_59A8FA(this). [callee:0x0059A8FA]
    // RETURN: Return the retained StructFieldInitWithConditionalCall result (or sub_59A8FA's result when a3 is set). [source:raw]

    // Conservative worker pseudocode:
    //   void streamCreationWithFlagInit(int this, int a2, char a3) {
    //     *(this+44) = 0;
    //     *(this+40) = a2;
    //     *(short*)(this+48) = SingleByteWriteViaStream(32);
    //     result = StructFieldInitWithConditionalCall(this);
    //     if (*(this+40) == 0) {
    //       v5 = *(this+4); LOBYTE(v5) |= 4;
    //       result = sub_59A5FE(v5, 0);
    //     }
    //     if (a3) return sub_59A8FA(this);
    //     return result;
    //   }
    // UNRESOLVED: Owner class is unknown; the ABI name 'Stream_Creation_with_Flag_Init' is LEGACY trust and the __thiscall receiver is not tied to a confirmed stream type.
    // UNRESOLVED: Callers CEHFrameSetup (0x00599B1C) and LocaleObjectAllocAndVtableSetup (0x00599BF0) call this constructor; the exact allocation/ownership flow around those call sites is not described by this packet.
    // UNRESOLVED: The semantics of the flags bit 2 (|= 4) at this+0x4 and the space-byte write at this+0x30 are inferred from the surrounding stream-construction pattern, not independently confirmed.
    // UNRESOLVED: sub_59A5FE and sub_59A8FA bodies are not included here, so the actual open and finalize behavior is only inferred from call shape.
}
