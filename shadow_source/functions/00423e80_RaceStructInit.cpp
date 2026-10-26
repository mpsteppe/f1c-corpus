// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00423E80
// Canonical corpus name: RaceStructInit
// Owner: F1CVehicle [CONFIRMED]
// Raw source: functions/RaceStructInit_00423e80.c

void F1CVehicle::RaceStructInit()
{
    // Vehicle race-struct constructor/initializer: constructs the tire-system sub-object at this+3 and the sub-object at this+4109, clears AI state flags, then zeroes or sentinel-initializes ~50 fields across the race state region (0x413C..0x461C). Field literals include -1 sentinels (0x4, 0x8, 0x44B0), float 1.0 values (0x4438, 0x4444), byte-flag ones (0x445C, 0x4488) and the 2139095039 sentinel (0x413C, 0x4484). Returns this.
    // CALL: Construct physics tire-system sub-object at this + 3 (dword index). [callee:0x004E4500, source:raw]
    // CALL: Construct sub-object at this + 4109 (dword index) via ShortComputation_b7a0. [callee:0x004BB7A0, source:raw]
    // CALL: Clear AI state flags on this. [callee:0x0042AE00, source:raw]
    // ASSIGNMENT: Set this[0] (postProcessInput) to 0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Set this[1] to -1. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Set this[2] to -1. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Set PitDecisionTimer (0x413C) to the 2139095039 sentinel. [field:this:0x0000413C, source:raw]
    // ASSIGNMENT: Set byte at 0x4140 to 0. [field:this:0x00004140, source:raw]
    // ASSIGNMENT: Set this[4187] (0x416C) to 0. [field:this:0x0000416C, source:raw]
    // ASSIGNMENT: Set this[4188] (0x4170) to 0. [field:this:0x00004170, source:raw]
    // ASSIGNMENT: Zero-init state/flag block 0x43F4..0x4434: this[4349]..this[4365] and byte 0x4410. [field:this:0x000043F4, field:this:0x000043F8, field:this:0x000043FC, field:this:0x00004400, field:this:0x00004404, field:this:0x00004408, field:this:0x0000440C, field:this:0x00004410, field:this:0x00004414, field:this:0x00004418, field:this:0x0000441C, field:this:0x00004420, field:this:0x00004424, field:this:0x00004428, field:this:0x0000442C, field:this:0x00004430, field:this:0x00004434, source:raw]
    // ASSIGNMENT: Set this[4366] (0x4438) to 1065353216 (packet labels as float 1.0). [field:this:0x00004438, source:raw]
    // ASSIGNMENT: Zero-init this[4367] (0x443C) and this[4368] (0x4440, Speed). [field:this:0x0000443C, field:this:0x00004440, source:raw]
    // ASSIGNMENT: Set this[4369] (0x4444) to 1065353216 (packet labels as float 1.0). [field:this:0x00004444, source:raw]
    // ASSIGNMENT: Zero-init this[4370]..this[4374] (0x4448, 0x444C, 0x4450 trackPartFromPitExit, 0x4454, 0x4458). [field:this:0x00004448, field:this:0x0000444C, field:this:0x00004450, field:this:0x00004454, field:this:0x00004458, source:raw]
    // ASSIGNMENT: Set byte at 0x445C to 1. [field:this:0x0000445C, source:raw]
    // ASSIGNMENT: Zero-init this[4378]..this[4384] (0x4468, 0x446C, 0x4470, 0x4474, 0x4478, 0x447C, 0x4480). [field:this:0x00004468, field:this:0x0000446C, field:this:0x00004470, field:this:0x00004474, field:this:0x00004478, field:this:0x0000447C, field:this:0x00004480, source:raw]
    // ASSIGNMENT: Set this[4385] (0x4484) to the 2139095039 sentinel. [field:this:0x00004484, source:raw]
    // ASSIGNMENT: Set byte at 0x4488 to 1. [field:this:0x00004488, source:raw]
    // ASSIGNMENT: Zero-init this[4387]..this[4395] (0x448C..0x44AC). [field:this:0x0000448C, field:this:0x00004490, field:this:0x00004494, field:this:0x00004498, field:this:0x0000449C, field:this:0x000044A0, field:this:0x000044A4, field:this:0x000044A8, field:this:0x000044AC, source:raw]
    // ASSIGNMENT: Set this[4396] (0x44B0) to -1. [field:this:0x000044B0, source:raw]
    // ASSIGNMENT: Set byte at 0x45F4 (AIControlFlag) to 0. [field:this:0x000045F4, source:raw]
    // ASSIGNMENT: Zero-init this[4478] (0x45F8) and this[4479] (0x45FC). [field:this:0x000045F8, field:this:0x000045FC, source:raw]
    // ASSIGNMENT: Set this[4487] (0x461C) to 0. [field:this:0x0000461C, source:raw]
    // RETURN: Return this. [function:0x00423E80, source:raw]

    // Conservative worker pseudocode:
    //   DWORD *RaceStructInit(this) {
    //     PhysicsTireSystemConstructor(this + 3);
    //     ShortComputation_b7a0(this + 4109);
    //     this[0] = 0; this[1] = -1;
    //     AIClearStateFlags(this);
    //     /* zero-init and sentinel-init race state region 0x413C..0x461C * /
    //     return this;
    //   }
    // UNRESOLVED: Most field offsets (0x4140..0x44AC region) have no semantic name in the packet; they are initialized to 0/1/-1/1065353216/2139095039 without per-field meaning.
    // UNRESOLVED: Literal 2139095039 at 0x413C and 0x4484 is kept in packet decimal spelling; no IEEE-754 interpretation asserted.
    // UNRESOLVED: Byte-width writes at 0x4140, 0x4410, 0x445C, 0x4488, 0x45F4 overlap sub-regions whose layout is not fully known.
}
