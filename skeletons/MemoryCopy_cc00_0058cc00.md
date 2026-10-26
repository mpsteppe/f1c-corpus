## MemoryCopy_cc00_0058cc00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_58806E (0058806e), sub_5886A7 (005886a7), sub_588C7A (00588c7a), sub_588E4E (00588e4e), sub_58B5D4 (0058b5d4), sub_592DFA (00592dfa), InputStreamReadWithBufferedFill (00598cf9), OutputStreamWriteWithBufferFlushAbstraction (00598d6d), sub_5990AE (005990ae), BufferWriteWithNullTerminate (00599615), BufferAllocationWithSizeRounding (0059964a), sub_59A103 (0059a103), sub_59A9CA (0059a9ca)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x1 | RW | — | [LLM] |
| this | 0x2 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x1: recalc every frame — external poke does NOT persist
- this 0x2: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0058cc60 | byte_58CC60 | R | [LLM] |
| 0058cc70 | loc_58CC70 | R | [LLM] |
| 0058cc9c | loc_58CC9C | R | [LLM] |
| 0058ccc0 | loc_58CCC0 | R | [LLM] |
| 0058ccdc | jpt_58CC5C | R | [LLM] |
| 0058ccfc | loc_58CCFC | R | [LLM] |
| 0058cd04 | loc_58CD04 | R | [LLM] |
| 0058cd0c | loc_58CD0C | R | [LLM] |
| 0058cd14 | loc_58CD14 | R | [LLM] |
| 0058cd1c | loc_58CD1C | R | [LLM] |
| 0058cd24 | loc_58CD24 | R | [LLM] |
| 0058cd2c | loc_58CD2C | R | [LLM] |
| 0058cd3f | loc_58CD3F | R | [LLM] |
| 0058cd48 | jpt_58CC35 | R | [LLM] |
| 0058cd58 | loc_58CD58 | R | [LLM] |
| 0058cd60 | loc_58CD60 | R | [LLM] |
| 0058cd6c | loc_58CD6C | R | [LLM] |
| 0058cd80 | loc_58CD80 | R | [LLM] |
| 0058cde8 | byte_58CDE8 | R | [LLM] |
| 0058cdf8 | byte_58CDF8 | R | [LLM] |
| 0058ce90 | jpt_58CDC2 | R | [LLM] |
| 0058ce94 | loc_58CE94 | R | [LLM] |
| 0058ce9c | loc_58CE9C | R | [LLM] |
| 0058cea4 | loc_58CEA4 | R | [LLM] |
| 0058ceac | loc_58CEAC | R | [LLM] |
| 0058ceb4 | loc_58CEB4 | R | [LLM] |
| 0058cebc | loc_58CEBC | R | [LLM] |
| 0058cec4 | loc_58CEC4 | R | [LLM] |
| 0058ced7 | loc_58CED7 | R | [LLM] |
| 0058cee0 | jpt_58CDE4 | R | [LLM] |
| 0058cef0 | loc_58CEF0 | R | [LLM] |
| 0058cef8 | loc_58CEF8 | R | [LLM] |
| 0058cf08 | loc_58CF08 | R | [LLM] |
| 0058cf1c | loc_58CF1C | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
