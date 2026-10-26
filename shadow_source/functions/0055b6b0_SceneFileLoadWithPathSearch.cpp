// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055B6B0
// Canonical corpus name: sub_55B6B0
// Owner: SceneFileLoader [DERIVED]
// Raw source: functions/sub_55B6B0_0055b6b0.c

void SceneFileLoader::SceneFileLoadWithPathSearch()
{
    // Loads a named scene file and parses it with SceneFileTopLevelParser. Tries the name directly, then each registered path entry (byte_8B5A3C array, stride 132) formatted as '<entry>\<name>', then a linked list of resource objects anchored at dword_8B8F14 matched by sub_560230. Reports an error and returns -1 when the file cannot be located; returns 0 on success or on a benign not-found.
    // GUARD: If the scene file name is empty, format 'Illegal scene file name %s' via StringFormatWithBufferOverflowCheck, log it via sub_53C590 and return -1. [callee:0x0058815F, callee:0x0053C590, global:0x005DC454, function:0x0055B6B0]
    // CALL: Try to open the file directly with sub_587DB0 using the binary-read mode string aRb. [callee:0x00587DB0, global:0x005BE828]
    // CALL: On a successful direct open: seek to the end (sub_587F64 with offset 0, origin 2), query the file size via FileSizeQueryWrapper, then seek back to the start (offset 0, origin 0). [callee:0x00587F64, callee:0x0058ACE6]
    // GUARD: Parse the opened file with SceneFileTopLevelParser(this, handle, size); on a nonzero parse result close the file via FileCloseWithLock and return -1. [callee:0x0055B200, callee:0x00587D02]
    // RETURN: Close the file via FileCloseWithLock and return 0 on the direct-open success path. [callee:0x00587D02, function:0x0055B6B0]
    // LOOP: If the direct open failed, search the registered path-entry array byte_8B5A3C (entries of stride 132, count dword_8B8E30): format '<entry>\<name>' with StringFormatWithBufferOverflowCheck (format literal aSS_3) and try sub_587DB0 until an open succeeds or the count is exhausted. [global:0x008B5A3C, global:0x008B8E30, callee:0x0058815F, callee:0x00587DB0, global:0x005C2D64]
    // CALL: On a successful entry open: measure the size (seek end, FileSizeQueryWrapper, seek start), parse via SceneFileTopLevelParser, close via FileCloseWithLock, and return 0 or -1 depending on the parse result. [callee:0x00587F64, callee:0x0058ACE6, callee:0x0055B200, callee:0x00587D02]
    // GUARD: If every registered entry was tried without success (search index equals dword_8B8E30), walk the linked list anchored at dword_8B8F14: while sub_560230 reports no name match, advance to the node's next pointer at index 76 and count the step; when matched, parse the node via SceneFileTopLevelParser using the node's data pointer at index 4 and a size derived from the node header fields at indexes 73 and 74. [global:0x008B8F14, global:0x008B8E30, callee:0x00560230, callee:0x0055B200]
    // GUARD: After the searches, if the walk/not-found counter differs from global dword_8B6AC0, return 0 (the scene file was considered handled). [global:0x008B6AC0, function:0x0055B6B0]
    // RETURN: When the file was not located, format 'Could not locate scene file %s' via StringFormatWithBufferOverflowCheck, log it via sub_53C590 and return -1. [callee:0x0058815F, callee:0x0053C590, global:0x005DC434, function:0x0055B6B0]

    // Conservative worker pseudocode:
    //   if (!*name) { log('Illegal scene file name %s'); return -1; }
    //   handle = fopen(name, "rb");
    //   if (handle) { size = fsize(handle); if (parse(this, handle, size)) { close; return -1; } close; return 0; }
    //   for (each registered entry, stride 132) { format '<entry>\\<name>'; if (fopen) { size; if (parse) { close; return -1; } close; return 0; } }
    //   if (no entry matched) for (node = list_head; node; node = node->next) if (name_matches) { if (parse) return -1; }
    //   if (counter != dword_8B6AC0) return 0;
    //   log('Could not locate scene file %s'); return -1;
    // UNRESOLVED: The exact role of global dword_8B6AC0 in the final return decision is unclear; the decompiled comparison only distinguishes a benign not-found from a reported error.
    // UNRESOLVED: The linked-list node size derivation ((node[73] << 8) + node[74] + 8) is described only at the index level; the node header layout is not resolved.
    // UNRESOLVED: The aSS_3 literal is assigned DERIVED to the '<entry>\<name>' path-format string based on the string-global set; its identity is not independently confirmed.
}
