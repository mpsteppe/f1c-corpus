// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BE9E0
// Canonical corpus name: AnimationStateSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AnimationStateSetter_004be9e0.c

void UnknownObject::AnimationStateSetter()
{
    // Animation/behavior parameter setter: writes four parameters supplied by the caller into the object as two byte flags (this+0x340, this+0x341) and two DWORDs (this+0x344, this+0x350), then returns the third argument a4 unchanged. Called by AIBehaviorInitialization (0x004BF0A0) as part of behavior setup.
    // ASSIGNMENT: Store the first byte parameter a2 into this+0x340 [field:this:0x00000340, source:raw]
    // ASSIGNMENT: Store the second byte parameter a3 into this+0x341 [field:this:0x00000341, source:raw]
    // ASSIGNMENT: Store the DWORD parameter a4 into this+0x344; a4 is also captured into the return value [field:this:0x00000344, source:raw]
    // ASSIGNMENT: Store the DWORD parameter a5 into this+0x350 [field:this:0x00000350, source:raw]
    // RETURN: Return a4 (the value written to this+0x344) [source:raw]
    // CALL: Invoked by AIBehaviorInitialization (0x004BF0A0) to configure the object's animation/behavior parameters [caller:0x004BF0A0, source:raw]

    // Conservative worker pseudocode:
    //   int AnimationStateSetter(int this, char a2, char a3, int a4, int a5) {
    //     this[0x340] = a2;
    //     this[0x341] = a3;
    //     this[0x344] = a4;
    //     this[0x350] = a5;
    //     return a4;
    //   }
    // UNRESOLVED: Semantic meaning of the four stored fields (flags at +0x340/+0x341, values at +0x344/+0x350) depends on the object type, which is unknown here
}
