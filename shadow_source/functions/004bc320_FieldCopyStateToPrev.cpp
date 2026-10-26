// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BC320
// Canonical corpus name: FieldCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldCopy_004bc320.c

void UnknownObject::FieldCopyStateToPrev()
{
    // Snapshot copy on a __thiscall object: reads the dword at byte offset 0x2C, copies the float at byte offset 0x68 into byte offset 0x28, stores the dword read from 0x2C into byte offset 0x24, and returns that dword. Called from multiplayer vehicle placement and netcomm slot-sync paths, consistent with preserving a current-state snapshot before an update.
    // CALCULATION: Read result = dword at byte offset 0x2C (the current state value to be snapshotted). [field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Copy the float at byte offset 0x68 into byte offset 0x28. [field:this:0x00000068, field:this:0x00000028, source:raw]
    // ASSIGNMENT: Store result (the value read from byte offset 0x2C) into byte offset 0x24. [field:this:0x0000002C, field:this:0x00000024, source:raw]
    // RETURN: Return result, the dword previously read from byte offset 0x2C. [field:this:0x0000002C, function:0x004BC320, source:raw]

    // Conservative worker pseudocode:
    //   int result = *(dword*)(this + 0x2C);
    //   *(float*)(this + 0x28) = *(float*)(this + 0x68);
    //   *(dword*)(this + 0x24) = result;
    //   return result;
    // UNRESOLVED: Semantic meaning of the copied state pair (0x2C -> 0x24) and float pair (0x68 -> 0x28) depends on the caller's object layout and is not resolvable here.
    // UNRESOLVED: Whether the two pairs belong to the same logical record or different sub-objects is unknown.
}
