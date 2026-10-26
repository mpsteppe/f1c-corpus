int __stdcall sub_525AB0(int *a1, const char **a2, int a3, int a4)
{
  int v4; // ebx
  const char *v5; // eax
  int v7; // eax

  v4 = 1;
  if ( a1 && a2 )
  {
    v5 = *a2;
    if ( !*a2 )
      v5 = &byte_629120;
    if ( !strlen(v5) )
    {
      *a1 = 0;
      return 1;
    }
    if ( dword_7D6BB0 )
    {
      v7 = (*(int (__thiscall **)(int, const char **, int, int))(*(_DWORD *)dword_7D6BB0 + 96))(
             dword_7D6BB0,
             a2,
             a3,
             a4);
      *a1 = v7;
      if ( v7 )
      {
        if ( !(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 20))(v7) )
          return 0;
      }
    }
  }
  return v4;
}
