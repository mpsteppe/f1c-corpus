// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005573F0
// Canonical corpus name: DualDelegate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualDelegate_005573f0.c

void UnknownObject::CallTwoStubs()
{
    // Sequential delegation with no return value: calls EmptyStub_b160 (0x0053B160), then a second stub EmptyStub_0170 (named in the raw source only), in that order. Invoked by sub_5574B0 (0x005574B0).
    // CALL: Call EmptyStub_b160 (0x0053B160) first. [callee:0x0053B160, source:raw]
    // CALL: Call EmptyStub_0170 second (named in the raw source; no packet callee evidence reference). [source:raw]
    // CALL: Invoked by sub_5574B0 (0x005574B0). [caller:0x005574B0, source:raw]

    // Conservative worker pseudocode:
    //   void sub_5573F0() {
    //     EmptyStub_b160();
    //     EmptyStub_0170();
    //   }
    // UNRESOLVED: EmptyStub_0170 is named in the raw source but has no packet callee evidence reference; its address and identity are not in this packet.
    // UNRESOLVED: Both callees are labeled stubs; their actual behavior is not evidenced here.
}
