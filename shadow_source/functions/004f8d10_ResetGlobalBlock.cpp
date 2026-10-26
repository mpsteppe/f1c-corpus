// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F8D10
// Canonical corpus name: DelegationThunk_8d10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DelegationThunk_8d10_004f8d10.c

void UnknownObject::ResetGlobalBlock()
{
    // Resets a sparse block of global state anchored at 0x008AFCA8: writes 0 to thirteen named members (dword_8AFCA8, dword_8AFCAC, unk_8AFCB0, unk_8AFCB4, unk_8AFCB8, unk_8AFCBC, unk_8AFCC0, unk_8AFCC4, unk_8AFCC8, unk_8AFCCC, unk_8AFCD0, unk_8AFCD4, unk_8AFD14) and returns the block base pointer &dword_8AFCA8. No arguments, no calls; a one-shot global-state clear used before first use.
    // ASSIGNMENT: Write 0 to the first member dword_8AFCA8 at 0x008AFCA8. [global:0x008AFCA8, source:raw]
    // ASSIGNMENT: Write 0 to the adjacent members dword_8AFCAC, unk_8AFCB0, unk_8AFCB4, unk_8AFCB8, unk_8AFCBC, unk_8AFCC0, unk_8AFCC4, unk_8AFCC8, unk_8AFCCC, unk_8AFCD0, unk_8AFCD4 following dword_8AFCA8 in the block. [source:raw]
    // ASSIGNMENT: Write 0 to member unk_8AFD14, located later in the same global block. [source:raw]
    // RETURN: Return result = &dword_8AFCA8, the base pointer of the zeroed global block. [global:0x008AFCA8, function:0x004F8D10, source:raw]

    // Conservative worker pseudocode:
    //   void* sub_4F8D10(void) {
    //     dword_8AFCA8 = 0; dword_8AFCAC = 0;
    //     unk_8AFCB0 = 0; unk_8AFCB4 = 0;
    //     unk_8AFCB8 = 0; unk_8AFCBC = 0;
    //     unk_8AFCC0 = 0; unk_8AFCC4 = 0; unk_8AFCC8 = 0;
    //     unk_8AFCCC = 0; unk_8AFCD0 = 0; unk_8AFCD4 = 0;
    //     unk_8AFD14 = 0;
    //     return &dword_8AFCA8;
    //   }
    // UNRESOLVED: The callee 0x00587B3E (BooleanToIntConversion) is listed by static facts but is not invoked anywhere in the raw source; possibly an artifact of prior analysis.
    // UNRESOLVED: global 0x004F8D30 (loc_4F8D30) is a code location listed as a read global; not referenced by the raw source.
    // UNRESOLVED: Identity and purpose of the global block anchored at 0x008AFCA8 are unknown; the sparse member layout implies a struct whose individual fields are reset.
}
