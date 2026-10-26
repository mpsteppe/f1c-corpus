// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00579FF0
// Canonical corpus name: sub_579FF0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_579FF0_00579ff0.c

void UnknownObject::StaticLocaleInitOnce()
{
    // Once-guarded static-initialization wrapper: installs an SEH/exception-handler record (unk_8D3BF0), runs frame enter/leave helpers, and uses the global guard counter dword_5EA04C so the construction block runs only on the first call. The block constructs static locale objects with vtable setup and links CEH exception-handling frames into a chain. Returns the saved incoming ECX value.
    // CALL: SEHHandlerInit(&unk_8D3BF0) installs the SEH/exception-handler record for this frame. [global:0x008D3BF0, source:raw]
    // ASSIGNMENT: Save the incoming v1 (ECX) value into frame slot a1-20 and zero frame slot a1-16. [source:raw]
    // CALL: sub_59A54D(a1-16) performs frame-enter bookkeeping. [source:raw]
    // GUARD: If the guard global dword_5EA04C is negative, this is the first call: set it to 1 and mark the once-branch (v2 = 1); otherwise increment it (v2 = 0). [source:raw]
    // CALL: sub_59A5E9(a1-16) performs frame-leave bookkeeping. [source:raw]
    // GUARD: If the once-branch flag v2 is set, run the one-time static construction block. [source:raw]
    // STATE_TRANSITION: One-time block: construct static locale objects via LocaleObjectConstructorWithVTableSetup / LocaleObjectAllocAndVtableSetup (targeting buffers including unk_5E6768 and unk_5E6788), then CEHFrameSetup links exception-handling frames and records forward/back pointers between them, including a frame with bit 2 set. [source:raw]
    // RETURN: Return the saved value from frame slot a1-20. [function:0x00579FF0, source:raw]

    // Conservative worker pseudocode:
    //   SEHHandlerInit(&unk_8D3BF0);
    //   *(DWORD*)(a1-20) = v1;   // saved ECX
    //   *(DWORD*)(a1-16) = 0;
    //   sub_59A54D(a1-16);
    //   if (dword_5EA04C < 0) { dword_5EA04C = 1; v2 = 1; }
    //   else { ++dword_5EA04C; v2 = 0; }
    //   sub_59A5E9(a1-16);
    //   if (v2) {
    //       // one-time static construction: locale objects with vtable setup,
    //       // then CEHFrameSetup to chain exception-handling frames
    //       LocaleObjectConstructorWithVTableSetup(&off_5E6748);
    //       LocaleObjectConstructorWithVTableSetup(&unk_5E6768);
    //       LocaleObjectConstructorWithVTableSetup(&unk_5E6788);
    //       LocaleObjectAllocAndVtableSetup(&unk_8D4510, 1, 1);
    //       CEHFrameSetup(&unk_8D44B8, 1, 1, 1);
    //       CEHFrameSetup(&unk_8D45A0, 1, 1, 1);
    //       CEHFrameSetup(&unk_8D45A0, 1, 1, 1);
    //       // link the constructed frames into the chain
    //   }
    //   return *(DWORD*)(a1-20);
    // UNRESOLVED: The one-time block references many static addresses (locale objects, CEH frames, the off_5E6748 vtable) that are absent from the packet evidence list; their individual roles are not grounded.
    // UNRESOLVED: The initial value of the guard counter dword_5EA04C is unknown; '< 0' first-call detection is inferred from the branch alone.
    // UNRESOLVED: Helpers sub_59A54D / sub_59A5E9 and the constructor / CEH helper functions are not in the packet callee list.
    // UNRESOLVED: The returned value is a saved ECX register value whose purpose is unclear; the packet declared name 'if' is a decompiler artifact.
}
