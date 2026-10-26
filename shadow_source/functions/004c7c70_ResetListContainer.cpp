// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C7C70
// Canonical corpus name: Passthrough_7c70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Passthrough_7c70_004c7c70.c

void UnknownObject::ResetListContainer()
{
    // Resets the global container/list object at byte_8AC494 and returns a pointer to it. Writes 0 into the seven consecutive dwords from byte_8AC494 through unk_8AC4A8 and writes the literal 1120403456 into unk_8AC4AC. The first dword write zeroes the container head pointer stored at byte_8AC494, and the returned pointer is the object's base. Sister function 004C7C90 destroys the same object via ListDestructorWithSubFree, so byte_8AC494 is a container the caller resets and later frees.
    // ASSIGNMENT: Write 0 into the dword at byte_8AC494, clearing the container head/list pointer. [global:0x008AC494, source:raw]
    // ASSIGNMENT: Write 0 into unk_8AC498, the field immediately following byte_8AC494. [source:raw]
    // ASSIGNMENT: Write 0 into unk_8AC49C. [source:raw]
    // ASSIGNMENT: Write 0 into unk_8AC4A0. [source:raw]
    // ASSIGNMENT: Write 0 into unk_8AC4A4. [source:raw]
    // ASSIGNMENT: Write 0 into unk_8AC4A8. [source:raw]
    // ASSIGNMENT: Write the literal 1120403456 into unk_8AC4AC, the only non-zero field initialized here. [source:raw]
    // RETURN: Return the container base pointer &byte_8AC494 so the caller can use the reset object. [global:0x008AC494, source:raw]

    // Conservative worker pseudocode:
    //   char* sub_4C7C70(void) {
    //     *(_DWORD*)&byte_8AC494 = 0;
    //     unk_8AC498 = 0;
    //     unk_8AC49C = 0;
    //     unk_8AC4A0 = 0;
    //     unk_8AC4A4 = 0;
    //     unk_8AC4A8 = 0;
    //     unk_8AC4AC = 1120403456;
    //     return &byte_8AC494;
    //   }
    // UNRESOLVED: Semantic role of each zeroed field and of the literal 1120403456 at the trailing field is not established; the value's meaning (e.g. a float bit pattern) is not provable from this packet alone.
    // UNRESOLVED: Identity of the container object at byte_8AC494 is unknown; only that 004C7C90 destroys it via ListDestructorWithSubFree is evident.
    // UNRESOLVED: The unk_8AC498..unk_8AC4AC fields are unnamed adjacent globals referenced only through the raw source text.
}
