// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C03F0
// Canonical corpus name: CareerStandingsStateLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CareerStandingsStateLoader_004c03f0.c

void UnknownObject::LoadCareerStandingsEntry()
{
    // Loads one career season standings entry from an ini-style token buffer. Iterates tokens via ConditionalDispatchBasedOnFlag over unk_8AC1E8 while the buffer is active. Handles Name/VehFile/RcdFile entries by copying the string; parses indexed FinishPosition and FinishPoints keys (formatted with the '%s%2.2d' pattern) into per-index byte offsets this+24 and this+216; writes season totals (SeasonPoints, PointsPosition, PolesTaken, OriginalGridPos, CurrentGridPos, ControlType) to this+408..428; and sets the active flag byte this+0x1B0 from the parsed 'Active' field. Returns 1 once any entry was processed, 0 otherwise.
    // GUARD: If the dword pointed to by a2 is zero, skip loading entirely and return the unset processed flag. [source:raw]
    // LOOP: While ConditionalDispatchBasedOnFlag(&unk_8AC1E8, 256) yields the next token, iterate; set processed flag v2 = 1. [callee:0x00566CC0, global:0x008AC1E8]
    // CALL: sub_5651B0(&unk_8AC050) checks scene setup; if the result is 1 or 4 (i.e. result-1 is 0 or 3), return the processed flag early. [callee:0x005651B0, global:0x008AC050]
    // ASSIGNMENT: When the token matches 'Name' (aName_2), 'VehFile' (aVehfile) or 'RcdFile' (aRcdfile), copy it into the token buffer via StringCopyWithBufferRealloc. [callee:0x005654A0, global:0x005CC650, global:0x005D2718, global:0x005D2710, callee:0x00566650]
    // CALCULATION: Look up the key formed by 'FinishPosition' + '%%s%%2.2d' index via sub_587C20; when found, parse the trailing index v10 with sub_587ECE, and if v10 < 0x30 format '%s%2.2d' and write the entry to this + 24 + 4*v10. [callee:0x00587C20, global:0x005D2700, callee:0x00587ECE, callee:0x0058815F, global:0x005D26F8, callee:0x00565760]
    // CALCULATION: Look up the key formed by 'FinishPoints' + '%%s%%2.2d' index via sub_587C20; when found, parse the trailing index v14 with sub_587ECE, and if v14 < 0x30 format '%s%2.2d' and write the entry to this + 216 + 4*v14. [callee:0x00587C20, global:0x005D26E8, callee:0x00587ECE, callee:0x0058815F, global:0x005D26F8, callee:0x00565760]
    // CALL: Write season summary fields with sub_565760: SeasonPoints to this+408, PointsPosition to this+412, PolesTaken to this+416, OriginalGridPos to this+420, CurrentGridPos to this+424, ControlType to this+428. [callee:0x00565760, global:0x005D26D8, global:0x005D26C8, global:0x005D26BC, global:0x005D26A4, global:0x005D2690, global:0x005D2684]
    // STATE_TRANSITION: Parse the 'Active' field into v15 via sub_565760; when it returns nonzero, set the byte this+0x1B0 (this[432]) to whether v15 is nonzero. [callee:0x00565760, global:0x005D267C, field:this:0x000001B0]
    // RETURN: Return the processed flag v2 (1 if any token was handled, 0 if the buffer was empty). [source:raw]

    // Conservative worker pseudocode:
    //   processed = 0;
    //   if (*a2) {
    //     while (ConditionalDispatchBasedOnFlag(&unk_8AC1E8, 256)) {
    //       processed = 1;
    //       if (sub_5651B0(&unk_8AC050) == 1 || sub_5651B0(&unk_8AC050) == 4) return processed;
    //       if (token_is(Name) || token_is(VehFile) || token_is(RcdFile)) StringCopyWithBufferRealloc(buf);
    //       else {
    //         i = parse_index(lookup(FinishPosition));
    //         if (i < 0x30) write(format('%s%2.2d', FinishPosition, i), this+24+4*i);
    //         j = parse_index(lookup(FinishPoints));
    //         if (j < 0x30) write(format('%s%2.2d', FinishPoints, j), this+216+4*j);
    //         write(SeasonPoints, this+408); write(PointsPosition, this+412); write(PolesTaken, this+416);
    //         write(OriginalGridPos, this+420); write(CurrentGridPos, this+424); write(ControlType, this+428);
    //         if (lookup(Active, &v15)) this[432] = v15 != 0;
    //       }
    //     }
    //   }
    //   return processed;
    // UNRESOLVED: Meaning of the 256 constant passed to ConditionalDispatchBasedOnFlag is not established.
    // UNRESOLVED: sub_5651B0 result semantics (only results that are 1 or 4 cause an early return) are not confirmed beyond this function.
    // UNRESOLVED: sub_565760's return value (used only for the 'Active' lookup) is assumed to signal key-present; not independently verified.
    // UNRESOLVED: a2 points to a validity flag for the token buffer; the buffer itself is unk_8AC1E8 global state.
    // UNRESOLVED: Only field 0x1B0 was extracted for this function; the this+408..428 writes and this+24/216 indexed arrays have no field evidence entries and are therefore described from raw source only.
}
