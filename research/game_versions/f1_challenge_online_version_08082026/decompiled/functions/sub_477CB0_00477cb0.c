int __thiscall sub_477CB0(_DWORD *this)
{
  int v2; // esi
  _DWORD *v3; // edi
  bool v4; // zf
  char *v5; // eax
  int v6; // edx
  char v7; // cl
  const char *i; // esi
  const char *v9; // edx
  char *v10; // eax
  int v11; // edi
  int v12; // eax
  int v13; // esi
  char v15[64]; // [esp+10h] [ebp-180h] BYREF
  char v16[64]; // [esp+50h] [ebp-140h] BYREF
  _BYTE v17[256]; // [esp+90h] [ebp-100h] BYREF

  sub_48EBD0();
  v2 = this[60];
  while ( v2 )
  {
    v3 = (_DWORD *)v2;
    v4 = *(_BYTE *)(v2 + 12) == 0;
    v2 = *(_DWORD *)(v2 + 4);
    if ( !v4 && *v3 )
      (**(void (__thiscall ***)(_DWORD, int))*v3)(*v3, 1);
    sub_587BCF(v3);
  }
  this[60] = 0;
  this[61] = 0;
  this[62] = 0;
  this[63] = 0;
  this[93] = 0;
  v5 = (char *)dword_5EC3F8;
  lpExistingFileName = aProfileiconDft;
  if ( !dword_5EC3F8 )
    v5 = byte_5EA438;
  v6 = v16 - v5;
  do
  {
    v7 = *v5;
    v5[v6] = *v5;
    ++v5;
  }
  while ( v7 );
  sub_565F80(aBmp_0, 1, (int)v16, 1);
  sub_566380(0);
  for ( i = (const char *)sub_5662D0(&unk_8AD3B0); i; i = (const char *)sub_5662D0(&unk_8AD3B0) )
  {
    v9 = &i[strlen(i)];
    if ( v9 > i )
    {
      while ( *v9 != 92 )
      {
        if ( --v9 <= i )
          goto LABEL_16;
      }
      ++v9;
    }
LABEL_16:
    strcpy(v15, v9);
    v10 = &v15[strlen(v15)];
    if ( v10 > v15 )
    {
      while ( *v10 != 46 )
      {
        if ( --v10 <= v15 )
          goto LABEL_21;
      }
      *v10 = 0;
    }
LABEL_21:
    sub_58815F(v17, "%s%s", v16, v9);
    v11 = sub_497AD0(v17, 0);
    if ( v11 )
    {
      v12 = sub_587C03(60);
      if ( v12 )
        v13 = sub_48FC50(v12);
      else
        v13 = 0;
      sub_566650(v17);
      sub_48FC80(v11);
      sub_566650(v15);
      sub_48F5D0(v13, 1);
    }
    else
    {
      sub_497AD0(aProfileiconDft, 0);
    }
    sub_565F20(&unk_8AD3B0);
  }
  sub_565EB0(&unk_8AD3B0);
  sub_48F640(this);
  return 0;
}
