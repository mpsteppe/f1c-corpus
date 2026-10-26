// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049A5D0
// Canonical corpus name: sub_49A5D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49A5D0_0049a5d0.c

void UnknownObject::UICommandDispatch()
{
    // Dispatches UI commands on an object at a2 (whose +64 slot holds a UI/manager object). The command ID at this+0x00 selects a handler: cases 1-2 search a list by name (normalized via StringNormalizeLookup_a460 against the lookup map at object+64+5772, defaulting null strings to byte_5EA438) and apply a selection action via UtilityFunction_7890 with parameter 0 or -1; cases 3-6 do the same but apply TwoFieldSetter for this+0x14 and UtilityFunction_7890 with index 1..4; case 7 searches list items via UIListItemSearchByName and runs LinkedListSearchWithAction; case 9 copies a string pair; case 0xA runs a polling loop; case 0xB sets the global session state dword_5CC9E8 to -1 (shutdown); case 0xC builds a rendering context via RenderingContextSetup and drives vtable methods on it. Cases that name a current page write it back through StringReverseCopyLookup against the "CurrentPage" string slot.
    // STATE_TRANSITION: Switch dispatch on the command ID at this+0x00, routed through the jump table jpt_49A5E3; the default case returns without action. [field:this:0x00000000, global:0x0049A900, source:raw]
    // CALL: Cases 1-2: normalize the name parameter at this+0x04 via StringNormalizeLookup_a460 (defaulting a null string to byte_5EA438) and search the UI list with UIListSearchByName_76c0. [field:this:0x00000004, callee:0x0049A460, callee:0x004976C0, global:0x005EA438, source:raw]
    // CALL: Cases 1-2: on a match, apply the selection action via UtilityFunction_7890 with parameter 0 (case 1) or -1 (case 2). [field:this:0x00000004, callee:0x00497890, source:raw]
    // CALL: Cases 1-2: write the matched item's label (at item+52, default byte_5EA438 when null) back to the "CurrentPage" string slot via StringReverseCopyLookup. [field:this:0x00000004, callee:0x0049A490, global:0x005CCB44, global:0x005EA438, source:raw]
    // CALL: Cases 3-6: normalize the name parameter at this+0x04 (default byte_5EA438) and search the UI list with UIListSearchByName_76c0. [field:this:0x00000004, callee:0x0049A460, callee:0x004976C0, global:0x005EA438, source:raw]
    // CALL: Cases 3-6: if the parameter at this+0x14 is nonzero, call TwoFieldSetter(uiObject, this+0x14). [field:this:0x00000014, callee:0x00497D00, source:raw]
    // CALL: Cases 3-6: apply the action via UtilityFunction_7890 with index 1..4 depending on the command ID. [field:this:0x00000000, callee:0x00497890, source:raw]
    // CALL: Cases 3-6: write the matched item's label (at item+52, default byte_5EA438 when null) back to the "CurrentPage" string slot via StringReverseCopyLookup. [callee:0x0049A490, global:0x005CCB44, global:0x005EA438, source:raw]
    // CALL: Case 7: normalize the name at this+0x04 (default byte_5EA438), search list items with UIListItemSearchByName, and on a match run LinkedListSearchWithAction on the found item. [field:this:0x00000004, callee:0x0049A460, callee:0x00497650, callee:0x004974A0, global:0x005EA438, source:raw]
    // CALL: Case 9: copy a string pair by calling StringReverseCopyLookup(uiObject+64+5772, key from this+0x04, source from this+0x0C, default byte_5EA438). [field:this:0x00000004, field:this:0x0000000C, callee:0x0049A490, global:0x005EA438, source:raw]
    // CALL: Case 0xA: run the polling loop through ThunkPollingLoopViaFUN00498f70(uiObject). [callee:0x004979B0, source:raw]
    // ASSIGNMENT: Case 0xB: set the global session state dword_5CC9E8 to -1, marking shutdown. [global:0x005CC9E8, source:raw]
    // CALL: Case 0xC: build a rendering context with RenderingContextSetup(uiObject, this+0x0C or default); on success invoke the context's vtable methods at +140 and +144 and register it with Setter(uiObject, context). [field:this:0x0000000C, callee:0x00497750, callee:0x004979C0, source:raw]
    // RETURN: Default case: unrecognized command ID falls through with no action. [field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   void sub_49A5D0(_DWORD *cmd, int a2) {
    //     void *ui = *(void**)(a2 + 64);
    //     char *name, *secondary;
    //     int item;
    //     switch (*cmd) {
    //       case 1: case 2:
    //         name = normalize(cmd[1] ? cmd[1] : byte_5EA438, ui+64+5772);
    //         item = UIListSearchByName_76c0(ui, name);
    //         if (item) {
    //           UtilityFunction_7890(ui, item, cmd[0] == 1 ? 0 : -1);
    //           StringReverseCopyLookup(ui+64+5772, aCurrentPage_0, *(char**)(item+52) ?: byte_5EA438);
    //         }
    //         return;
    //       case 3: case 4: case 5: case 6:
    //         name = normalize(cmd[1] ?: byte_5EA438, ui+64+5772);
    //         item = UIListSearchByName_76c0(ui, name);
    //         if (cmd[5]) TwoFieldSetter(ui, cmd[5]);
    //         UtilityFunction_7890(ui, item, *cmd - 2);
    //         StringReverseCopyLookup(ui+64+5772, aCurrentPage_0, *(char**)(item+52) ?: byte_5EA438);
    //         break;
    //       case 7:
    //         item = UIListItemSearchByName(ui, normalize(cmd[1] ?: byte_5EA438, ui+64+5772));
    //         if (item) LinkedListSearchWithAction(ui, item);
    //         break;
    //       case 9:
    //         StringReverseCopyLookup(ui+64+5772, cmd[1] ?: byte_5EA438, cmd[3] ?: byte_5EA438);
    //         break;
    //       case 0xA: ThunkPollingLoopViaFUN00498f70(ui); break;
    //       case 0xB: dword_5CC9E8 = -1; break;
    //       case 0xC:
    //         ctx = RenderingContextSetup(ui, cmd[3] ?: byte_5EA438);
    //         if (ctx) { (*(ctx->vtbl+140))(ctx); Setter(ui, ctx); (*(ctx->vtbl+144))(ctx); }
    //         break;
    //       default: return;
    //     }
    //   }
    // UNRESOLVED: Semantic roles of TwoFieldSetter (cases 3-6), ThunkPollingLoopViaFUN00498f70 (case 0xA), and the vtable-driven rendering-context methods (case 0xC) are caller/driver-specific and not established here.
    // UNRESOLVED: The item layout at item+52 (label string) and the lookup-map offset 5772 on ui+64 are DERIVED from this function only.
    // UNRESOLVED: Callers are sub_486600 (0x00486600) and LinkedListTraversalWithCallback (0x00486630); the UI dispatch context (menu/session) is not confirmed on a static frame path.
}
