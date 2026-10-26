// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045C240
// Canonical corpus name: FileScanner
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileScanner_0045c240.c

void UnknownObject::FileScanner()
{
    // Resets a file-scan object: seeds two leading bytes with LCG-random values, walks and frees the linked list of previously scanned file entries, zeroes the list metadata words (head at this+0x4, tail at this+0x8, cached tail at this+0xC, count at this+0x10), then invokes sub_45C0C0 three times to scan the selected directory path for .gdb (type 2), .hdv (type 1), and terrain.ini (type 0) files. The scanned directory is dword_5EC3D8 when set, else the byte_5EA438 default path. Returns the sub_45C0C0 result of the last scan. Called by DriverEntrantSetupEntry (00462550).
    // ASSIGNMENT: *this = RandLCGRandomNumberGenerator(this) % 247 + 8; seed the first byte of the object [field:this:0x00000000, callee:0x005884ED, source:raw]
    // ASSIGNMENT: this[1] = RandLCGRandomNumberGenerator(247); seed the second byte of the object [field:this:0x00000001, callee:0x005884ED, source:raw]
    // LOOP: Walk the linked list starting at the head stored in this+0x4, following next pointers at node+4 until a null node is reached [field:this:0x00000004, field:*(*(this+0x4)+0x4):0x00000004, source:raw]
    // GUARD: Per node, read the flag byte at node+8; only when it is nonzero free the node's data pointer chain [field:*(this+0x4):0x00000008, source:raw]
    // CALL: Free inner data: read the data pointer at node+0, free its first element (*v5) when present, then free the data pointer itself and finally the node; all via FreeWrapper_7bcf [callee:0x00587BCF, field:*(this+0x4):0x00000000, field:*(*(this+0x4)+0x0):0x00000000, source:raw]
    // ASSIGNMENT: Zero the list metadata: this+0x4 (head), this+0x8 (tail), this+0xC (cached tail), this+0x10 (count) [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // CALCULATION: Select scan directory: use dword_5EC3D8 when nonzero, else fall back to byte_5EA438 (repeated for each of the three scans) [global:0x005EC3D8, global:0x005EA438, source:raw]
    // CALL: sub_45C0C0(this, aGdb, selected path, 2); scan for .gdb files with type code 2 [callee:0x0045C0C0, global:0x005C5B9C, source:raw]
    // CALL: sub_45C0C0(this, aHdv_0, selected path, 1); scan for .hdv files with type code 1 [callee:0x0045C0C0, global:0x005C5B94, source:raw]
    // RETURN: Return sub_45C0C0(this, aTerrainIni, selected path, 0); scan for terrain.ini with type code 0 and return its result [callee:0x0045C0C0, global:0x005C5B88, source:raw]

    // Conservative worker pseudocode:
    //   this[0] = RandLCGRandomNumberGenerator(this) % 247 + 8;
    //   this[1] = RandLCGRandomNumberGenerator(247);
    //   v2 = *(DWORD*)(this+0x4);
    //   while (v2) {
    //     v3 = v2;
    //     v4 = *(BYTE*)(v2+8);
    //     v2 = *(DWORD*)(v2+4);
    //     if (v4) {
    //       v5 = *v3;
    //       if (v5) {
    //         if (*v5) FreeWrapper_7bcf(*v5);
    //         FreeWrapper_7bcf(v5);
    //       }
    //     }
    //     FreeWrapper_7bcf(v3);
    //   }
    //   *(DWORD*)(this+0x4) = 0; *(DWORD*)(this+0x8) = 0; *(DWORD*)(this+0xC) = 0; *(DWORD*)(this+0x10) = 0;
    //   path = dword_5EC3D8 ? (const char*)dword_5EC3D8 : (const char*)byte_5EA438;
    //   sub_45C0C0(this, aGdb, path, 2);
    //   sub_45C0C0(this, aHdv_0, path, 1);
    //   return sub_45C0C0(this, aTerrainIni, path, 0);
    // UNRESOLVED: sub_45C0C0 internals (directory enumeration and list-append behavior) are not documented here
    // UNRESOLVED: The meaning of the type codes 0/1/2 passed to sub_45C0C0 and the object bytes seeded at this+0x0/this+0x1 are inferred from the prelabel analysis only
    // UNRESOLVED: RandLCGRandomNumberGenerator receives the this pointer as its first argument; whether that is a true seed or a decompiler artifact is unresolved
    // UNRESOLVED: The abi name File_Scanner_Track_Config_Loader (LEGACY) and canonical FileScanner are retained as DERIVED naming; the scanned directory globals remain unnamed
}
