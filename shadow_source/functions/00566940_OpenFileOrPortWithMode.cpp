// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00566940
// Canonical corpus name: sub_566940
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_566940_00566940.c

void UnknownObject::OpenFileOrPortWithMode()
{
    // Opens a file or serial/comm port handle based on the access-mode argument. With a3==0 the path is resolved from a global buffer (unk_5E5174 or unk_5E5178 depending on this[3]) and opened through sub_587DB0; with a3!=0 a mode string is assembled over dword_5E5170 from global byte tables (byte_5E5164/5E5168/5E516C) selected by the mode value, optionally marked text mode (byte 116, 't') when this[3]==1, and opened through sub_534B00. The resulting handle is stored at this[0], the resolved path string is copied into this+1, and the byte at this+24 is cleared on success. An optional FileAttributeCheckSequence on a2 gates the whole open.
    // GUARD: When a5 is set, opening proceeds only if FileAttributeCheckSequence(a2) succeeds; otherwise the function returns the check result early. [callee:0x005668F0, source:raw]
    // ASSIGNMENT: Store access mode a3 into this[4] (offset 0x10) and sub-mode a4 into this[3] (offset 0xC). [field:this:0x00000010, field:this:0x0000000C]
    // CALL: Call sub_568620(1024), preparing the 1024-byte staging buffer used for the resolved path. [callee:0x00568620]
    // GUARD: Branch on a3: nonzero selects the comm/access-mode open path; zero selects the file open path. [source:raw]
    // ASSIGNMENT: Initialize the mode string area v15 from dword_5E5170 with a null terminator (v15[1]=0). [global:0x005E5170]
    // LOOP: Case 2: copy the null-terminated byte string byte_5E5164 into v15. [global:0x005E5164]
    // LOOP: Case 3: copy the null-terminated byte string byte_5E5168 into v15. [global:0x005E5168]
    // LOOP: Case 4: copy the null-terminated byte string byte_5E516C into v15. [global:0x005E516C]
    // GUARD: When this[3] (offset 0xC) equals 1, set the second byte of the mode string (v15 offset 1) to 116 ('t'), marking text mode. [guard:0, field:this:0x0000000C]
    // CALL: Call sub_534B00() to open the serial/comm port using the assembled mode string, storing the resulting handle into this[0] (offset 0x0). [callee:0x00534B00, field:this:0x00000000]
    // CALL: When a3==0 and this[3] (offset 0xC) is nonzero, open the file via sub_587DB0(v16, &unk_5E5174). [callee:0x00587DB0, global:0x005E5174, field:this:0x0000000C]
    // CALL: When a3==0 and this[3] (offset 0xC) is zero, open the file via sub_587DB0(v16, &unk_5E5178). [callee:0x00587DB0, global:0x005E5178, field:this:0x0000000C]
    // ASSIGNMENT: Store the open-call result handle into this[0] (offset 0x0) on the file-open path. [field:this:0x00000000]
    // CALCULATION: Compute v14 = (open result != 0); the success flag mirrors a non-null handle. [source:raw]
    // ASSIGNMENT: On success, zero the byte at this+24 (offset 0x18), clearing the error/status flag. [field:this:0x00000018]
    // CALL: On success, copy the resolved path string v16 into the object's name buffer via StringCopyWithBufferRealloc(this+1, v16). [callee:0x00566650, source:raw]
    // RETURN: Return v14 (open succeeded), or the FileAttributeCheckSequence result when the initial guard failed. [function:0x00566940, callee:0x005668F0]

    // Conservative worker pseudocode:
    //   bool OpenFileOrPortWithMode(int* this, const CHAR* a2, int a3, int a4, char a5)
    //   {
    //       if (a5 != 0 && FileAttributeCheckSequence(a2) == 0)
    //           return false;
    //       this[4] = a3;
    //       this[3] = a4;
    //       sub_568620(1024);
    //       if (a3 != 0)
    //       {
    //           v15[0] = dword_5E5170;
    //           v15[1] = 0;
    //           switch (this[4])
    //           {
    //               case 2: copy byte_5E5164 into v15; break;
    //               case 3: copy byte_5E5168 into v15; break;
    //               case 4: copy byte_5E516C into v15; break;
    //           }
    //           if (this[3] == 1)
    //               v15_byte1 = 116;
    //           this[0] = sub_534B00();
    //       }
    //       else
    //       {
    //           if (this[3])
    //               this[0] = sub_587DB0(v16, &unk_5E5174);
    //           else
    //               this[0] = sub_587DB0(v16, &unk_5E5178);
    //       }
    //       ok = (this[0] != 0);
    //       if (this[0] != 0)
    //       {
    //           *((BYTE*)this + 24) = 0;
    //           StringCopyWithBufferRealloc(this + 1, v16);
    //       }
    //       return ok;
    //   }
    // UNRESOLVED: Semantics of a2 (const CHAR*): consumed only by FileAttributeCheckSequence; it does not contribute to the opened path.
    // UNRESOLVED: Contents of byte_5E5164/5E5168/5E516C mode strings and the dword_5E5170 prefix are not in the packet.
    // UNRESOLVED: Exact open behavior of sub_534B00 (comm/port path) and sub_587DB0 (file path) is unresolved.
    // UNRESOLVED: unk_5E5174 / unk_5E5178 path buffers: their contents and the meaning of the this[3] selection trigger are unresolved.
    // UNRESOLVED: Object layout beyond this[0..4] and +24 is unknown; the name copy target this+1 (offset 0x4) is not represented in the packet field list.
    // UNRESOLVED: Twelve callers place this in the config/IO subsystem, but no specific owning class is established.
}
