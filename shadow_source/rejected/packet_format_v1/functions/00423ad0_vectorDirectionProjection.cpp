// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00423AD0
// Canonical corpus name: F_2DVectorDirectionProjection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_2DVectorDirectionProjection_00423ad0.c

void UnknownObject::vectorDirectionProjection()
{
    // Projects vector a2 (floats at +0/+8) onto the direction a1 (floats at +0/+8): returns dot(a1,a2) / dot(a1,a1), or 0.0 when a1 is the zero vector. Structural twin of ZeroVectorCheck (00404030). On the frame path; called by OpponentProximityScanTeamRecognition (0x0042A7D0).
    // CALCULATION: v2 = dot(a1,a1) = a1[0]*a1[0] + a1[2]*a1[2] (squared length of the direction vector). [field:this:0x00000000, field:this:0x00000008, source:raw]
    // GUARD: if (v2 == 0.0) return 0.0 (zero-direction early out). [source:raw]
    // CALCULATION: numerator = dot(a1,a2) = a1[0]*a2[0] + a1[2]*a2[2]. [field:this:0x00000000, field:this:0x00000008, source:raw]
    // RETURN: return numerator / v2 (signed projection scale of a2 along a1). [source:raw]
    // UNRESOLVED: Global flt_59E440 (0x0059E440) is read per the deterministic fact table but does not appear in the decompiled body; likely folded away by the compiler.
}
