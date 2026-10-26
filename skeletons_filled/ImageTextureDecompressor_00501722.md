## ImageTextureDecompressor_00501722 — ImageTextureDecompressor

**Summary:** State-machine-driven image texture decompressor. Decodes streaming texture data via setjmp/longjmp error recovery. Handles format 50 (raw RGBA copy) and format 22 (24-bit RGB unpacked from 16-bit RGB565 source). Allocates output pixel buffer on decode.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXSurfaceFormatNegotiation (00502a15)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 22 | Decoded texture format ID (22=RGB unpack, 50=raw RGBA) |
| this | 0x4 | RW | — | Output pixel data buffer (allocated on decode) |
| this | 0xC | RW | — | Width in pixels |
| this | 0x10 | RW | — | Height in pixels |
| this | 0x14 | RW | 1 | Direction/orientation flag |
| this | 0x30 | RW | — | Row stride in bytes |
| this | 0x34 | RW | 0 | Zero-initialized field |
| this | 0x38 | RW | 1 | Pixel ownership flag (1=owns allocated buffer) |
| this | 0x40 | R | — | Palette flag (0 = allocate and decode; non-zero = skip pixel decode) |

**Written-by note (persistence):**
- this 0x0: Written once per call to format ID (22 or 50)
- this 0x4: Written once per call to allocated pixel buffer
- this 0xC: Written once per call to decoded width
- this 0x10: Written once per call to decoded height
- this 0x14: Written once per call to constant 1
- this 0x30: Written once per call to computed row stride
- this 0x34: Written once per call to constant 0
- this 0x38: Written once per call to constant 1

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005016e0 | VTableDispatchWithLongjmp | R | Error recovery via longjmp (set in vtable) |
| 005016fc | loc_5016FC | R | Code label address used as function pointer in vtable |
| 00501711 | BufferPointerAdjust | R | Buffer read pointer advance function |
| 005114d5 | AudioVideoDecodeSubbandLoop | R | Subband decode loop for audio/video stream |
| 00511686 | VtableDispatchThunk | R | Dispatch thunk for vtable-based state machine |
| 0051dfca | nullsub_4 | R | No-op stub function (default vtable entry) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050f632 | sub_50F632 | Initialize state machine context buffer |
| 0050f6f2 | VTableDtorNullFields | Cleanup/destroy vtable dispatch context |
| 0050f904 | StateMachineDispatcher | Run state machine dispatch step |
| 0050f9ab | StateMachineDispatch_f9ab | Dispatch initial state machine setup |
| 0050fab7 | StreamBufferReadStateMachine | Read streaming data into decode buffer |
| 0050fb3b | StateMachineWithDispatch | Run state machine with dispatch table |
| 0050fc7d | sub_50FC7D | Check decode condition (determines pixel format path) |
| 0051177c | sub_51177C | Initialize vtable dispatch structure |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate pixel output buffer |
| 0058a7ec | Setjmp3MSVCJmpBufSave | Save setjmp buffer for error recovery |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 22 | Decode format 22: unpack 24-bit RGB from 16-bit source |
| this | 0x0 | == | 50 | Decode format 50: raw RGBA data copy |
| this | 0x40 | == | 0 | Palette flag: if zero, allocate output buffer and decode pixels |

**Guard interpretation:** If state machine result (v28) == 1 → set format to 50 and store width/height. If result == 3 → set format to 22 with stride = 4*width. In common decode block: if this+0x40 == 0, allocate output and decode. Within decode: format 50 → raw memcpy rows; format 22 → unpack 3 bytes (R/G/B) from 2-byte source per pixel.
