char __thiscall sub_466190(float **this)
{
  float *v2; // ecx
  DWORD v3; // eax
  int i; // esi
  int v5; // ecx
  int v6; // ecx
  _DWORD *v7; // esi
  float v9; // [esp+0h] [ebp-Ch]
  char v10; // [esp+4h] [ebp-8h]
  int v11; // [esp+8h] [ebp-4h]

  v2 = *this;
  v3 = *((_DWORD *)v2 + 1680);
  if ( v3 )
  {
    if ( *((_BYTE *)v2 + 32) )
    {
      sub_4623E0(v2);
      sub_462430(*this, 1);
      if ( *((_DWORD *)*this + 1680) == 3 )
      {
        if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 8873) )
          sub_500FE0((int)&unk_7D7920, aEnteringSynchr, v10);
        sub_460A50();
      }
    }
    else
    {
      *((_BYTE *)v2 + 32) = 1;
      for ( i = 0; i < 5194; i += 106 )
        sub_52E5C0(&(*this)[i + 1735]);
    }
    v5 = *((_DWORD *)*this + 1680);
    if ( v5 == 2 || v5 == 1 )
    {
      if ( dword_75CBB0 == 7 || byte_769A48 && dword_75CBB0 == 5 )
        sub_56A2A0(0);
      else
        sub_56A2A0(1);
    }
    else
    {
      (*this)[4] = 5.0;
      (*this)[166] = 0.0099999998;
    }
    v6 = *(_DWORD *)dword_76986C;
    if ( *(int *)dword_76986C <= 4 )
      v6 = 4;
    if ( dword_769890 >= v6 )
    {
      v11 = *(_DWORD *)dword_76986C;
      if ( *(int *)dword_76986C <= 4 )
        v11 = 4;
    }
    else
    {
      v11 = dword_769890;
    }
    v9 = (float)v11;
    sub_460960(*this, v9);
    (*this)[164] = 0.0;
    (*this)[162] = 0.0;
    LOBYTE(v3) = sub_45DE30((_DWORD *)*this + 6929, 1);
    if ( *((_BYTE *)*this + 30136) )
    {
      LOBYTE(v3) = *((_BYTE *)*this + 30137);
      if ( (_BYTE)v3 )
      {
        v7 = off_624A10;
        v3 = *((_DWORD *)off_624A10 + 45);
        if ( v3 )
        {
          v3 = GetTickCount() - v7[42];
          if ( v3 >= 0x2710 )
            LOBYTE(v3) = sub_5BB940(v7, 1);
        }
      }
    }
  }
  return v3;
}
