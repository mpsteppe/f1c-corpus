void __stdcall sub_6BA724(int a1, int a2, int a3)
{
  signed int v4; // edi
  int v5; // eax
  char v6; // bl
  unsigned __int8 v7; // al
  char v8; // [esp-Ch] [ebp-34h]
  char v9; // [esp-8h] [ebp-30h]
  char v10; // [esp-4h] [ebp-2Ch]
  unsigned __int8 v11[4]; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned __int8 v12[4]; // [esp+10h] [ebp-18h] BYREF
  unsigned __int8 v13; // [esp+14h] [ebp-14h]
  unsigned __int8 v14; // [esp+15h] [ebp-13h]
  unsigned __int8 v15; // [esp+16h] [ebp-12h]
  unsigned __int8 v16; // [esp+17h] [ebp-11h]
  unsigned __int8 v17; // [esp+18h] [ebp-10h]
  int v18; // [esp+1Ch] [ebp-Ch]
  int v19; // [esp+20h] [ebp-8h]
  int v20; // [esp+24h] [ebp-4h]
  int v21; // [esp+30h] [ebp+8h]
  char v22; // [esp+38h] [ebp+10h]

  if ( *(_DWORD *)(a1 + 88) )
    sub_679F05(a1, (int)"Out of place IHDR");
  if ( a3 != 13 )
    sub_679F05(a1, (int)"Invalid IHDR chunk");
  *(_DWORD *)(a1 + 88) |= 1u;
  sub_6B9DC1(a1, (int)v11, 13);
  sub_6BA69B(a1, 0);
  v4 = sub_6B9D7D(v11);
  v5 = sub_6B9D7D(v12);
  v6 = v13;
  v21 = v5;
  v22 = v14;
  v18 = v15;
  v19 = v16;
  v20 = v17;
  if ( v4 <= 0 || v5 <= 0 )
    sub_679F05(a1, (int)"Invalid image size in IHDR");
  if ( v13 != 1 && v13 != 2 && v13 != 4 && v13 != 8 && v13 != 16 )
    sub_679F05(a1, (int)"Invalid bit depth in IHDR");
  if ( v14 == 1 || v14 == 5 || v14 > 6u )
    sub_679F05(a1, (int)"Invalid color type in IHDR");
  if ( v14 == 3 && v13 > 8u || (v14 == 2 || v14 == 4 || v14 == 6) && v13 < 8u )
    sub_679F05(a1, (int)"Invalid color type/bit depth combination in IHDR");
  if ( v20 >= 2 )
    sub_679F05(a1, (int)"Unknown interlace method in IHDR");
  if ( v18 )
    sub_679F05(a1, (int)"Unknown compression method in IHDR");
  if ( v19 )
    sub_679F05(a1, (int)"Unknown filter method in IHDR");
  *(_BYTE *)(a1 + 275) = v20;
  *(_DWORD *)(a1 + 184) = v4;
  *(_DWORD *)(a1 + 188) = v5;
  *(_BYTE *)(a1 + 279) = v6;
  *(_BYTE *)(a1 + 278) = v22;
  switch ( v22 )
  {
    case 0:
      goto LABEL_39;
    case 2:
      *(_BYTE *)(a1 + 282) = 3;
      break;
    case 3:
LABEL_39:
      *(_BYTE *)(a1 + 282) = 1;
      break;
    case 4:
      *(_BYTE *)(a1 + 282) = 2;
      break;
    case 6:
      *(_BYTE *)(a1 + 282) = 4;
      break;
  }
  v10 = v19;
  v7 = v6 * *(_BYTE *)(a1 + 282);
  v9 = v18;
  *(_BYTE *)(a1 + 281) = v7;
  v8 = v20;
  *(_DWORD *)(a1 + 200) = (v4 * (unsigned int)v7 + 7) >> 3;
  sub_67A8A3(a1, a2, v4, v21, v6, v22, v8, v9, v10);
}
