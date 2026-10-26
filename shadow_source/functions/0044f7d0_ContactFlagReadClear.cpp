// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044F7D0
// Canonical corpus name: ContactFlagReadClear
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ContactFlagReadClear_0044f7d0.c

void UnknownObject::ContactFlagReadClear()
{
    // __thiscall accessor that reads the dword contact/event flag at this + 0xBC (this[47]), clears it to zero, and returns the prior value. A read-and-clear pattern for a one-shot event/contact flag. Existing analysis places a call from InitViewportDimensions during viewport initialization.
    // ASSIGNMENT: Read the flag at this[47] (offset 0xBC) into result. [source:raw, field:this:0x000000BC]
    // ASSIGNMENT: Clear the flag: write 0 back to this[47] (offset 0xBC). [source:raw, field:this:0x000000BC]
    // RETURN: Return the prior flag value captured before the clear. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_44F7D0(_DWORD *this) {
    //     int result = this[47];  // this + 0xBC, contact/event flag
    //     this[47] = 0;
    //     return result;
    //   }
    // UNRESOLVED: The object type owning the flag at offset 0xBC is unknown; the flag is supplied by caller InitViewportDimensions and its exact event meaning is unconfirmed.
}
