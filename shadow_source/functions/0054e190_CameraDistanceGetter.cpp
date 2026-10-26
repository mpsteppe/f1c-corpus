// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054E190
// Canonical corpus name: CameraDistanceGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CameraDistanceGetter_0054e190.c

void UnknownObject::CameraDistanceGetter()
{
    // Trivial thiscall getter. Returns the int field at this+0x120 (element this[72] of the _DWORD array). No side effects, no callees, no guards. Called from AnimationPlaybackSequence (0x0044ACB0) and VehicleGraphicsSceneLoader (0x004DFCE0). Owner object class not established.
    // RETURN: Return the int stored at field 0x120 of this (this[72]). [field:this:0x00000120, source:raw, function:0x0054E190]

    // Conservative worker pseudocode:
    //   int sub_54E190(this) {
    //     return this[72];
    //   }
    // UNRESOLVED: Semantic meaning of the returned value (assumed camera distance from the canonical name CameraDistanceGetter and the 'render' subsystem tag; no field metadata confirms the unit or the reference point).
    // UNRESOLVED: Owner object type and class are unknown; the object is only ever exposed as this+0x120.
}
