// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00554E90
// Canonical corpus name: sub_554E90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_554E90_00554e90.c

void UnknownObject::sub_554E90()
{
    // Texture-resource creation routine. Resolves the resource descriptor at *(a2+84); returns -2 if it is already marked created (*(v3+20) non-zero). Begins creation via a virtual dispatch at vtable+72 on the object at *(v3+16). Depending on the sign of the byte at *(v3+24), either delegates format setup to sub_55C650, or maps the format enum at *(v3+48) (values 9..0xD, via the jump table jpt_554ED2) to one of the 827611204/844388420/861165636/877942852/894720068 constants assigned to a2. Then invokes the device virtual method at vtable+80 through this+0x1100, storing the result in *this; returns -1 on failure (non-zero result) and 0 on success after setting flag 0x8 on *(v3+24).
    // GUARD: v3 = *(a2+84); if *(v3+20) is non-zero (already created), return -2. [source:raw]
    // CALL: *this = virtual call at vtable+72 on the object at *(v3+16) with argument 0 — begin resource creation. [field:this:0x00000000, source:raw]
    // GUARD: If the byte at *(v3+24) has its sign bit clear (>= 0), take the uncompressed-format path. [source:raw]
    // CALL: sub_55C650(&a2, *(v3+48), 0) — configure the uncompressed texture format. [callee:0x0055C650, source:raw]
    // STATE_TRANSITION: Otherwise switch on the format enum at *(v3+48) via the jump table jpt_554ED2: case 9 sets a2 = 827611204, case 0xA sets a2 = 844388420, case 0xB sets a2 = 861165636, case 0xC sets a2 = 877942852, case 0xD sets a2 = 894720068; default leaves a2 unchanged. [global:0x00554F6C, source:raw]
    // CALCULATION: v6 = *(v2+80); if v6 is zero it is replaced with 1 (minimum level count). [source:raw]
    // CALL: *this = virtual call at vtable+80 of the device object this[1088] (this+0x1100), passing *(v3+28), *(v3+32), v6, 0, a2, 0, and v3+20 — final resource creation dispatch. [field:*(this+0x1100):0x00000050, field:this:0x00001100, field:this:0x00000000, source:raw]
    // GUARD: If the creation dispatch result v7 is non-zero (creation failed), return -1. [source:raw]
    // ASSIGNMENT: On success set the created/ready flag: *(v3+24) |= 8. [source:raw]
    // RETURN: Return 0 on success. [function:0x00554E90, source:raw]

    // Conservative worker pseudocode:
    //   v3 = *(a2+84);
    //   if (*(v3+20) != 0) return -2;
    //   *this = (vtable[*(v3+16)] + 72)(*(v3+16), 0);
    //   if (*(v3+24) >= 0) {
    //     sub_55C650(&a2, *(v3+48), 0);
    //   } else {
    //     switch (*(v3+48)) {
    //       case 9:  a2 = 827611204; break;
    //       case 0xA: a2 = 844388420; break;
    //       case 0xB: a2 = 861165636; break;
    //       case 0xC: a2 = 877942852; break;
    //       case 0xD: a2 = 894720068; break;
    //       default: break;
    //     }
    //   }
    //   v6 = *(a2+80); if (v6 == 0) v6 = 1;
    //   *this = (vtable[this[1088]] + 80)(this[1088], *(v3+28), *(v3+32), v6, 0, a2, 0, v3+20);
    //   if (*this != 0) return -1;
    //   *(v3+24) |= 8;
    //   return 0;
    // UNRESOLVED: The identities of the two virtual-dispatch targets (vtable+72 and vtable+80) are not resolved; they are opaque interface methods.
    // UNRESOLVED: The 827611204/844388420/861165636/877942852/894720068 constants are interpreted in existing analysis as DXT FourCC codes but that mapping is not proven by this packet; treated here as opaque format constants.
    // UNRESOLVED: The meaning of the byte at *(v3+24) sign bit (compressed vs uncompressed path) is inferred, not independently established.
    // UNRESOLVED: The caller sub_554F80 (0x00554F80) is not analyzed in this packet.
}
