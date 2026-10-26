// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00546010
// Canonical corpus name: AudioEngineInitialization
// Owner: AudioEngine [DERIVED]
// Raw source: functions/AudioEngineInitialization_00546010.c

void AudioEngine::initialize()
{
    // Initializes the audio engine. Zeroes the engine state globals, runs a driver probe (sub_55B8C0) that reports a buffer size into dword_8B8EE8 and possibly fires an installed callback dword_8B8F00(16, 0), allocates a 496-byte audio mixer channel block (OperatorNewNhMallocWrapper + AudioMixerChannelInitializer), stores it into the output pointer *a1, appends it to a mixer linked list, ORs flag bits a3 into its flags at +0xEC, allocates the audio sample buffer via MemoryAllocationWithFallback, accumulates the four sample-size fields under the +0x110 block into Addend/dword_8B8EF4, allocates vertex-buffer resources, then walks the audio-node linked list (head at +0x100, next at +0x104) running the per-node init pipeline. Bumps the InterlockedIncrement counter and recomputes audio volume at each stage; returns 0 on success, -1 (after unlinking) on any allocation failure.
    // ASSIGNMENT: Zero the audio engine state globals dword_8B8EF8, Addend, and dword_8B8EE8. [global:0x008B8EF8, global:0x008B8EEC, global:0x008B8EE8]
    // GUARD: Guard on the installed callback: if dword_8B8F00 is non-null and the probe sub_55B8C0(a2, &dword_8B8EE8) succeeds (returns 0), invoke the callback. [global:0x008B8F00, callee:0x0055B8C0, global:0x008B8EE8]
    // CALL: Call sub_55B8C0(a2, &dword_8B8EE8), a driver/device probe that reports a buffer size into dword_8B8EE8. [callee:0x0055B8C0, global:0x008B8EE8]
    // CALL: Invoke the installed audio callback dword_8B8F00 with constants 16 and 0. [global:0x008B8F00]
    // ASSIGNMENT: Store the probed size: dword_8B8EF0 = dword_8B8EE8, and Addend = dword_8B8EE8 / 2 (half-buffer size). [global:0x008B8EF0, global:0x008B8EE8, global:0x008B8EEC]
    // CALL: InterlockedIncrement(&dword_8B8EF8) bumps the audio engine counter through the function pointer at 0x0059E238. [global:0x0059E238, global:0x008B8EF8]
    // CALL: AudioVolumeLoadComputation(0) recomputes the volume load. [callee:0x00545F50]
    // CALL: OperatorNewNhMallocWrapper(496) allocates a 496-byte mixer channel block into v3. [callee:0x00587C03]
    // GUARD: Guard on allocation: if v3 is non-null run AudioMixerChannelInitializer(v3), otherwise v4 = 0. [callee:0x005435D0]
    // CALL: AudioMixerChannelInitializer(v3) constructs the audio mixer channel object into v4. [callee:0x005435D0]
    // ASSIGNMENT: Store the mixer channel pointer: *a1 = v4 (output field this+0x00000000). [field:this:0x00000000]
    // CALL: LinkedListAppend_c5d0(v4) appends the new mixer channel to the mixer linked list. [callee:0x0053C5D0]
    // ASSIGNMENT: OR the flag bits of parameter a3 into the channel flags: *(*a1 + 236) |= a3 (field obj+0xEC). [field:obj:0x000000EC]
    // CALL: EmptyStubWithFlagCheck(2, 0) is invoked after the channel is registered. [callee:0x0053AC70]
    // CALL: MemoryAllocationWithFallback(*a1, a2) allocates the audio sample buffer; a non-zero result is a failure. [callee:0x00543A80]
    // CALL: On buffer-allocation failure, DoublyLinkedListUnlink(*a1) removes the channel from the mixer list. [callee:0x0053C630]
    // RETURN: Return -1 on the buffer-allocation failure path. [source:raw]
    // CALCULATION: Accumulate the total audio sample size: Addend += sum of the four dwords at (*(obj+0x110))+0x14, +0x18, +0x1C, +0x20. [global:0x008B8EEC, field:obj:0x00000110, field:*(obj+0x110):0x00000014, field:*(obj+0x110):0x00000018, field:*(obj+0x110):0x0000001C, field:*(obj+0x110):0x00000020]
    // ASSIGNMENT: Persist the accumulated size: dword_8B8EF4 = Addend. [global:0x008B8EF4, global:0x008B8EEC]
    // CALL: InterlockedIncrement(&dword_8B8EF8) bumps the audio engine counter again. [global:0x0059E238, global:0x008B8EF8]
    // CALL: AudioVolumeLoadComputation(0) recomputes the volume load after size accumulation. [callee:0x00545F50]
    // CALL: VertexBufferResourceAllocation(*a1) allocates vertex-buffer resources for the channel; a non-zero result is a failure. [callee:0x00543FA0]
    // CALL: On vertex-buffer failure: DoublyLinkedListUnlink(*a1) unlinks the channel and *a1 = 0 nulls the output pointer. [callee:0x0053C630, field:this:0x00000000]
    // RETURN: Return -1 on the vertex-buffer failure path. [source:raw]
    // LOOP: Walk the audio-node linked list: start at the head *(obj+0x100) (field obj+0x100) and follow next pointers at node+0x104 until null. [field:obj:0x00000100, field:*(*(obj+0x100)+0x104):0x00000104]
    // CALL: Per node, run the init pipeline: ArithmeticComparison_9170(i), LinkedListWalkWithDispatch(i), LinkedListUpdate(i), AudioNodeUpdateWalk(i), sub_549470(i). [callee:0x00549170, callee:0x005492B0, callee:0x00549380, callee:0x00549440, callee:0x00549470]
    // CALL: InterlockedIncrement(&dword_8B8EF8) bumps the counter after the node walk. [global:0x0059E238, global:0x008B8EF8]
    // CALL: AudioVolumeLoadComputation(0) recomputes the volume load before success return. [callee:0x00545F50]
    // CALL: EmptyStubWithFlagCheck(1, 0) is invoked on the success path. [callee:0x0053AC70]
    // RETURN: Return 0 on success. [source:raw, function:0x00546010]

    // Conservative worker pseudocode:
    //   int initialize(int* out, int a2, int a3) {
    //     dword_8B8EF8 = 0; Addend = 0; dword_8B8EE8 = 0;
    //     if (dword_8B8F00 && !sub_55B8C0(a2, &dword_8B8EE8)) dword_8B8F00(16, 0);
    //     dword_8B8EF0 = dword_8B8EE8; Addend = dword_8B8EE8 / 2;
    //     bumpCounter(); AudioVolumeLoadComputation(0);
    //     int block = OperatorNewNhMallocWrapper(496);
    //     int ch = block ? AudioMixerChannelInitializer(block) : 0;
    //     *out = ch; LinkedListAppend_c5d0(ch);
    //     *(*out + 236) |= a3; EmptyStubWithFlagCheck(2, 0);
    //     if (MemoryAllocationWithFallback(*out, a2)) { DoublyLinkedListUnlink(*out); return -1; }
    //     Addend += *(*(*out + 272) + 20) + *(*(*out + 272) + 24)
    //             + *(*(*out + 272) + 28) + *(*(*out + 272) + 32);
    //     dword_8B8EF4 = Addend; bumpCounter(); AudioVolumeLoadComputation(0);
    //     if (VertexBufferResourceAllocation(*out)) { DoublyLinkedListUnlink(*out); *out = 0; return -1; }
    //     for (int i = *(*out + 256); i; i = *(i + 260)) {
    //       ArithmeticComparison_9170(i); LinkedListWalkWithDispatch(i);
    //       LinkedListUpdate(i); AudioNodeUpdateWalk(i); sub_549470(i);
    //     }
    //     bumpCounter(); AudioVolumeLoadComputation(0); EmptyStubWithFlagCheck(1, 0);
    //     return 0;
    //   }
    // UNRESOLVED: global:0x008B8F24 is recorded as a read global by the deterministic fact extractor but does not appear in the raw source text; its role is unknown.
    // UNRESOLVED: Semantics of the callback dword_8B8F00 and the constants 16 and 0 passed to it are not established by the packet.
    // UNRESOLVED: Meaning of the per-node walk calls and of the a2/a3 parameters beyond the observed usage is not verifiable here.
    // UNRESOLVED: The owner type AudioEngine is DERIVED from the LEGACY ABI name 'Audio_Engine_Initialization' and the audio subsystem tag, not CONFIRMED.
}
