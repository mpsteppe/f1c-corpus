int __stdcall sub_64460A(int *a1, int a2, int a3)
{
  int *v3; // eax
  unsigned int v4; // ebx
  _DWORD *v5; // edi
  _DWORD *v6; // esi
  unsigned int v7; // eax
  int v8; // eax

  v3 = a1;
  v4 = -1;
  v5 = &unk_735FE8;
  while ( 1 )
  {
    v8 = *v3;
    if ( !v8 )
      return *v5;
    v6 = sub_644568(v8);
    if ( *v6 )
    {
      if ( v6[1] != 1 || a2 )
        break;
    }
LABEL_11:
    v3 = ++a1;
  }
  if ( *(_DWORD *)a3 != *v6 )
  {
    v7 = sub_644593(a3, (int)v6);
    if ( v7 != -1 && v7 <= v4 && (v7 != v4 || v6[2] < v5[2]) )
    {
      v4 = v7;
      v5 = v6;
    }
    goto LABEL_11;
  }
  return *(_DWORD *)a3;
}
