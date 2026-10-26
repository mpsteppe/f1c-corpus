// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F9B70
// Canonical corpus name: FileLoadWithRetryLoop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileLoadWithRetryLoop_004f9b70.c

void UnknownObject::FileLoadWithRetryLoop()
{
    // Loads a file/object via ObjectCreationWithRollbackOnFailure with a path-prefix replacement retry on first failure, then presents a Bink video loading sequence. When the wait flag a2 is set, the presentation loop spins until dword_7CB218 (input device count) becomes positive; otherwise it retries BinkVideoFrameRender until a frame renders. Releases the loaded object, closes the Bink stream and releases the guarded subsystem on exit. Returns 1 only if both load attempts fail, otherwise 0.
    // ASSIGNMENT: Initialize the object handle v7 to 0 before the creation attempts. [source:raw]
    // CALL: OneTimeInitializationWithAtexitStyleRegistration obtains the singleton/global initialization context; its +36 entry supplies the type descriptor for the object creation call. [callee:0x00404FE0, source:raw]
    // CALL: ObjectCreationWithRollbackOnFailure attempts to create/load the object from the original path a1 with rollback on failure, writing the result into v7. [callee:0x00551F10, source:raw]
    // GUARD: On first-attempt failure (v7 still zero) the filename is copied into the v9 buffer and prepared for a path-prefix replacement retry. [source:raw]
    // ASSIGNMENT: Copy the original filename a1 into the local 512-byte buffer v9. [source:raw]
    // CALL: StringFormatReplaceOperation applies the season parent path dword_5EC3D0 to replace the path prefix inside v9. [callee:0x00422FD0, global:0x005EC3D0, source:raw]
    // CALL: Second ObjectCreationWithRollbackOnFailure attempt using the path-replaced filename v9; the object type descriptor is again fetched via OneTimeInitializationWithAtexitStyleRegistration. [callee:0x00551F10, callee:0x00404FE0, source:raw]
    // GUARD: If the retry attempt also fails (v7 still zero) the function returns 1 to report total load failure before the video stage. [source:raw]
    // RETURN: Return 1 on total load failure (both original-path and path-replaced attempts failed). [source:raw]
    // CALL: VTableMethodGuard stores a guard result in v8; when it is non-zero, VTableDispatchViaGlobal performs the guarded vtable dispatch. [callee:0x004C8580, callee:0x004C85A0, source:raw]
    // CALL: GlobalAccessor, then sub_5434A0(0.0, 0.0, 1.0, 1.0, 0) and MultiStepInitSequence run the loading-sequence setup (render rectangle plus multi-step init) before video presentation. [callee:0x00495140, callee:0x005434A0, callee:0x00495020, source:raw]
    // CALL: A second GlobalAccessor plus sub_5434A0(0.0, 0.0, 1.0, 1.0, 0) resets the render rectangle after the init sequence. [callee:0x00495140, callee:0x005434A0, source:raw]
    // CALL: sub_551EB0 configures the DSP/audio transform parameter from flt_7CF2CC before the video loop. [callee:0x00551EB0, global:0x007CF2CC, source:raw]
    // CALL: First BinkVideoFrameRender on the global context renders a video frame; a failing frame opens the retry loop. [callee:0x00551CF0, callee:0x00495140, source:raw]
    // GUARD: If the first BinkVideoFrameRender fails, execution enters the retry loop; otherwise it jumps straight to cleanup. [source:raw]
    // LOOP: Retry loop: MultiStepInitSequence, then sub_4537B0 processes the module output array ppvOut at 0.050000001; when the wait flag a2 is set and dword_7CB218 (input device count) is positive the loop breaks early, otherwise sub_4A1830, GlobalAccessor and a further BinkVideoFrameRender continue; a successfully rendered frame jumps out to cleanup. [callee:0x00495020, callee:0x004537B0, global:0x007CA590, global:0x007CB218, callee:0x004A1830, callee:0x00495140, callee:0x00551CF0, source:raw]
    // CALL: After the loop exits without a rendered frame, one final sub_4537B0 processes ppvOut at 0.050000001 before cleanup. [callee:0x004537B0, global:0x007CA590, source:raw]
    // CALL: ConditionalFreeWithBinkClose releases the loaded object v7 and closes the Bink stream. [callee:0x00551F80, source:raw]
    // CALL: GuardedSubsystemRelease releases the guarded subsystem. [callee:0x00495060, source:raw]
    // GUARD: If the earlier vtable guard result v8 is set, NullCheckedVTableCall runs the null-checked vtable teardown call. [callee:0x004C85C0, source:raw]
    // RETURN: Return 0 on the success/cleanup path; callers include sub_4944A0, sub_4A00A0, sub_4A0760, sub_4A08E0 and sub_4A09F0. [function:0x004F9B70, caller:0x004944A0, caller:0x004A00A0, caller:0x004A0760, caller:0x004A08E0, caller:0x004A09F0, source:raw]

    // Conservative worker pseudocode:
    //   int FileLoadWithRetryLoop(const char* a1, char a2) {
    //     void* obj = 0;
    //     ctx = OneTimeInitializationWithAtexitStyleRegistration();
    //     ObjectCreationWithRollbackOnFailure(&obj, a1, 1, ctx[36]);
    //     if (!obj) {
    //       char v9[512];
    //       strcpy(v9, a1);
    //       StringFormatReplaceOperation(dword_5EC3D0, v9, 512);
    //       ctx = OneTimeInitializationWithAtexitStyleRegistration();
    //       ObjectCreationWithRollbackOnFailure(&obj, v9, 1, ctx[36]);
    //       if (!obj) return 1;
    //     }
    //     v8 = VTableMethodGuard();
    //     if (v8) VTableDispatchViaGlobal();
    //     GlobalAccessor();
    //     sub_5434A0(0.0, 0.0, 1.0, 1.0, 0);
    //     MultiStepInitSequence();
    //     GlobalAccessor();
    //     sub_5434A0(0.0, 0.0, 1.0, 1.0, 0);
    //     sub_551EB0(flt_7CF2CC);
    //     if (!BinkVideoFrameRender(GlobalAccessor(), 0, 0, 0)) {
    //       for (;;) {
    //         MultiStepInitSequence();
    //         sub_4537B0((int)&ppvOut, 0.050000001);
    //         if (a2) {
    //           if (dword_7CB218 > 0) break;
    //         }
    //         sub_4A1830();
    //         if (BinkVideoFrameRender(GlobalAccessor(), 0, 0, 0)) break;
    //       }
    //       sub_4537B0((int)&ppvOut, 0.050000001);
    //     }
    //     ConditionalFreeWithBinkClose(obj);
    //     GuardedSubsystemRelease();
    //     if (v8) NullCheckedVTableCall();
    //     return 0;
    //   }
    // UNRESOLVED: Identity and purpose of helper sub_4A1830 called inside the retry loop is undocumented.
    // UNRESOLVED: sub_5434A0 rectangle semantics (0.0, 0.0, 1.0, 1.0) are described as viewport/scissor setup only from skeleton prose, not proven by this packet.
    // UNRESOLVED: The reading of dword_7CB218 as an input-device count is DERIVED from skeleton analysis; this packet only proves it is compared against zero.
    // UNRESOLVED: Four read-only globals (unk_7CDE00, unk_7CE2A4, byte_8AC494, dword_8AFE64) are flagged by packet facts but appear nowhere in the raw decompiled source; they are unverifiable from this packet.
}
