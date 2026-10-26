// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A5C10
// Canonical corpus name: GuardedCallWithCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GuardedCallWithCheck_004a5c10.c

void UnknownObject::GuardedCallWithCheck()
{
    // thiscall helper on the per-frame path: resolves the nth valid part via NthValidPartLookup(this, a2). When a part is found, falls back to byte_5EA438 if the part string is empty, then maps it through TireCompoundNameIDMapping to a tire-compound name ID and returns the result; when no valid part exists, returns null. Called from AIDriverStructInit.
    // CALL: Resolve the nth valid part: result = NthValidPartLookup(this, a2). [callee:0x004A5820, source:raw]
    // GUARD: If result is null (no valid part), return result (null) immediately. [source:raw]
    // GUARD: If the resolved part string *result is null, substitute the fallback byte_5EA438. [global:0x005EA438, source:raw]
    // CALL: Map the part string through TireCompoundNameIDMapping(v3) and return its result. [callee:0x004A4830, source:raw]
    // CALL: Invoked during AI driver struct initialization by AIDriverStructInit. [caller:0x00424790]

    // Conservative worker pseudocode:
    //   result = NthValidPartLookup(this, a2);
    //   if (!result) return result;
    //   v3 = *result; if (!v3) v3 = byte_5EA438;
    //   return (char **)TireCompoundNameIDMapping(v3);
    // UNRESOLVED: byte_5EA438 is a read-only fallback string (an empty-string sentinel is presumed); its contents are not evidenced by the packet.
    // UNRESOLVED: Parameter a2 selects which part NthValidPartLookup resolves; whether it is an index or an identifier is not evidenced.
    // UNRESOLVED: Owner object is unknown; the ABI lead 'Guarded_Call_with_Check' describes behavior rather than naming a class.
}
