int __thiscall sub_4793EC(_DWORD *this, const char *a2)
{
  const char *v3; // esi
  char *v4; // edi
  int v5; // eax
  char v6; // cl
  int v7; // edx
  char *v8; // edi
  char v9; // cl
  int v10; // ecx
  char *v11; // eax
  bool v12; // cf
  int v13; // esi
  char v15[16]; // [esp+10h] [ebp-120h] BYREF
  char v16[16]; // [esp+20h] [ebp-110h] BYREF
  char v17[256]; // [esp+30h] [ebp-100h] BYREF

  if ( !a2 )
    return sub_478E80(0);
  v3 = &a2[strlen(a2)];
  if ( v3 > a2 )
  {
    while ( *v3 != 92 )
    {
      if ( --v3 <= a2 )
        goto LABEL_8;
    }
    ++v3;
  }
LABEL_8:
  sub_587DD0(v15, v3, 4);
  v15[4] = 0;
  sub_587DD0(v16, v3, 4);
  v4 = &v15[strlen(v15) + 1];
  v5 = dword_5C71C4;
  v6 = byte_5C71C8;
  *(_DWORD *)--v4 = dword_5C71C0;
  v7 = dword_5C7190;
  *((_DWORD *)v4 + 1) = v5;
  v4[8] = v6;
  v16[4] = 0;
  v8 = &v16[strlen(v16) + 1];
  LOWORD(v5) = word_5C7194;
  v9 = byte_5C7196;
  *(_DWORD *)--v8 = v7;
  *((_WORD *)v8 + 2) = v5;
  v8[6] = v9;
  sub_587DD0(byte_7CD718, a2, 255);
  byte_7CD817 = 0;
  v10 = strlen(byte_7CD718);
  if ( v10 > 0 )
  {
    v11 = &byte_7CD718[v10];
    if ( &byte_7CD718[v10] >= byte_7CD718 )
    {
      do
      {
        if ( *v11 == 92 )
          break;
        v12 = v11 < byte_7CD718;
        *v11 = 0;
        if ( v11 > byte_7CD718 )
          v12 = --v11 < byte_7CD718;
      }
      while ( !v12 );
    }
  }
  sub_587DD0(v17, byte_7CD718, 255);
  strcat(byte_7CD718, v15);
  v17[255] = 0;
  strcat(v17, v16);
  sub_587DD0(&unk_7CD618, byte_7CD718, 255);
  byte_7CD717 = 0;
  v13 = sub_497AD0(byte_7CD718, 0);
  sub_478E80(v13);
  if ( v13 )
    sub_566650(a2);
  else
    sub_566650(byte_5EA438);
  return sub_479170(this, (int)v17);
}
