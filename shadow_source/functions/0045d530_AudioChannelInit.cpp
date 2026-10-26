// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045D530
// Canonical corpus name: AudioChannelInit
// Owner: AudioChannel [DERIVED]
// Raw source: functions/AudioChannelInit_0045d530.c

void AudioChannel::AudioChannelInit()
{
    // One-time construction of an AudioChannel object (struct size ~112KB). Runs FAILWRONGDESCRIPTION on a sub-object pointer, zeroes and invalidates core handle fields (this+0xB4..0xC0), initializes two arrays of sub-objects (104 elements x 140-byte stride via ThunkToFUN00461480; 104 elements x 872-byte stride via PassthroughWrapper_f670), stores the function/interface pointer off_59F0CC, runs three sub-initializers (WrapperWithConstant, ZeroInit5FloatStruct, StructInitializer_cd50), fills the leading buffer with 0xFFFFFFFF, writes default timing/gain values (1/24 sample-rate divisor, 15.0/15.0 gain pair, 30.0, -1.0 sentinel), zeroes the flag blocks, stores the owner handle from a2 at this+0x0, and returns this.
    // CALL: Runs FAILWRONGDESCRIPTION on a sub-object pointer derived from this (validation/assert hook during construction) [callee:0x00461550, source:raw]
    // ASSIGNMENT: Zeroes this+0xB4 and this+0xBC, sets this+0xB8 and this+0xC0 to the -1 invalid-handle sentinel (this[45..48]) [field:this:0x000000B4, field:this:0x000000B8, field:this:0x000000BC, field:this:0x000000C0]
    // LOOP: Initializes an array of 104 sub-objects, each 140 bytes apart starting from a pointer inside this, via ThunkToFUN00461480 [callee:0x00461470]
    // ASSIGNMENT: Stores the function/interface pointer off_59F0CC into this+0x3FBC and zeroes this+0x3FC0, this+0x3FC8, this+0x3FCC, this+0x3FD0, this+0x3FD4 (this[4079..4085], with 4081 cleared in a later pass) [global:0x0059F0CC, field:this:0x00003FBC, field:this:0x00003FC0, field:this:0x00003FC8, field:this:0x00003FCC, field:this:0x00003FD0, field:this:0x00003FD4]
    // LOOP: Initializes an array of 104 sub-objects, each 872 bytes apart, via PassthroughWrapper_f670 [callee:0x004FF670]
    // CALL: Runs WrapperWithConstant on a sub-object pointer at a large offset inside this [callee:0x0045C750]
    // CALL: Zero-initializes a 5-float sub-struct via ZeroInit5FloatStruct [callee:0x0045C0A0]
    // ASSIGNMENT: Zeroes this+0x1B770 through this+0x1B78C (this[28124..28131]) [field:this:0x0001B770, field:this:0x0001B774, field:this:0x0001B778, field:this:0x0001B77C, field:this:0x0001B780, field:this:0x0001B784, field:this:0x0001B788, field:this:0x0001B78C]
    // CALL: Runs StructInitializer_cd50 on the tail region of this at byte 112528 [callee:0x0045CD50]
    // ASSIGNMENT: Stores the constructor argument a2 (owner handle) into this+0x0 [field:this:0x00000000]
    // ASSIGNMENT: Sets this+0x4 to 1/24 (sample-rate divisor), zeroes this+0x8, sets this+0xC and this+0x10 to 15.0 (default and ceiling gain) [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010]
    // ASSIGNMENT: Zeroes this+0x14, this+0x18, this+0x1C, this+0x20 and this+0x21 (state and flag bytes) [field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000021]
    // ASSIGNMENT: Sets this+0x24 to 30.0, zeroes this+0x28, sets this+0x29 to 1 (enabled flag), sets this+0x2C to -1.0 sentinel, zeroes this+0x30 [field:this:0x00000024, field:this:0x00000028, field:this:0x00000029, field:this:0x0000002C, field:this:0x00000030]
    // ASSIGNMENT: Sets byte this+0xC4 to 1 and zeroes this+0xC5, this+0xC6, this+0xC7 and this+0xC8 [field:this:0x000000C4, field:this:0x000000C5, field:this:0x000000C6, field:this:0x000000C7, field:this:0x000000C8]
    // ASSIGNMENT: Zeroes this+0x11C and this+0x16C, sets this+0x1AC to the -1 invalid-handle sentinel, zeroes this+0x1B0 and this+0x1D0 [field:this:0x0000011C, field:this:0x0000016C, field:this:0x000001AC, field:this:0x000001B0, field:this:0x000001D0]
    // CALL: Fills the leading buffer of this with 0xFFFFFFFF via BufferFillWith0xFFFFFFFF [callee:0x0045E590]
    // ASSIGNMENT: Zeroes this+0x374, this+0x378, this+0x37C, this+0x380, this+0x384, this+0x388, this+0x38C and this+0x390 (byte 884 and this[222..228]) [field:this:0x00000374, field:this:0x00000378, field:this:0x0000037C, field:this:0x00000380, field:this:0x00000384, field:this:0x00000388, field:this:0x0000038C, field:this:0x00000390]
    // ASSIGNMENT: Zeroes this+0x3E14, this+0x3FB8 and this+0x3FC4 (this[3973], this[4078], this[4081]) [field:this:0x00003E14, field:this:0x00003FB8, field:this:0x00003FC4]
    // ASSIGNMENT: Sets byte this+0x3FD8 to 8 and byte this+0x3FD9 to 0 (byte 16344 and byte 16345) [field:this:0x00003FD8, field:this:0x00003FD9]
    // ASSIGNMENT: Zeroes bytes this+0x1B768 through this+0x1B76E (bytes 112488..112494) [field:this:0x0001B768, field:this:0x0001B769, field:this:0x0001B76A, field:this:0x0001B76B, field:this:0x0001B76C, field:this:0x0001B76D, field:this:0x0001B76E]
    // RETURN: Returns this, the fully constructed object [source:raw]

    // Conservative worker pseudocode:
    //   FAILWRONGDESCRIPTION(this + 13);
    //   this[45] = 0; this[46] = -1; this[47] = 0; this[48] = -1;
    //   for (i = 0; i < 104; ++i) ThunkToFUN00461480(&subarray1[i * 140]);
    //   this[4079] = off_59F0CC; this[4080] = 0; this[4082..4085] = 0;
    //   for (i = 0; i < 104; ++i) PassthroughWrapper_f670(&subarray2[i * 872]);
    //   WrapperWithConstant(this + 26864);
    //   ZeroInit5FloatStruct(this + 28117);
    //   this[28124..28131] = 0;
    //   StructInitializer_cd50((byte*)this + 112528);
    //   this[0] = a2; this[2] = 0; this[1] = 1.0 / 24.0;
    //   this[3] = 1097859072; this[4] = 1097859072; this[9] = 1106247680; this[11] = -1082130432;
    //   zero all remaining flag bytes; set enable byte +0x29 to 1; set +0xC4 to 1;
    //   this[107] = -1;
    //   BufferFillWith0xFFFFFFFF(this);
    //   return this;
    // UNRESOLVED: Four read-only globals (flt_59E43C, flt_59F098, dword_59F09C, dword_59F0A4) are flagged by packet facts but appear nowhere in the raw decompiled source; they may be read by the invoked sub-initializers
    // UNRESOLVED: Several callees (FAILWRONGDESCRIPTION, WrapperWithConstant, ZeroInit5FloatStruct, StructInitializer_cd50) are invoked on pointers into sub-regions of this whose base offsets are not represented in the packet field list
    // UNRESOLVED: The two 104-element arrays (140-byte and 872-byte strides) are separate sub-object lists; their element semantics are not defined by this packet
}
