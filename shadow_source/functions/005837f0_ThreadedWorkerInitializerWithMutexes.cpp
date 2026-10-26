// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005837F0
// Canonical corpus name: sub_5837F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5837F0_005837f0.c

void UnknownObject::ThreadedWorkerInitializerWithMutexes()
{
    // Constructor-style initializer for a large threaded worker object. Fills a vtable pointer, installs a timed callback loop with a mutex pair, zero-initializes several structures, creates an array of quad-buffers each guarded by its own Win32 mutex, sets timing/configuration fields from a config object a2, and self-links this[336] to this. Also installs the SEH frame and the nested object init with vtable setup.
    // CALL: Install a timed callback loop with SEH on (this + 1), count 40, interval 1, using MutexPairInitializer and CloseHandlePairWrapper as the mutex pair callbacks. [callee:0x0058A6EB, global:0x00585EA0, global:0x00583AA0, source:raw]
    // CALL: Zero-initialize a structure at (this + 11). [callee:0x0057A020, source:raw]
    // ASSIGNMENT: Copy a 16-bit configuration value from a2 + 10 into this[32] (byte offset 0x80). [field:this:0x00000080, source:raw]
    // CALL: Initialize a timer with SEH handling at (this + 33). [callee:0x005835F0, source:raw]
    // ASSIGNMENT: Reset worker state: this[53] = 0, byte at offset 220 cleared, this[54] = -1. [field:this:0x000000D4, field:this:0x000000DC, field:this:0x000000D8, source:raw]
    // CALL: Create the first mutex with error handling on the timer block at (this + 33). [callee:0x005862C0, source:raw]
    // ASSIGNMENT: Reset worker state: this[60] = 0, byte at offset 248 cleared, this[61] = -1. [field:this:0x000000F0, field:this:0x000000F8, field:this:0x000000F4, source:raw]
    // CALL: Create/recreate a mutex (default block). [callee:0x00586500, source:raw]
    // ASSIGNMENT: Zero this[63] through this[66] (offsets 0xFC, 0x100, 0x104, 0x108). [field:this:0x000000FC, field:this:0x00000100, field:this:0x00000104, field:this:0x00000108, source:raw]
    // CALL: Quad-zero-initialize the first quad-buffer at (this + 67). [callee:0x004BA820, source:raw]
    // ASSIGNMENT: Zero this[71] through this[74] (offsets 0x11C, 0x120, 0x124, 0x128). [field:this:0x0000011C, field:this:0x00000120, field:this:0x00000124, field:this:0x00000128, source:raw]
    // CALL: Initialize a buffered character I/O structure at (this + 75). [callee:0x005876F0, source:raw]
    // CALL: Quad-zero-initialize the first mutex-protected buffer at (this + 337); reset this[341] = 0, byte at offset 1372 cleared, this[342] = -1. [callee:0x004BA820, field:this:0x00000554, field:this:0x0000055C, field:this:0x00000558, source:raw]
    // CALL: Create a Win32 mutex for the buffer at (this + 337). [callee:0x00582360, source:raw]
    // CALL: Quad-zero-initialize the buffer at (this + 344); reset this[348] = 0, byte at offset 1400 cleared, this[349] = -1. [callee:0x004BA820, field:this:0x00000570, field:this:0x00000578, field:this:0x00000574, source:raw]
    // CALL: Create a Win32 mutex for the buffer at (this + 344). [callee:0x00582360, source:raw]
    // CALL: Quad-zero-initialize the buffer at (this + 351); reset this[355] = 0, byte at offset 1428 cleared, this[356] = -1. [callee:0x004BA820, field:this:0x0000058C, field:this:0x00000594, field:this:0x00000590, source:raw]
    // CALL: Create a Win32 mutex for the buffer at (this + 351). [callee:0x00582360, source:raw]
    // CALL: Quad-zero-initialize the buffer at (this + 358); reset this[362] = 0, byte at offset 1456 cleared, this[363] = -1. [callee:0x004BA820, field:this:0x000005A8, field:this:0x000005B0, field:this:0x000005AC, source:raw]
    // CALL: Create a Win32 mutex for the buffer at (this + 358). [callee:0x00582360, source:raw]
    // ASSIGNMENT: Reset worker state: this[365] = 0, this[366] = 0, byte at offset 1472 cleared, this[367] = -1. [field:this:0x000005B4, field:this:0x000005B8, field:this:0x000005C0, field:this:0x000005BC, source:raw]
    // CALL: Create/recreate a mutex (default block). [callee:0x00586500, source:raw]
    // ASSIGNMENT: Reset worker state: this[369] = 0, byte at offset 1480 cleared. [field:this:0x000005C4, field:this:0x000005C8, source:raw]
    // ASSIGNMENT: Reset worker state: this[390] = 0, byte at offset 1568 cleared, this[391] = -1. [field:this:0x00000618, field:this:0x00000620, field:this:0x0000061C, source:raw]
    // CALL: Create/replace a mutex (default block). [callee:0x00586560, source:raw]
    // CALL: Initialize an object with vtable setup, passing -1, 255, 0. [callee:0x00587030, source:raw]
    // ASSIGNMENT: Reset worker state: this[400] = 0, byte at offset 1608 cleared, this[401] = -1. [field:this:0x00000640, field:this:0x00000648, field:this:0x00000644, source:raw]
    // CALL: Create a mutex via the Win32 API at (this + 393). [callee:0x005865C0, source:raw]
    // CALL: Large zero-initialization of a structure at (this + 404). [callee:0x005836A0, source:raw]
    // ASSIGNMENT: Set the vtable pointer: *this = off_5B8B60. [field:this:0x00000000, global:0x005B8B60, source:raw]
    // ASSIGNMENT: Set enable/state flags: byte at offset 92 = 0, byte at offset 93 = 1, this[24] = 64 (capacity), byte at offset 100 = 0. [field:this:0x0000005C, field:this:0x0000005D, field:this:0x00000060, field:this:0x00000064, source:raw]
    // ASSIGNMENT: Copy configuration: this[30] = *(a2 + 4), this[31] = 0. [field:this:0x00000078, field:this:0x0000007C, source:raw]
    // CALL: Lock the timer mutex with success check, apply a timing float value 0 via FloatSetWithTimingCall, then release the mutex. [callee:0x00585F60, callee:0x00583660, callee:0x00585F90, source:raw]
    // ASSIGNMENT: Set timing/state fields: this[56] = 0, this[57] = 1090021888 (7.7629f), this[58] = 1119092736 (90.0f). [field:this:0x000000E0, field:this:0x000000E4, field:this:0x000000E8, source:raw]
    // ASSIGNMENT: Self-link and final state: this[336] = this (self-reference), this[403] = 750. [field:this:0x00000540, field:this:0x0000064C, source:raw]
    // RETURN: Return this as the initialized object. [source:raw, function:0x005837F0, caller:0x0057BA10]

    // Conservative worker pseudocode:
    //   Worker* WorkerCtor(Worker* this, Config* a2, int a3) {
    //     InstallTimedCallbackLoop(this + 1, 40, 1, MutexPairInitializer, CloseHandlePairWrapper);
    //     StructZero(this + 11);
    //     this[32] = *(u16*)((char*)a2 + 10);
    //     TimerInit(this + 33);
    //     this[53] = 0; ((char*)this)[220] = 0; this[54] = -1;
    //     MutexCreate(this + 33);
    //     this[60] = 0; ((char*)this)[248] = 0; this[61] = -1;
    //     MutexCreate();
    //     this[63] = this[64] = this[65] = this[66] = 0;
    //     QuadZero(this + 67);
    //     this[71] = this[72] = this[73] = this[74] = 0;
    //     BufferedCharIOInit(this + 75);
    //     for (buf = 337; buf <= 358; buf += 7) { QuadZero(this + buf); MutexCreate(this + buf); }
    //     this[365] = 0; this[366] = 0; ((char*)this)[1472] = 0; this[367] = -1;
    //     MutexCreate();
    //     this[369] = 0; ((char*)this)[1480] = 0;
    //     this[390] = 0; ((char*)this)[1568] = 0; this[391] = -1;
    //     MutexCreateReplace();
    //     ObjectInit(-1, 255, 0);
    //     this[400] = 0; ((char*)this)[1608] = 0; this[401] = -1;
    //     CreateMutex(this + 393);
    //     LargeZero(this + 404);
    //     this->vtable = off_5B8B60;
    //     ((char*)this)[92] = 0; ((char*)this)[93] = 1; this[24] = 64; ((char*)this)[100] = 0;
    //     this[30] = *(int*)a2; this[31] = 0;
    //     MutexLock(this + 33); FloatSet(0); MutexUnlock(this + 33);
    //     this[56] = 0; this[57] = 1090021888; this[58] = 1119092736;
    //     this[336] = this;
    //     this[403] = 750;
    //     return this;
    //   }
    // UNRESOLVED: The a3 argument is unused by the shown body.
    // UNRESOLVED: dword_5B8B5C is read by the packet but does not appear in the decompiled body; its role is unknown.
    // UNRESOLVED: The SEH handler SEH_5837F0 wraps the timed callback setup; exact exception semantics unknown.
    // UNRESOLVED: Exact thread execution model of the quad-buffer/mutex array (which buffer feeds which consumer) is caller-driven.
}
