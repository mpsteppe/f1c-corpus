int __thiscall sub_40C140(_DWORD *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  char *v4; // eax
  char *v5; // edx
  char v6; // cl
  char v8[512]; // [esp+10h] [ebp-200h] BYREF

  if ( !this[6] )
  {
    v2 = (_DWORD *)OperatorNewNhMallocWrapper(84);
    if ( v2 )
      v3 = ShortComputation_84b0(v2);
    else
      v3 = 0;
    this[6] = v3;
  }
  PathTruncationUtility(v8, 512);
  strcat(v8, aCamsCfg);
  if ( (*(int (__thiscall **)(_DWORD, char *))(*(_DWORD *)this[6] + 4))(this[6], v8) )
  {
    v4 = (char *)dword_5EC440;
    if ( !dword_5EC440 )
      v4 = &byte_5EA438;
    v5 = (char *)(v8 - v4);
    do
    {
      v6 = *v4;
      v4[(_DWORD)v5] = *v4;
      ++v4;
    }
    while ( v6 );
    strcat(v8, aDefaultCfg);
    if ( (*(int (__thiscall **)(_DWORD, char *))(*(_DWORD *)this[6] + 4))(this[6], v8) )
      F_3DTransformObjectAllocator((_DWORD *)this[6]);
  }
  GameStateBranchDispatch(this);
  return 0;
}
