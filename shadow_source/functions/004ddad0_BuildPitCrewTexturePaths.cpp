// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DDAD0
// Canonical corpus name: PitCrewInstanceSetup
// Owner: PitCrewTexturePathsBuilder [DERIVED]
// Raw source: functions/PitCrewInstanceSetup_004ddad0.c

void PitCrewTexturePathsBuilder::BuildPitCrewTexturePaths()
{
    // Builds full texture file paths for the 9 pit-crew/vehicle texture types (car body, driver, arms, wing, helmet, pit body, pit helmet, lollipop, refueler) by combining a base directory from this+0, team and track config strings at this+972/this+984, and a track-name-matched linked-list node, then resolves each path with TextureAdjuster. For texture index 0 it may re-derive the selected path from the matched candidate. Frees the temporary buffers and the lookup handle it allocates before returning. Called by ZeroInitWrapper (0x004DDF70) and sub_4E2A60 (0x004E2A60).
    // GUARD: Return immediately when the this pointer a1 is NULL. Called by ZeroInitWrapper (0x004DDF70) and sub_4E2A60 (0x004E2A60). [function:0x004DDAD0, caller:0x004DDF70, caller:0x004E2A60, source:raw]
    // CALL: Allocate a 256-byte path buffer (v43) via OperatorNewNhMallocWrapper(256) and clear its first byte. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Read the base path string from this+0 (field:this:0x00000000), falling back to byte_5EA438 when null, copy it with StringCopyWithBufferRealloc, then walk backward from the end truncating the string at the first backslash (character 92) to strip the trailing path component. [field:this:0x00000000, global:0x005EA438, callee:0x00566650, source:raw]
    // CALL: Append the team-mass configuration key string aTeamMas (0x005CD5D8) onto the working buffer via sub_5665B0. [callee:0x005665B0, global:0x005CD5D8, source:raw]
    // CALL: Call sub_53CBC0(&v46, path) to build a lookup handle into v46 from the working path buffer; v46 is used as a handle for later path lookups and freed at the end. [callee:0x0053CBC0, source:raw]
    // ASSIGNMENT: Read team-related config string v44 from this+972 and track-related config string v45 from this+984, each falling back to byte_5EA438 when null. [global:0x005EA438, source:raw]
    // CALL: Load the TrackName configuration value into the 128-byte v53 buffer via StringCopyWithValidation(v53, 128, aTrackname, 0); when the load fails clear v53[0] to 0. [callee:0x004C58A0, global:0x005C6984, source:raw]
    // LOOP: Walk the linked list starting at this+980; sub_588410 compares each node's string (fallback byte_5EA438) against the TrackName buffer. On the first match capture the node's +8 string into v42 (fallback byte_5EA438), then stop. [callee:0x00588410, global:0x005EA438, source:raw]
    // ASSIGNMENT: Initialize the three candidate pairs in v50 to {0, -1} each; v50 holds up to three selected candidate (path, selector) pairs. [source:raw]
    // STATE_TRANSITION: For each of the 9 texture-type indices 0..8, dispatch through jump table jpt_4DDC40 (0x004DDF4C) and select the wc-prefixed variant string and the regular variant string: index 0 aWccarbody with default string, index 1 aWcdriver/aDriver, index 2 aWcarms/aArms_0, index 3 aWcwing/aWing, index 4 aWchelmet/aHelmet_0, index 5 aWcpitbody/aPitbody, index 6 aWcpithelmet/aPithelmet, index 7 aWclollipop/aLollipop_0, index 8 aWcrefueler/aRefueler. [global:0x004DDF4C, global:0x005D4CB8, global:0x005D4CAC, global:0x005D4CA4, global:0x005D4C9C, global:0x005D4C94, global:0x005D4C8C, global:0x005D4C84, global:0x005D4C78, global:0x005D4C70, global:0x005D4C64, global:0x005D4C5C, global:0x005D4C50, global:0x005D4C44, global:0x005D4C38, global:0x005D4C2C, global:0x005D4C20, global:0x005D4C14, source:raw]
    // ASSIGNMENT: Assemble up to three candidate name components: the a2 name argument (v48) and the track-name-matched node string (v42) always when non-empty; for texture indices 5-8 also the this+984 config string; always, room permitting, the this+972 config string. Each skipped component falls back to byte_5EA438. [global:0x005EA438, source:raw]
    // LOOP: For each selected candidate path: copy the base directory with StringCopyWithBufferRealloc, strip its trailing backslash, append the candidate component via sub_5665B0, truncate at the last '.' to drop any extension, then append the file name found by sub_589DB0(v22, 46) or the '.bmp' extension string aBmp (0x005D4C0C) when none is found. [callee:0x00566650, callee:0x005665B0, callee:0x00589DB0, global:0x005D4C0C, source:raw]
    // CALL: When fewer than three candidates were selected, fill the remaining v50 slots with the current wc-variant string plus the '.bmp' extension aBmp (0x005D4C0C) via StringCopyWithBufferRealloc and sub_5665B0. [callee:0x00566650, callee:0x005665B0, global:0x005D4C0C, source:raw]
    // CALL: Resolve the final texture path for the current variant with TextureAdjuster(variant, 1, firstCandidate, configStrings, ..., a4); the returned selector v31 is used for index 0 only. [callee:0x004DC770, source:raw]
    // GUARD: For texture index 0 when argument a3 is set: if the TextureAdjuster selector is 3 or more, reset the path to the default byte_5EA438 string; otherwise copy the selected candidate's path truncated at the last backslash (character 92), via StringCopyWithBufferRealloc. [global:0x005EA438, callee:0x00566650, source:raw]
    // CALL: After the 9-iteration loop completes, release the lookup handle v46 with PhysicsObjectLinkedListRemoval when it is non-zero. [callee:0x0053CE40, source:raw]
    // CALL: Free the three string buffers backing the v53 TrackName area and the path buffer v43 with FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]

    // Conservative worker pseudocode:
    //   if (!a1) return;
    //   path = alloc(256); *path = 0;
    //   copy(base = *(this) ? *(this) : defaultStr); truncateAtLastBackslash(path);
    //   append(path, aTeamMas); lookupHandle = sub_53CBC0(path);
    //   teamStr = this[972] ? this[972] : defaultStr;
    //   trackStr = this[984] ? this[984] : defaultStr;
    //   load TrackName into v53 (on failure clear);
    //   node = this[980]; while (node && sub_588410(node->str, v53)) node = node[16];
    //   matched = node ? node[8] : defaultStr;
    //   for idx in 0..8:
    //     (wcVariant, regularVariant) = dispatchTable[idx];
    //     candidates = [a2name, matched]; if (idx >= 5) add trackStr; add teamStr if room;
    //     for each candidate: copy base, strip backslash, append candidate, strip extension, append name-or-'.bmp';
    //     fill remaining slots with wcVariant + '.bmp';
    //     selector = TextureAdjuster(wcVariant, 1, candidates..., a4);
    //     if (idx == 0 && a3) selector >= 3 ? reset-to-default : copy selected-candidate path;
    //   if (lookupHandle) PhysicsObjectLinkedListRemoval(lookupHandle);
    //   free the three v53 string buffers and path;
    // UNRESOLVED: Globals 0x008AC368 and 0x008AFE64 are listed as packet reads but never appear in the raw function text; their role is unknown.
    // UNRESOLVED: The exact meaning of the this+972 and this+984 config strings and of the object they belong to is inferred, not independently evidenced.
    // UNRESOLVED: The semantics of sub_5665B0 and sub_53CBC0 (string append / lookup-handle build) are derived from usage only.
    // UNRESOLVED: The a3 and a4 argument roles beyond gating the index-0 re-copy are not evidenced.
    // UNRESOLVED: TextureAdjuster's return selector semantics (used only for index 0) are not documented by this packet.
}
