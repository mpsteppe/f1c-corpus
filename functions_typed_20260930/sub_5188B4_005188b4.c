void __cdecl sub_5188B4(int a1, int a2, int a3)
{
  signed int v4; // edi
  int v5; // eax
  int v6; // ebx
  unsigned __int8 v7; // al
  char v8; // [esp-Ch] [ebp-34h]
  char v9; // [esp-8h] [ebp-30h]
  char v10; // [esp-4h] [ebp-2Ch]
  unsigned __int8 v11[4]; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned __int8 v12[12]; // [esp+10h] [ebp-18h] BYREF
  int v13; // [esp+1Ch] [ebp-Ch]
  int v14; // [esp+20h] [ebp-8h]
  int v15; // [esp+24h] [ebp-4h]
  int v16; // [esp+30h] [ebp+8h]
  int v17; // [esp+38h] [ebp+10h]

  if ( *(_DWORD *)(a1 + 88) )
    GuardedCallWithLongjmp(a1, (int)"Out of place IHDR");
  if ( a3 != 13 )
    GuardedCallWithLongjmp(a1, (int)"Invalid IHDR chunk");
  *(_DWORD *)(a1 + 88) |= 1u;
  sub_517F58(a1, (int)v11, 13);
  sub_518828(a1, 0);
  v4 = ByteArrayToInt(v11);
  v5 = ByteArrayToInt(v12);
  v6 = v12[4];
  v16 = v5;
  v17 = v12[5];
  v13 = v12[6];
  v14 = v12[7];
  v15 = v12[8];
  if ( v4 <= 0 || v5 <= 0 )
    GuardedCallWithLongjmp(a1, (int)"Invalid image size in IHDR");
  if ( v6 != 1 && v6 != 2 && v6 != 4 && v6 != 8 && v6 != 16 )
    GuardedCallWithLongjmp(a1, (int)"Invalid bit depth in IHDR");
  if ( v17 == 1 || v17 == 5 || v17 > 6 )
    GuardedCallWithLongjmp(a1, (int)"Invalid color type in IHDR");
  if ( v17 == 3 && v6 > 8 || (v17 == 2 || v17 == 4 || v17 == 6) && v6 < 8 )
    GuardedCallWithLongjmp(a1, (int)"Invalid color type/bit depth combination in IHDR");
  if ( v15 >= 2 )
    GuardedCallWithLongjmp(a1, (int)"Unknown interlace method in IHDR");
  if ( v13 )
    GuardedCallWithLongjmp(a1, (int)"Unknown compression method in IHDR");
  if ( v14 )
    GuardedCallWithLongjmp(a1, (int)"Unknown filter method in IHDR");
  *(_BYTE *)(a1 + 275) = v15;
  *(_DWORD *)(a1 + 184) = v4;
  *(_DWORD *)(a1 + 188) = v16;
  *(_BYTE *)(a1 + 279) = v6;
  *(_BYTE *)(a1 + 278) = v17;
  if ( !(_BYTE)v17 )
    goto LABEL_39;
  switch ( (unsigned __int8)v17 )
  {
    case 2u:
      *(_BYTE *)(a1 + 282) = 3;
      break;
    case 3u:
LABEL_39:
      *(_BYTE *)(a1 + 282) = 1;
      break;
    case 4u:
      *(_BYTE *)(a1 + 282) = 2;
      break;
    case 6u:
      *(_BYTE *)(a1 + 282) = 4;
      break;
  }
  v10 = v14;
  v7 = v6 * *(_BYTE *)(a1 + 282);
  v9 = v13;
  *(_BYTE *)(a1 + 281) = v7;
  v8 = v15;
  *(_DWORD *)(a1 + 200) = (v4 * (unsigned int)v7 + 7) >> 3;
  sub_513A71(a1, a2, v4, v16, v6, v17, v8, v9, v10);
}

