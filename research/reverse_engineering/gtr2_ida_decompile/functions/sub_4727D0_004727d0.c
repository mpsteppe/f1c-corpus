void __thiscall sub_4727D0(const char *this, const char *a2, char a3)
{
  const char *v3; // esi
  int v5; // ebp
  const char *v6; // edi
  bool v7; // al
  int v8; // eax
  int v9; // eax

  v3 = a2;
  if ( a2 && strlen(a2) )
  {
    v5 = 0;
    v6 = this + 68;
    do
    {
      if ( a3 )
      {
        v7 = sub_616480(v6, v3) != 0;
      }
      else
      {
        v8 = strcmp(v6, v3);
        v3 = a2;
        v7 = v8 == 0;
      }
      if ( v7 )
      {
        *v6 = 0;
        *((_DWORD *)v6 + 20) = -1;
        *((_DWORD *)v6 + 21) = -1082130432;
        *((_DWORD *)v6 + 22) = 3;
        v9 = *((_DWORD *)this + 201);
        if ( v5 == v9 )
          *((_DWORD *)this + 201) = (v9 + 1) % 8;
      }
      ++v5;
      v6 += 92;
    }
    while ( v5 < 8 );
  }
}
