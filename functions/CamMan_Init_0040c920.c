int __thiscall sub_40C920(int this)
{
  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_15, 3633) )
    DebugLogWrite(&dword_8AD25C, aEnteredCammanI);
  *(_DWORD *)this = TwoLevelWideStringSearch(aMainview);
  dword_5EA550 = 0;
  dword_5EA554 = 0;
  dword_5EA558 = 0;
  dword_5EA500 = 0;
  dword_5EA504 = 0;
  dword_5EA508 = 0;
  SceneFileLoadByCurrentIndex((_DWORD *)this);
  ModuleAssetPathResolver((_DWORD *)this);
  sub_40C520((_DWORD *)this);
  *(_BYTE *)(this + 45) = 0;
  if ( !sub_40C140((_DWORD *)this) )
    *(_DWORD *)(this + 8) = *(_DWORD *)(this + 24);
  return GlobalFlagSetClear(32, 1);
}
