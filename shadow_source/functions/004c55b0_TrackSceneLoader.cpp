// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C55B0
// Canonical corpus name: TrackSceneLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TrackSceneLoader_004c55b0.c

void UnknownObject::TrackSceneLoader()
{
    // Finds and selects a scene by name. Copies the input name into a local buffer, normalizes it via sub_589901, then linearly scans the scene registry: dword_8AC488 entries of stride 396 starting at dword_8AC490, reading each entry's name at offset +260, normalizing it, and comparing with strcmp. On a match sets dword_8AC48C to the matching index; returns the scene count when no entry matches.
    // CALL: Copy input a1 into SrcStr and normalize it via sub_589901(SrcStr). [callee:0x00589901]
    // ASSIGNMENT: result = dword_8AC488 (scene count) and v2 = 0 before the search. [global:0x008AC488]
    // GUARD: Guard: search only runs when dword_8AC488 > 0. [global:0x008AC488]
    // LOOP: Loop over entries with index step 396 (entry stride): read the name at dword_8AC490 + i + 260, byte-copy it into the local buffer v7, normalize via sub_589901(v7), and strcmp against SrcStr. [global:0x008AC490, callee:0x00589901]
    // STATE_TRANSITION: On a name match, break out of the loop and set dword_8AC48C = v2 (the current scene index). [global:0x008AC48C]
    // RETURN: Return dword_8AC488 (scene count) when the loop exhausts without a match, otherwise return 0 after the match. [global:0x008AC488, source:raw]

    // Conservative worker pseudocode:
    //   int TrackSceneLoader(const char *name) {
    //     CHAR SrcStr[80]; CHAR v7[80];
    //     strcpy(SrcStr, name);
    //     sub_589901(SrcStr);
    //     int count = dword_8AC488;
    //     int i = 0;
    //     if (dword_8AC488 > 0) {
    //       for (i = 0; ; i += 396) {
    //         CHAR *p = (CHAR *)(i + dword_8AC490 + 260);
    //         do { v6 = *p; *(&v7[0] + (p - (i + dword_8AC490 + 260))) = *p; ++p; } while (v6);
    //         sub_589901(v7);
    //         if (!strcmp(SrcStr, v7)) break;
    //         if (++i_step >= dword_8AC488) return dword_8AC488;
    //       }
    //       dword_8AC48C = i_step;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The normalization transform inside sub_589901 is not evidenced here.
    // UNRESOLVED: The scene registry layout (name offset +260 within a 396-byte entry) is inferred from the loop arithmetic and is not otherwise documented.
}
