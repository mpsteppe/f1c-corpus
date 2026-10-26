// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C0370
// Canonical corpus name: StructInitWithDefaults
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithDefaults_004c0370.c

void UnknownObject::StructInitWithDefaults()
{
    // Constructor/initializer that sets nine fields on this to sentinel-heavy defaults: +0x0 and +0x8 are cleared to 0, all others (+0x4, +0xC, +0x10, +0x14, +0x18, +0x1C, +0x20) are set to -1. Returns this. Called by AudioSubsystemInitializer (004C0AB0) during audio subsystem setup. No reads, no globals, no callees.
    // ASSIGNMENT: Set field +0x0 to 0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Set field +0x4 to -1. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Set field +0x8 to 0. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Set field +0xC to -1. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Set field +0x10 to -1. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Set field +0x14 to -1. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Set field +0x18 to -1. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Set field +0x1C to -1. [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Set field +0x20 to -1. [field:this:0x00000020, source:raw]
    // RETURN: Return the initialized object pointer this. [source:raw]
    // CALL: Invoked by AudioSubsystemInitializer (004C0AB0) as part of audio subsystem setup. [caller:0x004C0AB0, source:raw]

    // Conservative worker pseudocode:
    //   this[0] = 0;
    //   this[1] = -1;
    //   this[2] = 0;
    //   this[3] = -1;
    //   this[4] = -1;
    //   this[5] = -1;
    //   this[6] = -1;
    //   this[7] = -1;
    //   this[8] = -1;
    //   return this;
    // UNRESOLVED: Which of these defaulted fields are later enabled or re-assigned by the audio subsystem is unknown from this function.
    // UNRESOLVED: No callees or globals are present, so the struct's role beyond a sentinel-heavy default state is not inferable here.
}
