// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045BEA0
// Canonical corpus name: AVIStreamCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AVIStreamCleanup_0045bea0.c

void UnknownObject::AVIStreamCleanup()
{
    // Releases the AVI playback handles owned by the object: two AVIStream interfaces (this+0x3C, this+0x40) and one AVIFile interface (this+0x38), each released only while non-null and then nulled to 0. Delegates teardown to AVIPlayerCleanup and returns its result. Called by sub_45BE80 (0045be80).
    // GUARD: If handle at this+0x3C is non-null, release the first AVIStream interface [field:this:0x0000003C]
    // CALL: AVIStreamRelease on the first stream handle (this+0x3C) [callee:0x00534AEC, field:this:0x0000003C]
    // ASSIGNMENT: Null this+0x3C to 0 after releasing the first stream [field:this:0x0000003C]
    // GUARD: If handle at this+0x40 is non-null, release the second AVIStream interface [field:this:0x00000040]
    // CALL: AVIStreamRelease on the second stream handle (this+0x40) [callee:0x00534AEC, field:this:0x00000040]
    // ASSIGNMENT: Null this+0x40 to 0 after releasing the second stream [field:this:0x00000040]
    // GUARD: If handle at this+0x38 is non-null, release the AVIFile interface [field:this:0x00000038]
    // CALL: AVIFileRelease on the file handle (this+0x38) [callee:0x00534AE6, field:this:0x00000038]
    // ASSIGNMENT: Null this+0x38 to 0 after releasing the file [field:this:0x00000038]
    // RETURN: Return the result of AVIPlayerCleanup() [function:0x0045BEA0, source:raw]

    // Conservative worker pseudocode:
    //   if (this->stream1) { AVIStreamRelease(this->stream1); this->stream1 = 0; }
    //   if (this->stream2) { AVIStreamRelease(this->stream2); this->stream2 = 0; }
    //   if (this->file) { AVIFileRelease(this->file); this->file = 0; }
    //   return AVIPlayerCleanup();
    // UNRESOLVED: AVIPlayerCleanup is called as the final step but has no address or callee evidence reference in the packet; its identity and return contract are unverified
}
