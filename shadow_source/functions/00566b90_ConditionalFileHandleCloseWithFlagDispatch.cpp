// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00566B90
// Canonical corpus name: ConditionalFileHandleCloseWithFlagDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalFileHandleCloseWithFlagDispatch_00566b90.c

void UnknownObject::ConditionalFileHandleCloseWithFlagDispatch()
{
    // Conditional file-handle close. Defaults the result to false, then branches on the close-method flag at this+0x10: when it is zero the handle at this+0x0 is closed directly with FileCloseWithLock; when non-zero it is closed through the type-checked dispatch StreamFileTypeCheckWithDispatch. In both success paths the handle is nulled and the result reflects whether the close call succeeded; when the handle is already null the function returns false.
    // ASSIGNMENT: Initialize result to false before the handle checks. [source:raw]
    // GUARD: Branch on the close-method flag at this+0x10 being zero (direct close) versus non-zero (type-checked dispatch close). [guard:0, field:this:0x00000010, source:raw]
    // GUARD: Both branches further require the handle at this+0x0 to be non-zero before closing. [field:this:0x00000000, source:raw]
    // CALL: Flag-zero path: FileCloseWithLock(*this) closes the handle directly; on success the handle is nulled and the success result returned. [callee:0x00587D02, field:this:0x00000000, source:raw]
    // CALL: Flag-non-zero path: StreamFileTypeCheckWithDispatch(v4) closes the handle via type-specific dispatch; on success the handle is nulled and the success result returned. [callee:0x005355A0, field:this:0x00000000, source:raw]
    // RETURN: Return false when the handle was already null (no close performed). [source:raw]
    // CALL: Called on the frame path by camera, scene-loader, text/UI, vehicle-setup, config/file-parser, audio-stream and damage-model subsystems as a shared file-handle teardown helper. [caller:0x00408E20, caller:0x00409770, caller:0x0040B030, caller:0x0040BD10, caller:0x0042FD00, caller:0x00432E70, caller:0x004330D0, caller:0x0044BC50, caller:0x0044BE70, caller:0x0045ECD0, caller:0x004A51C0, caller:0x004B0770, caller:0x004B7300, caller:0x004B7500, caller:0x004B7DE0, caller:0x004BA1F0, caller:0x004C22A0, caller:0x004C2700, caller:0x004D24D0, caller:0x004D7150, caller:0x004E3360, caller:0x004F24F0, caller:0x004F3C80, caller:0x004F7460, caller:0x005668D0, caller:0x00566B20, caller:0x00567F40]

    // Conservative worker pseudocode:
    //   bool sub_566B90(this) {
    //     bool result = false;
    //     bool direct = (this[0x10/4] == 0);
    //     int handle = *this;
    //     if (direct) {
    //       if (handle) { int ok = FileCloseWithLock(*this); *this = 0; return ok == 0; }
    //     } else if (handle) {
    //       int ok = StreamFileTypeCheckWithDispatch(handle); *this = 0; return ok == 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The meaning of the close-method flag at this+0x10 (which file types route through StreamFileTypeCheckWithDispatch) is not defined here.
    // UNRESOLVED: The file-handle resource semantics of the two close paths are not established by this packet.
}
