// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564B80
// Canonical corpus name: PadOutputWithSpacesUpToLengthLimit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PadOutputWithSpacesUpToLengthLimit_00564b80.c

void UnknownObject::Base64EncodeUpToLength()
{
    // Encodes up to a2 bytes from input buffer a1 into base64, writing to output buffer a3 and null-terminating it. Bytes are consumed in groups of three; a partial trailing group is zero-padded before the four base64 characters are produced via Base64IndexToCharEncoding.
    // GUARD: If a2 <= 0, skip encoding entirely, write a single null terminator into a3 and return. [source:raw]
    // LOOP: Outer while loop repeats until the number of consumed input bytes v4 reaches the limit v12 (equal to a2). [source:raw]
    // LOOP: Inner for loop gathers up to three input bytes into a temporary buffer; when fewer than three remain (v4 >= v3) the remaining slots are zero-filled to pad the group. [source:raw]
    // CALCULATION: Pack the three gathered bytes into four 6-bit base64 indices (v10[0..3]) via shifts and masks on the 24-bit group. [source:raw]
    // CALL: For each of the four indices, call Base64IndexToCharEncoding(index) and write the returned character into the output buffer v5. [callee:0x00564C40, source:raw]
    // STATE_TRANSITION: Advance the consumed-byte counter v4 by 3 per group; terminate the outer loop once v4 >= v12. [source:raw]
    // ASSIGNMENT: Write a null terminator after the last emitted base64 character (*v5 = 0). [source:raw]
    // RETURN: Return the last character produced by Base64IndexToCharEncoding (the `result` variable reused by the decompiler). [callee:0x00564C40, source:raw]
    // UNRESOLVED: The canonical name 'PadOutputWithSpacesUpToLengthLimit' and the abi lead describe space padding, while the observed logic is base64 encoding; the output-consumer contract (caller sub_562E30) decides which framing applies.
    // UNRESOLVED: Zero-padding a partial group yields base64 characters for the zero bytes; whether the caller expects '=' padding or trailing spaces is unresolved.
    // UNRESOLVED: The decompiler reuses a1 and result as scratch registers; exact register-level grouping order is a compiler artifact.
}
