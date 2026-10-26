// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C5830
// Canonical corpus name: CurrentSceneIndexSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CurrentSceneIndexSetter_004c5830.c

void UnknownObject::setCurrentSceneIndex()
{
    // Stores its argument into the global scene-index dword dword_8AC48C and returns the argument unchanged.
    // ASSIGNMENT: Store argument a1 into global scene-index dword dword_8AC48C at 0x008AC48C. [global:0x008AC48C, function:0x004C5830, source:raw]
    // RETURN: Return a1 unchanged. [function:0x004C5830, source:raw]

    // Conservative worker pseudocode:
    //   int setCurrentSceneIndex(int scene_index)
    //   {
    //       dword_8AC48C = scene_index;
    //       return scene_index;
    //   }
    // UNRESOLVED: Scene-index semantics comes only from the LEGACY ABI lead name; this packet carries no caller context to confirm the field's meaning.
}
