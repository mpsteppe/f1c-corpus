// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F6D60
// Canonical corpus name: ArrayNonZeroCounter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayNonZeroCounter_004f6d60.c

void UnknownObject::ArrayNonZeroCounter()
{
    // Counts consecutive non-zero dword entries (maximum 5) from an array whose pointer is stored at this+0x40, writing the count into this+0x0 and returning it. Iteration stops early at the first zero entry. Called once by ArithmeticComparison_8370 (0x004F8370).
    // ASSIGNMENT: Load v1 = this[16], i.e. dereference the pointer field at this+0x40 that selects the array to scan [field:this:0x00000040, source:raw]
    // ASSIGNMENT: Write *this = 0, initializing the run-length counter at offset 0x0 to zero before scanning [field:this:0x00000000, source:raw]
    // LOOP: Scan loop with counter result from 0 up to 4 (maximum 5 entries); loop advances v1 and increments the *this counter while entries are non-zero [field:this:0x00000000, field:this:0x00000040, source:raw]
    // GUARD: Early-exit guard: break out of the loop when the current entry *v1 is zero, ending the consecutive non-zero run [field:this:0x00000040, source:raw]
    // CALCULATION: On each non-zero entry, advance the walk pointer (++v1) and increment the stored count (++*this at offset 0x0) [field:this:0x00000000, source:raw]
    // RETURN: Return the final count (loop counter result, which equals the number of scanned entries); consumed by ArithmeticComparison_8370 (0x004F8370) [function:0x004F6D60, caller:0x004F8370, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   v1 = (uint32_t*)this[16];
    //   *this = 0;
    //   for (result = 0; result < 5; ++result) {
    //     if (!*v1) break;
    //     ++v1;
    //     ++*this;
    //   }
    //   return result;
    // UNRESOLVED: Owner class unknown; the caller ArithmeticComparison_8370 at 0x004F8370 would be needed to establish what the array at this+0x40 holds
    // UNRESOLVED: The fixed 5-entry limit and the meaning of the stored count are caller-context dependent, not resolvable from this packet
}
