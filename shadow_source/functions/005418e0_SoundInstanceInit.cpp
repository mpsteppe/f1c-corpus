// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005418E0
// Canonical corpus name: SoundInstanceInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SoundInstanceInit_005418e0.c

void UnknownObject::SoundInstanceInit()
{
    // Default-initialises a 3D sound-emitter instance. Sets playback/gain defaults (volume 1.0, max attenuation distance 1000.0), zeroes position/velocity and runtime playback state, configures cone angles (90/75 degrees), stores the sound-name string via strcpy, and initialises the 3D position/orientation sub-object through UtilityFunction_1cd0. Returns 0.
    // CALL: Initialise the 3D position/orientation sub-object via UtilityFunction_1cd0(0, 0, 0.0, 0, 0, 0). [callee:0x00541CD0, source:raw]
    // ASSIGNMENT: Set sound volume/gain field this+0x4 to 1065353216 (1.0f). [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Set max attenuation distance this+0x8 to 1148846080 (1000.0f). [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Zero playback state this+0xC, instance id this+0x10, priority this+0x14, playback cursor this+0x18, playback flags this+0x1C and sound group this+0x20. [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, source:raw]
    // ASSIGNMENT: Zero 3D position this+0x3C, this+0x40, this+0x44 and orientation/velocity fields this+0x48 through this+0x68. [field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060, field:this:0x00000064, field:this:0x00000068, source:raw]
    // ASSIGNMENT: Set cone inner/outer attenuation fields: this+0x6C = 1119092736 (90.0f), this+0x70 = 1117126656 (75.0f), this+0x74 = 1065353216 (1.0f), this+0x78 = 0, this+0x7C = 0. [field:this:0x0000006C, field:this:0x00000070, field:this:0x00000074, field:this:0x00000078, field:this:0x0000007C, source:raw]
    // ASSIGNMENT: Set this+0x80 = 34, this+0x84 = 18446744073709551615 (-1, unassigned handle), this+0x88 = 1065353216 (1.0f). [field:this:0x00000080, field:this:0x00000084, field:this:0x00000088, source:raw]
    // ASSIGNMENT: Store the audio device/session pointer dword_484848 into this+124 (0x7C). [global:0x00484848, field:this:0x0000007C, source:raw]
    // ASSIGNMENT: Copy the sound-name argument a2 into the instance name buffer at this+140 via strcpy. [source:raw]
    // ASSIGNMENT: Zero the runtime playback state block at this+156 for 0x60 bytes via memset. [source:raw]
    // ASSIGNMENT: Zero extended instance fields this+412 through this+440 (0x19C, 0x1A0, 0x1A4, 0x1A8, 0x1AC, 0x1B0, 0x1B4, 0x1B8). [field:this:0x0000019C, field:this:0x000001A0, field:this:0x000001A4, field:this:0x000001A8, field:this:0x000001AC, field:this:0x000001B0, field:this:0x000001B4, field:this:0x000001B8, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int SoundInstanceInit(void *this, const char *name) {
    //     this->volume = 1.0f;
    //     this->maxDist = 1000.0f;
    //     // zero playback state, instance id, priority, cursor, flags, group
    //     // zero 3D position/orientation fields 0x3C..0x68
    //     // cone angles: 90.0f, 75.0f, 1.0f, 0, 0
    //     // 34, -1, 1.0f at 0x80, 0x84, 0x88
    //     this->device = dword_484848;
    //     strcpy(this->name, name);
    //     memset(this->playback, 0, 0x60);
    //     return 0;
    //   }
    // UNRESOLVED: The exact semantics of the texture-blit flag path are not present in this function.
    // UNRESOLVED: Semantic purpose of fields 0x3C..0x68 (position vs orientation split) is not proven by this packet alone.
    // UNRESOLVED: The identity of the object whose pointer is copied from dword_484848 is not resolvable here.
}
