// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049ADB0
// Canonical corpus name: ShortComputation_adb0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_adb0_0049adb0.c

void UnknownObject::Field0xCGetter()
{
    // Getter: reads the dword field at this+0xC (this[3]) and returns it with no side effects. Used as a small accessor by thirteen callers across settings-copy, UI-scroll, media/audio and object-lookup paths.
    // CALCULATION: Read the dword field at this+0xC (this[3]) to form the return value; no other state is touched. [field:this:0x0000000C, source:raw]
    // RETURN: Return the read value to its callers, including ConditionalDelegation, UIScrollAreaAutoScrollManager, TwoChannel16BitReader, PitStopOrderLoader and ObjectIDLookupAcross9Arrays. [caller:0x0040DD30, caller:0x00432220, caller:0x00487060, caller:0x004870E0, caller:0x00487160, caller:0x0048D850, caller:0x0048D9D0, caller:0x00499F00, caller:0x0049AE40, caller:0x004D12C0, caller:0x004FE350, caller:0x00567A90, caller:0x005684A0, source:raw]

    // Conservative worker pseudocode:
    //   int Field0xCGetter(_DWORD* this) {
    //     return this[3];
    //   }
    // UNRESOLVED: The owning class is unknown; the semantic role of the dword at this+0xC (an index, handle or count) is not established by the packet alone.
    // UNRESOLVED: Whether the field is read as a signed or unsigned quantity is not determined by the raw source.
}
