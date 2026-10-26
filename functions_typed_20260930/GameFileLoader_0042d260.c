int __thiscall sub_42D260(char *this)
{
  char *v2; // eax
  CHAR Filename[256]; // [esp+0h] [ebp-100h] BYREF

  if ( GetModuleFileNameA(0, Filename, 0x100u) )
    UtilityFunction_8a60(7, this + 28);
  v2 = (char *)dword_5EC408;
  if ( !dword_5EC408 )
    v2 = &byte_5EA438;
  sub_423890((int *)byte_5EC4C0, (int)v2, 0);
  RandomNoiseTableInitialization(&dword_8AAE70);
  TireBrandLoader(&dword_8AD254);
  SceneFileLoader(&unk_8AC368);
  if ( dword_8AC488 <= 0 )
  {
    if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_11, 326) )
      DebugLogWrite(&dword_8AD25C, aNoSceneFilesFo);
    return 1;
  }
  VehicleFileLoader(&unk_8AC388);
  if ( dword_8AC390 <= 0 )
  {
    if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_11, 335) )
      DebugLogWrite(&dword_8AD25C, aNoVehicleFiles);
    return 1;
  }
  return 0;
}

