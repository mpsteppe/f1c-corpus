// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049B0A0
// Canonical corpus name: sub_49B0A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49B0A0_0049b0a0.c

void UnknownObject::WidgetResourceArrayInit()
{
    // Initializes four UI button widgets (vehicle display, network problem, next track, next session) by building a resource path from the season directory (dword_5EC3D8) or a default directory, loading a resource container via sub_53CBC0, then allocating and constructing each widget into the dword_7CE23C slot array. When bitmap/surface creation for a widget fails, that widget is cleaned up and its slot cleared.
    // ASSIGNMENT: Initialize the path buffer to empty and select the base directory string: dword_5EC3D8 when set, otherwise the byte_5EA438 default directory. [source:raw, global:0x005EC3D8, global:0x005EA438]
    // CALL: StringFormatWithBufferOverflowCheck formats the resource path into the stack buffer from the base directory and off_5CCB54[0] using the aSS format string. [source:raw, callee:0x0058815F, global:0x005BE860, global:0x005CCB54]
    // ASSIGNMENT: Initialize the resource-container handle local v8 to zero. [source:raw]
    // CALL: sub_53CBC0 loads the resource container from the formatted path into v8; a nonzero return aborts the routine. [source:raw, callee:0x0053CBC0]
    // GUARD: Guard: proceed to build the four widgets only when the container load returned zero. [source:raw]
    // LOOP: Loop over four widget slots; a switch (jump table jpt_49B107) selects the bitmap name string per index: aVehicledisplay, aNetproblemBmp, aNexttrackBmp, aNextsessionBmp. [source:raw, global:0x0049B1AC, global:0x005CCE04, global:0x005CCDF4, global:0x005CCDE4, global:0x005CCDD4]
    // CALL: OperatorNewNhMallocWrapper allocates a 40-byte widget object for the current slot. [source:raw, callee:0x00587C03]
    // CALL: On allocation success ShortComputation_cb70 constructs the widget object. [source:raw, callee:0x004DCB70]
    // ASSIGNMENT: Store the widget pointer (or null when allocation failed) into the current dword_7CE23C slot. [source:raw, global:0x007CE23C]
    // GUARD: Guard: sub_4DCBA0 attempts bitmap/surface creation from the selected name; a nonzero return flags failure. [source:raw, callee:0x004DCBA0]
    // CALL: On surface-creation failure the widget is cleaned up via ResourceCleanup_cd10, freed via FreeWrapper_7bcf, and the slot is reset to null. [source:raw, callee:0x004DCD10, callee:0x00587BCF, global:0x007CE23C]
    // RETURN: Return PhysicsObjectLinkedListRemoval(v8) as the final result of the routine. [source:raw, callee:0x0053CE40]

    // Conservative worker pseudocode:
    //   char path_buf[512]; path_buf[0] = 0;
    //   const char* base = dword_5EC3D8 ? (const char*)dword_5EC3D8 : byte_5EA438;
    //   StringFormatWithBufferOverflowCheck(path_buf, aSS, base, off_5CCB54[0]);
    //   int handle = 0;
    //   if (sub_53CBC0(&handle, path_buf) == 0) {
    //     for (int i = 0; i < 4; ++i) {
    //       const char* name = pickBitmapName(i);
    //       void* w = (void*)OperatorNewNhMallocWrapper(40);
    //       if (w) ShortComputation_cb70(w); else w = 0;
    //       dword_7CE23C[i] = (int)w;
    //       if (sub_4DCBA0(-16777216, name, 0, 0, 0, 32, 32, 0, 0)) {
    //         if (dword_7CE23C[i]) { ResourceCleanup_cd10(dword_7CE23C[i]); FreeWrapper_7bcf((void*)dword_7CE23C[i]); }
    //         dword_7CE23C[i] = 0;
    //       }
    //     }
    //     return PhysicsObjectLinkedListRemoval(handle);
    //   }
    //   return result;
    // UNRESOLVED: dword_8AFE64 is reported as read by the facts but does not appear in the raw decompiled body; its role in this routine is unknown.
    // UNRESOLVED: off_5CCB54[0] is consumed as a path string here despite the global being treated as a vtable entry elsewhere; exact meaning is unclear.
    // UNRESOLVED: The meaning of the sub_4DCBA0 arguments (color literal, 32x32 dimensions, trailing zeros) is inferred, not confirmed.
}
