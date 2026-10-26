// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598DE3
// Canonical corpus name: MemoryCopyFromIDLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemoryCopyFromIDLookup_00598de3.c

void UnknownObject::MemoryCopyFromIDLookup()
{
    // stdcall helper: calls sub_59942B (0x0059942B) with -1 to obtain a source object pointer v4, copies 0x18u bytes from it into the caller buffer a1 via qmemcpy, and returns a1. The extra arguments a2, a3 and a4 are not referenced by the raw source.
    // CALL: Call sub_59942B (0x0059942B) with -1 to look up the source object pointer v4. [callee:0x0059942B, source:raw]
    // ASSIGNMENT: Set result = a1 so the destination buffer is also the return value. [source:raw]
    // CALL: Copy 0x18u bytes from v4 into a1 (qmemcpy inline memcpy). [source:raw]
    // RETURN: Return result (a1), the destination buffer. [source:raw]

    // Conservative worker pseudocode:
    //   void *sub_598DE3(void *dst, int a2, int a3, int a4) {
    //     const void *src = (const void *)sub_59942B(-1);
    //     void *result = dst;
    //     qmemcpy(dst, src, 0x18u);
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the lookup key -1 in sub_59942B and the semantics of the unused arguments a2, a3, a4 are not evidenced in this packet.
}
