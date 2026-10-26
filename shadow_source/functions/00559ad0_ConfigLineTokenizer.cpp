// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00559AD0
// Canonical corpus name: sub_559AD0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_559AD0_00559ad0.c

void UnknownObject::ConfigLineTokenizer()
{
    // Parses one key=value configuration line from the buffer starting at offset 0xC of the parsing context. Strips a trailing carriage return, trims leading whitespace (space 32 / tab 9), stores the location of the '=' separator at offset 0x30C (this[195]), and lowercases the key side. Returns 0 on a parsed line, 1 for a blank/whitespace/comment line, and 2 on a line that fails the start-token check or is empty.
    // CALL: Compute the length of the line buffer at offset 0xC with strlen and write a null terminator at its end. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: If the last content character is a carriage return (13), replace it with a null terminator. [field:this:0x0000000C, source:raw]
    // LOOP: Copy the line buffer (offset 0xC) into a local scratch buffer, stopping at the terminating null. [field:this:0x0000000C, source:raw]
    // GUARD: Scan past leading whitespace in the copied line: skip characters that are space (32) or tab (9). [guard:0, source:raw]
    // CALL: sub_588640 compares the trimmed line start against the delimiter set at unk_5C30B8; if it does not match, return 2 as a format error. [callee:0x00588640, global:0x005C30B8, source:raw]
    // GUARD: If the line is now empty after trimming, return 2. [field:this:0x0000000C, source:raw]
    // GUARD: A trailing character of space (32) or closing brace (125) classifies the line as a comment and returns 1. [field:this:0x0000000C, source:raw]
    // CALL: sub_587C20 locates the '=' separator position inside the line buffer. [callee:0x00587C20, source:raw]
    // ASSIGNMENT: Store the located '=' separator pointer at this[195] (offset 0x30C) and clear the found character. [field:this:0x0000030C, source:raw]
    // LOOP: Lowercase the key side character by character via sub_589A35 until the '=' (61) separator is reached. [callee:0x00589A35, source:raw]
    // RETURN: Return 0 on a successfully tokenized line, 1 on a blank/comment line, 2 on a format error. [source:raw]

    // Conservative worker pseudocode:
    //   int ConfigLineTokenizer(char *this) {
    //     trim_cr_and_leading_ws(line = this + 0xC);
    //     if (!sub_588640(line, &unk_5C30B8, 2) || !strlen(line)) return 2;
    //     if (last_char == ' ' || last_char == '}') return 1;
    //     sep = sub_587C20(line, &unk_5C30B8);
    //     this[195] = sep; if (sep) *sep = 0;
    //     for (p = line; *p != '='; ++p) *p = sub_589A35(*p);
    //     return 0;
    //   }
    // UNRESOLVED: Exact semantics of unk_5C30B8 delimiter/quote set used by sub_588640 and sub_587C20 are unknown.
    // UNRESOLVED: sub_587C20, sub_588640 and sub_589A35 are only known by their call sites here; their standalone behavior is unverified.
    // UNRESOLVED: Whether offset 0x30C (the '=' pointer) is consumed by the caller LineReaderFromBuffer after this returns is unproven.
    // UNRESOLVED: Owner object of the parsing context is unknown.
}
