// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055B8C0
// Canonical corpus name: sub_55B8C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55B8C0_0055b8c0.c

void UnknownObject::CountMeshFilesInSceneFile()
{
    // Opens a scene file by direct path or by searching the registered search-directory array byte_8B5A3C (stride 132, count dword_8B8E30), reads the whole file into a heap buffer, then scans the line-reader stream and counts MeshFile entries found inside Instance blocks, storing the count through output pointer a2. On an empty name or when no file is found, formats the message "Illegal scene file name %s" and reports it through sub_53C590(-1, message), returning -1; otherwise the file is freed and closed and 0 is returned.
    // CALL: Zero-initialize the line-reader struct v8 via LargeBufferZeroInit_9a40(v8). [callee:0x00559A40, source:raw]
    // GUARD: If the first byte of the scene file name a1 is NUL (empty name), branch to the illegal-name error path. [source:raw]
    // CALL: Try opening a1 directly with sub_587DB0(a1, aRb), treating aRb as the file-mode string (rb). [callee:0x00587DB0, global:0x005BE828, source:raw]
    // GUARD: If the direct open returned a non-NULL handle (v3), proceed to the load path. [source:raw]
    // LOOP: Search the registered directory array byte_8B5A3C (entry count dword_8B8E30, stride 132): build each candidate path in v11 with StringFormatWithBufferOverflowCheck(v11, "%s\\%s", v5, a1), try sub_587DB0(v11, aRb), advance v5 by 132 and increment v4 until the handle is found or all dword_8B8E30 entries are tried. [callee:0x00587DB0, callee:0x0058815F, global:0x005BE828, global:0x008B5A3C, global:0x008B8E30, source:raw]
    // GUARD: If v4 differs from dword_8B8E30 (a search entry opened the file) go to the load path; otherwise the file was not found and control falls through to the illegal-name error path. [global:0x008B8E30, source:raw]
    // CALL: Position the file handle to the end with sub_587F64(v3, 0, 2) (fseek to end). [callee:0x00587F64, source:raw]
    // CALL: Query the file size into v6 with FileSizeQueryWrapper(v3) (ftell). [callee:0x0058ACE6, source:raw]
    // CALL: Rewind the file handle to the start with sub_587F64(v3, 0, 0) (fseek to beginning). [callee:0x00587F64, source:raw]
    // ASSIGNMENT: Store the size into v9 and allocate a heap buffer of that size: v10 = OperatorNewNhMallocWrapper(v6). [callee:0x00587C03, source:raw]
    // CALL: Read the whole file into v10 with ThreadSafeReadWrapper_803f(v10, 1, v9, v3); continue to parsing only if the read returned the full size and the first LineReaderFromBuffer(v8) call did not return status 3. [callee:0x00559A70, callee:0x0058803F, field:this:0x00000000, source:raw]
    // LOOP: Outer loop over lines read from v8 by LineReaderFromBuffer, running until v8[0] equals status 3 (end of stream). [callee:0x00559A70, field:this:0x00000000, source:raw]
    // GUARD: Inside the outer loop, when v8[0] is not status 2, sub_559E20(v8, aInstance, v7, 0) matches the Instance key, and the next line is not the end of stream, enter the Instance-block scan. [callee:0x00559A70, callee:0x00559E20, field:this:0x00000000, global:0x005CD620, source:raw]
    // LOOP: Inner loop scanning lines within an Instance block until v8[0] equals status 3. [callee:0x00559A70, field:this:0x00000000, source:raw]
    // GUARD: Inside the inner loop, when v8[0] is not status 2 and sub_559E20(v8, aMeshfile, v7, 0) matches the MeshFile key, count the entry and leave the inner loop. [callee:0x00559E20, global:0x005CD614, source:raw]
    // STATE_TRANSITION: If the output pointer a2 is non-NULL, increment the count it points to (++*a2) for each MeshFile entry found inside an Instance block. [source:raw]
    // CALL: Release the file buffer with FreeWrapper_7bcf(v10). [callee:0x00587BCF, source:raw]
    // CALL: Close the file handle with FileCloseWithLock(v3). [callee:0x00587D02, source:raw]
    // RETURN: Return 0 after the file was loaded, parsed and released. [source:raw]
    // ASSIGNMENT: On the illegal-name/file-not-found path, format the message into v7 with StringFormatWithBufferOverflowCheck(v7, "Illegal scene file name %s", a1). [callee:0x0058815F, global:0x005DC454, source:raw]
    // CALL: Report the error message through sub_53C590(-1, v7). [callee:0x0053C590, source:raw]
    // RETURN: Return -1 on the illegal-name/file-not-found path. [source:raw]
    // CALL: Called by AudioEngineInitialization (0x00546010), which supplies the scene file name and the optional count destination. [caller:0x00546010, source:raw]

    // Conservative worker pseudocode:
    //   LargeBufferZeroInit_9a40(v8);
    //   if (*a1 == 0) goto illegal_name;
    //   v3 = sub_587DB0(a1, aRb);
    //   if (v3 == 0) {
    //     v4 = 0;
    //     v5 = byte_8B5A3C;
    //     while (v4 < dword_8B8E30) {
    //       StringFormatWithBufferOverflowCheck(v11, "%s\\%s", v5, a1);
    //       v3 = sub_587DB0(v11, aRb);
    //       if (v3) break;
    //       ++v4; v5 += 132;
    //     }
    //   }
    //   if (v4 == dword_8B8E30) goto illegal_name;
    //   sub_587F64(v3, 0, 2);
    //   v6 = FileSizeQueryWrapper(v3);
    //   sub_587F64(v3, 0, 0);
    //   v9 = v6;
    //   v10 = OperatorNewNhMallocWrapper(v6);
    //   if (ThreadSafeReadWrapper_803f(v10, 1, v9, v3) == v6 && LineReaderFromBuffer(v8) != 3) {
    //     while (LineReaderFromBuffer(v8) != 3) {
    //       if (v8[0] != 2 && sub_559E20(v8, aInstance, v7, 0) && LineReaderFromBuffer(v8) != 3) {
    //         while (v8[0] != 3) {
    //           if (v8[0] != 2 && sub_559E20(v8, aMeshfile, v7, 0)) {
    //             if (a2) ++*a2;
    //             break;
    //           }
    //           if (LineReaderFromBuffer(v8) == 3) break;
    //         }
    //       }
    //     }
    //   }
    //   FreeWrapper_7bcf(v10);
    //   FileCloseWithLock(v3);
    //   return 0;
    //   illegal_name:
    //   StringFormatWithBufferOverflowCheck(v7, "Illegal scene file name %s", a1);
    //   sub_53C590(-1, v7);
    //   return -1;
    // UNRESOLVED: global:0x005C2D64 (aSS_3) is listed as a read global but does not appear in the raw source text; its role here is unestablished.
    // UNRESOLVED: The semantics of sub_559E20 (key/property match) and the exact meaning of line-reader status v8[0] (2 = skip, 3 = end) are inferred, not proven by this packet.
    // UNRESOLVED: byte_8B5A3C and dword_8B8E30 are confirmed as the search-directory array (stride 132) and its entry count, but the contents of the directory array are not in this packet.
    // UNRESOLVED: sub_587DB0 (fopen), sub_587F64 (fseek), FileSizeQueryWrapper (ftell) and the ThreadSafeReadWrapper_803f read wrapper are labelled by existing analysis; their exact low-level behavior is outside this packet.
    // UNRESOLVED: The owning object type is unknown; the packet carries no class-level evidence beyond the single line-reader status field at offset 0x0.
}
