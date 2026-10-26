void __thiscall sub_45BA60(_DWORD *this, const char *a2, char a3)
{
  _DWORD *v3; // esi
  int v4; // ebp
  const char *v5; // edi
  bool v6; // al
  int v7; // eax

  v3 = this;
  if ( a2 && strlen(a2) )
  {
    v4 = 0;
    v5 = (const char *)(v3 + 15);
    do
    {
      if ( a3 )
      {
        v6 = sub_566810(v5, a2) != 0;
      }
      else
      {
        v7 = strcmp(v5, a2);
        v3 = this;
        v6 = v7 == 0;
      }
      if ( v6 )
        sub_45B430(v3, v4);
      ++v4;
      v5 += 92;
    }
    while ( v4 < 8 );
  }
}
