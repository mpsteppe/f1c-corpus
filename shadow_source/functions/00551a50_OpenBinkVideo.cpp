// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00551A50
// Canonical corpus name: sub_551A50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_551A50_00551a50.c

void UnknownObject::OpenBinkVideo()
{
    // Opens a Bink video file (.bik). Copies the requested file name, normalizes it, and appends the .bik extension when missing; selects the Bink sound system (Miles for flag bit 1, DirectSound for flag bit 2) when a sound device is supplied, otherwise clears the sound track; builds the BinkOpen flag word from flag bits; opens the file directly and, on failure, retries through registered media directories. On success stores the Bink handle and the video width and height from BinkGetSummary and returns 0; otherwise reports the Bink error and returns -1.
    // CALCULATION: Copy the requested file name a2 into the local SrcStr buffer and normalize it via sub_589901. [callee:0x00589901, source:raw]
    // GUARD: If sub_587C20 reports that SrcStr does not already carry the extension stored at aBik, append the 4-byte extension text from aBik plus its trailing byte aBik[4] (byte_5DC0BC) at the end of SrcStr. [callee:0x00587C20, global:0x005DC0B8, global:0x005DC0BC, source:raw]
    // CALL: When flag bit 1 is set and the sound device a4 is non-null, register the Miles sound system via BinkSetSoundSystem(BinkOpenMiles, a4); on failure obtain the error text with BinkGetError, format the Miles-sound error message with StringFormatWithBufferOverflowCheck, report it through sub_53C590 and return -1. [global:0x0059E358, global:0x0059E354, global:0x0059E35C, global:0x005DC070, callee:0x0058815F, callee:0x0053C590, source:raw]
    // CALL: When flag bit 2 is set and the sound device a4 is non-null, register the DirectSound system via BinkSetSoundSystem(BinkOpenDirectSound, a4); on failure obtain the error text with BinkGetError, format the DirectSound error message with StringFormatWithBufferOverflowCheck, report it through sub_53C590 and return -1. [global:0x0059E358, global:0x0059E360, global:0x0059E35C, global:0x005DC094, callee:0x0058815F, callee:0x0053C590, source:raw]
    // CALL: When neither sound flag applies, clear the Bink sound track with BinkSetSoundTrack(0, 0) and seed the BinkOpen flag word with 0x4000. [global:0x0059E364, source:raw]
    // CALCULATION: Build the BinkOpen flag word from flag bits: with bit 0x10 set, add 0x60000000 plus 0x30000000 when bit 2 is set, with bit 3 adjusting the word via the 0x8FFFFFFF/0x9FFFFFFF masks to 0x20000000 or 0x50000000; without bit 0x10, add 0x30000000, 0x10000000 or 0x40000000 (mask-clearing 0x8FFFFFFF when combining 0x40000000). [source:raw]
    // CALL: Open the video directly with BinkOpen(SrcStr, flag word) and store the returned handle into the handle field this+0x0. [global:0x0059E368, field:this:0x00000000, source:raw]
    // GUARD: If the direct open failed, iterate the registered media directories: format the directory path with StringFormatWithBufferOverflowCheck using the aSS_3 path format, walking the directory table at byte_8B5A3C in 132-byte steps, and call BinkOpen on each candidate path, updating this+0x0, until one succeeds or dword_8B8E30 directories have been tried. [global:0x0059E368, global:0x005C2D64, global:0x008B5A3C, global:0x008B8E30, callee:0x0058815F, field:this:0x00000000, source:raw]
    // CALL: On a successful open, call BinkGetSummary(handle, summary buffer) and copy the summary width into this+0x8 and the height into this+0xC. [global:0x0059E350, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // RETURN: Return 0 on success; if every open attempt failed, obtain the error text with BinkGetError, format the Bink-file error message with StringFormatWithBufferOverflowCheck, report it through sub_53C590 and return -1. [global:0x005DC054, global:0x0059E35C, callee:0x0058815F, callee:0x0053C590, source:raw]

    // Conservative worker pseudocode:
    //   SrcStr = normalize(copy(a2)); if no extension from aBik: append it;
    //   if (bit1 && a4) BinkSetSoundSystem(BinkOpenMiles, a4) else if (bit2 && a4) BinkSetSoundSystem(BinkOpenDirectSound, a4) else BinkSetSoundTrack(0, 0), flags |= 0x4000;
    //   flags = build from bits 0x10 / 4 / 8 (masks 0x10000000..0x60000000);
    //   h = BinkOpen(SrcStr, flags);
    //   if (!h) for dir in directory table: h = BinkOpen("%s\\%s"(dir, SrcStr), flags);
    //   if (h) { BinkGetSummary(h, summary); this.width = summary[0]; this.height = summary[1]; return 0; }
    //   else { log("Error: %s for BINK file %s", BinkGetError()); return -1; }
    // UNRESOLVED: The exact mapping of aErrorSWhileSet_0 (0x005DC070) versus aErrorSWhileSet (0x005DC094) to the Miles versus DirectSound error branch cannot be determined from the packet; both are treated as the two sound-setup error format strings.
    // UNRESOLVED: aSS_3 (0x005C2D64) is used here as the directory path format string, which conflicts with the packet's existing-analysis label 'Session config file path string'; the format-string interpretation is DERIVED from the raw call.
    // UNRESOLVED: The Bink imports (_BinkGetSummary@8 and so on) are Bink runtime exports whose precise prototypes are not evidenced in the packet.
}
