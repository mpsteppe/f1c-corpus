// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00540CB0
// Canonical corpus name: AudioResourceFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioResourceFree_00540cb0.c

void UnknownObject::AudioResourceFree()
{
    // Frees the sub-resources of an audio resource object (buffers at a2+28 and a2+36, plus flag/pointer fields at a2+44 and a2+48) selected by a state flag at this+0x13DC. When the flag is set, buffers are freed directly with FreeWrapper_7bcf. When clear, the object at a2+28 is first released through a virtual release and the object at a2+36 through a draining-loop finalizer, then both are freed. Returns 0 on both paths.
    // GUARD: Branch on the state flag at this+0x13DC: set selects the direct-free path, clear selects the virtual-release teardown path. [field:this:0x000013DC, source:raw]
    // GUARD: Direct path: when the buffer at a2+28 is present, free it with FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // GUARD: Direct path: when the buffer at a2+36 is present, free it with FreeWrapper_7bcf, and zero the resource fields at a2+28, a2+36, a2+44 and a2+48. [callee:0x00587BCF, source:raw]
    // CALL: Virtual-release path: reset the object at a2+28 through its virtual release routine. [callee:0x00540EB0, source:raw]
    // CALL: Virtual-release path: finalize the draining loop for the object at a2+36. [callee:0x00541040, source:raw]
    // CALL: Virtual-release path: free the buffers at a2+28 and a2+36 with FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // RETURN: Return 0 on both paths. [source:raw]

    // Conservative worker pseudocode:
    //   int AudioResourceFree(AudioSubsystem* this, AudioResource* res) {
    //     if (this->direct_free_flag_0x13DC) {
    //       if (res->buffer_28) FreeWrapper_7bcf(res->buffer_28);
    //       void* buffer36 = res->buffer_36;
    //       res->buffer_28 = 0; res->field_44 = 0;
    //       if (buffer36) FreeWrapper_7bcf(buffer36);
    //       res->buffer_36 = 0; res->field_48 = 0;
    //       return 0;
    //     }
    //     ObjectResetWithVirtualRelease(res->buffer_28);
    //     if (res->buffer_28) FreeWrapper_7bcf(res->buffer_28);
    //     DrainingLoopFinalizer(res->buffer_36);
    //     if (res->buffer_36) FreeWrapper_7bcf(res->buffer_36);
    //     return 0;
    //   }
    // UNRESOLVED: The sub-resource layout at a2+28/+36/+44/+48 (buffer and flag/pointer pairs) is assumed; packet field evidence covers only this+0x13DC.
    // UNRESOLVED: Why the two teardown paths (direct free versus virtual-release plus draining-loop finalizer) diverge is not explained by this packet.
    // UNRESOLVED: The this+0x13DC flag's setter is not visible here.
}
