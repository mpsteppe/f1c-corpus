// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059BFC3
// Canonical corpus name: CxxThrowException8
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CxxThrowException8_0059bfc3.c

void UnknownObject::CxxThrowException8()
{
    // Raises a structured exception from a copied 8-dword template: copies the template block from unk_5B9DE0, overwrites the last two slots with the supplied parameters a1 and a2, and calls RaiseException with the template's exception code, flags, argument count and argument pointer.
    // ASSIGNMENT: Copy the 8-dword exception template from unk_5B9DE0 into the local exception descriptor buffer. [global:0x005B9DE0, source:raw]
    // ASSIGNMENT: Overwrite template slots 6 and 7 with the two supplied parameters a1 and a2. [source:raw]
    // CALL: Raise the exception via RaiseException using the template's exception code (slot 0), flags (slot 1), number of arguments (slot 4) and argument pointer (slot 5). [global:0x0059E130, source:raw]
    // CALL: Called by eight exception-throwing wrappers to raise a prepared exception: sub_59A5FE, CThrowWithException, CExceptionThrowWrapper, sub_59AD49, CThrowWithException_ae07, CExceptionThrowWrapper_af17, sub_59AF68, ExceptionThrowWrapper. [abi:lead, function:0x0059BFC3, caller:0x0059A5FE, caller:0x0059A70B, caller:0x0059A81B, caller:0x0059AD49, caller:0x0059AE07, caller:0x0059AF17, caller:0x0059AF68, caller:0x0059AFFF, source:raw]
    // UNRESOLVED: Which copied template fields act as exception code, flags, argument count and argument pointer is inferred from the RaiseException argument order and is not separately documented in the packet.
    // UNRESOLVED: The purpose of parameters a1/a2 landing in template slots 6 and 7 is unknown; they are not named by any packet symbol.
}
