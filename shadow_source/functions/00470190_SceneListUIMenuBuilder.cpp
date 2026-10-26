// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00470190
// Canonical corpus name: sub_470190
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_470190_00470190.c

void UnknownObject::SceneListUIMenuBuilder()
{
    // Calls StateCleanupNotification, then iterates the scene entry array (count dword_8AC488, base dword_8AC490, stride 396) and creates one UI menu item per entry via UIMenuItemCreator from a formatted name/time string. Called by SetupFileLoadAndFinalize.
    // CALL: Invoke StateCleanupNotification on this to clear prior state before building the scene menu. [callee:0x00489CB0, source:raw]
    // ASSIGNMENT: result = scene entry count dword_8AC488; same count bounds the loop below. [global:0x008AC488, source:raw]
    // GUARD: Enter the scene iteration only when dword_8AC488 (scene count) is greater than zero. [global:0x008AC488, source:raw]
    // LOOP: For index v2 from 0 while v2 < dword_8AC488, build one menu item per scene entry; advance scene offset v3 by 396 bytes per iteration. [global:0x008AC488, source:raw]
    // CALCULATION: Scene entry pointer v4 = array base dword_8AC490 + current offset v3; string operands are read at entry +260 and +324. [global:0x008AC490, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck formats the time portion into v6 using format string aI063f ("%i:%06.3f") with arguments 0 and 0.0. [callee:0x0058815F, global:0x005C6930, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck formats the full scene label into v7 using format string aSSSSSI ("%s, %s%s%s%s%i") from entry string at +324, entry string at +260, separator word_5C692C, time buffer v6, separator word_5C692C again, and integer v5. [callee:0x0058815F, global:0x005C6E1C, global:0x005C692C, source:raw]
    // CALL: UIMenuItemCreator creates a UI menu item from the formatted scene label v7 with all four extra parameters zero. [callee:0x00489600, source:raw]
    // RETURN: Return the final scene count from dword_8AC488. [global:0x008AC488, source:raw]

    // Conservative worker pseudocode:
    //   StateCleanupNotification(this);
    //   for (index = 0, offset = 0; index < scene_count; index++, offset += 396) {
    //       entry = scene_array_base + offset;
    //       format_time(v6, 0, 0.0);
    //       format_label(v7, entry+324, entry+260, sep, v6, sep, v5);
    //       UIMenuItemCreator(v7, 0, 0, 0, 0);
    //   }
    // UNRESOLVED: Meaning of the scene entry string fields at +260 and +324 is not established from this packet.
    // UNRESOLVED: Integer argument v5 is read uninitialized in the raw source; its source and role are unknown.
    // UNRESOLVED: Semantic content of the three token globals (word_5C692C separator, aI063f, aSSSSSI) beyond format usage is unverified.
}
