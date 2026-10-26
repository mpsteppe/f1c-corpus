// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00559D80
// Canonical corpus name: sub_559D80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_559D80_00559d80.c

void UnknownObject::HotChainStringLookup()
{
    // Copies the string at this+0xC into a working buffer at this+0x18C, then walks a chain of tokens delimited by asc_5C30AC and the '.HOT' delimiter at word_5C32D8 using sub_5897CA, seeking the first token that does not match the requested key a2. The current token pointer is tracked at this+0x30C. Returns FALSE when the chain is exhausted; otherwise returns TRUE if a non-matching token is found after stepping past the delimiter.
    // LOOP: Copy the null-terminated string from this+0xC to the working buffer at this+0x18C, byte by byte until a zero terminator. [field:this:0x0000000C, field:this:0x0000018C, source:raw]
    // CALL: Tokenize the working buffer this+0x18C with sub_5897CA using the delimiter at asc_5C30AC; store the returned token pointer at this+0x30C. [field:this:0x0000018C, global:0x005C30AC, callee:0x005897CA, source:raw]
    // ASSIGNMENT: Store the first tokenizer result at this+0x30C. [field:this:0x0000030C, source:raw]
    // GUARD: If the first token is null, return FALSE (chain exhausted). [source:raw]
    // LOOP: While sub_588410 reports the current token at this+0x30C equals the requested key a2, advance: consume the token via sub_5897CA(0, &word_5C32D8), then fetch the next token via sub_5897CA(0, asc_5C30AC) and store it at this+0x30C; return FALSE if that next token is null. [field:this:0x0000030C, global:0x005C32D8, global:0x005C30AC, callee:0x00588410, callee:0x005897CA, source:raw]
    // CALL: After the loop, consume the final delimiter with sub_5897CA(0, &word_5C32D8); store the result at this+0x30C. [global:0x005C32D8, callee:0x005897CA, source:raw]
    // ASSIGNMENT: Store the final tokenizer result at this+0x30C. [field:this:0x0000030C, source:raw]
    // RETURN: Return TRUE when the final token is non-null, otherwise FALSE. [source:raw]

    // Conservative worker pseudocode:
    //   BOOL sub_559D80(StringNode *this, int key) {
    //     memcpy(this->work18C, this->src0C);
    //     int tok = sub_5897CA(this->work18C, asc_5C30AC);
    //     this->token30C = tok;
    //     if (!tok) return FALSE;
    //     while (sub_588410(this->token30C, key)) {
    //       sub_5897CA(0, &word_5C32D8);
    //       int next = sub_5897CA(0, asc_5C30AC);
    //       this->token30C = next;
    //       if (!next) return FALSE;
    //     }
    //     int finalTok = sub_5897CA(0, &word_5C32D8);
    //     this->token30C = finalTok;
    //     return finalTok != 0;
    //   }
    // UNRESOLVED: Exact token stream layout: the word_5C32D8 '.HOT' delimiter chains the candidates and asc_5C30AC separates tokens within each candidate (per prior analysis).
    // UNRESOLVED: Semantics of sub_5897CA's null first argument and what distinguishes the two call modes.
    // UNRESOLVED: Whether the result is a matched property value or merely a successfully stepped-to candidate.
}
