// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00542E50
// Canonical corpus name: sub_542E50
// Owner: AudioEmitter [DERIVED]
// Raw source: functions/sub_542E50_00542e50.c

void AudioEmitter::AudioEmitterDestructor()
{
    // Destructor/reset path for an audio emitter object. Attempts to unregister this instance from the SoundManager singleton (dword_8B78A0) via sub_53FB80; on a nonzero return it reports the 'Error deallocating' message through sub_53C590 and returns -1. On success it snapshots the buffer pointer at field 0x4, drains and frees it (EmptyStub_7470 / FreeWrapper_7bcf), zeroes all state fields, resets the mode field 0x30 to the default 6, and returns 0.
    // CALL: Attempt to unregister this emitter from the SoundManager singleton: call sub_53FB80(dword_8B78A0, this). [callee:0x0053FB80, global:0x008B78A0]
    // GUARD: Error-path guard: if sub_53FB80 returns nonzero (unregistration failed), take the error branch. [callee:0x0053FB80]
    // CALL: Report the failure through sub_53C590(-1, aErrorDeallocat), the 'Error deallocating' message literal. [callee:0x0053C590, global:0x005DBDC4]
    // RETURN: Return -1 on the unregistration-failure path. [source:raw]
    // ASSIGNMENT: Snapshot the buffer pointer stored at field 0x4 (index 1) into a local before the object is reset. [field:this:0x00000004]
    // ASSIGNMENT: Zero state fields 0x0, 0x18, 0x1C, 0x20, 0x24, 0x28 and 0x34 (indexes 0, 6, 7, 8, 9, 10, 13). [field:this:0x00000000, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x00000034]
    // ASSIGNMENT: Reset the mode field 0x30 (index 12) to the default value 6. [field:this:0x00000030]
    // GUARD: If the saved buffer pointer is non-null, drain and free it before clearing the slot. [field:this:0x00000004]
    // CALL: Drain the saved buffer through EmptyStub_7470. [callee:0x00557470]
    // CALL: Release the buffer allocation through FreeWrapper_7bcf. [callee:0x00587BCF]
    // ASSIGNMENT: Clear field 0x4 (index 1) back to 0 after the buffer has been freed. [field:this:0x00000004]
    // ASSIGNMENT: Zero the remaining fields 0x8, 0xC, 0x10 and 0x14 (indexes 2, 3, 4, 5). [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014]
    // RETURN: Return 0 on the success path. [source:raw]

    // Conservative worker pseudocode:
    //   int AudioEmitterDestructor(AudioEmitter* this) {
    //     if (sub_53FB80(gSoundManager, this)) {
    //       sub_53C590(-1, "Error deallocating");
    //       return -1;
    //     }
    //     buffer = this->field_4;
    //     this->field_0 = 0; this->field_18 = 0; this->field_1C = 0;
    //     this->field_20 = 0; this->field_24 = 0; this->field_28 = 0;
    //     this->field_34 = 0; this->field_30 = 6;
    //     if (buffer) { EmptyStub_7470(buffer); FreeWrapper_7bcf(buffer); this->field_4 = 0; }
    //     this->field_8 = 0; this->field_C = 0; this->field_10 = 0; this->field_14 = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Exact semantics of sub_53FB80 are unknown; the nonzero-return error interpretation rests on the 'Error deallocating' message.
    // UNRESOLVED: Roles of fields 0x8..0x34 (indexes 2..13) are unknown; they are treated here as generic state being reset.
    // UNRESOLVED: What EmptyStub_7470 performs is unknown; it is only known to run on the buffer before FreeWrapper_7bcf frees it.
}
