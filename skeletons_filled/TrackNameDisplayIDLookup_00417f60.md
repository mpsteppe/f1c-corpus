## TrackNameDisplayIDLookup_00417f60 — TrackNameToDisplayIDLookup

**Summary:** Maps track scene name strings to integer display IDs for commentary/UI. Called from CommentaryTVPWSPathBuilder to resolve display IDs per track and mode (a3=alternate layout, a4=dry/wet or event type).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CommentaryTVPWSPathBuilder (00414e60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | Output track display ID (set on success) |
| this | 0xC | RW | — | Output computed value from ShortComputation_41a0 |
| this | 0x10 | RW | 0 | Status/flag field (zeroed on success) |

**Written-by note (persistence):**
- this 0x8: conditional write on success (v5>0 && v4>0)
- this 0xC: conditional write on success (v5>0 && v4>0)
- this 0x10: initialized to 0 on success only

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c2628 | aIndianapolis | R | StringIndianapolis [DERIVED] |
| 005c2638 | aSuzuka | R | StrTrackSuzuka [DERIVED] |
| 005c2640 | aSepang | R | Str_Track_Sepang [DERIVED] |
| 005c2648 | aNurburgring | R | String_Nurburgring [DERIVED] |
| 005c2654 | aMonza | R | sTrackName_Monza [DERIVED] |
| 005c265c | aSpaFrancorcham | R | TrackName_Spa [DERIVED] |
| 005c2670 | aHungaroring | R | StrHungaroring [DERIVED] |
| 005c267c | aHockenheim | R | aHockenheim [DERIVED] |
| 005c2688 | aA1Ring | R | TrackNameA1Ring [DERIVED] |
| 005c2694 | aSilverstone | R | aSilverstone [DERIVED] |
| 005c26a0 | aMagnyCours | R | TrackMagnyCours [DERIVED] |
| 005c26ac | aMontreal | R | TrackName_Montreal [DERIVED] |
| 005c26b8 | aBarcelona | R | TrackNameBarcelona [DERIVED] |
| 005c26c4 | aMonaco_0 | R | Str_TrackName_Monaco [DERIVED] |
| 005c26cc | aImola | R | sTrackImola [DERIVED] |
| 005c26d4 | aInterlagos | R | TrackName_Interlagos [DERIVED] |
| 005c26e0 | aAlbertPark | R | TrackNameAlbertPark [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004141a0 | ShortComputation_41a0 | Computes numeric value from argument (1); result stored to this+0xC on success. Used as gate (must be >0). |
| 00566650 | StringCopyWithBufferRealloc | Copies/constructs string buffer for track name display |
| 00566810 | sub_566810 | String comparison; matches scene name against track name globals |

**Guard conditions:** ShortComputation_41a0(1) must return >= 0; else returns 1 (error). a2 scene index must be >= 0; else returns 1. Scene entry at dword_8AC490 + 396*a2 must be non-null; else returns 1. On success path, both v5 and v4 must be > 0; else returns 1 (skips output write).
