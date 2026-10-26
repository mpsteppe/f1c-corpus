// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005016E0
// Canonical corpus name: VTableDispatchWithLongjmp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableDispatchWithLongjmp_005016e0.c

void UnknownObject::VTableDispatchWithLongjmp()
{
    // Dispatches a vtable callback at object offset 8, then invokes LongjmpMSVCCRT on a recovery buffer 132 bytes past the vtable base. If execution continues after the longjmp, restores context state by copying v1[7] to v1[0] and v1[8] to v1[1] where v1 = this+0x14, then returns 1. Fiber/yield or SEH recovery pattern.
    // CALL: Indirect vtable call: read the vtable base from a1[0] (this+0x0), load the function pointer at obj+0x8, and call it with a1 as the argument. [field:this:0x00000000, field:obj:0x00000008]
    // CALL: Call LongjmpMSVCCRT with the jump buffer at vtable base + 132 and value 1, entering the recovery path. [callee:0x0058A770, field:this:0x00000000]
    // ASSIGNMENT: Load the secondary context pointer from this+0x14 into v1. [field:this:0x00000014]
    // ASSIGNMENT: Restore the first context word: copy v1[7] (this+0x30) into v1[0] (this+0x14). [field:this:0x00000014, field:this:0x00000030]
    // ASSIGNMENT: Restore the second context word: copy v1[8] (this+0x34) into v1[1] (this+0x18). [field:this:0x00000018, field:this:0x00000034]
    // RETURN: Return 1 when execution continues past the longjmp. [function:0x005016E0]

    // Conservative worker pseudocode:
    //   // a1: dispatch object; a1[0] is the vtable pointer
    //   call vtable[2](a1);                 // function pointer at obj+0x8
    //   longjmp(*(a1 + 132), 1);            // recovery buffer past the vtable base
    //   // executed only if longjmp does not transfer control
    //   ctx = a1[5];                        // this+0x14
    //   ctx[0] = ctx[7];                    // restore this+0x14 from this+0x30
    //   ctx[1] = ctx[8];                    // restore this+0x18 from this+0x34
    //   return 1;
    // UNRESOLVED: Jump buffer offset 132 (0x84) is referenced in the raw source but has no packet field evidence ref; kept as a raw literal.
    // UNRESOLVED: The indirect vtable dispatch target at obj+0x8 cannot be resolved statically.
    // UNRESOLVED: Existing analysis treats this+0x18 as a secondary context pointer not directly used here; the write to v1[1] lands at this+0x18.
}
