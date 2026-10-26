// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404F10
// Canonical corpus name: ConditionalFlagReturn
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalFlagReturn_00404f10.c

void UnknownObject::ConditionalFlagReturn()
{
    // Conditional boolean flag query. Evaluates a packed byte field on the object through ByteFieldExtractorWithShift; when it reports true, reads a dword through a pointer reached from the ecx register context (v1) offset by 32 bytes, and returns true only when that value is in the range 1..2. Returns false otherwise. Used as a state/flag guard by menu, HUD and session callers on the frame path.
    // CALL: Evaluates a packed byte field on the object through ByteFieldExtractorWithShift(this) [callee:0x00404F00, source:raw]
    // GUARD: Proceeds only when the byte field extractor returns non-zero [callee:0x00404F00, source:raw]
    // CALCULATION: Reads a dword through the pointer reached from the ecx register context (v1), offset by 32 bytes, into v2 [source:raw]
    // GUARD: Returns true only when the read value v2 is greater than 0 and at most 2 [source:raw]
    // RETURN: Returns 1 on the in-range condition, otherwise returns 0 [function:0x00404F10, source:raw]
    // CALL: Used as a state/flag guard by callers such as MainMenuTransition and HUDFlagRendererMain [caller:0x00404F30, caller:0x004D82D0, source:raw]

    // Conservative worker pseudocode:
    //   if (!ByteFieldExtractorWithShift(this)) return 0;
    //   v2 = *(*(v1) + 32);
    //   if (v2 > 0 && v2 <= 2) return 1;
    //   return 0;
    // UNRESOLVED: v1 (ecx) is dereferenced as a pointer without a visible assignment in the decompiled source; it is likely the this object but that is not verifiable from this packet
    // UNRESOLVED: ByteFieldExtractorWithShift's return value is consumed only as a boolean condition; its packed-field semantics are defined elsewhere
}
