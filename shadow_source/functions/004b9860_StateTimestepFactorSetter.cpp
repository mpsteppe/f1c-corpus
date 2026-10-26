// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9860
// Canonical corpus name: SingleFunctionCallWrapper_9860
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleFunctionCallWrapper_9860_004b9860.c

void UnknownObject::StateTimestepFactorSetter()
{
    // Records the caller-supplied index a2 into obj+0x9AC, then maps a2 (0-4) to one of five float-constant bit patterns stored at obj+0xF7C. An a2 outside 0-4 writes only the index field and returns. obj is obtained by dereferencing this+0x0.
    // ASSIGNMENT: Dereference this+0x0 to obtain obj; write a2 into obj+0x9AC. [field:this:0x00000000, field:obj:0x000009AC, source:raw, function:0x004B9860]
    // GUARD: When a2 is outside 0..4 the switch falls to default and returns a2 immediately, leaving obj+0xF7C unchanged. [field:obj:0x00000F7C, source:raw, function:0x004B9860]
    // ASSIGNMENT: a2 == 0: store constant 1042983595 into obj+0xF7C. [field:obj:0x00000F7C, source:raw]
    // ASSIGNMENT: a2 == 1: store constant 1040187392 into obj+0xF7C. [field:obj:0x00000F7C, source:raw]
    // ASSIGNMENT: a2 == 2: store constant 1036831949 into obj+0xF7C. [field:obj:0x00000F7C, source:raw]
    // ASSIGNMENT: a2 == 3: store constant 1034594987 into obj+0xF7C. [field:obj:0x00000F7C, source:raw]
    // ASSIGNMENT: a2 == 4: store constant 1026206379 into obj+0xF7C. [field:obj:0x00000F7C, source:raw]
    // RETURN: Return a2 (the index value) as the function result. [source:raw, function:0x004B9860]

    // Conservative worker pseudocode:
    //   int SetTimestepFactor(this, a2) {
    //     obj = *this;
    //     obj[0x9AC] = a2;
    //     switch (a2) {
    //       case 0: obj[0xF7C] = 1042983595; break;
    //       case 1: obj[0xF7C] = 1040187392; break;
    //       case 2: obj[0xF7C] = 1036831949; break;
    //       case 3: obj[0xF7C] = 1034594987; break;
    //       case 4: obj[0xF7C] = 1026206379; break;
    //       default: return a2;
    //     }
    //     return a2;
    //   }
    // UNRESOLVED: The object reached via this+0x0 is untyped; 0x9AC/0xF7C interpreted as timestep index and factor by prior analysis (DERIVED), not confirmed.
    // UNRESOLVED: The constant bit patterns are float literals as compiled; no IEEE-754 decode is asserted here.
    // UNRESOLVED: Single caller sub_4BA460; the write of a2 to obj+0x9AC persists regardless of a2 range, only the obj+0xF7C constant is conditional.
}
