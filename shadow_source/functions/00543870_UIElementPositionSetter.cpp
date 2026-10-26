// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00543870
// Canonical corpus name: UIElementPositionSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIElementPositionSetter_00543870.c

void UnknownObject::UIElementPositionSetter()
{
    // UI element position setter (__thiscall): writes three 16-bit fields - a2 to this+0x18C, a4 to this+0x188 and a3 to this+0x18A - and ORs bit 0x10000 into the flags field at this+0xEC to signal that an update is pending. Returns the updated flags value. No guard - always writes all three positions and sets the flag.
    // ASSIGNMENT: Write the 16-bit value a2 into this+0x18C. [field:this:0x0000018C, source:raw]
    // ASSIGNMENT: Write the 16-bit value a4 into this+0x188. [field:this:0x00000188, source:raw]
    // CALCULATION: Read the flags field at this+0xEC and OR in bit 0x10000 to mark the position update as pending. [field:this:0x000000EC, source:raw]
    // ASSIGNMENT: Write the 16-bit value a3 into this+0x18A. [field:this:0x0000018A, source:raw]
    // ASSIGNMENT: Store the OR-updated flags value back into this+0xEC. [field:this:0x000000EC, source:raw]
    // RETURN: Return the updated flags value. [field:this:0x000000EC, source:raw]
    // CALL: Called by sub_4FCEE0 (0x004FCEE0) to set a UI element's position and flag it dirty. [caller:0x004FCEE0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_543870(void* this, __int16 a2, __int16 a3, __int16 a4) {
    //     *(__int16*)((char*)this + 396) = a2;
    //     *(__int16*)((char*)this + 392) = a4;
    //     *(__int16*)((char*)this + 394) = a3;
    //     unsigned flags = *(unsigned*)((char*)this + 236) | 0x10000;
    //     *(unsigned*)((char*)this + 236) = flags;
    //     return flags;
    //   }
    // UNRESOLVED: Whether the three 16-bit fields (this+0x188, this+0x18A, this+0x18C) are the element X/Y/Z position components is inferred from the caller context, not proven by this function alone.
    // UNRESOLVED: Semantics of flag bit 0x10000 at this+0xEC (assumed update-pending) are inferred, not independently confirmed.
    // UNRESOLVED: Owner class is unknown; sub_4FCEE0 is not analyzed in this packet.
}
