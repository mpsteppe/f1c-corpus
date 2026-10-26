int __userpurge sub_4A0940@<eax>(int a1@<ecx>, int a2@<edi>, int a3, int a4, int a5, int a6)
{
  int v8; // eax
  int v9; // edi
  int i; // edi
  int v11; // eax
  int v12; // eax
  int j; // edi
  int v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  int v17; // eax
  int v18; // [esp+0h] [ebp-8h]
  int v19; // [esp+4h] [ebp-4h]
  void *retaddr; // [esp+8h] [ebp+0h]

  if ( !(*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)a1 + 120))(a1) )
    return -1;
  v18 = a2;
  v8 = sub_4CF930(0);
  v9 = v8;
  if ( v8 && sub_4E3120(v8) )
    sub_4E4010(v9, v18);
  for ( i = 0; i < sub_4CF920(a1); ++i )
  {
    sub_4CF930(i);
    sub_4E2FE0(800, COERCE_FLOAT(600));
    v11 = sub_4CF930(i);
    sub_4E2640(v11, 1065353216, 1065353216);
  }
  v12 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 164))(a1);
  if ( *(_DWORD *)(a1 + 300) != v12 )
  {
    *(_DWORD *)(a1 + 300) = v12;
    for ( j = 0; j < sub_4CF920(a1); ++j )
    {
      v14 = sub_4CF930(j);
      sub_4E2730(v14);
    }
  }
  if ( dword_B71BC4 )
  {
    v15 = *(const char **)(a1 + 168);
    if ( !v15 )
      v15 = WindowName;
    if ( _stricmp(v15, "no") )
    {
      v16 = *(const char **)(a1 + 168);
      if ( !v16 )
        v16 = WindowName;
      if ( _stricmp(v16, off_6FE318) )
        return sub_4D2B30(v18, v19, retaddr, a3);
    }
  }
  if ( !*(_BYTE *)(a1 + 304) )
  {
    sub_48E050(a1);
    *(_BYTE *)(a1 + 304) = 1;
  }
  v17 = sub_4CF930(0);
  if ( v17 )
    sub_4E40C0(v17);
  return 0;
}
