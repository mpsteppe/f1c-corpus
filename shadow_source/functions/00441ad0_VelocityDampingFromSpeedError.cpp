// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00441AD0
// Canonical corpus name: VelocityDampingFromSpeedError
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VelocityDampingFromSpeedError_00441ad0.c

void UnknownObject::VelocityDampingFromSpeedError()
{
    // Computes an aerodynamic velocity damping force from the difference between the body speed and a reference speed (8.0): guarded by an enable byte and a mode dword on the state struct at this+0x1F00 and by a global flag, reads the body at this+0x15F0, forms the speed error scaled by 93.75, applies the direction scalar at this+0x48 (sign-flipped when this+0x1EF0 is not -1), and accumulates the resulting force into the body force buffer at body+0x134/0x13C/0x144.
    // GUARD: Read the byte enable flag at *(this+0x1F00)+0x344C; skip the whole routine when it is zero. [field:this:0x00001F00, field:*(this+0x1F00):0x0000344C, source:raw]
    // GUARD: Read the mode dword at *(this+0x1F00)+0x3450; skip the damping when it equals 3. [guard:0, field:*(this+0x1F00):0x00003450, source:raw]
    // GUARD: Skip the routine unless the global byte_7CE838 is nonzero. [global:0x007CE838, source:raw]
    // CALCULATION: Load the body pointer v4 = *(this+0x15F0) and compute v5 = (8.0 - sqrt(*(v4+0x64)^2 + *(v4+0x6C)^2 + *(v4+0x74)^2)) * 93.75. The reference speed 8.0 and the gain 93.75 are compiled as the three double globals (dbl_59E430, dbl_59ED40, dbl_59ED48), whose individual assignment to the two constants is not determined. [field:this:0x000015F0, field:*(this+0x15F0):0x00000064, field:*(this+0x15F0):0x0000006C, field:*(this+0x15F0):0x00000074, global:0x0059E430, global:0x0059ED40, global:0x0059ED48, source:raw]
    // GUARD: Proceed with damping only when the speed error v5 is greater than 0.0. [source:raw]
    // CALCULATION: Read the direction scalar v6 = *(this+0x48); when the dword at this+0x1EF0 is not -1, negate it (v6 = -v6). [guard:1, field:this:0x00000048, field:this:0x00001EF0, source:raw]
    // CALCULATION: Accumulate the damping force into the body force buffer: v7 = v5*v6* *(v4+0x44), v8 = v5*v6* *(v4+0x5C); then *(v4+0x134) += v5*v6* *(v4+0x2C), *(v4+0x13C) += v7, *(v4+0x144) += v8. [field:*(this+0x15F0):0x0000002C, field:*(this+0x15F0):0x00000044, field:*(this+0x15F0):0x0000005C, field:*(this+0x15F0):0x00000134, field:*(this+0x15F0):0x0000013C, field:*(this+0x15F0):0x00000144, source:raw]

    // Conservative worker pseudocode:
    //   void VelocityDampingFromSpeedError(int this) {
    //     char* state = *(char**)(this + 0x1F00);
    //     if (!*(char*)(state + 13388)) return;
    //     if (*(int*)(state + 13392) == 3) return;
    //     if (!byte_7CE838) return;
    //     char* body = *(char**)(this + 0x15F0);
    //     double mag = sqrt(*(double*)(body+100)**(double*)(body+100)
    //                     + *(double*)(body+108)**(double*)(body+108)
    //                     + *(double*)(body+116)**(double*)(body+116));
    //     double err = (8.0 - mag) * 93.75;
    //     if (err <= 0.0) return;
    //     double dir = *(double*)(this + 72);
    //     if (*(int*)(this + 7920) != -1) dir = -dir;
    //     *(double*)(body + 308) += err * dir * *(double*)(body + 44);
    //     *(double*)(body + 316) += err * dir * *(double*)(body + 68);
    //     *(double*)(body + 324) += err * dir * *(double*)(body + 92);
    //   }
    // UNRESOLVED: Which of the three double globals (dbl_59E430, dbl_59ED40, dbl_59ED48) supplies the 8.0 reference speed versus the 93.75 gain is not determinable from this packet.
    // UNRESOLVED: Meaning of the mode dword at *(this+0x1F00)+0x3450 and why value 3 disables damping.
    // UNRESOLVED: Whether the direction scalar at this+0x48 and the sign selector at this+0x1EF0 map to a reverse/brake direction flag; the existing analysis labels this+0x1EF0 as a direction sign selector, which is DERIVED.
    // UNRESOLVED: The velocity components at body+0x2C/0x44/0x5C versus the magnitude components at body+0x64/0x6C/0x74 are read as distinct vectors, but their exact physical roles (e.g. local vs world velocity) are not confirmed.
}
