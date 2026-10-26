// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005640F0
// Canonical corpus name: sub_5640F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5640F0_005640f0.c

void UnknownObject::AudioContainerSubStructDestructor()
{
    // Unconditional teardown: reads a container/sub-struct pointer from this+0x0, frees the audio array held at sub-struct offset +0xC via DestroyAudioArrayFreeElementsThenContainer, then frees the container/sub-struct itself via sub_58AA6F.
    // ASSIGNMENT: Read v1 = *(void**)this, the container/sub-struct pointer stored at this+0x0 [field:this:0x00000000, source:raw]
    // CALL: DestroyAudioArrayFreeElementsThenContainer on the audio array pointer read at sub-struct offset +0xC (reached through this+0x0), freeing its elements and container [field:this:0x00000000, field:obj:0x0000000C, callee:0x00564740, source:raw]
    // CALL: sub_58AA6F(v1) frees the container/sub-struct itself after its audio array has been destroyed [callee:0x0058AA6F, source:raw]

    // Conservative worker pseudocode:
    //   substruct = *(void**)this;
    //   DestroyAudioArrayFreeElementsThenContainer(*(LPVOID**)((BYTE*)substruct + 12));
    //   sub_58AA6F(substruct);
    // UNRESOLVED: Exact object layout: the relationship between this (the wrapper) and the sub-struct at this+0x0 is inferred, not documented
    // UNRESOLVED: What sub_58AA6F does beyond memory deallocation is not evidenced in the packet
}
