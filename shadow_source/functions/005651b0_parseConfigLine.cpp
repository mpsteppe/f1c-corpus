// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005651B0
// Canonical corpus name: sub_5651B0
// Owner: ConfigLineParser [DERIVED]
// Raw source: functions/sub_5651B0_005651b0.c

void ConfigLineParser::parseConfigLine()
{
    // Parses the configuration/INI line stored at this+408 in place: skips leading whitespace, strips C++-style // comments and bare newline/CR characters, toggles double-quote handling, tracks parenthesis depth so whitespace inside parens is dropped, then trims trailing spaces and returns a line-classification code (1 for empty or space/brace lines, 2 for closing-brace lines, 3 for comment-only lines, 0/4 for content lines).
    // CALCULATION: Set line buffer pointer v1 = this + 408 (offset 408 of the object holds the config line buffer being parsed). [function:0x005651B0, source:raw]
    // CALCULATION: Compute v2 = strlen(this + 408) + 1, the length of the current line including its terminator. [function:0x005651B0, source:raw]
    // ASSIGNMENT: Initialize parser state: v18=0 (line_class), v17=0 (paren_depth), v14=0 (in_quotes), v13=0 (slash_seen), v15=0 (comment_found), v16=0 (out_index). [source:raw]
    // LOOP: Skip leading whitespace: advance i while sub_589BF3(v1[i]) is nonzero and v1[i] is nonzero, using the character-classification lookup table byte_5653C0. [callee:0x00589BF3, global:0x005653C0, source:raw]
    // LOOP: Iterate over the remaining characters of the line from index i up to v2-1. [source:raw]
    // GUARD: If the comment_found flag v15 is set, break out of the scan loop. [source:raw]
    // STATE_TRANSITION: If the current char is double-quote (34), toggle the in_quotes flag v14. [source:raw]
    // GUARD: When not inside quotes (v14 false): reset slash_seen v13 to 0 when the current char is not '/'. If the char is '/', v13 is left unchanged so a following '/' can be detected. [source:raw]
    // GUARD: Switch on the character via jump table jpt_56525A: newline (10) and carriage-return (13) cases are skipped (continue) without being copied to output. [global:0x005653AC, source:raw]
    // CALCULATION: Track parenthesis depth: '(' (40) increments v17, ')' (41) decrements v17. [source:raw]
    // STATE_TRANSITION: On '/' (47) when slash_seen v13 is already set: a C++-style comment begins. Set comment_found v15=1, line_class v18=3, back out the first '/' already appended (--v16), and continue. [source:raw]
    // STATE_TRANSITION: On a single '/' (47) that does not start a comment, set slash_seen v13=1. [source:raw]
    // GUARD: Default case: when inside parentheses (v17>0) and the char is classified as whitespace by sub_589BF3 (lookup byte_5653C0), mark it for dropping by clearing v5. [callee:0x00589BF3, global:0x005653C0, source:raw]
    // CALL: Transform the current character through sub_589A35, producing the normalized form of v6 that may be appended to output. [callee:0x00589A35, source:raw]
    // ASSIGNMENT: Append the surviving character v4 to the output buffer v20 at index v16, advancing v16. [source:raw]
    // ASSIGNMENT: Terminate the output buffer v20[v16]=0 and copy it back over the line buffer v1 with strcpy. [source:raw]
    // LOOP: Trim trailing spaces: scan backward from j = strlen(v1)-1 while v1[j] == 32 (space) to locate the last non-space index j. [source:raw]
    // ASSIGNMENT: NUL-terminate the trimmed line by writing this[j+409] = 0 (equivalent to v1[j+1] = 0, since v1 = this+408). [function:0x005651B0, source:raw]
    // GUARD: If line_class v18 == 3 (comment was present): return 3 when the processed line is empty (v10==1), otherwise return result (0). [source:raw]
    // GUARD: Return 1 when the processed line is empty (v10 == strlen(v1)+1 == 1). [source:raw]
    // GUARD: Classify by last character: v8[j+408]==' ' (32) returns 1, v8[j+408]=='}' (125) returns 2. [source:raw]
    // CALL: Call StrlenFormatCallWrapper(v1, aS_4 "%s", v20); on return value -1 return 4, otherwise return the accumulated line_class v18 (0 for content lines). [callee:0x005887ED, global:0x005C2C18, source:raw]

    // Conservative worker pseudocode:
    //   // Parse config/INI line stored at this+408, in place.
    //   line = this + 408
    //   len = strlen(line) + 1
    //   out = stack buffer[384]
    //   line_class = 0; paren = 0; in_quotes = 0; slash = 0; comment = 0; n = 0
    //   
    //   i = 0
    //   while is_skip(line[i]) and line[i]: i++
    //   for (; i < len - 1; i++):
    //       if comment: break
    //       c = line[i]; keep = 1
    //       if c == '"': in_quotes = !in_quotes
    //       if !in_quotes:
    //           if c != '/': slash = 0
    //           switch c:
    //               case '\n', '\r': continue
    //               case '(': paren++
    //               case ')': paren--
    //               case '/':
    //                   if slash: comment = 1; line_class = 3; n--; continue
    //                   slash = 1
    //               default:
    //                   if paren and is_skip(c): keep = 0
    //                   c = normalize(c)
    //                   if !keep: continue
    //       out[n++] = c
    //   out[n] = 0
    //   strcpy(line, out)
    //   
    //   j = strlen(line) - 1
    //   while j > 0 and line[j] == ' ': j--
    //   this[j + 409] = 0
    //   len = strlen(line) + 1
    //   
    //   if line_class == 3:
    //       return (len == 1) ? 3 : 0
    //   if len == 1: return 1
    //   last = this[j + 408]
    //   if last == ' ': return 1
    //   if last == '}': return 2
    //   if StrlenFormatCallWrapper(line, "%s", out) == -1: return 4
    //   return line_class
    // UNRESOLVED: Exact semantics of sub_589A35 character transform (candidate: case normalization) not confirmed.
    // UNRESOLVED: Exact whitespace/skip classification produced by sub_589BF3 and the byte_5653C0 lookup table contents not known.
    // UNRESOLVED: Meaning of the StrlenFormatCallWrapper(v1, "%s", v20) == -1 check and of return code 4 vs 0 for content lines is ambiguous.
    // UNRESOLVED: Owner object identity (which class owns the buffer at +408) not confirmed; type proposal is DERIVED from caller names.
    // UNRESOLVED: Return-code meanings for 0/1/2/3/4 are inferred from branch structure, not externally confirmed.
}
