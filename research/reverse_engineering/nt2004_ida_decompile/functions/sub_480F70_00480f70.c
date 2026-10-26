bool __stdcall sub_480F70(int a1, int a2)
{
  int i; // edi
  char *v3; // eax
  int v4; // eax

  for ( i = 0; i < a2; ++i )
  {
    if ( *(_WORD *)(a1 + 2 * i) == 15 )
    {
      v3 = (char *)sub_49D1F0(0);
      if ( v3 )
      {
        v4 = sub_4AD520(v3);
        if ( v4 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 132))(v4);
      }
    }
  }
  return sub_4A1860(a1, a2) != 0;
}
