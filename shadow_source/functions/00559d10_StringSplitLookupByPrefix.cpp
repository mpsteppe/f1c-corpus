// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00559D10
// Canonical corpus name: StringTableLookup_9d10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringTableLookup_9d10_00559d10.c

void UnknownObject::StringSplitLookupByPrefix()
{
    // Copies the input string at this+0xC into a working buffer at this+0x18C, then splits/tokenizes it with sub_5897CA using the delimiter at asc_5C30AC. If no token is found or the token equals the requested key a2 (per sub_588410), returns FALSE. Otherwise performs a second tokenizer call with byte_5EA438 and returns TRUE only when that call yields a non-null token.
    // LOOP: Copy the null-terminated string from this+0xC to the working buffer at this+0x18C, byte by byte until a zero terminator. [field:this:0x0000000C, field:this:0x0000018C, source:raw]
    // CALL: Tokenize the working buffer this+0x18C with sub_5897CA using the delimiter at asc_5C30AC; store the returned token pointer at this+0x30C. [field:this:0x0000018C, global:0x005C30AC, callee:0x005897CA, source:raw]
    // ASSIGNMENT: Store the first tokenizer result at this+0x30C. [field:this:0x0000030C, source:raw]
    // GUARD: If the token is null OR sub_588410 reports the token equals the requested key a2, return FALSE. [callee:0x00588410, source:raw]
    // CALL: Run a second tokenizer call sub_5897CA(0, byte_5EA438); store the result at this+0x30C. [global:0x005EA438, callee:0x005897CA, source:raw]
    // ASSIGNMENT: Store the second tokenizer result at this+0x30C. [field:this:0x0000030C, source:raw]
    // RETURN: Return TRUE only when the second tokenizer result is non-null, otherwise FALSE. [source:raw]

    // Conservative worker pseudocode:
    //   BOOL sub_559D10(StringNode *this, int key) {
    //     memcpy(this->work18C, this->src0C);
    //     int tok = sub_5897CA(this->work18C, asc_5C30AC);
    //     this->token30C = tok;
    //     if (!tok || sub_588410(tok, key)) return FALSE;
    //     int tok2 = sub_5897CA(0, byte_5EA438);
    //     this->token30C = tok2;
    //     return tok2 != 0;
    //   }
    // UNRESOLVED: Exact roles of the two delimiter globals asc_5C30AC and byte_5EA438 (period delimiter and fallback/application token per prior analysis).
    // UNRESOLVED: Semantics of the two sub_5897CA call modes (buffer pointer vs null first argument).
    // UNRESOLVED: String is stored at this+0x18C and overwritten each call, so it is transient working storage.
}
