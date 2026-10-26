## CommandDispatchStateMachine_0051126a — JPEG marker dispatch state machine

**Summary:** Main JPEG marker parsing dispatcher. Reads the next marker from the stream using byte-stuffing-aware (BitstreamTokenReader) or raw (JPEGMarkerReader) mode based on a flag. Dispatches to specialized parsers based on the marker value (192-255 = standard JPEG markers; 1, 208-215 = special; 224-239 = APP via function table; 254 = COM handler).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | vtable base for state dispatcher (vfunc 0 for error/state 59, 67) |
| obj | 0x4 | R | — | second vtable entry for parameterized dispatch (state 84, 91) |
| obj | 0x14 | RW | 84 | state code — set per dispatch (52, 59, 67, 84, 91) |
| obj | 0x18 | RW | — | marker byte value passed to dispatch |
| this | 0x0 | R | — | pointer to state dispatcher object |
| this | 0x178 | RW | 0 | current marker byte — 0 triggers reading next marker; set by reader functions |
| this | 0x190 | R | — | pointer to dispatch table base for markers 224-239 (APP markers) |
| this | 0x19C | R | — | function pointer for marker 254 (COM handler, at *(this+0x190+12)) |
| this | 0x1E0 | R | — | byte-stuffing mode flag (at *(this+0x190+80)) — selects BitstreamTokenReader vs JPEGMarkerReader |

**Written-by note (persistence):**
- obj 0x14: written each dispatch call
- obj 0x18: written with current marker byte
- this 0x178: reset to 0 after each dispatch (triggers next marker read on next call)

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050ff84 | sub_50FF84 | SOI (marker 216) handler — context initialization |
| 00510012 | ImageFormatStreamDecoder | SOF0/SOF1/SOF2 (markers 192-194, 201-202) handler — image frame decoder |
| 0051030d | sub_51030D | SOS (marker 218) handler — start of scan/command parser |
| 00510975 | sub_510975 | marker 204 handler — byte pair parser with nibble store |
| 00510acc | sub_510ACC | DHT (marker 196) handler — Huffman table definition parser |
| 00510d60 | MP3HuffmanDecoder | DQT (marker 219) handler — quantization table parser |
| 00510f89 | StreamRead2ByteTokenParser | DRI (marker 221) handler — restart interval token reader |
| 00511060 | StreamingDataReader | DNL (marker 220) handler — segment size reader with skip |
| 005110fc | BitstreamTokenReader | reads next marker from byte-stuffed stream (used when stuffing flag set) |
| 005111d3 | JPEGMarkerReader | reads next raw marker from stream (used when stuffing flag clear) |

**Guard conditions:** Marker value dispatch is a multi-way switch. Key guards: this+0x178 must be 0 to trigger marker read; otherwise re-dispatch same marker. BitstreamTokenReader used when *(this+0x190+80) flag is set; JPEGMarkerReader when clear. Marker > 207 breaks out of the main loop to a secondary dispatch section. Markers 205-207, 203, 197-200, 195, 0, 2-191 go to error states (59 or 67). Markers 222-223, 240-253, 255 also go to unknown state 67.
