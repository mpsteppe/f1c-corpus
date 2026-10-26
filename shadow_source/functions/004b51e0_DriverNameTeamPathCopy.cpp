// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B51E0
// Canonical corpus name: DriverNameTeamCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DriverNameTeamCopy_004b51e0.c

void UnknownObject::DriverNameTeamPathCopy()
{
    // Copies driver/team identity strings and two file path strings from a source struct (a2) into this. First calls StructInitWithGlobalData, then copies a 63-byte name string from a2+17952 into this+1 (null-terminated at this[64]). Extracts the filename portion after the last backslash of the path string at a2+18196 into this+65 (31 bytes, null-terminated at this[96]). Reads a path pointer at a2+1920, falling back to the default directory global byte_5EA438 when null, extracts its filename after the last backslash into this+97 (31 bytes, null-terminated at this[128]). Finally copies a flag byte from a2+18580 into this[0]. Called from VehicleInstanceListBuilder during vehicle instance setup.
    // CALL: StructInitWithGlobalData(this) zero-initializes the destination struct before any string copy [callee:0x004B4F70, source:raw]
    // CALL: sub_587DD0(this + 1, a2 + 17952, 63) copies a 63-byte name string from the source into this, then this[64] = 0 writes the null terminator [callee:0x00587DD0, field:this:0x00000040, source:raw]
    // CALCULATION: v3 starts at the terminator of the path string at a2+18196 (a2 + 18196 + strlen) [source:raw]
    // GUARD: Backslash search proceeds only while v3 is above a2+18196; when the string is empty v3 stays at the start and the search is skipped [source:raw]
    // LOOP: Walk v3 backwards until a backslash (0x5C) is found, then advance one byte so it points at the filename portion after the last backslash [source:raw]
    // CALL: sub_587DD0(this + 65, v3, 31) copies the extracted first filename, then this[96] = 0 writes its null terminator [callee:0x00587DD0, field:this:0x00000060, source:raw]
    // ASSIGNMENT: v4 = *(a2 + 1920) reads the second path pointer; when it is null it is replaced by the default directory global byte_5EA438 [global:0x005EA438, source:raw]
    // GUARD: Second backslash search proceeds only while v5 is above v4; when the string is empty the search is skipped [source:raw]
    // LOOP: Walk v5 backwards until a backslash is found, then advance one byte so it points at the filename portion after the last backslash [source:raw]
    // CALL: sub_587DD0(this + 97, v5, 31) copies the extracted second filename, then this[128] = 0 writes its null terminator [callee:0x00587DD0, field:this:0x00000080, source:raw]
    // ASSIGNMENT: this[0] = *(a2 + 18580) copies a single flag byte from the source into the destination's first byte [field:this:0x00000000, source:raw]
    // RETURN: Returns this, the destination struct pointer [function:0x004B51E0, source:raw]
    // CALL: Invoked by VehicleInstanceListBuilder during vehicle instance setup [caller:0x004B5C50, source:raw]

    // Conservative worker pseudocode:
    //   StructInitWithGlobalData(this);
    //   sub_587DD0(this + 1, a2 + 17952, 63); this[64] = 0;
    //   v3 = a2 + 18196 + strlen(a2 + 18196);
    //   if (v3 > a2 + 18196) { while (*v3 != '\\') if (--v3 <= a2 + 18196) break; ++v3; }
    //   sub_587DD0(this + 65, v3, 31); this[96] = 0;
    //   v4 = *(a2 + 1920); if (!v4) v4 = byte_5EA438;
    //   v5 = v4 + strlen(v4);
    //   if (v5 > v4) { while (*v5 != '\\') if (--v5 <= v4) break; ++v5; }
    //   sub_587DD0(this + 97, v5, 31); this[128] = 0;
    //   this[0] = *(a2 + 18580);
    //   return this;
    // UNRESOLVED: The meaning of the flag byte copied from a2+18580 into this[0] is not established from this packet
    // UNRESOLVED: The exact layout of the source struct a2 (fixed offsets 17952, 18196, 18580, 1920) is not defined here; the destination struct layout (1 + 63 + 1 + 31 + 1 + 31 + 1 bytes) is inferred from the copy widths
    // UNRESOLVED: What sub_587DD0 does beyond a length-limited string copy (strncpy equivalent) is defined elsewhere
}
