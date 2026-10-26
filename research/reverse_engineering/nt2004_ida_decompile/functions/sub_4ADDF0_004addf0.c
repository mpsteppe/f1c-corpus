char __thiscall sub_4ADDF0(_DWORD *this, char *String2)
{
  LPVOID *v4; // eax
  LPVOID *v5; // esi
  LPVOID **v6; // eax
  void *v7; // edi

  if ( (unsigned __int8)sub_4ADEF0(String2) )
    return 1;
  v4 = (LPVOID *)operator new(0x20u);
  v5 = 0;
  if ( v4 )
  {
    *v4 = 0;
    v4[1] = (LPVOID)-1;
    v4[2] = 0;
    v4[3] = (LPVOID)-1;
    v4[5] = (LPVOID)-1;
    v4[4] = 0;
    v4[6] = (LPVOID)1065353216;
    v4[7] = (LPVOID)1065353216;
    v5 = v4;
  }
  sub_578600(String2);
  sub_578600(String2);
  if ( (unsigned __int8)sub_4B0B30(v5) )
  {
    if ( v5 )
    {
      v6 = (LPVOID **)operator new(0xCu);
      if ( v6 )
      {
        *v6 = v5;
        v6[1] = 0;
        *((_BYTE *)v6 + 8) = 1;
      }
      else
      {
        v6 = 0;
      }
      if ( this[87] )
      {
        *(_DWORD *)(this[88] + 4) = v6;
      }
      else
      {
        this[87] = v6;
        this[89] = v6;
      }
      this[88] = v6;
      ++this[90];
    }
    return 1;
  }
  else
  {
    if ( v5 )
    {
      v7 = v5[2];
      if ( v7 )
        sub_5BE8AE(v7);
      if ( *v5 )
        sub_5BE8AE(*v5);
      sub_5BE8AE(v5);
    }
    return 0;
  }
}
