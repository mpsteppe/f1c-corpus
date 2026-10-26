// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052A5A8
// Canonical corpus name: ArithmeticComparison_a5a8
// Owner: AudioCodecBasePointerProvider [DERIVED]
// Raw source: functions/ArithmeticComparison_a5a8_0052a5a8.c

void AudioCodecBasePointerProvider::GetAudioCodecBasePointers()
{
    // Reads four global base pointers (dword_5D9418, dword_5D941C, unk_5D9420, unk_5DA420) into the four caller-provided output parameters and returns 0. Called during audio codec initialization by sub_527752 to expose internal base addresses.
    // ASSIGNMENT: Write dword_5D9418 (audio decode table base) to output parameter *a1. [global:0x005D9418, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write dword_5D941C (second global base pointer) to output parameter *a2. [global:0x005D941C, source:raw]
    // ASSIGNMENT: Write the address of unk_5D9420 (third global base) to output parameter *a3. [global:0x005D9420, source:raw]
    // ASSIGNMENT: Write the address of unk_5DA420 (fourth global base) to output parameter *a4. [global:0x005DA420, source:raw]
    // RETURN: Return 0 (success/no error). [source:raw]
    // CALL: Consumed by caller sub_527752 as part of audio codec initialization. [caller:0x00527752]

    // Conservative worker pseudocode:
    //   *a1 = dword_5D9418;
    //   *a2 = dword_5D941C;
    //   *a3 = &unk_5D9420;
    //   *a4 = &unk_5DA420;
    //   return 0;
    // UNRESOLVED: Semantics of the four returned globals (decode table, heap, atlas, buffer) are inferred from the caller and not directly evidenced.
    // UNRESOLVED: The object that owns the four globals is not identified.
}
