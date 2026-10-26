char __thiscall sub_40EE60(void *this, _DWORD *ArgList)
{
  char result; // al
  CHAR *v4; // eax
  __int16 v5; // bx
  signed int v6; // ecx
  const char *v7; // eax
  int v8; // eax
  int *v9; // eax
  int i; // eax
  int v11; // eax
  int *v12; // eax
  int v13; // ecx
  char v14; // [esp-Ch] [ebp-14h]
  char v15; // [esp+0h] [ebp-8h]

  result = 0;
  if ( *ArgList )
  {
    sub_57A400((int)ArgList, aS_5, (char)aParticipant);
    sub_57A400((int)ArgList, asc_5FC03C, v14);
    v4 = *(CHAR **)this;
    if ( !*(_DWORD *)this )
      v4 = &byte_629120;
    sub_57A400((int)ArgList, aVehiclefileS_0, (char)v4);
    if ( *((_BYTE *)this + 32) )
      sub_57A400((int)ArgList, aIsplayer1, v15);
    if ( dword_75CBA8 == 5 )
    {
      v5 = 0;
      if ( (int)NumOfElements > 0 )
      {
        v6 = 0;
        while ( 1 )
        {
          v7 = *(const char **)this;
          if ( !*(_DWORD *)this )
            v7 = &byte_629120;
          v8 = _strcmpi((const char *)(dword_75AAD0[v6] + 24992), v7);
          HIWORD(v6) = 0;
          if ( !v8 )
            break;
          LOWORD(v6) = ++v5;
          if ( v6 >= (int)NumOfElements )
            goto LABEL_15;
        }
        LOWORD(v6) = v5;
        *((_BYTE *)this + 8) = *(_BYTE *)(dword_75AAD0[v6] + 20884);
      }
    }
LABEL_15:
    sub_57A400((int)ArgList, aPlaceD_0, *((_BYTE *)this + 8));
    v9 = (int *)*((_DWORD *)this + 3);
    *((_DWORD *)this + 5) = v9;
    if ( v9 )
    {
      for ( i = *v9; i; i = *v12 )
      {
        sub_414130(i, ArgList);
        v11 = *((_DWORD *)this + 5);
        if ( !v11 )
          break;
        v12 = *(int **)(v11 + 4);
        *((_DWORD *)this + 5) = v12;
        if ( !v12 )
          break;
      }
    }
    v13 = *((_DWORD *)this + 7);
    if ( v13 )
      (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v13 + 60))(v13, ArgList);
    sub_57A400((int)ArgList, asc_5FBF2C, v15);
    return 1;
  }
  return result;
}
