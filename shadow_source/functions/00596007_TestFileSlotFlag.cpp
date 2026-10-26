// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00596007
// Canonical corpus name: sub_596007
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_596007_00596007.c

void UnknownObject::TestFileSlotFlag()
{
    // Bounds-checked per-slot flag test on a global slot-group table. dword_8D4920 holds pointers to groups of 32 slots (36 bytes each); uNumber is the total slot count. If the requested index a1 is below uNumber, resolves the slot base as dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F), reads the byte at slot + 4, and returns it masked with 0x40 (so the result is 0x40 or 0). Out-of-range indices return 0. Callers (sub_58CF35, sub_58E41B, sub_59C1E7) use the non-zero result as a gate before per-slot initialization, so bit 0x40 of the slot flag byte is a state that permits or blocks an operation on that slot.
    // GUARD: Bounds check: only proceed when a1 < uNumber; otherwise return 0. [global:0x008D4A20, source:raw]
    // CALCULATION: Select the slot group: dword_8D4920[a1 >> 5] indexes the group-pointer array by a1 / 32. [global:0x008D4920, source:raw]
    // CALCULATION: Resolve the slot base within the group: group base + 36 * (a1 & 0x1F), i.e. a stride of 36 bytes per in-group slot. [source:raw]
    // CALCULATION: Read the byte at slot base + 4 and mask it with 0x40, yielding a non-zero result when bit 0x40 is set. [source:raw]
    // RETURN: Return the masked flag byte (0x40 or 0), or 0 for out-of-range indices. Serves as a validity/state gate for the file-slot callers sub_58CF35, sub_58E41B, and sub_59C1E7. [caller:0x0058CF35, caller:0x0058E41B, caller:0x0059C1E7, function:0x00596007, source:raw]

    // Conservative worker pseudocode:
    //   int TestFileSlotFlag(int index) {
    //     if (index >= uNumber) return 0;
    //     char* slot = dword_8D4920[index >> 5] + 36 * (index & 0x1F);
    //     return slot[4] & 0x40;
    //   }
    // UNRESOLVED: Meaning of bit 0x40 in the flag byte at slot + 4 is not established by this function; callers treat a non-zero result as permission to initialize or operate on the slot, but the exact state it encodes is unknown.
    // UNRESOLVED: The concrete type of the 36-byte slot entries and what the other flag bits of the slot flag byte represent.
    // UNRESOLVED: Why the group-pointer array is indexed by a1 >> 5 (32 slots per group) while uNumber bounds the flat index; the relationship is structurally clear but the object that owns the table is unknown.
}
