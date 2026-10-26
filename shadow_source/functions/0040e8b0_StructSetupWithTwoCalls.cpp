// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040E8B0
// Canonical corpus name: StructSetupWithTwoCalls
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructSetupWithTwoCalls_0040e8b0.c

void UnknownObject::StructSetupWithTwoCalls()
{
    // Initializes fields of a structure: writes word a2 into this+0x8, stores constant 8 into this+0x1C, and stores a3 into this+0x20. Then calls LightFrustumClosestPoint with a3 and output float pointers this+0x0C and this+0x18 to compute the closest point in a light frustum, and returns the result of NestedLoopRangeTraversal(this). Called by sub_40FE50.
    // ASSIGNMENT: Store the 16-bit argument a2 into the word at this+0x8 (type/index discriminator) [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Store the constant 8 into the DWORD at this+0x1C (subtype/kind constant) [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Store argument a3 into the DWORD at this+0x20 (external data carried through to the sub-calls) [field:this:0x00000020, source:raw]
    // CALL: Call LightFrustumClosestPoint with a3 and the float output pointers this+0x0C and this+0x18 to compute the closest point of the light frustum [callee:0x0040E480, source:raw]
    // RETURN: Return the result of NestedLoopRangeTraversal(this), which traverses/validates the structure's range data [callee:0x004BE1D0, source:raw]
    // CALL: Invoked by sub_40FE50 (0040FE50) to set up the light/shadow structure before its range data is processed [caller:0x0040FE50, source:raw]

    // Conservative worker pseudocode:
    //   *(WORD*)(this + 8) = a2;
    //   *(DWORD*)(this + 0x1C) = 8;
    //   *(DWORD*)(this + 0x20) = a3;
    //   LightFrustumClosestPoint(a3, (float*)(this + 0x0C), (float*)(this + 0x18));
    //   return NestedLoopRangeTraversal(this);
    // UNRESOLVED: Global dword_8AB710 is flagged by packet facts as read-only but appears nowhere in the raw decompiled source; its role here cannot be verified
    // UNRESOLVED: The interpretation of this structure as a light/shadow object is inferred from the sibling analysis and callee name only, and is not proven within this function
    // UNRESOLVED: The DWORD at this+0x0C/this+0x18 written by LightFrustumClosestPoint is not listed as a packet field
}
