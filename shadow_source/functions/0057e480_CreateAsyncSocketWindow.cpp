// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057E480
// Canonical corpus name: sub_57E480
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57E480_0057e480.c

void UnknownObject::CreateAsyncSocketWindow()
{
    // Lazily creates the hidden window used for async socket message dispatching. If the cached window handle dword_8D3E28 is already non-zero, returns true immediately. Otherwise zero-fills a local WNDCLASSA, registers a class whose window procedure is WindowProcIgnore6666 with the hInstance read from this+0x774, then calls CreateWindowExA to build an off-screen 1x1 window (style 0x8000000, off-screen origin 0x80000000) and stores the resulting handle in dword_8D3E28. Returns whether that handle is non-zero.
    // GUARD: Guard: if the cached window handle global dword_8D3E28 is already non-zero, return true without creating a new window. [global:0x008D3E28, source:raw]
    // ASSIGNMENT: Zero-initialize the local WNDCLASSA struct. [source:raw]
    // ASSIGNMENT: Read the HINSTANCE from this+0x774 for use in the window class and window creation. [field:this:0x00000774, source:raw]
    // ASSIGNMENT: Fill the WNDCLASSA: style 3, lpfnWndProc = WindowProcIgnore6666, hInstance from this+0x774, no menu name, class name lpClassName. [global:0x0057AEA0, global:0x005E5374, source:raw]
    // CALL: Register the window class via RegisterClassA. [global:0x0059E29C, source:raw]
    // CALL: Create the off-screen window via CreateWindowExA with extended style 0, class lpClassName, title lpWindowName, style 0x8000000, position (0x80000000, 0x80000000), size 1x1, no owner/parent/menu, hInstance from this+0x774; store the returned handle into dword_8D3E28. [global:0x0059E290, global:0x005E5374, global:0x005E5378, global:0x008D3E28, field:this:0x00000774, source:raw]
    // RETURN: Return (dword_8D3E28 != 0). Invoked by sub_57BA10. [global:0x008D3E28, caller:0x0057BA10, function:0x0057E480, source:raw]

    // Conservative worker pseudocode:
    //   bool CreateAsyncSocketWindow(void* self) {
    //     if (dword_8D3E28 != 0) return true;
    //     WNDCLASSA wc = {0};
    //     wc.style = 3;
    //     wc.lpfnWndProc = WindowProcIgnore6666;
    //     wc.hInstance = self->hInstance; // +0x774
    //     wc.lpszMenuName = 0;
    //     wc.lpszClassName = lpClassName;
    //     RegisterClassA(&wc);
    //     dword_8D3E28 = CreateWindowExA(0, lpClassName, lpWindowName, 0x8000000,
    //                                     0x80000000, 0x80000000, 1, 1, 0, 0, self->hInstance, 0);
    //     return dword_8D3E28 != 0;
    //   }
    // UNRESOLVED: Five write-only globals byte_FF00000000005445/05446/05449/0544D/0544E are flagged by packet facts but absent from the raw source; their addresses look like malformed 64-bit artifacts and are unverifiable from this packet.
    // UNRESOLVED: The handling of message 0x6666 inside WindowProcIgnore6666 is external to this function and unknown here.
}
