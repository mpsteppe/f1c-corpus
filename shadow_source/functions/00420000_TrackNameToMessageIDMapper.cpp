// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00420000
// Canonical corpus name: sub_420000
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_420000_00420000.c

void UnknownObject::TrackNameToMessageIDMapper()
{
    // Maps the current track/scene name to a track-specific message ID. Computes the current scene entry as dword_8AC490 + 396 * dword_8AC48C, and when that entry exists, compares the name string at entry offset 260 against 17 known track names via sub_566810, returning the matching track message ID (338..354) or -1 when no track matches.
    // ASSIGNMENT: Compute the current scene entry pointer: dword_8AC490 + 396 * dword_8AC48C. [global:0x008AC490, global:0x008AC48C, source:raw]
    // GUARD: Proceed only when the scene entry pointer is non-null. [source:raw]
    // GUARD: sub_566810 compares the scene name (at entry offset 260) against aAlbertPark; on match return 338. [callee:0x00566810, global:0x005C26E0, source:raw]
    // GUARD: Compare against aInterlagos; on match return 339. [callee:0x00566810, global:0x005C26D4, source:raw]
    // GUARD: Compare against aImola; on match return 340. [callee:0x00566810, global:0x005C26CC, source:raw]
    // GUARD: Compare against aMonaco_0; on match return 341. [callee:0x00566810, global:0x005C26C4, source:raw]
    // GUARD: Compare against aBarcelona; on match return 342. [callee:0x00566810, global:0x005C26B8, source:raw]
    // GUARD: Compare against aMontreal; on match return 343. [callee:0x00566810, global:0x005C26AC, source:raw]
    // GUARD: Compare against aMagnyCours; on match return 344. [callee:0x00566810, global:0x005C26A0, source:raw]
    // GUARD: Compare against aSilverstone; on match return 345. [callee:0x00566810, global:0x005C2694, source:raw]
    // GUARD: Compare against aA1Ring; on match return 346. [callee:0x00566810, global:0x005C2688, source:raw]
    // GUARD: Compare against aHockenheim; on match return 347. [callee:0x00566810, global:0x005C267C, source:raw]
    // GUARD: Compare against aHungaroring; on match return 348. [callee:0x00566810, global:0x005C2670, source:raw]
    // GUARD: Compare against aSpaFrancorcham; on match return 349. [callee:0x00566810, global:0x005C265C, source:raw]
    // GUARD: Compare against aMonza; on match return 350. [callee:0x00566810, global:0x005C2654, source:raw]
    // GUARD: Compare against aNurburgring; on match return 354. [callee:0x00566810, global:0x005C2648, source:raw]
    // GUARD: Compare against aSepang; on match return 351. [callee:0x00566810, global:0x005C2640, source:raw]
    // GUARD: Compare against aSuzuka; on match return 352. [callee:0x00566810, global:0x005C2638, source:raw]
    // GUARD: Compare against aIndianapolis; on match return 353. [callee:0x00566810, global:0x005C2628, source:raw]
    // RETURN: Fall through when no track name matches; return -1. [source:raw]

    // Conservative worker pseudocode:
    //   // Map the current scene/track name to a track message ID.
    //   entry = dword_8AC490 + 396 * dword_8AC48C;
    //   if (!entry) return -1;
    //   name = entry + 260;
    //   if (sub_566810(name, aAlbertPark))    return 338;
    //   if (sub_566810(name, aInterlagos))    return 339;
    //   if (sub_566810(name, aImola))         return 340;
    //   if (sub_566810(name, aMonaco_0))      return 341;
    //   if (sub_566810(name, aBarcelona))     return 342;
    //   if (sub_566810(name, aMontreal))      return 343;
    //   if (sub_566810(name, aMagnyCours))    return 344;
    //   if (sub_566810(name, aSilverstone))   return 345;
    //   if (sub_566810(name, aA1Ring))        return 346;
    //   if (sub_566810(name, aHockenheim))    return 347;
    //   if (sub_566810(name, aHungaroring))   return 348;
    //   if (sub_566810(name, aSpaFrancorcham)) return 349;
    //   if (sub_566810(name, aMonza))         return 350;
    //   if (sub_566810(name, aNurburgring))   return 354;
    //   if (sub_566810(name, aSepang))        return 351;
    //   if (sub_566810(name, aSuzuka))        return 352;
    //   if (sub_566810(name, aIndianapolis))  return 353;
    //   return -1;
    // UNRESOLVED: The consumers and meaning of the track message IDs 338..354 are unknown here.
    // UNRESOLVED: The 396-byte scene entry stride and the name field at offset 260 are inferred from the arithmetic in the raw source, not from independent struct evidence.
}
