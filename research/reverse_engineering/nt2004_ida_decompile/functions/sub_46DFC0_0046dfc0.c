char __thiscall sub_46DFC0(void *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // esi
  char v5; // bl
  char *v7; // esi
  int v8; // eax
  int v9; // eax
  char v10; // [esp+Fh] [ebp-1h]

  v2 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
  if ( !v2 )
    return 0;
  v3 = *(_DWORD *)(v2 + 28);
  if ( !v3 )
    return 0;
  v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 64))(v3) - (_DWORD)this;
  v10 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 36))(dword_76BB24);
  v5 = 0;
  while ( 1 )
  {
    v4 -= (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)dword_76BB24 + 60))(dword_76BB24, (unsigned __int8)(v10 + v5));
    if ( v4 < 0 )
      break;
    if ( (unsigned __int8)++v5 >= 3u )
      return 0;
  }
  v7 = (char *)(*(int (__thiscall **)(int, _BYTE))(*(_DWORD *)dword_76BB24 + 56))(dword_76BB24, v10 + v5);
  if ( sub_57AE50(aSeasonraces) && sub_57A720(v7) )
  {
    v8 = sub_57A720(aEventname);
    if ( v8 )
    {
      v9 = sub_57A6D0(v8);
      sub_578600(v9);
    }
  }
  return 1;
}
