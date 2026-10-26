// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491EE0
// Canonical corpus name: FileOpenWrapperWithModeCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileOpenWrapperWithModeCheck_00491ee0.c

void UnknownObject::FileOpenWrapperWithModeCheck()
{
    // Open-file wrapper for an audio stream object: opens a read stream with mode "rb" into this[0], optionally opens a write stream with mode "wt" into this[1] when the write-mode flag byte at this+0x19A is set, clears that flag if the write stream could not be created, reads/initializes the audio stream buffer from the read stream when present, then configures the write stream if the flag remains set. Always returns 0.
    // ASSIGNMENT: open the read stream: this[0] = sub_534B00(this + 3, aRb) using the "rb" mode string [callee:0x00534B00, global:0x005BE828, field:this:0x00000000]
    // GUARD: guard: only attempt the write stream when the write-mode flag byte at this+0x19A is non-zero [field:this:0x0000019A]
    // ASSIGNMENT: open the write stream: this[1] = sub_587DB0(this + 35, aWt) using the "wt" mode string [callee:0x00587DB0, global:0x005C302C, field:this:0x00000004, field:this:0x0000019A]
    // STATE_TRANSITION: if the write stream handle at this+0x4 is null while the write-mode flag is still set, clear the flag byte at this+0x19A to 0 [field:this:0x00000004, field:this:0x0000019A]
    // GUARD: guard: only read the audio stream buffer when the read stream handle at this+0x0 is non-null [field:this:0x00000000]
    // CALL: call AudioStreamBufferRead(0) to read/initialize the audio stream buffer from the read stream [callee:0x00535390, field:this:0x00000000]
    // GUARD: guard: only configure the write stream when the write-mode flag byte at this+0x19A remains set [field:this:0x0000019A]
    // CALL: call sub_587F64(this[1], 0, 0) to configure the write stream handle at this+0x4 [callee:0x00587F64, field:this:0x00000004, field:this:0x0000019A]
    // RETURN: return 0 unconditionally [source:raw, function:0x00491EE0]

    // Conservative worker pseudocode:
    //   *this = sub_534B00(this + 3, aRb);
    //   if ( *((BYTE*)this + 0x19A) )
    //       this[1] = sub_587DB0(this + 35, aWt);
    //   if ( !this[1] && *((BYTE*)this + 0x19A) )
    //       *((BYTE*)this + 0x19A) = 0;
    //   if ( *this )
    //       AudioStreamBufferRead(0);
    //   if ( *((BYTE*)this + 0x19A) )
    //       sub_587F64(this[1], 0, 0);
    //   return 0;
    // UNRESOLVED: Owner object type is unknown; packet owner is UNKNOWN/UnknownObject. The read/write stream handles suggest an audio stream/file object but there is no named class evidence.
    // UNRESOLVED: sub_534B00 and sub_587DB0 are presumed open-with-mode helpers from the mode strings, but their exact semantics are not established by this packet.
}
