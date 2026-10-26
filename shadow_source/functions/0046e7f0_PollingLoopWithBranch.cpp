// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046E7F0
// Canonical corpus name: PollingLoopWithBranch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PollingLoopWithBranch_0046e7f0.c

void UnknownObject::PollingLoopWithBranch()
{
    // Path-processing loop with a final conditional branch. Iteratively calls DirectoryPathExtraction on the dword_7C73E0 path string until StringEmptyCheck reports it empty, then branches on this+0x168: when zero, reads a settings setup file from that path and returns its result; otherwise retrieves UI text via UIScreenTextAccessor(this) and runs PathNormalizerFileEnumeration on the path with that text, returning its result.
    // LOOP: while (!StringEmptyCheck(dword_7C73E0)) DirectoryPathExtraction(dword_7C73E0); strips one directory component per iteration from the dword_7C73E0 path until it becomes empty [callee:0x004328F0, callee:0x00432A10, global:0x007C73E0, source:raw]
    // GUARD: Branch on this+0x168 (this[90]): zero takes the settings-read path, non-zero takes the UI-text/normalize path [field:this:0x00000168, source:raw]
    // CALL: Settings-read branch: raw source names the callee SettingsSetupFileRead on (char**)dword_7C73E0 and returns its result; the packet callee list carries no distinct entry for this call [global:0x007C73E0, source:raw]
    // CALL: UIScreenTextAccessor(this) retrieves text content from the UI screen element into v3 [callee:0x00489920, source:raw]
    // CALL: PathNormalizerFileEnumeration((char**)dword_7C73E0, v3) normalizes the path string and enumerates files; its result is returned [callee:0x00432980, global:0x007C73E0, source:raw]
    // RETURN: Return the settings-read or file-enumeration result from the selected branch [source:raw]

    // Conservative worker pseudocode:
    //   while (!StringEmptyCheck(dword_7C73E0))
    //     DirectoryPathExtraction(dword_7C73E0);
    //   if (this[0x168/4] == 0)
    //     return SettingsSetupFileRead((char**)dword_7C73E0);
    //   v3 = UIScreenTextAccessor(this);
    //   return PathNormalizerFileEnumeration((char**)dword_7C73E0, v3);
    // UNRESOLVED: Raw source names the settings-read callee SettingsSetupFileRead, but the packet callee list (StringEmptyCheck, PathNormalizerFileEnumeration, DirectoryPathExtraction, UIScreenTextAccessor) has no matching entry, so its address cannot be pinned from this packet
    // UNRESOLVED: The role of dword_7C73E0 (labeled ModuleCallbackTable path in the skeleton fill) is not verifiable from this packet
}
