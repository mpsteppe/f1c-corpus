// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B8090
// Canonical corpus name: BinaryFloatComparison
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BinaryFloatComparison_004b8090.c

void UnknownObject::SerializationMagicCheck()
{
    // Serialization magic self-check. Initializes the allocation context with the raw float argument, then writes two sentinel values (the 4-byte string 'xxxx' and float -1.0) through the serialization backend via FileWriteWithBackendDispatch, then returns whether the sentinel buffer equals the global string at 0x005D2434 and the sentinel float equals the global float at 0x005D2438. Used by the model-scene loader for serialization format detection.
    // CALL: Invoke ConditionalAllocInitDispatch with the raw bit pattern of the float argument, initializing the allocation context for the serialization operation. [callee:0x00566D30, source:raw]
    // ASSIGNMENT: Copy the 4-byte sentinel string 'xxxx' into the local buffer v2 via strcpy. [source:raw]
    // ASSIGNMENT: Set the float argument a1 to the sentinel value -1.0. [source:raw]
    // CALL: Write the 4-byte sentinel buffer v2 through the serialization backend via FileWriteWithBackendDispatch(v2, 4). [callee:0x00566C00, source:raw]
    // CALL: Write the 4-byte float a1 through the serialization backend via FileWriteWithBackendDispatch(&a1, 4). [callee:0x00566C00, source:raw]
    // CALCULATION: Compute the check result as !strcmp(v2, off_5D2434) && (a1 == flt_5D2438): the sentinel buffer must equal the global string at 0x005D2434 and the sentinel float must equal the global float at 0x005D2438. [global:0x005D2434, global:0x005D2438, source:raw]
    // RETURN: Return the comparison result as a bool. [source:raw]

    // Conservative worker pseudocode:
    //   bool sub_4B8090(float a1) {
    //     char buf[8];
    //     ConditionalAllocInitDispatch(*(int*)&a1);
    //     strcpy(buf, "xxxx");
    //     a1 = -1.0f;
    //     FileWriteWithBackendDispatch(buf, 4);
    //     FileWriteWithBackendDispatch(&a1, 4);
    //     return !strcmp(buf, off_5D2434) && a1 == flt_5D2438;
    //   }
    // UNRESOLVED: Globals dword_5D246C and byte_5D2470 are listed in the packet as read-only but do not appear in the raw decompiled source; their role in this check is unknown.
    // UNRESOLVED: Whether FileWriteWithBackendDispatch is write-only or performs a read-back: the raw source compares against the globals, so the round-trip semantics of the magic check are uncertain.
}
