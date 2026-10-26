// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00423AD0
// Canonical corpus name: F_2DVectorDirectionProjection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_2DVectorDirectionProjection_00423ad0.c

void UnknownObject::F_2DVectorDirectionProjection()
{
    // Takes two float pointers a1/a2 interpreted as 2D vectors (x stored at a1[0]/+0x0, z stored at a1[2]/+0x8). Computes the projection of a2 onto a1: dot(a1,a2) / dot(a1,a1); returns 0.0 when the a1 length-squared is zero. Structural twin of ZeroVectorCheck (00404030) per the DERIVED cluster prelabel.
    // CALCULATION: v2 = a1[0]*a1[0] + a1[2]*a1[2]; squared length of a1 computed from fields +0x0 and +0x8. [field:this:0x00000000, field:this:0x00000008, function:0x00423AD0, source:raw]
    // GUARD: If v2 == 0.0, return 0.0 (degenerate/zero-length a1 yields a zero projection). [function:0x00423AD0, source:raw]
    // CALCULATION: Else compute (a2[2]*a1[2] + a1[0]*a2[0]) / v2, i.e. the scalar projection of a2 onto a1. [field:this:0x00000000, field:this:0x00000008, function:0x00423AD0, source:raw]
    // RETURN: Return the computed projection, or 0.0 when a1 is the zero vector. [function:0x00423AD0, source:raw]

    // Conservative worker pseudocode:
    //   v2 = a1.x*a1.x + a1.z*a1.z;
    //   if (v2 == 0.0) return 0.0;
    //   return (a2.z*a1.z + a1.x*a2.x) / v2;
    // UNRESOLVED: Global flt_59E440 is listed as read in the packet but does not appear in the raw source; its role in this function is unknown.
    // UNRESOLVED: Caller OpponentProximityScanTeamRecognition (0042A7D0) suggests an AI/opponent context, but owner object is not identified.
}
