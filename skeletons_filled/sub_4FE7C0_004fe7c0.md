## sub_4FE7C0_004fe7c0 — WeatherAudioLoadAndChannelStop

**Summary:** Loads an audio file by resource ID, stops the weather audio channel, and processes the stopped channel data into the caller's float buffer. Returns 0 on success or -1 if the channel stop fails.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCC30 (004fcc30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d173c | aWeather_1 | R | StrWeather [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004fe350 | sub_4FE350 | Process stopped audio channel data into caller's output buffer |
| 00567a00 | StructZeroInit_7a00 | Zero-initialize local audio processing struct |
| 00567a30 | LinkedListDestructorWithInnerFree | Free temporary audio buffer linked list |
| 00567f40 | AudioFileLoadDecode | Load and decode audio file by resource ID |
| 00568210 | AudioChannelStop | Stop the weather audio channel and retrieve channel handle |

**Guard conditions:** None at entry. After AudioChannelStop, return of v3 (channel handle) is checked: non-NULL → process via sub_4FE350, cleanup, return result; NULL → cleanup, return -1.
