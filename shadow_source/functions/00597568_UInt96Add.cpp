// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00597568
// Canonical corpus name: CRTAdd12
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CRTAdd12_00597568.c

void UnknownObject::UInt96Add()
{
    // Adds two 96-bit unsigned integers (each three dwords: [0] low, [1] mid, [2] high), accumulating the result in place in a1, with carry propagation across all three limbs via OverflowCheckedUnsignedAddition (00597547). The low-limb add additionally folds a carry-into-mid step (mid += 1) when both the low and mid additions overflow, and the final high-limb add returns its overflow flag. Matches the CRT __add_12 pattern. Called by sub_597621 and sub_5976E8.
    // CALL: Low-limb add: OverflowCheckedUnsignedAddition(*a1, *a2, a1) — a1[0] += a2[0], returns carry [callee:0x00597547, field:this:0x00000000, source:raw]
    // CALL: Mid-limb increment: OverflowCheckedUnsignedAddition(a1[1], 1, a1+1) — propagates a carry into the mid dword [callee:0x00597547, field:this:0x00000004, source:raw]
    // GUARD: If both the low-limb add and the mid increment overflow, ++a1[2] — cascades carry to the high dword [field:this:0x00000008, source:raw]
    // CALL: Mid-limb add: OverflowCheckedUnsignedAddition(a1[1], a2[1], a1+1) — a1[1] += a2[1], returns carry [callee:0x00597547, field:this:0x00000004, source:raw]
    // GUARD: If the mid-limb add overflows, ++a1[2] — carry to the high dword [field:this:0x00000008, source:raw]
    // RETURN: return OverflowCheckedUnsignedAddition(a1[2], a2[2], a1+2) — high-limb add, result is the final carry flag [callee:0x00597547, field:this:0x00000008, function:0x00597568, source:raw]
    // CALL: Invoked by sub_597621 (00597621) and sub_5976E8 (005976E8) for CRT-style 96-bit arithmetic [caller:0x00597621, caller:0x005976E8]

    // Conservative worker pseudocode:
    //   if (overflow_check(a1[0] += a2[0]) && overflow_check(a1[1] += 1)) a1[2]++;
    //   if (overflow_check(a1[1] += a2[1])) a1[2]++;
    //   return overflow_check(a1[2] += a2[2]);
    // UNRESOLVED: The higher-level 96-bit value this add operates on (timer, counter, or checksum) is not resolvable from this packet
    // UNRESOLVED: The purpose of folding the carry into mid (+1) only when the low add also overflows is compiler-produced control flow; the exact source structure is not recoverable
}
