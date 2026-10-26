// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004485C5
// Canonical corpus name: DualFieldStore
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualFieldStore_004485c5.c

void UnknownObject::DualFieldStore()
{
    // Unconditional dual-field store under fastcall (a1 in ECX, a2 in EDX as the target pointer): writes a1 into the target structure at both 0x58 (88) and 0x5C (92). Existing fill (DualFieldStore_004485c5) corroborates the mechanics and notes both fields are overwritten every call so an external poke survives.
    // ASSIGNMENT: Store a1 into the target-structure DWORD at offset 0x58 (88). [field:this:0x00000058, source:raw]
    // ASSIGNMENT: Store a1 into the target-structure DWORD at offset 0x5C (92). [field:this:0x0000005C, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4485C5(int a1, int a2, int a3)
    //   {
    //     *(DWORD*)(a2 + 88) = a1;
    //     *(DWORD*)(a2 + 92) = a1;
    //   }
    // UNRESOLVED: a3 is never referenced; it may be a vestigial parameter.
    // UNRESOLVED: Purpose of storing the same value into both 0x58 and 0x5C is unknown; possibly twin caches or a logical pair the compiler kept as two DWORDs.
    // UNRESOLVED: Target object identity and caller context are not present in the packet.
}
