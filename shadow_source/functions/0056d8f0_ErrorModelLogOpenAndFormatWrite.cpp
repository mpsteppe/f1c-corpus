// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056D8F0
// Canonical corpus name: sub_56D8F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_56D8F0_0056d8f0.c

void UnknownObject::ErrorModelLogOpenAndFormatWrite()
{
    // Opens the model error text log file (sub_587DB0 with the aPmodelErrorTxt/aA string literals), writes a formatted string aS_4 into it via StringFormatWithNestedIO, then closes the handle with FileCloseWithLock. Returns 0 unchanged when the file open fails.
    // CALL: sub_587DB0(aPmodelErrorTxt, aA): open/create the model error text log file using two string-literal arguments; a non-null return is a valid file handle. [callee:0x00587DB0, global:0x005E5248, global:0x005E525C, source:raw]
    // GUARD: If the returned handle is non-null, proceed to format and close; otherwise skip the write path. [callee:0x00587DB0, source:raw]
    // CALL: StringFormatWithNestedIO(handle, aS_4): write the formatted aS_4 string into the open log file. [callee:0x005887B1, global:0x005C2C18, source:raw]
    // CALL: FileCloseWithLock(v1): close the file handle on the success path. [callee:0x00587D02, source:raw]
    // RETURN: Returns the handle value on success (the close call result) and 0 on the failed-open path. [callee:0x00587DB0, source:raw]

    // Conservative worker pseudocode:
    //   handle = sub_587DB0(aPmodelErrorTxt, aA);
    //   if (handle) { StringFormatWithNestedIO(handle, aS_4); return FileCloseWithLock(handle); }
    //   return 0;
    // UNRESOLVED: Literal contents of the string xrefs aPmodelErrorTxt, aA and the aS_4 format string are unknown; only their code xrefs are evidence.
    // UNRESOLVED: Caller VehiclePhysicsJointSystemLoader (0x0056D930) runs this on the frame path, but the exact error-reporting duty in that loader is not established.
}
