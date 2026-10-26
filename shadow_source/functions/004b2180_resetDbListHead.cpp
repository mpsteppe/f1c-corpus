// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2180
// Canonical corpus name: ThunkToFUN004b3ad0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToFUN004b3ad0_004b2180.c

void UnknownObject::resetDbListHead()
{
    // Resets a small list/container: sets dword_7D2E50 (0x007D2E50) to 0, points dword_83EE54, dword_83EE58 and dword_83EE5C at unk_7D2E54, and returns the address of dword_7D2E50.
    // ASSIGNMENT: result = address of dword_7D2E50 (0x007D2E50). [source:raw, global:0x007D2E50]
    // ASSIGNMENT: dword_83EE5C = (int)&unk_7D2E54. [source:raw]
    // ASSIGNMENT: dword_83EE58 = (int)&unk_7D2E54. [source:raw]
    // ASSIGNMENT: dword_83EE54 = (int)&unk_7D2E54. [source:raw]
    // ASSIGNMENT: dword_7D2E50 (0x007D2E50) = 0. [source:raw, global:0x007D2E50]
    // RETURN: Return result, the address of dword_7D2E50 (0x007D2E50). [source:raw, function:0x004B2180]

    // Conservative worker pseudocode:
    //   int *resetDbListHead(void)
    //   {
    //       int *result = &dword_7D2E50;
    //       dword_83EE5C = (int)&unk_7D2E54;
    //       dword_83EE58 = (int)&unk_7D2E54;
    //       dword_83EE54 = (int)&unk_7D2E54;
    //       dword_7D2E50 = 0;
    //       return result;
    //   }
    // UNRESOLVED: ABI lead labels this a thunk to FUN_004b3ad0, but the decompiled body is a sequence of assignments, not a jump thunk; the thunk identity is unverified.
    // UNRESOLVED: Globals dword_83EE5C, dword_83EE58, dword_83EE54 and unk_7D2E54 appear in the raw source but carry no structured evidence_ref in the packet.
    // UNRESOLVED: The meaning of pointing three globals at unk_7D2E54 (shared node) while zeroing dword_7D2E50 is not explained by the packet.
}
