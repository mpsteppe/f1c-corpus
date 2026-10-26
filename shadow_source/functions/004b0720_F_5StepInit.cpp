// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B0720
// Canonical corpus name: F_5StepInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_5StepInit_004b0720.c

void UnknownObject::F_5StepInit()
{
    // Five-step player-file session initialization sequence. Formats the object's name/path into a 256-byte (0x100) stack buffer via NamePathFormatterWithLengthCheck, tears down a dual-list container at dword offset 4678 (byte 0x4918) via DualListDestructionWithDeepCleanup, copies vehicle data fields, dispatches the formatted buffer through FAILWRONGTRIAGECATEGORY, then runs the closing step sub_4B0C00. Always returns 0. Called from PlayerFileInit and NameCompareAndFormat during player-session setup.
    // CALL: Formats the object's name/path into the 256-byte (0x100) stack buffer v3 via NamePathFormatterWithLengthCheck(this, v3, 0x100u). [callee:0x004B02B0, source:raw]
    // CALL: Tears down a dual-list container at dword offset 4678 (byte 0x4918) from this via DualListDestructionWithDeepCleanup. [callee:0x004C2300, source:raw]
    // CALL: Copies vehicle data fields out of this via VehicleDataFieldCopy. [callee:0x004B0E30, source:raw]
    // CALL: Dispatches the formatted buffer v3 through FAILWRONGTRIAGECATEGORY. [callee:0x004C22A0, source:raw]
    // CALL: Runs the closing initialization step sub_4B0C00 on this. [callee:0x004B0C00, source:raw]
    // RETURN: Returns 0 unconditionally. [function:0x004B0720, source:raw]

    // Conservative worker pseudocode:
    //   char v3[256];
    //   NamePathFormatterWithLengthCheck(this, v3, 0x100);
    //   DualListDestructionWithDeepCleanup((_DWORD*)this + 4678);
    //   VehicleDataFieldCopy(this);
    //   FAILWRONGTRIAGECATEGORY(v3);
    //   sub_4B0C00(this);
    //   return 0;
    // UNRESOLVED: The exact semantics of FAILWRONGTRIAGECATEGORY (0x004C22A0) and sub_4B0C00 are not evidenced within this packet.
    // UNRESOLVED: The target object of DualListDestructionWithDeepCleanup at dword offset 4678 (byte 0x4918) is unidentified; the owner remains UnknownObject.
    // UNRESOLVED: The name F_5StepInit and the structural-twin relationship to MemoryAllocation_5160 are DERIVED prelabel metadata, not evidenced by the raw body.
}
