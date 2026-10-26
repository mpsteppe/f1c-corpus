// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BE700
// Canonical corpus name: PerformanceSetupStructInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PerformanceSetupStructInitializer_004be700.c

void UnknownObject::PerformanceSetupStructInitializer()
{
    // Initializes an AI performance/setup configuration struct on `this` to defaults: enables two boolean flags at byte offsets 0x340 and 0x341, disables a third flag at 0x342, writes four default float parameters (1065353216/1.0f at 0x344, 1065353216/1.0f at 0x348, 1142292480/600.0f at 0x34C, 1092616192/10.0f at 0x350), zeroes two float accumulators at 0x354 and 0x358, and sets an integer countdown (10) and mode identifier (5) at 0x35C and 0x360. Returns 0. Invoked by Delegation_e6f0 (0x004BE6F0).
    // ASSIGNMENT: Write byte 1 (enabled) to this+0x340. [field:this:0x00000340, source:raw]
    // ASSIGNMENT: Write byte 1 (enabled) to this+0x341. [field:this:0x00000341, source:raw]
    // ASSIGNMENT: Write byte 0 (disabled) to this+0x342. [field:this:0x00000342, source:raw]
    // ASSIGNMENT: Write dword 1065353216 (1.0f) to this+0x344. [field:this:0x00000344, source:raw]
    // ASSIGNMENT: Write dword 1065353216 (1.0f) to this+0x348. [field:this:0x00000348, source:raw]
    // ASSIGNMENT: Write dword 1142292480 (600.0f) to this+0x34C. [field:this:0x0000034C, source:raw]
    // ASSIGNMENT: Write dword 1092616192 (10.0f) to this+0x350. [field:this:0x00000350, source:raw]
    // ASSIGNMENT: Write dword 0 (zeroed accumulator) to this+0x354. [field:this:0x00000354, source:raw]
    // ASSIGNMENT: Write dword 0 (zeroed accumulator) to this+0x358. [field:this:0x00000358, source:raw]
    // ASSIGNMENT: Write dword 10 (countdown or limit) to this+0x35C. [field:this:0x0000035C, source:raw]
    // ASSIGNMENT: Write dword 5 (session/mode identifier) to this+0x360. [field:this:0x00000360, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int PerformanceSetupStructInitializer(this) {
    //     this[0x340] = 1; this[0x341] = 1; this[0x342] = 0;
    //     *(dword*)(this + 0x344) = 1065353216; /* 1.0f * /
    //     *(dword*)(this + 0x348) = 1065353216; /* 1.0f * /
    //     *(dword*)(this + 0x34C) = 1142292480; /* 600.0f * /
    //     *(dword*)(this + 0x350) = 1092616192; /* 10.0f * /
    //     *(dword*)(this + 0x354) = 0; *(dword*)(this + 0x358) = 0;
    //     *(dword*)(this + 0x35C) = 10; *(dword*)(this + 0x360) = 5;
    //     return 0;
    //   }
    // UNRESOLVED: Exact purpose of the per-field float parameters (1.0, 1.0, 600.0, 10.0) and of integer fields 10 and 5 depends on the owning struct's role in the AI performance/setup system; the raw source only assigns values.
    // UNRESOLVED: Packet facts list a read of dword_5ACDAC (0x005ACDAC) that is not visible in the raw decompiled source; its role in this function is unknown.
}
