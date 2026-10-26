// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BA770
// Canonical corpus name: sub_4BA770
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4BA770_004ba770.c

void UnknownObject::FileSettingExistenceCheckWrapper()
{
    // Thin single-call wrapper (no arguments) that invokes FileSettingExistenceCheck() and returns its boolean result unchanged. The ABI packet classifies this as a Single_Call_Wrapper. The only recorded caller is GameExit (0x0042DB20), suggesting it is an exit-path file-setting presence check, but the callee target itself is not present in the packet's callees list.
    // CALL: Calls FileSettingExistenceCheck() (named in raw source; no address evidence in the packet) and returns its boolean result directly. Invoked from GameExit (0x0042DB20). [source:raw, function:0x004BA770, caller:0x0042DB20]
    // RETURN: Returns the boolean result of FileSettingExistenceCheck() unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   return FileSettingExistenceCheck();
    // UNRESOLVED: FileSettingExistenceCheck() is named in raw source but has no address in the packet's empty callees list.
    // UNRESOLVED: Purpose of a file-setting existence check on the GameExit path is unverified.
}
