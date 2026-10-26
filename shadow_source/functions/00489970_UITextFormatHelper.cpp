// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00489970
// Canonical corpus name: UITextFormatHelper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UITextFormatHelper_00489970.c

void UnknownObject::UITextFormatHelper()
{
    // Reads the text of a UI screen widget via UIScreenTextAccessor, locates the last path-delimiter (word_5C692C) occurrence in a copy of the text, skips a2 delimiter-separated components by repeatedly locating the preceding delimiter, and copies the suffix from the final delimiter position into the this+0xE1 (225) output buffer; returns a pointer to that buffer. Returns 0 if the widget has no text or no delimiter is found. Legacy ABI label: UI_Text_Format_Helper.
    // ASSIGNMENT: Initialize the stack buffer: v12[0] = byte_5EA438[0], then memset the remainder (0x4C bytes plus the v13/v14 tail) to 0. [global:0x005EA438, source:raw]
    // CALL: v3 = UIScreenTextAccessor(this) fetches the widget's text; guard: return 0 when NULL. [callee:0x00489920, source:raw]
    // ASSIGNMENT: Set the output-buffer pointer v4 = this + 225 (offset 0xE1) and clear its first byte: *(this + 225) = 0. [field:this:0x000000E1, source:raw]
    // LOOP: Copy the widget text string from v3 into the stack buffer v12 (null-terminated copy). [source:raw]
    // CALL: v7 = sub_5897CA(v12, &word_5C692C) finds the last path-delimiter occurrence in the copied text. [callee:0x005897CA, global:0x005C692C, source:raw]
    // LOOP: When a2 > 0, repeat a2 times sub_5897CA(0, &word_5C692C) to walk back across a2 delimiter-separated path components. [callee:0x005897CA, global:0x005C692C, source:raw]
    // GUARD: Return 0 when v7 is NULL after the delimiter search. [source:raw]
    // LOOP: Copy the suffix string from v7 (the final delimiter position) into the this+0xE1 output buffer (null-terminated copy). [field:this:0x000000E1, source:raw]
    // RETURN: Return v4, the pointer to the output buffer at this + 225 (offset 0xE1). [field:this:0x000000E1, source:raw]

    // Conservative worker pseudocode:
    //   int UITextFormatHelper(int this, int skip) {
    //     char buf[80]; buf[0] = byte_5EA438[0]; memset(buf + 1, 0, 0x4C);
    //     char* text = UIScreenTextAccessor(this);
    //     if (!text) return 0;
    //     char* out = (char*)(this + 225); *out = 0;
    //     strcpy(buf, text);
    //     char* d = sub_5897CA(buf, &word_5C692C);
    //     for (int i = 0; i < skip; ++i) d = sub_5897CA(0, &word_5C692C);
    //     if (!d) return 0;
    //     strcpy(out, d);
    //     return (int)out;
    //   }
    // UNRESOLVED: sub_5897CA is only identified as a delimiter locator (strrchr-style, per existing analysis); its behavior when its first argument is 0 (used in the skip loop) is inferred, not proven here.
    // UNRESOLVED: Ownership of the 'this' object and the exact meaning of the this+0xE1 buffer (a path/name suffix for a UI list) depends on the caller UIListManagementHandler (0x0048A3C0).
    // UNRESOLVED: The legacy ABI label UI_Text_Format_Helper (abi:lead) is retained as weak (LEGACY) naming evidence only.
}
