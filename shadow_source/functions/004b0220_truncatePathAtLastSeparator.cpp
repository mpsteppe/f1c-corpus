// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B0220
// Canonical corpus name: PathTruncationUtility
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PathTruncationUtility_004b0220.c

void UnknownObject::truncatePathAtLastSeparator()
{
    // Path string utility that truncates an in-place string buffer at its last backslash directory separator, stripping the trailing file component. It validates both arguments, copies the input into a 512-byte scratch buffer with a bounded copy, force-terminates the buffer at the caller-supplied limit, then walks backward from the end of the string clearing bytes until it reaches a backslash. Callers include settings/profile loaders and profile-icon copy paths, consistent with a path-directory normalization helper.
    // GUARD: Guard on the arguments: when either the path pointer a1 or the length a2 is zero/null, return -1 immediately without touching the buffers. [source:raw]
    // CALL: Calls sub_568620 with the scratch-buffer size 512 before the copy; the callee's body is absent from the packet so its exact role (stack setup / guard) is unverified. [callee:0x00568620, source:raw]
    // CALL: Bounded copy of the input path a1 into the 512-byte scratch buffer v5, limited to a2-1 bytes, via sub_587DD0 (a bounded string copy helper). [callee:0x00587DD0, source:raw]
    // ASSIGNMENT: Force-terminates the path at the caller-supplied limit by writing a NUL byte at a1[a2-1], guarding against an unterminated buffer. [source:raw]
    // CALCULATION: Computes v2 = strlen(a1) + 1, i.e. the string length including its terminator, which locates the last data byte at a1[v2-2]. [source:raw]
    // LOOP: Backward scan: starting at a1[v2-2] and walking down toward a1, each byte is cleared until a byte equal to backslash (ASCII 92) is found, at which point the loop breaks. This truncates the string at the last directory separator, dropping the trailing file/component. [source:raw]
    // RETURN: Returns 0 on the successful truncation path after the backward scan completes. [function:0x004B0220, source:raw]

    // Conservative worker pseudocode:
    //   if (!a1 || !a2) return -1;
    //   sub_568620(512);
    //   sub_587DD0(a1, v5, a2 - 1);
    //   a1[a2 - 1] = 0;
    //   for (i = &a1[strlen(a1) - 1]; i >= a1; *i-- = 0)
    //     if (*i == 92) break;
    //   return 0;
    // UNRESOLVED: sub_568620 is called with 512 before the copy but its body is not in the packet, so whether it is stack setup, a size guard or something else is unverified.
    // UNRESOLVED: The object/subsystem owning this free path utility is unknown; the caller set spans settings reading and profile-icon copy helpers without establishing one owner.
    // UNRESOLVED: Exact caller expectations for a2 (hard buffer capacity vs copy bound) are not verified from any single call site.
}
