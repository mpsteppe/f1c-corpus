// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00599475
// Canonical corpus name: MSVCStreambufGninc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MSVCStreambufGninc_00599475.c

void UnknownObject::MSVCStreambufGninc()
{
    // MSVC streambuf get-pointer increment (gninc). Pre-decrements the remaining-count dword pointed to by this+0x2C, then fetches the current byte through the read pointer stored at this+0x1C and post-increments that pointer. Advances the buffer read position by one byte and returns the byte read. Called by StdBasicStreambufUflow (00598cdc) and sub_5990AE (005990ae).
    // CALCULATION: Pre-decrements the remaining-count dword reached through the pointer stored at this+0x2C: --**(this+0x2C) [field:this:0x0000002C, field:*(this+0x2C):0x00000000, source:raw]
    // CALCULATION: Loads the read pointer v1 from this+0x1C, returns the current byte *v1, then increments the pointer: return (*v1)++ [field:this:0x0000001C, field:*(this+0x1C):0x00000000, source:raw]
    // RETURN: Returns the byte at the read position before the pointer advanced (the character fetched) [source:raw]
    // CALL: Invoked by StdBasicStreambufUflow (00598cdc) and sub_5990AE (005990ae) as the streambuf get-pointer advance [caller:0x00598CDC, caller:0x005990AE]

    // Conservative worker pseudocode:
    //   --**(_DWORD **)(this + 44);
    //   v1 = *(_DWORD **)(this + 28);
    //   return (*v1)++;
    // UNRESOLVED: The concrete layout of the streambuf (read pointer at this+0x1C, remaining-count pointer at this+0x2C) is inferred from the MSVC streambuf idiom; the owning class is unknown
}
