// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00565520
// Canonical corpus name: sub_565520
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_565520_00565520.c

void UnknownObject::ConfigKeyValueProcessor()
{
    // Config-value resolver on the config object. Guards on the token string at this+0x198: if non-empty it counts '=' characters and dispatches the query a2 to StringBasedLookup when exactly one '=' is found, otherwise to sub_565400 (dot-delimited path parser); an empty token skips straight to the path parser. A null lookup result returns 0. The resolved text is strcpy'd into this from the buffer pointer at this+0x180, then split on the delimiter asc_5D251C: the first segment is copied into output lpSrcStr and finalized with sub_589901, and a second sub_5897CA pass on the remaining text finalizes output a4. Returns 1 after extraction.
    // GUARD: If the first byte of the token string at this+0x198 is zero, skip the '='-counting path and go directly to sub_565400 [field:this:0x00000198, source:raw]
    // LOOP: Walk the token string at this+0x198 counting '=' characters (ASCII 61) until the null terminator [field:this:0x00000198, source:raw]
    // STATE_TRANSITION: Dispatch the query a2: exactly one '=' uses StringBasedLookup, any other count uses sub_565400(this, a2) [callee:0x005653F0, callee:0x00565400, source:raw]
    // GUARD: If the lookup result pointer is null, return 0 [source:raw]
    // ASSIGNMENT: Copy the resolved string, read from the pointer stored at this+0x180, into this via strcpy [field:this:0x00000180, source:raw]
    // CALL: Split this on the delimiter asc_5D251C with sub_5897CA to locate the first value segment [callee:0x005897CA, global:0x005D251C, source:raw]
    // ASSIGNMENT: If a first segment was found and lpSrcStr is non-null, copy the segment text into lpSrcStr and finalize it with sub_589901(lpSrcStr) [callee:0x00589901, source:raw]
    // CALL: Run sub_5897CA again on the residual text; if a second segment exists and a4 is non-null, copy it into a4 and finalize with sub_589901(a4) [callee:0x005897CA, callee:0x00589901, global:0x005D251C, source:raw]
    // RETURN: Return 1 after the value segments have been extracted and copied [source:raw]
    // CALL: Widely called by config and loader paths, including CameraViewSystem, ConfigIniParser, GameOptionsWriter and VehiclePhysicsJointSystemLoader [caller:0x00408E20, caller:0x00421CD0, caller:0x004C1E80, caller:0x0056D930, source:raw]

    // Conservative worker pseudocode:
    //   count = 0;
    //   if (this[0x198] != 0) {
    //     for (p = this+0x198; *p; ++p) if (*p == '=') ++count;
    //     result = (count == 1) ? StringBasedLookup(a2) : sub_565400(this, a2);
    //   } else result = sub_565400(this, a2);
    //   if (!result) return 0;
    //   strcpy(this, *(char**)(this+0x180));
    //   seg1 = sub_5897CA(this, asc_5D251C);
    //   if (seg1 && lpSrcStr) { copy seg1 into lpSrcStr; sub_589901(lpSrcStr);
    //     seg2 = sub_5897CA(0, asc_5D251C);
    //     if (seg2 && a4) { copy seg2 into a4; sub_589901(a4); } }
    //   return 1;
    // UNRESOLVED: This is a __thiscall method, so the receiver 'this' is a class instance, but its type is not identified; the '=' dispatch and the dot-delimited branch imply a config-string parser state machine that is not fully defined
    // UNRESOLVED: The delimiter constant asc_5D251C and the two output buffers lpSrcStr/a4 are consumed by callers that are not visible in this packet
    // UNRESOLVED: The residual copy loops are rendered as address-arithmetic byte copies in the raw source; their exact string semantics depend on sub_5897CA behavior
}
