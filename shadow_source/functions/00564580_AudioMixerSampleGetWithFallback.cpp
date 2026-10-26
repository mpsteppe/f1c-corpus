// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564580
// Canonical corpus name: AudioMixerSampleGetWithFallback
// Owner: AudioMixer [DERIVED]
// Raw source: functions/AudioMixerSampleGetWithFallback_00564580.c

void AudioMixer::AudioMixerSampleGetWithFallback()
{
    // Audio helper that resolves an audio-mixer sample object through a double-call indirection and returns the sample stored at element 1 of the resolved object, falling back to the caller-supplied default value when the indirection returns null.
    // CALL: Call DoubleCallWrapper(a1, a2) to resolve an indirection on the mixer state and keep the returned object pointer. [callee:0x005644F0, source:raw]
    // GUARD: Guard on the resolved pointer: proceed to read the sample only when it is non-null, otherwise take the fallback path. [source:raw]
    // CALL: Read the sample value at element index 1 of the resolved object and return it through sub_58850F. [callee:0x0058850F, source:raw]
    // RETURN: Return the caller-supplied fallback double a3 when the indirection resolves to null. [source:raw]

    // Conservative worker pseudocode:
    //   double AudioMixerSampleGetWithFallback(int a1, int a2, double fallback) {
    //       int* obj = DoubleCallWrapper(a1, a2);
    //       if (obj) return sub_58850F(obj[1]);
    //       return fallback;
    //   }
    // UNRESOLVED: Semantic meaning of the two parameters a1/a2 and of element 1 of the resolved object is not established from the packet alone.
    // UNRESOLVED: Whether sub_58850F reads a global sample buffer or a field of the resolved object is unknown.
}
