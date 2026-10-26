char __thiscall sub_4A1B90(_DWORD *this, int a2)
{
  int v3; // ebx
  _BYTE *v4; // eax
  _BYTE *v5; // eax
  const char *v6; // esi
  _BYTE *v7; // eax
  char *v8; // edx
  char *v9; // eax
  char result; // al
  char v11; // [esp+13h] [ebp-185h]
  int v12; // [esp+14h] [ebp-184h]
  char v13[384]; // [esp+18h] [ebp-180h] BYREF

  v11 = 0;
  v12 = sub_566E20(a2);
  v3 = 0;
  v13[0] = 0;
  if ( !sub_566CC0(v13, 384) )
    goto LABEL_22;
  while ( 1 )
  {
    if ( sub_596C80(v13, &unk_5C30B8, 2) )
    {
      v4 = (_BYTE *)sub_587C20(v13, &word_5C30B4);
      if ( v4 )
        *v4 = 0;
      v5 = (_BYTE *)sub_587C20(v13, asc_5C30B0);
      if ( v5 )
        *v5 = 0;
      if ( strlen(v13) )
      {
        v6 = (const char *)this[1];
        ++v3;
        if ( !v6 )
          v6 = byte_5EA438;
        if ( !sub_596C80(v6, v13, strlen(v6)) )
          break;
      }
    }
    if ( !sub_566CC0(v13, 384) )
      goto LABEL_22;
  }
  v7 = (_BYTE *)sub_587C20(v13, &unk_5C30B8);
  if ( v7 )
    *v7 = 0;
  v8 = &v13[strlen(v6) + 2];
  v9 = &v13[strlen(v13)];
  if ( v9 >= v8 )
  {
    while ( *v9 != 34 )
    {
      if ( --v9 < v8 )
        goto LABEL_20;
    }
    *v9 = 0;
  }
LABEL_20:
  if ( !(*(unsigned __int8 (__thiscall **)(_DWORD *, char *))(*this + 4))(this, v8) || (result = 1, v11 = 1, v3 != 1) )
  {
LABEL_22:
    sub_566DB0(v12);
    return v11;
  }
  return result;
}
