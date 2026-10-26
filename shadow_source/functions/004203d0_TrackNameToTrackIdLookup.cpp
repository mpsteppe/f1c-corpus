// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004203D0
// Canonical corpus name: ThunkToFUN004201e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToFUN004201e0_004203d0.c

void UnknownObject::TrackNameToTrackIdLookup()
{
    // Maps a track name to a numeric track identifier. Computes an element base v3 = dword_8AC490 + 396 * dword_8AC48C and reads the name field at v3 + 260. Performs a linear chain of string equality tests against 18 hardcoded track-name literals (Albert Park through Indianapolis); on the first match it returns the associated track id (355-372), otherwise it returns -1.
    // CALCULATION: Compute the element base pointer v3 = dword_8AC490 + 396 * dword_8AC48C; 396 is the element stride of the track table. [source:raw, global:0x008AC490, global:0x008AC48C]
    // ASSIGNMENT: Initialize the result v0 = -1, the default returned when no track name matches. [source:raw]
    // GUARD: Guard: if the computed base v3 is zero, skip every comparison and return -1. [source:raw]
    // ASSIGNMENT: Compute v1 = v3 + 260, the pointer to the track-name field within the table element. [source:raw]
    // CALL: Test the name field via sub_566810(v1, trackLiteral); the chain covers aAlbertPark, aInterlagos, aImola, aMonaco_0, aBarcelona, aMontreal, aMagnyCours, aSilverstone, aA1Ring, a2002Hockenheim, aHockenheim, aHungaroring, aSpaFrancorcham, aMonza, aNurburgring, aSepang, aSuzuka, aIndianapolis. [source:raw]
    // RETURN: On the first equality match, return the associated track id (355-372 in the listed order); when no literal matches, return the default v0 = -1. [source:raw]

    // Conservative worker pseudocode:
    //   int TrackNameToTrackIdLookup() {
    //     int v3 = dword_8AC490 + 396 * dword_8AC48C;
    //     int v0 = -1;
    //     if (v3) {
    //       int v1 = v3 + 260;
    //       if (sub_566810(v1, aAlbertPark)) return 355;
    //       if (sub_566810(v1, aInterlagos)) return 356;
    //       if (sub_566810(v1, aImola)) return 357;
    //       if (sub_566810(v1, aMonaco_0)) return 358;
    //       if (sub_566810(v1, aBarcelona)) return 359;
    //       if (sub_566810(v1, aMontreal)) return 360;
    //       if (sub_566810(v1, aMagnyCours)) return 361;
    //       if (sub_566810(v1, aSilverstone)) return 362;
    //       if (sub_566810(v1, aA1Ring)) return 363;
    //       if (sub_566810(v1, a2002Hockenheim)) return 365;
    //       if (sub_566810(v1, aHockenheim)) return 364;
    //       if (sub_566810(v1, aHungaroring)) return 366;
    //       if (sub_566810(v1, aSpaFrancorcham)) return 367;
    //       if (sub_566810(v1, aMonza)) return 368;
    //       if (sub_566810(v1, aNurburgring)) return 372;
    //       if (sub_566810(v1, aSepang)) return 369;
    //       if (sub_566810(v1, aSuzuka)) return 370;
    //       if (sub_566810(v1, aIndianapolis)) return 371;
    //     }
    //     return v0;
    //   }
    // UNRESOLVED: The string-compare helper sub_566810 is called by this function but is absent from the packet callee list, so its address has no evidence reference here.
    // UNRESOLVED: The ABI/canonical names suggest an unconditional jump to the function named FUN_004201e0, but the raw source is a real body; the relationship to that address is unresolved.
    // UNRESOLVED: Meanings of the globals dword_8AC48C (table index) and dword_8AC490 (table base) and of the 396-element stride are unknown.
    // UNRESOLVED: Track id sequence is non-monotonic (365 before 364, 372 before 369); likely reflects the game's internal track ordering.
}
