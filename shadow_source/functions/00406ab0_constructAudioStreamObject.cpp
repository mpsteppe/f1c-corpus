// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00406AB0
// Canonical corpus name: GenericObjectConstructorWithVTable
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GenericObjectConstructorWithVTable_00406ab0.c

void UnknownObject::constructAudioStreamObject()
{
    // Constructor for a stream-like object. Zeroes the data block this[2]..this[18] (+0x8..+0x48), installs the vtable global off_59E530 at +0x0, sets scalar members (1 at +0x4, 1.0f at +0x8C, 2 at +0x54), zeroes the tail fields +0x88..+0x9C, and calls MilesSoundSystemSampleAllocator(0) before returning this. Invoked once from the one-time initialization path.
    // ASSIGNMENT: Zero the data field block from this[2] (+0x8) through this[18] (+0x48). [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048]
    // ASSIGNMENT: Install the vtable global off_59E530 as the object vtable at +0x0. [field:this:0x00000000, global:0x0059E530]
    // ASSIGNMENT: Set this[1] at +0x4 to 1. [field:this:0x00000004]
    // ASSIGNMENT: Set this[34] at +0x88 to 0. [field:this:0x00000088]
    // ASSIGNMENT: Set this[35] at +0x8C to 1065353216 (1.0f). [field:this:0x0000008C]
    // ASSIGNMENT: Set this[36] at +0x90 to 0. [field:this:0x00000090]
    // ASSIGNMENT: Set this[37] at +0x94, this[38] at +0x98 and this[39] at +0x9C to 0. [field:this:0x00000094, field:this:0x00000098, field:this:0x0000009C]
    // ASSIGNMENT: Set this[21] at +0x54 to 2. [field:this:0x00000054]
    // CALL: Call MilesSoundSystemSampleAllocator(0) to allocate/initialize the Miles sample handle for the stream object. [callee:0x004072E0, source:raw]
    // RETURN: Return the constructed object pointer (this). [function:0x00406AB0, source:raw]

    // Conservative worker pseudocode:
    //   this[2..18] = 0;
    //   this->vftable = &off_59E530;
    //   this[1] = 1;
    //   this[34] = 0;
    //   this[35] = 1.0f;
    //   this[36] = 0;
    //   this[37] = 0; this[38] = 0; this[39] = 0;
    //   this[21] = 2;
    //   MilesSoundSystemSampleAllocator(0);
    //   return this;
    // UNRESOLVED: The owning class is unknown; the audio-stream interpretation comes from the existing skeleton analysis (AudioStreamObjectConstructor), which is prose, not independent evidence.
    // UNRESOLVED: The roles of the 1.0f float at +0x8C, the 1 at +0x4 and the 2 at +0x54 are DERIVED (assumed sample count / float scale / selector), not confirmed.
    // UNRESOLVED: The type identity of the vtable target off_59E530 is referenced but not independently confirmed.
}
