// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F1C00
// Canonical corpus name: ConditionalBufferCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalBufferCall_004f1c00.c

void UnknownObject::ConditionalBufferCall()
{
    // Reads the flag at this+0x32BC (this[3247]); if it is zero, calls VisualStateChange(&dbl_7C7428, a2, 1) and returns the callee's low-byte result, otherwise returns the flag value unchanged. Cluster-copied prelabel notes a structural twin with the same gate field gating a different dispatch call.
    // GUARD: Load v2 = this[3247] (dword at offset 0x32BC). If v2 is non-zero, skip the VisualStateChange call and return v2 unchanged. [field:this:0x000032BC, source:raw]
    // CALL: When the gate field is zero, call VisualStateChange(&dbl_7C7428, a2, 1) and store its low-byte return value into v2. [callee:0x00447C70, global:0x007C7428, source:raw]
    // RETURN: Return v2: the original this[3247] value when it was non-zero, otherwise the low byte of the VisualStateChange result. [function:0x004F1C00, source:raw]

    // Conservative worker pseudocode:
    //   char ConditionalBufferCall(void *this, char a2) {
    //       int v2 = *(int *)((char *)this + 0x32BC);
    //       if (!v2)
    //           v2 = VisualStateChange(&dbl_7C7428, a2, 1);
    //       return v2;
    //   }
    // UNRESOLVED: dbl_7C7428 is used as the first argument to VisualStateChange; its role (e.g. a visual-state object or timer) is not evidenced in the packet.
    // UNRESOLVED: The meaning of the a2 parameter and the constant 1 passed to VisualStateChange is unevidenced.
    // UNRESOLVED: Whether this+0x32BC is a per-object flag, pointer, or count is not evidenced by the packet alone; only its zero/non-zero gating behavior is grounded.
}
