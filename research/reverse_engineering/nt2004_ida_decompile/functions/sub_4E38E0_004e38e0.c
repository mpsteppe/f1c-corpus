char __thiscall sub_4E38E0(char *this, _DWORD *ArgList, char *Buffer)
{
  CHAR *v4; // eax
  CHAR *v5; // eax
  CHAR *v6; // eax
  CHAR *v7; // eax
  int v8; // edi
  int *v9; // ebx
  char v11; // [esp-2Ch] [ebp-34h]

  if ( *ArgList )
  {
    if ( Buffer )
    {
      sub_57A4C0(Buffer);
      sub_57A4C0(asc_5FB9D8);
    }
    v4 = *(CHAR **)this;
    if ( !*(_DWORD *)this )
      v4 = &byte_629120;
    sub_57A400((int)ArgList, aNameS, (char)v4);
    v5 = (CHAR *)*((_DWORD *)this + 2);
    if ( !v5 )
      v5 = &byte_629120;
    sub_57A400((int)ArgList, aVehfileS, (char)v5);
    v6 = (CHAR *)*((_DWORD *)this + 4);
    if ( !v6 )
      v6 = &byte_629120;
    sub_57A400((int)ArgList, aModfileS, (char)v6);
    v7 = (CHAR *)*((_DWORD *)this + 6);
    if ( !v7 )
      v7 = &byte_629120;
    sub_57A400((int)ArgList, aRcdfileS, (char)v7);
    v8 = 0;
    v9 = (int *)(this + 224);
    do
    {
      if ( *v9 >= 0 )
      {
        sub_57A400((int)ArgList, aFinishresult22, v8);
        sub_57A400((int)ArgList, aFinishposition_0, v8);
        sub_57A400((int)ArgList, aFinishpoints22, v8);
      }
      ++v8;
      ++v9;
    }
    while ( v8 < 48 );
    sub_57A400((int)ArgList, aSeasonpointsD, *((_DWORD *)this + 152));
    sub_57A400((int)ArgList, aPointsposition_0, *((_DWORD *)this + 153));
    sub_57A400((int)ArgList, aPolestakenD, *((_DWORD *)this + 154));
    sub_57A400((int)ArgList, aLapsleadD, *((_DWORD *)this + 155));
    sub_57A400((int)ArgList, aLapscompletedD, *((_DWORD *)this + 156));
    sub_57A400((int)ArgList, aOriginalgridpo_0, *((_DWORD *)this + 157));
    sub_57A400((int)ArgList, aCurrentgridpos_0, *((_DWORD *)this + 158));
    sub_57A400((int)ArgList, aControltypeD, *((_DWORD *)this + 159));
    sub_57A400((int)ArgList, aActiveD, this[640] != 0);
    sub_57A400((int)ArgList, asc_5FB9D8, v11);
  }
  return 0;
}
