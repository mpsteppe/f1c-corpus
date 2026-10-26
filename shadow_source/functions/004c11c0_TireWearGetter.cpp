// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C11C0
// Canonical corpus name: TireWearGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireWearGetter_004c11c0.c

void UnknownObject::TireWearGetter()
{
    // Trivial thiscall getter. Returns the int field at this+0xB14C (element this[11347] of the _DWORD array). No side effects, no callees, no guards. Called from SessionInit (0x004A06E0). Owner object class not established.
    // RETURN: Return the int stored at field 0xB14C of this (this[11347]). [field:this:0x0000B14C, source:raw, function:0x004C11C0]

    // Conservative worker pseudocode:
    //   int sub_4C11C0(this) {
    //     return this[11347];
    //   }
    // UNRESOLVED: Semantic meaning of the returned value (assumed tire wear quantity only from the subsystem tag 'pit' and the canonical name TireWearGetter; no field metadata confirms units or lifetime).
    // UNRESOLVED: Owner object type and class are unknown; the object is only ever exposed as this+0xB14C.
}
