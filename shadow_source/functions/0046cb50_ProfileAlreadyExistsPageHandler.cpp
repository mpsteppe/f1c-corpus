// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046CB50
// Canonical corpus name: ProfileAlreadyExistsPageHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ProfileAlreadyExistsPageHandler_0046cb50.c

void UnknownObject::ProfileAlreadyExistsPageHandler()
{
    // UI flow handler for the profile-create page. Pulls child control 3 out of the page control (this[16]) via its vtable and branches on whether the entered player name (byte_7CD818) passes the uniqueness check. If unique: optionally formats and shows a 'player name never used' message built from the settings directory, sanitizes the name, allocates and initializes a temporary UI control window, and on successful text-file load creates the profile (ShortComputation_92a0), tears down the window, triggers a follow-up (sub_4B0770) when v3[276] > 0, then runs profile file create/read and a final cleanup (ShortComputation_0ad0); result becomes 0. If the name already exists: copies the 'profile already' string into byte_5EC4CC, displays it on the page control, dispatches the profile-exists prompt (LookupDispatch with -1) and keeps result -1. Finally re-fetches two dispatch objects (3 and 45) from dword_7CD8C0 and calls their vtable methods, then returns the accumulated result.
    // GUARD: Fetch child control 3 from page control this[16] via vtable method at +28; the whole profile flow runs only when that control is non-null. [field:this:0x00000040, field:*(this+0x40):0x0000001C]
    // GUARD: Unique-name branch: enters only when byte_7CD818 is non-empty (strlen) and PlayerNameNeverUsedProfileNameUniquenessCheck(v3, &byte_7CD818) is true. [global:0x007CD818, callee:0x00469550]
    // GUARD: If byte_7D2E41 is set, the 'player name never used' message is formatted and shown once; the flag is then cleared. [global:0x007D2E41]
    // CALCULATION: Select the directory string for the message: dword_5EC440, falling back to byte_5EA438 when null. [global:0x005EC440, global:0x005EA438]
    // CALL: StringFormatWithBufferOverflowCheck(byte_7CD718, "%s%s", dir, aPlayernameneve) builds the display path/name into byte_7CD718. [callee:0x0058815F, global:0x007CD718, global:0x005BE860, global:0x005C6970]
    // CALL: sub_499690(byte_7CD718) shows the constructed 'player name never used' message. [callee:0x00499690, global:0x007CD718]
    // ASSIGNMENT: Clear byte_7D2E41 to 0 after the one-shot message. [global:0x007D2E41]
    // CALL: ReplaceSpecialCharsWithUnderscoreHyphen(&byte_7CD818) sanitizes the entered profile name for use as a directory/file name. [callee:0x00568560, global:0x007CD818]
    // CALL: OperatorNewNhMallocWrapper(18868) allocates a temporary UI control window block. [callee:0x00587C03]
    // CALL: UIControlWindowInitialization(v5) constructs the window on the allocated block; when allocation failed the window pointer stays null. [callee:0x004A70E0]
    // GUARD: Success branch: TextFileReader(&byte_7CD818) != -1 means the profile text file was readable. [callee:0x004B09A0, global:0x007CD818]
    // CALL: ShortComputation_92a0(v3, &byte_7CD818, 1) registers/creates the profile entry; result is set to 0 on this path. [callee:0x004692A0, global:0x007CD818]
    // GUARD: If the temporary window exists, run StaticInitBulk(v6) then FreeWrapper_7bcf(v6) to initialize and release it. [callee:0x004A8B80, callee:0x00587BCF]
    // GUARD: When v3[276] > 0, call sub_4B0770(0) to run the follow-up step. [callee:0x004B0770]
    // CALL: PlayerNameNeverUsedProfileFileCreateRead(&byte_7CE498) creates or reads the profile file state. [callee:0x004B03F0, global:0x007CE498]
    // CALL: ShortComputation_0ad0(&unk_7CE24C) performs the final state update on the profile-exists flow. [callee:0x004A0AD0, global:0x007CE24C]
    // GUARD: Already-exists branch: BinarySearchInStringTable(byte_5EC4C0, aProfileAlready, byte_5EC4CC) locates the 'profile already' message string. [callee:0x00423A00, global:0x005EC4C0, global:0x005C6B38, global:0x005EC4CC]
    // LOOP: String-copy loop: copy aProfileAlready into byte_5EC4CC one byte at a time until the NUL terminator. [global:0x005C6B38, global:0x005EC4CC]
    // CALL: Page control vtable method at +4 is called with byte_5EC4CC to display the error message on the profile page. [field:*(this+0x40):0x00000004, global:0x005EC4CC]
    // CALL: LookupDispatch(aProfileExistsP, -1) dispatches the profile-exists prompt; result stays -1 on this branch. [callee:0x00497940, global:0x005C6B24]
    // ASSIGNMENT: Already-exists branch keeps the return value at -1. [source:raw]
    // CALL: Fetch dispatch object 3 via dword_7CD8C0 vtable method at +28 and invoke its vtable method at +160 when non-null. [global:0x007CD8C0]
    // CALL: Fetch dispatch object 45 via dword_7CD8C0 vtable method at +28 and invoke its vtable method at +56 with argument 1. [global:0x007CD8C0]
    // RETURN: Return the accumulated result: 0 on successful profile creation, -1 otherwise. [source:raw]

    // Conservative worker pseudocode:
    //   int ProfileAlreadyExistsPageHandler(ProfilePage **this) {
    //     int result = -1;
    //     Control *ctrl = this->page->GetControl(3);           // *(this[16]) vtable +28
    //     if (ctrl) {
    //       if (strlen(g_name) && PlayerNameNeverUsedProfileNameUniquenessCheck(ctrl, g_name)) {
    //         if (g_msgFlag) {
    //           char *dir = g_settingsDir ? g_settingsDir : g_defaultDir;
    //           StringFormatWithBufferOverflowCheck(g_msgBuf, "%s%s", dir, g_playerNameNever);
    //           ShowMessage(g_msgBuf);
    //           g_msgFlag = 0;
    //         }
    //         SanitizeName(g_name);
    //         void *wnd = OperatorNew(18868) ? UIControlWindowInit(OperatorNew(18868)) : 0;
    //         if (TextFileReader(g_name) != -1) {
    //           RegisterProfile(ctrl, g_name, 1);
    //           result = 0;
    //         }
    //         if (wnd) { StaticInitBulk(wnd); FreeWrapper(wnd); }
    //         if (ctrl[276] > 0) FollowUp(0);
    //         ProfileFileCreateRead(g_profileState);
    //         FinalStateUpdate(&g_state);
    //       } else {
    //         if (BinarySearchInStringTable(g_table, g_profileAlready, g_msgBuf)) strcpy(g_msgBuf, g_profileAlready);
    //         this->page->SetMessage(g_msgBuf);           // *(this[16]) vtable +4
    //         LookupDispatch(g_profileExistsPrompt, -1);
    //         result = -1;
    //       }
    //     }
    //     Dispatch *d3 = g_dispatch->Get(3);  if (d3) d3->Method160();
    //     Dispatch *d45 = g_dispatch->Get(45); if (d45) d45->Method56(1);
    //     return result;
    //   }
    // UNRESOLVED: byte_7CD818 is treated as the entered profile name buffer but its source/writer is elsewhere.
    // UNRESOLVED: Semantics of v3[276] and of sub_4B0770(0) are not grounded in this packet.
    // UNRESOLVED: Dispatch objects 3 and 45 fetched from dword_7CD8C0 and their +160/+56 vtable methods are unnamed.
    // UNRESOLVED: Relationship between ShortComputation_92a0 / ShortComputation_0ad0 and the profile storage layer is caller-internal.
}
