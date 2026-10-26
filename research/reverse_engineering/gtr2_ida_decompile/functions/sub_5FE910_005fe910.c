int __thiscall sub_5FE910(char *this, const char *a2, int a3, char a4)
{
  unsigned int v4; // eax
  char *v6; // ebp
  int *v7; // eax
  bool v8; // zf
  int v9; // edi
  int v10; // eax
  int *v11; // eax
  char String[64]; // [esp+10h] [ebp-40h] BYREF

  sub_630FE0(String);
  if ( (int)strlen(a2) <= 63 )
    v4 = strlen(a2);
  else
    v4 = dword_16C997C;
  String[v4] = 0;
  _strupr(String);
  v6 = this + 580;
  if ( !a4 )
    v6 = this + 564;
  v7 = *(int **)v6;
  v8 = *(_DWORD *)v6 == 0;
  *((_DWORD *)v6 + 2) = *(_DWORD *)v6;
  if ( v8 )
    return 0;
  v9 = *v7;
  if ( !*v7 )
    return 0;
  while ( strcmp((const char *)(v9 + 8), String) || *(_DWORD *)(v9 + 276) != a3 )
  {
    v10 = *((_DWORD *)v6 + 2);
    if ( v10 )
    {
      v11 = *(int **)(v10 + 4);
      *((_DWORD *)v6 + 2) = v11;
      if ( v11 )
      {
        v9 = *v11;
        if ( *v11 )
          continue;
      }
    }
    return 0;
  }
  return v9;
}
