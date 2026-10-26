void __thiscall sub_54B5A0(_DWORD *this)
{
  int v1; // esi
  char v2; // al
  _DWORD *v3; // esi
  int v4; // edi
  _DWORD *v5; // ebx
  int v6; // ebp
  int v7; // ebx
  _DWORD *v8; // edi

  v1 = 994654 * this[994657];
  v2 = this[v1 + 1];
  v3 = &this[v1];
  if ( v2 && *(float *)v3 == *(float *)&dword_B64140 )
  {
    if ( *(_DWORD *)dword_B72314 == 4 )
      sub_5363D0(&unk_B76270);
    sub_430250(&dword_B640C0, v3[37]);
    dword_B640C0 = v3[35];
    sub_430F70(&dword_B640C0, v3[36]);
    sub_58FFA0(&unk_FB1E98);
    sub_5537E0(v3 + 188);
    sub_52B1F0(&byte_9034D0, (int)(v3 + 648));
    if ( byte_B7075C[0] )
      dword_FB1EF8 = v3[193];
    else
      dword_FB1EF8 = 1065353216;
    sub_598FF0(&dword_FB1EF8, v3 + 994215);
    v4 = 0;
    if ( dword_757C10 > 0 )
    {
      v5 = v3 + 880;
      do
      {
        sub_53F420();
        ++v4;
        v5 += 9460;
      }
      while ( v4 < dword_757C10 );
    }
    v6 = 0;
    if ( dword_757C14 > 0 )
    {
      v7 = 0;
      v8 = v3 + 984720;
      do
      {
        sub_53F420();
        ++v6;
        v8 += 9460;
        v7 += 22616;
      }
      while ( v6 < dword_757C14 );
    }
    sub_456ED0((int)&dbl_B66040, (int)(v3 + 654));
    sub_53E6A0((void *)dword_91E084, *((_BYTE *)v3 + 3976720) != 0);
    sub_414450(&dword_91BF20, v3[994182]);
    sub_413D50((_DWORD **)&dword_91BF20, (int)(v3 + 994183), 1);
    sub_412EB0(&dword_91BF20, v3[994181], 0);
    sub_410BD0(&dword_91BF20);
  }
}
