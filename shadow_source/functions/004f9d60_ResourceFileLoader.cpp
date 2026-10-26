// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F9D60
// Canonical corpus name: ResourceFileLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceFileLoader_004f9d60.c

void UnknownObject::ResourceFileLoader()
{
    // Loads a named resource: first via the direct path, then via default directory (byte_5EA438) + override path (dword_5EC408). When the handle is obtained, runs a timed loading screen (clipped render region + present, optional input polling that breaks early on input) for a2 seconds, then releases the handle. Returns 1 on success, 0 on failure.
    // ASSIGNMENT: v3 = 0, v12 = 0; StructZeroInit_8ba0(v13) zero-initializes the timer/result structure. [callee:0x00568BA0, source:raw]
    // GUARD: ShortComputation_4fb0(&v12, a1, 1): try to open the direct resource path; if it returns 0, skip to the timed-loading block (LABEL_6). [callee:0x00494FB0, source:raw]
    // CALCULATION: Initialize path buffer v14: copy byte_5EA438[0], zero-fill the remainder (0xFC bytes), clear the trailing v15/v16 terminator fields. [global:0x005EA438, source:raw]
    // ASSIGNMENT: v4 = dword_5EC408 (override path pointer), or byte_5EA438 default directory when null. [global:0x005EC408, global:0x005EA438, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v14, "%s%s", v4, a1) builds the default-dir + name path using path-format-string global aSS. [callee:0x0058815F, global:0x005BE860, global:0x005EC408, source:raw]
    // ASSIGNMENT: v12 = 0 before retrying with the formatted path. [source:raw]
    // GUARD: ShortComputation_4fb0(&v12, v14, 1): retry with the formatted path; if it returns nonzero (still no handle), call EmptyStub_0170() and return 0. [callee:0x00494FB0, callee:0x004B0170, source:raw]
    // RETURN: Return 0 when the resource could not be opened by either path. [source:raw]
    // GUARD: If v12 (resource handle) is nonzero, run the timed loading screen and set the success flag v3 = 1. [source:raw]
    // CALL: Draw a full-window clipped region (ClippedRenderRegion) using size values read from the handle at v12+28 and v12+32 and the render dimension from GlobalAccessor_5150, present via sub_495080; the draw+present pair runs twice. [callee:0x00543250, callee:0x00495150, callee:0x00495080, source:raw]
    // CALL: QPCTimerInitialization(1): (re)start the timer for the loading wait. [callee:0x00568BE0, source:raw]
    // LOOP: While PerformanceCounterDiffWithScaling(v13) < a2 (elapsed time below the requested seconds), keep looping the loading screen. [callee:0x00568D90, source:raw]
    // CALL: If a3 is set, sub_4537B0(&ppvOut, 0.05f) polls/processes input with a 50ms timeout; break the wait when dword_7CB218 > 0 (user input detected). [callee:0x004537B0, global:0x007CA590, global:0x007CB218, source:raw]
    // CALL: ThunkToFUN0053cb90(v12): release/free the loaded resource handle; ShortComputation_50c0() runs the post-load cleanup. [callee:0x00494FD0, callee:0x004950C0, source:raw]
    // ASSIGNMENT: v12 = 0; v3 = 1 (success). [source:raw]
    // CALL: EmptyStub_0170() on the exit path. [callee:0x004B0170, source:raw]
    // RETURN: Return v3 (1 success / 0 failure). [source:raw]

    // Conservative worker pseudocode:
    //   v3 = 0; v12 = 0; StructZeroInit_8ba0(v13);
    //   if (!ShortComputation_4fb0(&v12, a1, 1)) goto load;
    //   v14 = clear_buffer(byte_5EA438);
    //   base = dword_5EC408 ? dword_5EC408 : byte_5EA438;
    //   StringFormatWithBufferOverflowCheck(v14, "%s%s", base, a1);
    //   v12 = 0;
    //   if (ShortComputation_4fb0(&v12, v14, 1)) { EmptyStub_0170(); return 0; }
    //   load:
    //   if (v12) {
    //       for (twice) { ClippedRenderRegion(0,0,GlobalAccessor_5150(),0,0,*(v12+28),*(v12+32),-1,0); sub_495080(); }
    //       QPCTimerInitialization(1);
    //       while (PerformanceCounterDiffWithScaling(v13) < a2) {
    //           if (a3) { sub_4537B0(&ppvOut, 0.05f); if (dword_7CB218 > 0) break; }
    //       }
    //       ThunkToFUN0053cb90(v12); ShortComputation_50c0();
    //       v12 = 0; v3 = 1;
    //   }
    //   EmptyStub_0170(); return v3;
    // UNRESOLVED: unk_7CDE00 (0x007CDE00) appears in the packet globals table but has no visible raw-source access; its role (Unknown_Render_CDE00 per the fill) is not evidenced here.
    // UNRESOLVED: aSS (0x005BE860) is the path format string per the fill (PathFormatString, DERIVED); the raw source renders it only as the literal "%s%s".
    // UNRESOLVED: Resource-handle offsets +28/+32 and the -1 / 0.05f / 0xFC literals come only from the raw source; no field evidence exists for the handle layout.
    // UNRESOLVED: ShortComputation_4fb0 return semantics (0 = success) are inferred from the control flow, not named in the packet.
    // UNRESOLVED: dword_7CB218 as an input/device count is fill-derived (InputDeviceCount, DERIVED).
}
