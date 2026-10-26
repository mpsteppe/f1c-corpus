// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005932F3
// Canonical corpus name: sub_5932F3
// Owner: CRTErrorHandler [DERIVED]
// Raw source: functions/sub_5932F3_005932f3.c

void CRTErrorHandler::ShowRuntimeErrorWithCodeLookup()
{
    // Microsoft Visual C++ runtime error display handler. Searches a table of (error code, description string) pairs for the incoming code. If a console is attached, writes the description to the standard error handle via WriteFile. Otherwise builds the classic "Runtime Error!\n\nProgram: <exe>\n\n<description>" message and shows it as a titled message box, shortening the executable path when it is too long.
    // LOOP: Scan the error code table starting at dword_5E78C0 in 2-dword steps (code plus string pointer) until the end sentinel off_5E7950, tracking the match index. [global:0x005E78C0, global:0x005E7950]
    // GUARD: Proceed with handling only when the incoming code matches the found table entry. [source:raw]
    // GUARD: Select the console path when dword_8D3EBC equals 1, or equals 0 while dword_5E65B4 (console attached flag) is 1. [global:0x008D3EBC, global:0x005E65B4]
    // ASSIGNMENT: Fetch the error description string from the parallel description table off_5E78C4 at the matched index. [global:0x005E78C4]
    // CALCULATION: Measure the description length with Strlen. [callee:0x0058E1B0]
    // CALL: Obtain the standard error handle via GetStdHandle and return its WriteFile result. [global:0x0059E104]
    // CALL: Write the error description to the standard error handle with WriteFile and return the call result. [global:0x0059E220]
    // GUARD: Take the message-box path only when the code is not the special value 252. [source:raw]
    // CALL: Retrieve the executable module path with GetModuleFileNameA into a 260-char buffer. [global:0x0059E0EC]
    // ASSIGNMENT: When the module name lookup fails, use the "<program name unknown>" fallback string and invoke sub_58FCA0 to begin message assembly. [callee:0x0058FCA0, global:0x005B9928]
    // CALCULATION: When the path plus terminator exceeds 0x3C characters, shorten it through sub_587DD0 using the asc_5C5C8C separator token. [callee:0x0058E1B0, callee:0x00587DD0, global:0x005C5C8C]
    // CALL: Start the message buffer with the "Runtime Error!\n\nProgram: " prefix via sub_58FCA0. [callee:0x0058FCA0, global:0x005B990C]
    // CALL: Append the (possibly shortened) program path to the message buffer via sub_58FCB0. [callee:0x0058FCB0]
    // CALL: Append the separator newline pair to the message buffer via sub_58FCB0. [callee:0x0058FCB0]
    // CALL: Append the error description string from off_5E78C4 to the message buffer via sub_58FCB0. [callee:0x0058FCB0, global:0x005E78C4]
    // CALL: Display the message box via sub_597234 with the "Microsoft Visual C++ Runtime Library" title string. [callee:0x00597234, global:0x005B98E0]
    // RETURN: Return the table search result pointer (or dword_8D3EBC on the found-but-untreated path). [source:raw]

    // Conservative worker pseudocode:
    //   int *ShowRuntimeErrorWithCodeLookup(DWORD code) {
    //     int i = 0;
    //     int *slot = dword_5E78C0;
    //     while ((int)slot < (int)&off_5E7950) {
    //       if (code == *slot) break;
    //       slot += 2; ++i;
    //     }
    //     int *end = slot;
    //     if (code == dword_5E78C0[2 * i]) {
    //       int mode = dword_8D3EBC;
    //       if (mode == 1 || (mode == 0 && dword_5E65B4 == 1)) {
    //         const char *msg = (&off_5E78C4)[2 * i];
    //         HANDLE h = GetStdHandle(STD_ERROR_HANDLE);
    //         return (int *)WriteFile(h, msg, Strlen(msg), &code, 0);
    //       }
    //       if (code != 252) {
    //         CHAR path[260];
    //         if (!GetModuleFileNameA(0, path, 0x104)) {
    //           // fallback "<program name unknown>" via sub_58FCA0
    //           sub_58FCA0();
    //         }
    //         char *name = path;
    //         if (Strlen(path) + 1 > 0x3C) {
    //           name = shortened_path(path);
    //           sub_587DD0(name, asc_5C5C8C, 3u);
    //         }
    //         sub_58FCA0();
    //         sub_58FCB0(msg_buf, name);
    //         sub_58FCB0(msg_buf, "\n\n");
    //         sub_58FCB0(msg_buf, (&off_5E78C4)[2 * i]);
    //         return (int *)sub_597234(msg_buf, "Microsoft Visual C++ Runtime Library", 73744);
    //       }
    //     }
    //     return end;
    //   }
    // UNRESOLVED: The helper sub_58FCA0 is called with no visible arguments but relies on locals (message prefix, fallback buffer); its exact role is inferred as message-buffer assembly.
    // UNRESOLVED: The special value 252 suppresses display here; the reason is not visible in this function.
    // UNRESOLVED: Role of asc_5B9908 is not visible in this raw source.
}
