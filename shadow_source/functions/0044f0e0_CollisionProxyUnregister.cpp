// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044F0E0
// Canonical corpus name: CollisionProxyUnregister
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionProxyUnregister_0044f0e0.c

void UnknownObject::CollisionProxyUnregister()
{
    // Unregisters a collision proxy slot: clears the active-flag byte at this + 0x37C, removes the proxy index from the active word list at byte 0xC88 (word index 1604, up to 256 entries), and resets the per-proxy float/dword field at byte 0x87C + 4*a2 to either 0.0 or the dead-zone threshold dbl_8AFEA8 + a3 depending on the sign of a3.
    // ASSIGNMENT: Clear the active-flag byte at this + a2 + 0x37C (byte 892 of the proxy record) [function:0x0044F0E0, source:raw]
    // LOOP: Scan the active proxy-ID word list at byte 0xC88 (word index 1604) for the first entry equal to a2, iterating up to 256 entries [field:this:0x00000C88, source:raw]
    // ASSIGNMENT: Clear the matched entry in the active proxy-ID word list at byte 0xC88 (word index 1604 + scan position) [field:this:0x00000C88, source:raw]
    // GUARD: Branch on a3 against the zero threshold: when a3 <= 0.0 write 0 to the dword at byte 0x87C + 4*a2; otherwise store float dbl_8AFEA8 + a3 there [global:0x0059E440, global:0x008AFEA8, source:raw]
    // RETURN: Return void; raw source has no conditional early exit [source:raw]

    // Conservative worker pseudocode:
    //   void CollisionProxyUnregister(unsigned __int16* this, int proxyIndex, float axis) {
    //       this[proxyIndex + 446] = 0;
    //       unsigned int v3 = 0;
    //       unsigned __int16* v4 = this + 1604;
    //       while (*v4 != proxyIndex) { ++v3; ++v4; if (v3 >= 0x100) goto LABEL_6; }
    //       this[v3 + 1604] = 0;
    //   LABEL_6:
    //       if (axis <= 0.0) { *(DWORD*)&this[2 * proxyIndex + 1086] = 0; }
    //       else { *(float*)&this[2 * proxyIndex + 1086] = dbl_8AFEA8 + axis; }
    //   }
    // UNRESOLVED: Semantic role of the active-flag byte at this + 0x37C is DERIVED from behavior; struct role unconfirmed.
    // UNRESOLVED: The dword/float field at byte 0x87C + 4*a2 (reset to 0 or dead-zone + axis) is unconfirmed as a named member.
    // UNRESOLVED: Owner object is unknown (UnknownObject).
    // UNRESOLVED: flt_59E440 is treated as the zero-threshold constant the raw source inlines as literal 0.0; identity DERIVED.
}
