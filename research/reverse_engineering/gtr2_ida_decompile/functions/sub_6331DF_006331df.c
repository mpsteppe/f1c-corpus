_BYTE *__cdecl sub_6331DF(_BYTE *a1, char *a2)
{
  unsigned int v2; // kr00_4
  int v3; // eax
  char v5; // dl
  _BYTE *v6; // edx
  _BYTE *v7; // ebx
  int v9; // [esp+0h] [ebp-28h]
  _BYTE v10[32]; // [esp+4h] [ebp-24h] BYREF
  int v11; // [esp+24h] [ebp-4h]

  v2 = __readeflags();
  v3 = *(_DWORD *)__ROL4__(dword_16C6D40, loc_482B38);
  __writeeflags(v2);
  v11 = v3;
  v9 = _getptd();
  memset(v10, 0, sizeof(v10));
  do
  {
    v5 = *a2;
    v10[(unsigned __int8)*a2 >> 3] |= 1 << (*a2 & 7);
    ++a2;
  }
  while ( v5 );
  v6 = a1;
  if ( !a1 )
    v6 = *(_BYTE **)(v9 + 24);
  while ( ((unsigned __int8)(1 << (*v6 & 7)) & v10[(unsigned __int8)*v6 >> 3]) != 0 && *v6 )
    ++v6;
  v7 = v6;
  while ( *v6 )
  {
    if ( ((unsigned __int8)(1 << (*v6 & 7)) & v10[(unsigned __int8)*v6 >> 3]) != 0 )
    {
      *v6++ = 0;
      break;
    }
    ++v6;
  }
  *(_DWORD *)(v9 + 24) = v6;
  return v6 != v7 ? v7 : 0;
}
