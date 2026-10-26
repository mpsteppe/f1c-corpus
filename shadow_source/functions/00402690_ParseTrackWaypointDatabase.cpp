// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00402690
// Canonical corpus name: sub_402690
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_402690_00402690.c

void UnknownObject::ParseTrackWaypointDatabase()
{
    // Parses a track AI waypoint database file (.AIW) into the track database object. Reads FEATURES (pit lane, starting grid, pit/garage spot counts with minimum clamps), GRID (grid position triples), PITS (team-indexed pit/garage positions and orientations), and per-waypoint properties (branch id, path, event, score, width, groove, bitfields, pointer set). Allocates the waypoint array from the parsed count (316-byte stride plus 4-byte header), falls back to a default two-waypoint array when no count is parsed, remaps indexes, and post-processes each waypoint position delta.
    // CALL: Release the target's existing per-track arrays before reparsing. [callee:0x004034D0, source:raw]
    // CALL: Allocate the mesh buffers referenced by the track database after the reset. [callee:0x00403350]
    // ASSIGNMENT: Clear the left-handed-pit flag field (init literal 0). [field:this:0x0000012C]
    // GUARD: If the input file handle is null, skip parsing and jump to the default waypoint init block. [source:raw]
    // LOOP: Outer loop: read one line at a time from the waypoint database file via the read-until-newline helper. [callee:0x00587CA0]
    // GUARD: Detect the FEATURES section token and enter the feature-parameter parsing loop. [callee:0x00587C20, global:0x005BE684]
    // LOOP: Read feature-section lines until the section-marker token is found. [callee:0x00587CA0]
    // CALL: Tokenize the current line; the returned marker decides whether to stop the section. [callee:0x005651B0]
    // CALL: Parse the PITLANES token into the pit-lane count field. [callee:0x00565760, global:0x005BE678]
    // CALL: Parse the STARTINGGRID token into the starting-grid count field. [callee:0x00565760, global:0x005BE668]
    // GUARD: Clamp the starting-grid count field to a minimum of 104. [guard:0, field:this:0x00000160]
    // ASSIGNMENT: Apply the clamped starting-grid count (minimum 104). [field:this:0x00000160]
    // CALL: Parse the PITSPOTS token into the pit-spot count field. [callee:0x00565760, global:0x005BE65C]
    // GUARD: Clamp the pit-spot count field to a minimum of 52. [guard:1, field:this:0x00000164]
    // ASSIGNMENT: Apply the clamped pit-spot count (minimum 52). [field:this:0x00000164]
    // CALL: Parse the GARAGESPOTS token into the garage-spot count field. [callee:0x00565760, global:0x005BE650]
    // GUARD: Clamp the garage-spot count field to a minimum of 3. [guard:2, field:this:0x00000168]
    // ASSIGNMENT: Apply the clamped garage-spot count (minimum 3). [field:this:0x00000168]
    // CALL: Reallocate the mesh buffers now that the feature counts are known. [callee:0x00403350]
    // GUARD: Detect the GRID section token for starting-grid position parsing. [callee:0x00587C20, global:0x005BE648]
    // LOOP: Read grid-section lines until the section-marker token is found; grid slot index starts at -1. [callee:0x00587CA0]
    // CALL: Tokenize the current grid line. [callee:0x005651B0]
    // CALL: Parse the GRIDINDEX token for the grid slot being defined. [callee:0x00565760, global:0x005BE63C]
    // CALL: Parse a grid position triple through the first offset variant. [callee:0x00565870, global:0x005BE638]
    // CALL: Parse a grid position triple through the aligned variant; only slots below index 104 are written. [callee:0x00565870, global:0x005BE634]
    // ASSIGNMENT: Write the parsed grid position into the grid-position array (base field 0x150, 28-byte stride, optional +12 alignment offset). [field:this:0x00000150]
    // GUARD: Detect the PITS section token for pit/garage position parsing. [callee:0x00587C20, global:0x005BE62C]
    // LOOP: Read pit-section lines until the section-marker token is found; team index starts at -1. [callee:0x00587CA0]
    // CALL: Tokenize the current pit line. [callee:0x005651B0]
    // CALL: Parse the TEAMINDEX token for the team being defined. [callee:0x00565760, global:0x005BE620]
    // CALL: Parse the PITPOS token and store the position triple in the pit-position array (field 0x154, 28-byte stride). [callee:0x00565870, global:0x005BE618, field:this:0x00000154]
    // CALL: Parse the PITORI token and store the orientation triple in the pit-orientation slot (field 0x154 +12). [callee:0x00565870, global:0x005BE610, field:this:0x00000154]
    // CALL: Parse the GARPOS token; convert the garage row value and index the garage-position array (field 0x158) by team index plus row times pit-spot count. [callee:0x00565870, global:0x005BE608, callee:0x00587BDC, field:this:0x00000158, field:this:0x00000164]
    // CALL: Parse the GARORI token and store the orientation triple in the garage-orientation slot (field 0x158 +12). [callee:0x00565870, global:0x005BE600, callee:0x00587BDC, field:this:0x00000158, field:this:0x00000164]
    // GUARD: Stop the outer loop when a section-marker token with value 4 is read. [callee:0x005651B0]
    // CALL: Parse the NUMBERWAYPOINT token for the waypoint count; on success allocate the waypoint array. [callee:0x00565760, global:0x005BE5EC]
    // CALL: Allocate the waypoint array block (316 bytes per waypoint plus a 4-byte header) via the operator-new wrapper. [callee:0x00587C03]
    // LOOP: Run the per-waypoint constructor for each allocated slot (79 dwords per slot). [callee:0x004FAD80]
    // ASSIGNMENT: Store the allocated waypoint-array pointer in field 0x134 and the waypoint count in field 0x130. [field:this:0x00000134, field:this:0x00000130]
    // CALL: Parse the LEFTHANDEDPITS token and store its boolean into the left-handed-pit flag field. [callee:0x00565760, global:0x005BE5DC, field:this:0x0000012C]
    // CALL: Parse the WORSTADJUST token into the worst-adjust field, clamped to at least 0.5. [callee:0x00565870, global:0x005BE5D0, field:this:0x0000011C]
    // CALL: Parse the MIDADJUST token into the mid-adjust field. [callee:0x00565870, global:0x005BE5C4]
    // CALL: Parse the BESTADJUST token into the best-adjust field, clamped to at most 1.3. [callee:0x00565870, global:0x005BE5B8, field:this:0x00000124]
    // CALL: Parse the RACEQUALRATIO token; if absent continue the parameter chain. [callee:0x00565870, global:0x005BE5A8]
    // CALL: Parse the LAPLENGTH token. [callee:0x00565870, global:0x005BE59C]
    // CALL: Parse the SECTOR1LENGTH token. [callee:0x00565870, global:0x005BE58C]
    // CALL: Parse the SECTOR2LENGTH token. [callee:0x00565870, global:0x005BE57C]
    // CALL: Parse the FUELUSE token. [callee:0x00565870, global:0x005BE574]
    // CALL: Parse the GROOVEWIDTH token. [callee:0x00565870, global:0x005BE568]
    // CALL: Parse the GROOVEWIDTHWET token. [callee:0x00565870, global:0x005BE558]
    // CALL: Parse the INTERMEDIATEFO token; on success feed the value to the clamped-reciprocal helper. [callee:0x00565870, global:0x005BE540, callee:0x004FEFC0]
    // ASSIGNMENT: Store the two-value INTERMEDIATEFO0 result in the intermediate-fog globals. [global:0x005BE528, global:0x008AFFA4, global:0x008AFFA8]
    // ASSIGNMENT: Store the RAINYFOGPLANES result in the rainy-fog-plane globals. [global:0x005BE518, global:0x008AFFB0, global:0x008AFFB4]
    // ASSIGNMENT: Store the scaled INTERMEDIATEFO1 color components (0..255 scale factor ~0.0039) in the intermediate-fog color globals. [global:0x005BE500, global:0x008AFF80, global:0x008AFF84, global:0x008AFF88]
    // ASSIGNMENT: Store the scaled RAINYFOGCOLOR components in the rainy-fog color globals. [global:0x005BE4F0, global:0x008AFF8C, global:0x008AFF90, global:0x008AFF94]
    // ASSIGNMENT: Store the FOGDENSITY result in the fog-density globals. [global:0x005BE4E4, global:0x008AFFAC, global:0x008AFFB8]
    // CALL: Parse RAINYDARKNESS and pass both values to the clamp-range helper. [callee:0x00565870, global:0x005BE4D4, callee:0x004FF040]
    // CALL: Parse the WPB RANCHID token into the current waypoint's branch-id field. [callee:0x00565760, global:0x005BE4C8]
    // CALL: Parse the WPPATH token into the current waypoint's path data. [callee:0x00565870, global:0x005BE4C0]
    // CALL: Parse the WPEVENT token and store the two event integers in the waypoint record. [callee:0x00565870, global:0x005BE4B4]
    // CALL: Parse the WPWPSE token into the waypoint's score/segment fields. [callee:0x00565760, global:0x005BE4AC]
    // CALL: Parse the WPPOS token (position triple) and mirror it into the waypoint record's position fields. [callee:0x00565870, global:0x005BE4A4]
    // CALL: Parse the WPGALPHA token for the waypoint alpha field. [callee:0x00565870, global:0x005BE498]
    // CALL: Parse the WPGROOVELAT token for the waypoint groove-lateral field. [callee:0x00565870, global:0x005BE488]
    // CALL: Parse the WPSCORE token; convert the float score to an integer stored in the waypoint record. [callee:0x00565870, global:0x005BE47C, callee:0x00587BDC]
    // CALL: Parse the WPPERP token (perpendicular vector triple). [callee:0x00565870, global:0x005BE474]
    // CALL: Parse the WPWIDTH token (width quadruple). [callee:0x00565870, global:0x005BE468]
    // CALL: Parse the WPWIDTHD token (width-delta quadruple). [callee:0x00565870, global:0x005BE45C]
    // CALL: Parse the WPBITFIELDS token for the waypoint bit-field word. [callee:0x00565760, global:0x005BE44C]
    // CALL: Parse the WPPTRS token; on success advance the waypoint cursor to the next slot, guarded by the waypoint count field. [callee:0x00565760, global:0x005BE444, field:this:0x00000130]
    // GUARD: Fallback path when no waypoint count was parsed: install a default two-waypoint array. [source:raw]
    // ASSIGNMENT: Allocate the default two-slot waypoint array (count 2 stored in field 0x130, pointer in field 0x134, constructor run per slot). [callee:0x00587C03, callee:0x004FAD80, field:this:0x00000130, field:this:0x00000134]
    // ASSIGNMENT: Initialize default waypoint[0] fields: flag set to 1, state set to -1, float param set to 1.0, and zero/negative sentinels at the trailing fields. [field:*(this+0x134):0x00000120, field:*(this+0x134):0x00000128, field:*(this+0x134):0x000001D8, field:*(this+0x134):0x0000025C, field:*(this+0x134):0x00000260, field:*(this+0x134):0x00000264]
    // CALL: Rebuild index remapping structures for the track database after parsing. [callee:0x00403540]
    // LOOP: Post-process each parsed waypoint (316-byte stride) with the position-delta computation. [callee:0x004FAEC0]
    // RETURN: Return the result of the final post-processing call. [source:raw]

    // Conservative worker pseudocode:
    //   // Parse track AI waypoint database file handle into the track object.
    //   resetTrackArrays(); allocateMeshBuffers(); leftHandedPits = 0;
    //   if (!file) goto fallback;
    //   while (readLine(line)) {
    //     if (section(line, FEATURES)) { while (readLine(line)) { parse feature counts; clamp grids to 104/52/3; } allocateMeshBuffers(); }
    //     if (section(line, GRID)) { while (readLine(line)) { parse grid slot positions into grid array; } }
    //     if (section(line, PITS)) { while (readLine(line)) { parse team index + pit/garage pos/ori triples; } }
    //     if (marker(line) == 4) break;
    //     if (!marker(line)) {
    //       if (value(line, NUMBERWAYPOINT, &n)) { array = alloc(316*n+4); construct slots; waypoints = array; count = n; }
    //       else if (value(line, LEFTHANDEDPITS, &v)) leftHandedPits = (v != 0);
    //       else parse track params (adjusts, lengths, fuel, groove, fog/weather);
    //       parse per-waypoint fields (branch, path, event, score, width, groove, bitfields, ptrs);
    //       if (ptrs) { if (index < count) { index++; waypoints = slot(index); } }
    //     }
    //   }
    //   fallback: if (!count) { count = 2; waypoints = alloc(636); init 2 default slots with sentinels; }
    //   remapIndexes(); for each parsed waypoint: computePositionDelta();
    // UNRESOLVED: The exact layout/semantics of each per-waypoint field beyond the token names is not recoverable from this function alone.
    // UNRESOLVED: Read globals flt_59E450, flt_59E460, flt_59E464 and unk_8AFEC0 are referenced by this function but do not appear in the raw body; they are likely consumed inside the token-parsing helpers.
    // UNRESOLVED: Stride and header assumptions (316-byte slot, 4-byte header, 79 dwords per constructor call) are inferred from allocation size and index arithmetic in the raw source.
}
