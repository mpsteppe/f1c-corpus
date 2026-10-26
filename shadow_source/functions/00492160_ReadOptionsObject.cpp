// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00492160
// Canonical corpus name: sub_492160
// Owner: Options_OSC_Reader [DERIVED]
// Raw source: functions/sub_492160_00492160.c

void Options_OSC_Reader::ReadOptionsObject()
{
    // Parses an options screen configuration (.OSC) file line by line. Guarded by the options object pointer at this + 420; when null, logs the self-identifying error string "Invalid Options Pointer in Options_OSC_Reader::ReadOptionsObject()" and returns 0. When valid, optionally builds the options screens resource path, then loops reading lines and dispatches each token to type-specific handlers for Attributeset, Layer, Gizmo, Dopage, Loadingscreenp, Systemfont, Tooltipfont, tooltip colors, SetSymbol and DisableGizmo.
    // GUARD: Guard on the options object pointer at this + 420; null pointer routes to the error path. [field:this:0x000001A4]
    // GUARD: When the byte flag at this + 410 is non-zero, build the options screens resource path first. [field:this:0x0000019A]
    // CALL: ResourcePathBuilder(aOptionsScreens) sets up the options screens asset path. [callee:0x00493E20, global:0x005CC5CC]
    // LOOP: Loop calling sub_491FB0(this) to fetch the next configuration line until it returns false. [callee:0x00491FB0]
    // ASSIGNMENT: Seed the line buffer with byte_5EA438[0] and zero-fill the remainder. [global:0x005EA438]
    // CALL: Dispatch: token equals aAttributeset -> sub_493060 handles the attributeset. [callee:0x005654A0, global:0x005CC5BC, callee:0x00493060]
    // CALL: Dispatch: token equals aLayer -> sub_492460 handles the layer. [callee:0x005654A0, global:0x005CC5B4, callee:0x00492460]
    // CALL: Dispatch: token equals aGizmo -> sub_492A40 builds a gizmo; when non-null sub_4975D0 attaches it. [callee:0x005654A0, global:0x005CC5AC, callee:0x00492A40, callee:0x004975D0]
    // CALL: Dispatch: token equals aDopage -> UIListSearchByName_76c0 finds the page by name and UtilityFunction_7890 applies it with -1. [callee:0x005654A0, global:0x005CC5A4, callee:0x004976C0, callee:0x00497890]
    // CALL: Dispatch: token equals aLoadingscreenp -> UIListSearchByName_76c0 finds it and ConditionalSetter0x30 sets it when found. [callee:0x005654A0, global:0x005CC590, callee:0x004976C0, callee:0x004980C0]
    // CALL: Dispatch: token equals aSystemfont -> sub_498440 handles the system font. [callee:0x005654A0, global:0x005CC584, callee:0x00498440]
    // ASSIGNMENT: Else branch: when token equals aTooltipfont, copy the line into the tooltip font name buffer at (options object + 5432). [callee:0x005654A0, global:0x005CC578, field:this:0x000001A4]
    // CALL: Non-tooltipfont tokens: parse tooltip colors aTooltipColorFi/aTooltipColorEd via sub_565760 into the options object at offsets +180 and +184. [callee:0x00565760, global:0x005CC564, global:0x005CC550, field:this:0x000001A4]
    // CALL: Dispatch: token equals aSetSymbol -> split on ":\t" via sub_5897CA and remap through StringReverseCopyLookup. [callee:0x005654A0, global:0x005CC544, callee:0x005897CA, callee:0x0049A490]
    // CALL: Dispatch: token equals aDisableGizmo -> RenderingContextSetup finds the gizmo and a virtual method (vtable slot at offset 56) disables it with argument 1. [callee:0x005654A0, global:0x005CC530, callee:0x00497750]
    // CALL: Error path: copy the invalid-options message and log it via sub_493C80(3, message). [callee:0x00493C80]
    // RETURN: Return 0 on both the parsed and the error paths. [source:raw]

    // Conservative worker pseudocode:
    //   if (options == get_ptr(this + 420)) {
    //     if (get_byte(this + 410)) ResourcePathBuilder(aOptionsScreens);
    //     while (sub_491FB0(this)) {
    //       line[0] = byte_5EA438[0]; memset(line + 1, 0, 124); line[126] = 0; line[127] = 0;
    //       if      (str_eq(line, aAttributeset))  sub_493060(line);
    //       else if (str_eq(line, aLayer))          sub_492460(line);
    //       else if (str_eq(line, aGizmo))         { obj = sub_492A40(line); if (obj) sub_4975D0(obj, 0); }
    //       else if (str_eq(line, aDopage))        UtilityFunction_7890(UIListSearchByName_76c0(line), -1);
    //       else if (str_eq(line, aLoadingscreenp)){ page = UIListSearchByName_76c0(line); if (page) ConditionalSetter0x30(page); }
    //       else if (str_eq(line, aSystemfont))    sub_498440(line);
    //       else {
    //         if (!str_eq(line, aTooltipfont)) {
    //           if (!sub_565760(aTooltipColorFi, options + 180, 0, 0, 0)
    //               && !sub_565760(aTooltipColorEd, options + 184, 0, 0, 0)) {
    //             if (str_eq(line, aSetSymbol)) {
    //               strcpy(sep, ":\t");
    //               left = sub_5897CA(line, sep); right = sub_5897CA(0, sep);
    //               if (left && right) StringReverseCopyLookup(left, right);
    //             } else if (str_eq(line, aDisableGizmo)) {
    //               gz = RenderingContextSetup(line);
    //               if (gz) (*(vtable(gz) + 56))(gz, 1);
    //             }
    //           }
    //         } else {
    //           strcpy(options + 5432, line);
    //         }
    //       }
    //     }
    //     return 0;
    //   } else {
    //     strcpy(msg, "Invalid Options Pointer in Options_OSC_Reader::ReadOptionsObject()");
    //     sub_493C80(3, msg);
    //     return 0;
    //   }
    // UNRESOLVED: Globals word_5CC540, byte_5CC542, aInvalidOptions and unk_7CD9D8 are listed as read but do not appear in the raw source body of this function; likely string-region fragments or attributed reads whose role is unknown here.
    // UNRESOLVED: Virtual method invoked through vtable slot at offset 56 is a runtime-dispatched call; its concrete behavior is outside this function.
}
