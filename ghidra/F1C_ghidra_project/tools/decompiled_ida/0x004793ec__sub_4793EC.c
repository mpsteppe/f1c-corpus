// Address: 0x004793ec
// Size: 495 bytes
// Name: sub_4793EC
// Type: int __stdcall(const char *)
// Source: IDA Hex-Rays decompilation

int __stdcall sub_4793EC(const char *a1)
{
  const char *v2; // esi
  char *v3; // edi
  int v4; // eax
  char v5; // cl
  int v6; // edx
  char *v7; // edi
  char v8; // cl
  int v9; // ecx
  char *v10; // eax
  bool v11; // cf
  int v12; // esi
  char v13[16]; // [esp+10h] [ebp-120h] BYREF
  char v14[16]; // [esp+20h] [ebp-110h] BYREF
  char v15[256]; // [esp+30h] [ebp-100h] BYREF

  if ( !a1 )
    return sub_478E80(0);
  v2 = &a1[strlen(a1)];
  if ( v2 > a1 )
  {
    while ( *v2 != 92 )
    {
      if ( --v2 <= a1 )
        goto LABEL_8;
    }
    ++v2;
  }
LABEL_8:
  sub_587DD0(v13, v2, 4);
  v13[4] = 0;
  sub_587DD0(v14, v2, 4);
  v3 = &v13[strlen(v13) + 1];
  v4 = dword_5C71C4;
  v5 = byte_5C71C8;
  *(_DWORD *)--v3 = dword_5C71C0;
  v6 = dword_5C7190;
  *((_DWORD *)v3 + 1) = v4;
  v3[8] = v5;
  v14[4] = 0;
  v7 = &v14[strlen(v14) + 1];
  LOWORD(v4) = word_5C7194;
  v8 = byte_5C7196;
  *(_DWORD *)--v7 = v6;
  *((_WORD *)v7 + 2) = v4;
  v7[6] = v8;
  sub_587DD0(byte_7CD718, a1, 255);
  byte_7CD817 = 0;
  v9 = strlen(byte_7CD718);
  if ( v9 > 0 )
  {
    v10 = &byte_7CD718[v9];
    if ( &byte_7CD718[v9] >= byte_7CD718 )
    {
      do
      {
        if ( *v10 == 92 )
          break;
        v11 = v10 < byte_7CD718;
        *v10 = 0;
        if ( v10 > byte_7CD718 )
          v11 = --v10 < byte_7CD718;
      }
      while ( !v11 );
    }
  }
  sub_587DD0(v15, byte_7CD718, 255);
  strcat(byte_7CD718, v13);
  v15[255] = 0;
  strcat(v15, v14);
  sub_587DD0(&unk_7CD618, byte_7CD718, 255);
  byte_7CD717 = 0;
  v12 = sub_497AD0(byte_7CD718, 0);
  sub_478E80(v12);
  if ( v12 )
    sub_566650(a1);
  else
    sub_566650(&byte_5EA438);
  return sub_479170(v15);
}
