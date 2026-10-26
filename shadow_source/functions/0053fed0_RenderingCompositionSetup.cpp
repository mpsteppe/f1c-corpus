// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053FED0
// Canonical corpus name: RenderingCompositionSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RenderingCompositionSetup_0053fed0.c

void UnknownObject::RenderingCompositionSetup()
{
    // Rendering compositing setup. Chooses an alpha value from a4 flags: when a4[6] has bit 0x800 set and a4[13] is non-zero the alpha becomes a4[13] | 0xFF000000; when (unk_800000 & a4[6]) is set a labeled path is taken; otherwise alpha defaults to -65281. Locks the source via LockUnlockWrapper (error into this+0x0, returning -1 on failure), optionally fills the destination surface fields and calls sub_55C450 and sub_53F720 when a6 is null. Selects the output surface by the a5 flag value (4 or 8 use vtable slot +60 of v6[4]/v6[5]; 1 and 2 use v6[2]/v6[3]), then performs the compositing blit via sub_5008E4 and releases the surface for the 4/8 cases. Returns 0 on success, -1 on any failure.
    // ASSIGNMENT: Initialize alpha to 0 and read the flag word v7 = a4[6]. [source:raw]
    // GUARD: If bit 0x800 of a4[6] is set and a4[13] is non-zero, use alpha = a4[13] | 0xFF000000 and continue at the lock step. [source:raw]
    // GUARD: Else if the global unk_800000 bit is set in a4[6], take the same labeled path (alpha already chosen path). [global:0x00800000, source:raw]
    // ASSIGNMENT: Default alpha value when neither flag path applies: v19 = -65281. [source:raw]
    // CALL: Lock the source via LockUnlockWrapper(a2, a3, v20) and store the result into this+0x0. [callee:0x005006D5, field:this:0x00000000, source:raw]
    // GUARD: If the lock result in this+0x0 is non-zero, return -1 (failure). [source:raw]
    // GUARD: When a6 is null: copy fields from the locked data v20 into the surface v6 (v6[6], v6[7], v6[8]) and query format/size via sub_55C450(v20[4], v6+9, v6+12). [callee:0x0055C450, source:raw]
    // CALL: When a6 is null, call sub_53F720(this, v6, v6[11]); return -1 if it reports failure. [callee:0x0053F720, source:raw]
    // GUARD: When mode a5 == 4, dispatch vtable slot +60 of the surface object v6[4], store the result into this+0x0 and return -1 on failure. [source:raw]
    // GUARD: When mode a5 == 8, dispatch vtable slot +60 of the surface object v6[5], store the result into this+0x0 and return -1 on failure. [source:raw]
    // GUARD: When bit 0x1 of mode a5 is set, select the destination surface a4 = v6[2]. [source:raw]
    // GUARD: When bit 0x2 of mode a5 is set, select the destination surface a4 = v6[3]. [source:raw]
    // CALL: Perform the compositing blit: sub_5008E4(a4, 0, 0, a2, a3, 0, 1, v19, v20); store the result into this+0x0 and return -1 on failure. [callee:0x005008E4, field:this:0x00000000, source:raw]
    // GUARD: For modes 4 or 8, release the surface by dispatching vtable slot +8 of the destination a4. [source:raw]
    // RETURN: Return 0 on success; every failure path returns -1. [source:raw]

    // Conservative worker pseudocode:
    //   // 0x0053FED0
    //   alpha = 0;
    //   flags = a4[6];
    //   if ((flags & 0x800) && a4[13]) {
    //       alpha = a4[13] | 0xFF000000;
    //   } else if (unk_800000 & flags) {
    //       /* labeled alpha path * /
    //   } else {
    //       alpha = -65281;
    //   }
    //   this[0] = LockUnlockWrapper(a2, a3, v20);
    //   if (this[0]) return -1;
    //   if (!a6) {
    //       v6[8] = v20[1];
    //       v6[7] = v20[0];
    //       v6[6] |= a5;
    //       sub_55C450(v20[4], v6 + 9, v6 + 12);
    //       if (sub_53F720(this, v6, v6[11])) return -1;
    //   }
    //   if (a5 == 4) { this[0] = vtable60(v6[4], a6, &a4); if (this[0]) return -1; }
    //   else if (a5 == 8) { this[0] = vtable60(v6[5], a6, &a4); if (this[0]) return -1; }
    //   else if (a5 & 1) a4 = v6[2];
    //   else if (a5 & 2) a4 = v6[3];
    //   this[0] = sub_5008E4(a4, 0, 0, a2, a3, 0, 1, alpha, v20);
    //   if (this[0]) return -1;
    //   if (a5 == 4 || a5 == 8) vtable8(a4);
    //   return 0;
    // UNRESOLVED: The surface structure v6 (indexes 2, 3, 4, 5, 6, 7, 8, 9, 11, 12) has no field evidence in this packet; only this+0x0 is a packet field.
    // UNRESOLVED: The exact meaning of the alpha paths (0x800/unk_800000 flags) and the default -65281 value is not established beyond the raw source.
    // UNRESOLVED: The vtable slot +60 and +8 dispatch targets are indirect; their callees are not statically known here.
    // UNRESOLVED: The global unk_800000 is tested but its value and purpose are unverified; the existing analysis labels it MMX flag as DERIVED.
    // UNRESOLVED: Why modes 1 and 2 select v6[2]/v6[3] without a vtable dispatch while 4 and 8 dispatch is not explained by packet evidence.
}
