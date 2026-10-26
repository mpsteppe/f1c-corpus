// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058BD8F
// Canonical corpus name: sub_58BD8F
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58BD8F_0058bd8f.c

void UnknownObject::FassignLongDoubleCopy()
{
    // CRT-style long-double assignment helper (ABI lead: CRT___fassign) that writes a value into the destination dword pair a2. When the discriminator a1 is nonzero it materializes the source a3 into the local two-dword buffer v4 via BufferFormatHelper and stores both dwords to *a2 and a2[1]. When a1 is zero it parses/transforms the source in place via StringParseWithFormat(&a3, a3) and stores the resulting value into *a2. Returns the destination pointer a2 on both paths.
    // GUARD: Dispatch on a1: a nonzero discriminator takes the materialize path, a zero discriminator takes the parse path. [source:raw]
    // CALL: BufferFormatHelper(v4, a3) materializes the source value into the local two-dword buffer v4. [callee:0x00595550, source:raw]
    // ASSIGNMENT: Store both dwords from v4 into the destination: *a2 = v4[0] and a2[1] = v4[1]. [source:raw]
    // CALL: StringParseWithFormat(&a3, a3) parses or transforms the source argument in place. [callee:0x0059557D, source:raw]
    // ASSIGNMENT: Store the parsed source into the destination: *a2 = a3. [source:raw]
    // RETURN: Return the destination pointer a2 on both paths. [source:raw]

    // Conservative worker pseudocode:
    //   DWORD* FassignLongDoubleCopy(int mode, DWORD* dest, int src) {
    //     if (mode) {
    //       DWORD v[2];
    //       BufferFormatHelper(v, src);
    //       dest[0] = v[0];
    //       dest[1] = v[1];
    //     } else {
    //       StringParseWithFormat(&src, src);
    //       dest[0] = src;
    //     }
    //     return dest;
    //   }
    // UNRESOLVED: The two paths write different widths (two dwords versus one), so the exact long-double or format representation being handled is not resolvable from this function alone.
    // UNRESOLVED: Whether the value is a binary long double or a formatted string representation depends on the caller's usage of a1.
    // UNRESOLVED: Semantics of BufferFormatHelper and StringParseWithFormat are taken from their LLM-supplied names and are not independently verified.
}
