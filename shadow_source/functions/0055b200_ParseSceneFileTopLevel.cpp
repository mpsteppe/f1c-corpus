// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055B200
// Canonical corpus name: SceneFileTopLevelParser
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneFileTopLevelParser_0055b200.c

void UnknownObject::ParseSceneFileTopLevel()
{
    // Top-level parser for a scene definition (MAS) file. Allocates a buffer the size of argument a3, reads the file contents from handle a2 into it, then walks the text line by line through a line-reader state (v14). Each non-skipped line is tested against a fixed set of keyword strings; matching directives either write scene-state fields (fog color/mode/in/out/density, ambient color, groupmethod flags), load other resources (searchpath, fontfile, masfile), or recurse into specialized sub-parsers for includefile, view, group, instance, and light blocks. A nested parse or load failure exits with -1 after freeing the buffer; end of file exits with 0.
    // ASSIGNMENT: Function identity and ABI lead for the scene top-level parser 0x0055B200; zero-initialize the line-reader state v14 via LargeBufferZeroInit_9a40. [function:0x0055B200, abi:lead, callee:0x00559A40, source:raw]
    // ASSIGNMENT: Store argument a3 (file size) in v15. [source:raw]
    // CALL: Allocate the raw file-data buffer v16 of a3 bytes via OperatorNewNhMallocWrapper. [callee:0x00587C03, source:raw]
    // GUARD: Guard: proceed only if ThreadSafeReadWrapper_803f(v16, 1, v15, a2) returns a3 (full read of the file from handle a2) and the first LineReaderFromBuffer(v14) result is not 3 (end of file). Otherwise skip the parse loop entirely. [callee:0x0058803F, callee:0x00559A70, source:raw]
    // LOOP: Line loop: while v14[0] != 3 (end of file), process the current line. [source:raw]
    // GUARD: Skip the line when v14[0] == 2 (line marker meaning nothing to parse); continue to the next line. [source:raw]
    // CALL: includefile directive: sub_559E20 matches current line against aIncludefile; when it matches and sub_55B6B0(v13) returns nonzero, jump to the failure exit. sub_55B6B0 also calls this function, forming a mutual recursion for nested scene files. [global:0x005DC428, callee:0x00559E20, callee:0x0055B6B0, caller:0x0055B6B0, source:raw]
    // CALL: searchpath directive: sub_559E20 matches against aSearchpath; on match call sub_53C6F0(v13) to set the search path for subsequent file loading. [global:0x005D3968, callee:0x00559E20, callee:0x0053C6F0, source:raw]
    // CALL: groupmethod directive: sub_559E20 matches against aGroupmethod; when matched, sub_588640(v13, aDynamic, 7) tests whether the method is "dynamic". [global:0x005DC41C, global:0x005DC414, callee:0x00559E20, callee:0x00588640, source:raw]
    // STATE_TRANSITION: groupmethod flags: when "dynamic" and NOT aLinksingle (sub_588640(v13, aLinksingle, 10) false), set bit flag 0x1000 on this via FlagBitSetter_a160; otherwise set bit flag 0x2000. [global:0x005DC408, callee:0x00588640, callee:0x0054A160, source:raw]
    // CALL: fontfile directive: sub_559E20 matches against aFontfile; on match, sub_53CFE0(&v11, v13, 67585) opens a font resource into v11 (nonzero return jumps to the failure exit), then LinkedListAppend_d340(v11) appends the font resource to a linked list. [global:0x005DC3FC, callee:0x00559E20, callee:0x0053CFE0, callee:0x0053D340, source:raw]
    // CALL: masfile directive: sub_559E20 matches against aMasfile; when matched and ErrorHandlerSet(&v12, v13) returns nonzero (load failure), jump to the failure exit. [global:0x005D3960, callee:0x00559E20, callee:0x0053CE10, source:raw]
    // CALL: ambientcolor directive: sub_559F00(v14, aAmbientcolor, &v10, &v9, &v8, 0) parses three components; on match call F_3DPositionSetWithUIRefresh(this, v10, v9, v8) to set the ambient color on the scene object. [global:0x005DC3EC, callee:0x00559F00, callee:0x00543800, source:raw]
    // ASSIGNMENT: fogmode directive: sub_559E20 matches against aFogmode; compare v13 with strcmp against aLinear/aExp/aExp2 and write the fog-mode literal 0x20000 / 0x40000 / 0x80000 to field this+0x19C (fog mode; packet records init literal 524288 = 0x80000 EXP2 default). [global:0x005DC3E4, global:0x005DC3DC, global:0x005DC3D8, global:0x005DC3D0, callee:0x00559E20, field:this:0x0000019C, source:raw]
    // ASSIGNMENT: fogcolor directive: sub_559F00(v14, aFogcolor, &v10, &v9, &v8, 0) parses three color components; store WORD v10 at this+0x18C (red), v9 at this+0x18A (green), v8 at this+0x188 (blue). [global:0x005DC3C4, callee:0x00559F00, field:this:0x0000018C, field:this:0x0000018A, field:this:0x00000188, source:raw]
    // ASSIGNMENT: fogin directive: PRNG4UniformFloatsFromSeed(v14, aFogin, (float *)&v7, 0, 0, 0) parses a float; on match store v7 at field this+0x194 (fog near distance). [global:0x005DC3BC, callee:0x00559FB0, field:this:0x00000194, source:raw]
    // ASSIGNMENT: fogout directive: PRNG4UniformFloatsFromSeed(v14, aFogout, (float *)&v7, 0, 0, 0) parses a float; on match store v7 at field this+0x198 (fog far distance). [global:0x005DC3B4, callee:0x00559FB0, field:this:0x00000198, source:raw]
    // ASSIGNMENT: fogdensity directive: PRNG4UniformFloatsFromSeed(v14, aFogdensity, (float *)&v7, 0, 0, 0) parses a float; on match store v7 at field this+0x190 (fog density). [global:0x005DC3A8, callee:0x00559FB0, field:this:0x00000190, source:raw]
    // GUARD: Block-dispatch guard: any one of sub_559E20 matching aView (then sub_55A060), aGroup (then sub_55A790), aInstance (then SceneNode), or aLight (then sub_55A500) whose sub-parser returns nonzero jumps to the failure exit, aborting the whole parse. [global:0x005DC234, global:0x005DC3A0, global:0x005CD620, global:0x005DC298, callee:0x00559E20, callee:0x0055A060, callee:0x0055A790, callee:0x0055A910, callee:0x0055A500, source:raw]
    // LOOP: Advance to the next line: when LineReaderFromBuffer(v14) == 3 the loop breaks; otherwise the next iteration re-reads v14[0]. [callee:0x00559A70, source:raw]
    // RETURN: Failure exit path: free the file-data buffer v16 via FreeWrapper_7bcf and return -1. [callee:0x00587BCF, source:raw]
    // RETURN: Success exit path: free the file-data buffer v16 via FreeWrapper_7bcf and return 0. [callee:0x00587BCF, source:raw]

    // Conservative worker pseudocode:
    //   int ParseSceneFileTopLevel(int this, int fileHandle, int fileSize) {
    //     ZeroInit(v14);
    //     LPVOID buf = Alloc(fileSize);
    //     if (ThreadSafeReadWrapper_803f(buf, 1, fileSize, fileHandle) == fileSize && LineReaderFromBuffer(v14) != 3) {
    //       while (v14[0] != 3) {
    //         if (v14[0] != 2) {
    //           if (Match(v14, aIncludefile) && sub_55B6B0(v13)) goto fail;
    //           if (Match(v14, aSearchpath)) sub_53C6F0(v13);
    //           if (Match(v14, aGroupmethod)) {
    //             if (StrEq(v13, aDynamic)) { if (!StrEq(v13, aLinksingle)) SetFlag(this, 0x1000); }
    //             else SetFlag(this, 0x2000);
    //           }
    //           if (Match(v14, aFontfile)) { if (OpenFont(&v11, v13, 67585)) goto fail; AppendFont(v11); }
    //           if (Match(v14, aMasfile) && ErrorHandlerSet(&v12, v13)) goto fail;
    //           if (ParseRGB(v14, aAmbientcolor, &v10, &v9, &v8)) SetAmbientColor(this, v10, v9, v8);
    //           if (Match(v14, aFogmode)) {
    //             if (streq(v13, aLinear)) this->fogMode = 0x20000;
    //             else if (streq(v13, aExp)) this->fogMode = 0x40000;
    //             else if (streq(v13, aExp2)) this->fogMode = 0x80000;
    //           }
    //           if (ParseRGB(v14, aFogcolor, &v10, &v9, &v8)) {
    //             this->fogRed = v10; this->fogGreen = v9; this->fogBlue = v8;
    //           }
    //           if (ParseFloat(v14, aFogin)) this->fogIn = v7;
    //           if (ParseFloat(v14, aFogout)) this->fogOut = v7;
    //           if (ParseFloat(v14, aFogdensity)) this->fogDensity = v7;
    //           if ((Match(v14, aView) && sub_55A060(this, v13, 0, v14))
    //            || (Match(v14, aGroup) && sub_55A790(this, v13, v14))
    //            || (Match(v14, aInstance) && SceneNode(this, v13, 0, v14))
    //            || (Match(v14, aLight) && sub_55A500(this, v13, v14))) goto fail;
    //         }
    //         if (LineReaderFromBuffer(v14) == 3) break;
    //       }
    //     }
    //     Free(buf);
    //     return 0;
    //   fail:
    //     Free(buf);
    //     return -1;
    //   }
    // UNRESOLVED: Exact semantics of the recursive sub-parsers sub_55A060 (view), sub_55A790 (group), SceneNode (instance), sub_55A500 (light), and sub_55B6B0 (includefile) are not known here.
    // UNRESOLVED: The init literal 524288 for field 0x19C is recorded in the packet but no write of that value appears in this function's raw code; it may be a struct-default elsewhere.
    // UNRESOLVED: PRNG4UniformFloatsFromSeed is used as a single-float parser despite its PRNG-oriented name.
    // UNRESOLVED: The keyword string contents behind the a-prefixed globals are not in this packet; only their references are.
}
