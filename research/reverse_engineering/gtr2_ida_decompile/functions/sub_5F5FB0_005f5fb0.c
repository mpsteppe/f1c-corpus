char **__stdcall sub_5F5FB0(char *a1)
{
  char **v1; // esi
  char *v2; // eax

  v1 = off_910F40;
  if ( !off_910F40[0] )
    return 0;
  while ( !(*(int (__thiscall **)(int, char *, _DWORD))(*(_DWORD *)dword_FB27A4 + 632))(dword_FB27A4, *v1, 0)
       || v1[4] != a1 )
  {
    v2 = v1[5];
    v1 += 5;
    if ( !v2 )
      return 0;
  }
  return v1;
}
