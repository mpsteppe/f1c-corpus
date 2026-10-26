// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00406CC0
// Canonical corpus name: AudioDriverInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioDriverInit_00406cc0.c

void UnknownObject::AudioDriverInit()
{
    // Initializes the Miles Sound System digital audio driver for the audio driver object. Dispatches an init method through the vtable at *this+12, registers callbacks (CallbackRegistration_4ac0), starts Miles (AIL_startup, AIL_set_preference), then selects a sample rate from the selector at this+0x54 (0 -> 11025, 1 -> 22050, otherwise 44100) and opens the digital driver via AIL_open_digital_driver. On success it stores the driver handle at this+0x90, dispatches the vtable method at *this+52 with argument 12, sets the DirectSound HWND, zeroes nine state fields (this+0x58..0x84), installs file callbacks (AIL_set_file_callbacks with ShortComputation_5050 and three literal callback addresses) and sets this+0x88 = 1, returning 0. On failure it clears the handle, dispatches *this+52 with argument 0, calls AIL_shutdown, sets this+0x88 = 0 and returns 1.
    // CALL: Dispatch the vtable init method at *this+12 (method index 3) on the audio driver object. [abi:lead, field:this:0x00000000, field:obj:0x0000000C, source:raw]
    // CALL: CallbackRegistration_4ac0() registers audio callbacks. [callee:0x00534AC0, source:raw]
    // CALL: AIL_startup() boots the Miles Sound System runtime. [global:0x0059E3A0, source:raw]
    // CALL: AIL_set_preference(31, 0) configures Miles preference 31 with value 0. [global:0x0059E39C, source:raw]
    // CALCULATION: Read the sample-rate selector at this+0x54 and map it: 0 -> 11025, 1 -> 22050, otherwise 44100. [field:this:0x00000054, source:raw]
    // CALL: AIL_open_digital_driver(selectedRate, 16, 2, 0) opens the digital driver; the return value becomes the driver handle. [global:0x0059E398, source:raw]
    // ASSIGNMENT: Store the opened driver handle into this+0x90. [field:this:0x00000090, source:raw]
    // GUARD: Branch on the driver handle at this+0x90: non-zero enters the success path, zero enters the shutdown path. [field:this:0x00000090, source:raw]
    // CALL: Success path: dispatch the vtable method at *this+52 (method index 13) with argument 12. [field:obj:0x00000034, field:this:0x00000000, source:raw]
    // CALL: AIL_set_DirectSound_HWND(this+0x90, a2) binds the DirectSound window handle to the driver. [global:0x0059E390, field:this:0x00000090, source:raw]
    // ASSIGNMENT: Zero nine state fields on success: this+0x58, this+0x5C, this+0x60, this+0x70, this+0x74, this+0x78, this+0x7C, this+0x80 and this+0x84. [field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060, field:this:0x00000070, field:this:0x00000074, field:this:0x00000078, field:this:0x0000007C, field:this:0x00000080, field:this:0x00000084, source:raw]
    // CALL: AIL_set_file_callbacks(ShortComputation_5050, 4215040, 4215136, 4215424) installs the file I/O callback set (one named pointer plus three literal callback addresses). [global:0x00405050, global:0x0059E3E4, source:raw]
    // ASSIGNMENT: Mark the driver initialized: set this+0x88 = 1 on success. [field:this:0x00000088, source:raw]
    // RETURN: Return 0 on the success path. [function:0x00406CC0, source:raw]
    // GUARD: Failure path: the driver handle at this+0x90 is zero. [field:this:0x00000090, source:raw]
    // ASSIGNMENT: Clear the driver handle: this+0x90 = 0. [field:this:0x00000090, source:raw]
    // CALL: Dispatch the vtable method at *this+52 (method index 13) with argument 0 to tear down the failed driver. [field:obj:0x00000034, field:this:0x00000000, source:raw]
    // CALL: AIL_shutdown() shuts down the Miles Sound System runtime. [global:0x0059E394, source:raw]
    // ASSIGNMENT: Clear the initialized flag: this+0x88 = 0 on failure. [field:this:0x00000088, source:raw]
    // RETURN: Return 1 on the failure path. [function:0x00406CC0, source:raw]

    // Conservative worker pseudocode:
    //   int AudioDriverInit(void* this, int a2) {
    //     ((void (__thiscall*)(void*))((*(int**)this)[3]))(this);           // *this+12 init method
    //     CallbackRegistration_4ac0();
    //     AIL_startup();
    //     AIL_set_preference(31, 0);
    //     int sel = *(int*)((char*)this + 0x54);                            // sample-rate selector
    //     int rate = sel ? (sel != 1 ? 44100 : 22050) : 11025;
    //     int hdr = AIL_open_digital_driver(rate, 16, 2, 0);
    //     *(int*)((char*)this + 0x90) = hdr;                                // driver handle
    //     if (hdr) {
    //       ((void (__thiscall*)(void*, int))((*(int**)this)[13]))(this, 12); // *this+52 method
    //       AIL_set_DirectSound_HWND(hdr, a2);
    //       for (off in {0x58, 0x5C, 0x60, 0x70, 0x74, 0x78, 0x7C, 0x80, 0x84}) *(int*)((char*)this+off) = 0;
    //       AIL_set_file_callbacks(ShortComputation_5050, 4215040, 4215136, 4215424);
    //       *(int*)((char*)this + 0x88) = 1;
    //       return 0;
    //     }
    //     *(int*)((char*)this + 0x90) = 0;
    //     ((void (__thiscall*)(void*, int))((*(int**)this)[13]))(this, 0);   // *this+52 method
    //     AIL_shutdown();
    //     *(int*)((char*)this + 0x88) = 0;
    //     return 1;
    //   }
    // UNRESOLVED: The three literal callback addresses passed to AIL_set_file_callbacks (4215040, 4215136, 4215424) are preserved as decimals per the packet; they have no named evidence refs.
    // UNRESOLVED: The semantic role of the nine zeroed state fields (this+0x58..0x84) and of the flag this+0x88 is not established by the packet alone.
    // UNRESOLVED: The vtable methods at *this+12 and *this+52 are unnamed; their exact behavior is not established.
}
