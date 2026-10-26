// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C5940
// Canonical corpus name: SeasonRacesSceneSorter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SeasonRacesSceneSorter_004c5940.c

void UnknownObject::SortScenesBySeasonRaces()
{
    // Reorders the global scene array (dword_8AC490, stride 396 bytes, name field at entry+260) so scenes appear in season-races order. Retrieves the 'seasonraces' linked list via AudioChannelStop(dword_8AD3B4, aSeasonraces); if it is null the whole function is skipped and null returned. Otherwise builds a temporary index array (4 * dword_8AC488 dwords) mapping each scene to its matched position in the races list, selection-sorts that index array, swapping the corresponding 396-byte scene records through a 396-byte stack buffer, then frees the index array with FreeWrapper_7bcf and returns its result.
    // GUARD: Call AudioChannelStop(dword_8AD3B4, aSeasonraces) to fetch the season races list; if it returns null, skip all work and return null. [callee:0x00568210, global:0x008AD3B4, global:0x005D31C8, source:raw]
    // CALL: LinkedListCount the returned races list to obtain the number of race entries used as the search bound. [callee:0x00567980, source:raw]
    // CALL: Allocate the temporary index array with OperatorNewNhMallocWrapper(4 * dword_8AC488), one dword per scene entry. [callee:0x00587C03, global:0x008AC488, source:raw]
    // LOOP: For each scene entry (base dword_8AC490, advancing 396 bytes each step, name pointer at entry+260), scan the races list with NullCheckWrapper/ StringPointerAccessor and compare the name with sub_588410; store the first matching list index into the index array. [global:0x008AC490, callee:0x005679A0, callee:0x00499E20, callee:0x00588410, source:raw]
    // LOOP: Selection-sort the index array ascending; whenever two indices are swapped, also swap the two 396-byte scene records in dword_8AC490 using a 396-byte stack buffer via qmemcpy (0x18C bytes per copy). [global:0x008AC490, source:raw]
    // CALL: Free the temporary index array via FreeWrapper_7bcf and return its result. [callee:0x00587BCF, source:raw]
    // RETURN: Return null when the season races list was unavailable; otherwise return the FreeWrapper_7bcf result. [source:raw, caller:0x004C52C0]

    // Conservative worker pseudocode:
    //   DWORD* SortScenesBySeasonRaces() {
    //     DWORD* races = AudioChannelStop(dword_8AD3B4, aSeasonraces);
    //     if (!races) return 0;
    //     int raceCount = LinkedListCount(races);
    //     DWORD* idx = Alloc(4 * dword_8AC488);
    //     for (i = 0; i < dword_8AC488; i++) {
    //       BYTE* scene = (BYTE*)dword_8AC490 + i * 396;
    //       j = 0;
    //       for (; j < raceCount; j++) {
    //         node = NullCheckWrapper(j);
    //         name = StringPointerAccessor(node);
    //         if (!sub_588410(name, scene + 260)) break;
    //       }
    //       idx[i] = j;
    //     }
    //     // selection sort idx[]; on each swap also swap the 396-byte scene records
    //     // (qmemcpy of 0x18C bytes via a 396-byte stack buffer)
    //     return FreeWrapper_7bcf(idx);
    //   }
    // UNRESOLVED: AudioChannelStop is called with a directory-like global (dword_8AD3B4) and a literal key; whether it returns a plain linked list of race-name nodes or a wrapped structure is not established here.
    // UNRESOLVED: sub_588410 semantics are inferred only as a string equality that returns 0 on match; its exact contract is unknown.
    // UNRESOLVED: The mapping stores the first matching race index; ties or scenes absent from the races list collapse to raceCount (out-of-range sentinel).
}
