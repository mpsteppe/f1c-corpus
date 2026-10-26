// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005881F0
// Canonical corpus name: sub_5881F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5881F0_005881f0.c

void UnknownObject::ForwardTwoInt64Args()
{
    // Thin forwarding helper. Receives two 64-bit values a1 and a2 via x87 ST registers, decomposes each into its low/high 32-bit halves, and forwards all four dwords to sub_588212. Returns sub_588212's result directly. No local state is touched.
    // CALCULATION: Decompose a2 into its low dword and high dword (HIDWORD(a2)), and a1 into its low dword and high dword (HIDWORD(a1)). [source:raw]
    // CALL: Call sub_588212 with the four halves in order (a2 low, a2 high, a1 low, a1 high). [callee:0x00588212, source:raw]
    // RETURN: Return the result of sub_588212 in EAX. [source:raw]
    // UNRESOLVED: Meaning of the two 64-bit inputs a1/a2. Callers include random, noise, audio-pitch and wheel-update paths, suggesting a randomness or transform entry point, but sub_588212's semantics are unconfirmed here.
    // UNRESOLVED: Purpose of widening two 64-bit values into four 32-bit parameters for sub_588212 (register-pair argument marshalling).
}
