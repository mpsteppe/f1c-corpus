// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004258C0
// Canonical corpus name: sub_4258C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4258C0_004258c0.c

void UnknownObject::AISteeringStateInit()
{
    // AI steering dynamics reset: writes 0 to the accumulator at this+0x4434 and 1.0f (1065353216) to the multiplier at this+0x4438. If speed (float at this+0x4440) is below 4.0, or both threshold fields at this+0x37CC and this+0x38C4 exceed 0.9, sets driverStatus at this+0x4510 to 2. Called from AIMainUpdate.
    // CALCULATION: v1 = speed read as float at this+0x4440. [field:this:0x00004440, source:raw]
    // ASSIGNMENT: Set this+0x4438 to 1065353216 (1.0f). [field:this:0x00004438, source:raw]
    // ASSIGNMENT: Set this+0x4434 to 0. [field:this:0x00004434, source:raw]
    // GUARD: If v1 < 4.0, or (float at this+0x37CC > 0.9 AND float at this+0x38C4 > 0.9), set driverStatus. [field:this:0x00004440, field:this:0x000037CC, field:this:0x000038C4, source:raw]
    // ASSIGNMENT: Set this+0x4510 to 2 (driverStatus). [field:this:0x00004510, source:raw]

    // Conservative worker pseudocode:
    //   void AISteeringStateInit(int this) {
    //     float speed = *(float *)(this + 0x4440);
    //     *(_DWORD *)(this + 0x4438) = 1065353216;
    //     *(_DWORD *)(this + 0x4434) = 0;
    //     if (speed < 4.0f || (*(float *)(this + 0x37CC) > 0.9f && *(float *)(this + 0x38C4) > 0.9f))
    //       *(_DWORD *)(this + 0x4510) = 2;
    //   }
    // UNRESOLVED: Globals flt_59E46C (0x0059E46C) and flt_59E824 (0x0059E824) are listed as referenced but do not appear in the raw source text; their role is ungrounded.
    // UNRESOLVED: Semantics of the two 0.9 threshold fields (this+0x37CC, this+0x38C4) and of driverStatus value 2 are derived from surrounding context only, not from raw source.
}
