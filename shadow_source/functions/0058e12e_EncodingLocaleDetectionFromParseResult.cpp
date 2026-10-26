// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058E12E
// Canonical corpus name: EncodingLocaleDetectionFromParseResult
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EncodingLocaleDetectionFromParseResult_0058e12e.c

void UnknownObject::EncodingLocaleDetectionFromParseResult()
{
    // Detects a locale/encoding from a parse result. Calls sub_596245 to parse the input string into a format-classification flag byte and an end-of-string pointer; when the classification flag has bit 2 (value 4) set the encoding is the OEM code page (512) and the double parameter is zeroed, otherwise StringParseViaDelegate parses the numeric double and classification bits 1 and 0 (or delegate returns 1 and 2) select the ANSI (128) and Unicode/DBCS (0x100) encodings, which can be OR-ed together. Stores the resulting encoding word at this+0x0, the consumed byte count (end pointer minus input pointer) at this+0x4 and the double at this+0x10, then returns this.
    // CALL: Parse the input locale string with sub_596245(v8, &v10, a2, 0, 0, 0, 0), producing the classification flag byte v3 and the end-of-string pointer v10. [callee:0x00596245, source:raw]
    // GUARD: If the classification flag v3 has bit 2 (value 4) set, take the OEM encoding path. [source:raw]
    // ASSIGNMENT: OEM path: set the encoding word v2 = 512 and the double v9 = 0.0. [source:raw, function:0x0058E12E]
    // CALL: Otherwise parse the numeric double via StringParseViaDelegate(v8, &v9), storing the delegate return value in v4. [callee:0x00595524, source:raw]
    // GUARD: If the classification flag has bit 1 (value 2) set or v4 == 1, set the encoding word to 128 (ANSI/SBCS). [source:raw]
    // GUARD: If the classification flag has bit 0 (value 1) set or v4 == 2, OR 0x100 into the encoding word (Unicode/DBCS). [source:raw]
    // ASSIGNMENT: Write the encoding word to this+0x0, the double v9 to this+0x10 and the consumed byte count (v10 - a2) to this+0x4. [field:this:0x00000000, field:this:0x00000010, field:this:0x00000004, source:raw]
    // RETURN: Return the output pointer a1 (this), as the callers chain the result. [source:raw]
    // CALL: Invoked from sub_58850F and sub_58B077 during CRT locale initialization. [caller:0x0058850F, caller:0x0058B077, source:raw]

    // Conservative worker pseudocode:
    //   int EncodingLocaleDetectionFromParseResult(int out, const char *in) {
    //     int flags = sub_596245(buf, &end, in, 0, 0, 0, 0);
    //     int encoding;
    //     if ((flags & 4) != 0) { encoding = 512; dval = 0.0; }
    //     else {
    //       int ret = StringParseViaDelegate(buf, &dval);
    //       if ((flags & 2) != 0 || ret == 1) encoding = 128;
    //       if ((flags & 1) != 0 || ret == 2) encoding |= 0x100;
    //     }
    //     *(int*)out = encoding;
    //     *(double*)(out + 16) = dval;
    //     *(int*)(out + 4) = end - in;
    //     return out;
    //   }
    // UNRESOLVED: The exact meaning of the two StringParseViaDelegate return values (1 and 2) beyond selecting the ANSI/Unicode encodings is established by the CRT layer, not recoverable here.
    // UNRESOLVED: The OEM/ANSI/Unicode encoding constants (512, 128, 0x100) are caller-visible; their concrete code-page interpretations live outside this function.
    // UNRESOLVED: The zeroing of the double on the OEM path and its numeric meaning on the parse path are both passed through to the caller unchanged.
}
