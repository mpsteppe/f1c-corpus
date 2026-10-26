// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C11E0
// Canonical corpus name: SessionConfigReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionConfigReader_004c11e0.c

void UnknownObject::SessionConfigReader()
{
    // Parses a session entry's configuration from the season data: guards on AudioChannelStop with the scene-order key, validates the session index via NullCheckWrapper, finds the season races section, loads the track scene, copies two scene path strings into the session object, then reads QualifyLaps, QualifyTime, RaceLaps and RaceTime integer values from the section's keyed linked list (defaulting each to -1 when the key is absent), stores the selected session index, and returns a pointer into the session string buffer.
    // GUARD: If AudioChannelStop(dword_8AD3B4, aSceneorder) fails, return 0. [callee:0x00568210, global:0x008AD3B4, global:0x005D28B4]
    // RETURN: Return 0 on the AudioChannelStop failure guard. [source:raw]
    // CALL: v3 = NullCheckWrapper(a2): null-guards the session index parameter. [callee:0x005679A0]
    // GUARD: If v3 is null, return 0. [callee:0x005679A0]
    // CALL: v4 = StringPointerAccessor(v3): extracts the session name/path string. [callee:0x00499E20]
    // CALL: v5 = SeasonRacesSectionFinder(v4): locates the season races section for this session. [callee:0x004C5840]
    // GUARD: If v5 is null, return 0. [callee:0x004C5840]
    // CALL: v7 = StringPointerAccessor(v5) then TrackSceneLoader(v7): loads the track scene for the section. [callee:0x00499E20, callee:0x004C55B0]
    // CALCULATION: v8 = dword_8AC490 + 396 * dword_8AC48C: computes the current scene entry pointer into the scene array. [global:0x008AC490, global:0x008AC48C]
    // CALL: StringCopyWithBufferRealloc(this+11336, v8+260): copies the scene name path string into the session string buffer. [callee:0x00566650]
    // CALL: StringCopyWithBufferRealloc(this+11338, v8+4): copies the scene path string into the second session string slot. [callee:0x00566650]
    // GUARD: Search the section's keyed linked list for aQualifylaps; if found, this[11340] = sub_587ECE(DataEntryAccessor(entry)), else this[11340] = -1. [callee:0x005679C0, global:0x005D231C, callee:0x00567970, callee:0x00587ECE, field:this:0x0000B130]
    // GUARD: Search for aQualifytime; if found, this[11341] = sub_587ECE(DataEntryAccessor(entry)), else this[11341] = -1. [callee:0x005679C0, global:0x005D28C0, callee:0x00567970, callee:0x00587ECE, field:this:0x0000B134]
    // GUARD: Search for aRacelaps; if found, this[11342] = sub_587ECE(DataEntryAccessor(entry)), else this[11342] = -1. [callee:0x005679C0, global:0x005C7444, callee:0x00567970, callee:0x00587ECE, field:this:0x0000B138]
    // GUARD: Search for aRacetime; if found, this[11343] = sub_587ECE(DataEntryAccessor(entry)), else this[11343] = -1. [callee:0x005679C0, global:0x005D2310, callee:0x00567970, callee:0x00587ECE, field:this:0x0000B13C]
    // GUARD: If a2 >= this[11346] (session count bound), set this[11344] = -1; otherwise set this[11344] = this[a2 + 11233] (copy stored session index). [field:this:0x0000B148, field:this:0x0000B140]
    // RETURN: Return this + 11336 (pointer to the session string buffer). [function:0x004C11E0]

    // Conservative worker pseudocode:
    //   if !AudioChannelStop(sessionKey): return 0
    //   section = SeasonRacesSectionFinder(StringPointerAccessor(a2)); if !section: return 0
    //   TrackSceneLoader(StringPointerAccessor(section))
    //   copy scene name from scene[dword_8AC48C] (entry+260) and scene path (entry+4) into session strings
    //   session.QualifyLaps  = key(section, "QualifyLaps")  ? atoi : -1
    //   session.QualifyTime = key(section, "QualifyTime") ? atoi : -1
    //   session.RaceLaps    = key(section, "RaceLaps")    ? atoi : -1
    //   session.RaceTime    = key(section, "RaceTime")    ? atoi : -1
    //   session.selected = (a2 >= count) ? -1 : session[a2 + 11233]
    //   return &session->stringBuffer
    // UNRESOLVED: The copy targets this+11336 and this+11338 (byte offsets 0xB120/0xB128) have no field evidence entries in this packet; the closest packet fields (0xB130/0xB134) are the parsed value slots, not the string buffers.
    // UNRESOLVED: Global unk_8AC368 is listed in evidence but not referenced in the decompiled body.
    // UNRESOLVED: sub_587ECE is treated as an opaque integer parser; its exact conversion semantics are not established here.
    // UNRESOLVED: Meaning of this[a2 + 11233] (the stored index source) is inferred only from position in the array.
}
