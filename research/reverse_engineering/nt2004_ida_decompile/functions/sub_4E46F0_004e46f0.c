char __thiscall sub_4E46F0(_DWORD *this)
{
  int v2; // eax
  CHAR **v3; // eax
  CHAR *v4; // eax
  _DWORD *v5; // esi
  int v6; // ebx
  int v7; // eax
  int v8; // esi
  CHAR *v9; // edi

  v2 = sub_4E4980(this);
  v3 = (CHAR **)sub_4E4A30(v2);
  if ( v3 )
  {
    v4 = *v3;
    if ( !v4 )
      v4 = &byte_629120;
    sub_4E8C80(v4);
    sub_4E8A30(&byte_7D6A30);
    this[7730] = 0;
    sub_4E3B00(this + 7571);
    v5 = this + 4;
    v6 = 47;
    do
    {
      v5[159] = 1;
      sub_4E3B00(v5);
      v5 += 161;
      --v6;
    }
    while ( v6 );
    v7 = sub_4E4C30(this) + 1;
    if ( v7 < 47 )
    {
      v8 = 25304 * v7;
      do
      {
        sub_51BC20(-1, 0);
        v8 += 25304;
      }
      while ( v8 < 1189288 );
    }
    sub_4CE420((int)byte_7663E0, -1.0);
    dword_7685D0 = this[7743];
    if ( dword_7685D0 >= dword_7685D8 )
    {
      if ( dword_7685D0 > dword_7685DC )
        dword_7685D0 = dword_7685DC;
    }
    else
    {
      dword_7685D0 = dword_7685D8;
    }
    v9 = (CHAR *)this[7575];
    if ( !v9 )
      v9 = &byte_629120;
    sub_578600(v9);
  }
  return 0;
}
