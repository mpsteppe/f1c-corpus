int __thiscall sub_455D50(float *this)
{
  if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(2, aDDevF119992002_13, 5258) )
    DebugLogWrite(&dword_8AD25C, aEnteredHwinput_1);
  AudioSceneUpdateLoop(this);
  GlobalStateInitializerWithEnumValues((int *)this);
  return CameraViewportConfigBatch(this);
}
