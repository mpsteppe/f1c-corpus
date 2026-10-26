int __thiscall sub_48A040(int this)
{
  int v2; // eax
  int v3; // esi
  unsigned __int8 v4; // al
  int v5; // ecx
  int v6; // eax
  const char **v7; // eax
  const char **v8; // esi
  const char *v9; // ecx
  bool v10; // zf
  char *v11; // eax
  bool v12; // bl
  CHAR *v13; // eax
  char *v15; // eax

  v2 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
  if ( !v2 )
    goto LABEL_16;
  v3 = *(_DWORD *)(v2 + 28);
  if ( !v3 )
    goto LABEL_16;
  v4 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v3 + 124))(*(_DWORD *)(v2 + 28));
  v5 = *(_DWORD *)(this + 840);
  v6 = v4 - 1;
  if ( v5 >= 0 )
  {
    if ( v5 > v6 )
      *(_DWORD *)(this + 840) = v6;
  }
  else
  {
    *(_DWORD *)(this + 840) = 0;
  }
  v7 = (const char **)(*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 128))(v3, *(unsigned __int8 *)(this + 840));
  v8 = v7;
  if ( v7 )
  {
    v9 = *v7;
    if ( !*v7 )
      v9 = &byte_629120;
    v10 = _strcmpi(*(const char **)(this + 796), v9) == 0;
    v11 = (char *)*v8;
    v12 = !v10;
    if ( !*v8 )
      v11 = &byte_629120;
    sub_4A1AC0(v11);
    v13 = (CHAR *)*v8;
    if ( !*v8 )
      v13 = &byte_629120;
    sub_578600(v13);
    dword_7652F8 = (int)v8[2];
    dword_7652E4 = *((unsigned __int8 *)v8 + 13);
    if ( v12 )
    {
      dword_600F44 = 1;
      return 0;
    }
  }
  else
  {
LABEL_16:
    sub_578600(aNA_1);
    v15 = dword_765324;
    dword_7652F8 = 0;
    dword_7652E4 = 0;
    if ( !dword_765324 )
      v15 = &byte_629120;
    sub_4A1AC0(v15);
  }
  return 0;
}
