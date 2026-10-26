void __cdecl sub_555842(jmp_buf Buf, int a2, int a3)
{
  signed int v4; // edi
  int v5; // eax
  char v6; // bl
  unsigned __int8 v7; // al
  char v8; // [esp-Ch] [ebp-34h]
  char v9; // [esp-8h] [ebp-30h]
  char v10; // [esp-4h] [ebp-2Ch]
  int v11; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned __int8 v12[4]; // [esp+10h] [ebp-18h] BYREF
  unsigned __int8 v13; // [esp+14h] [ebp-14h]
  unsigned __int8 v14; // [esp+15h] [ebp-13h]
  unsigned __int8 v15; // [esp+16h] [ebp-12h]
  unsigned __int8 v16; // [esp+17h] [ebp-11h]
  unsigned __int8 v17; // [esp+18h] [ebp-10h]
  int v18; // [esp+1Ch] [ebp-Ch]
  int v19; // [esp+20h] [ebp-8h]
  int v20; // [esp+24h] [ebp-4h]
  int *__attribute__((__org_typedef(jmp_buf))) Bufa; // [esp+30h] [ebp+8h]
  char v22; // [esp+38h] [ebp+10h]

  if ( Buf[22] )
    sub_54E7FC(Buf, (int)"Out of place IHDR");
  if ( a3 != 13 )
    sub_54E7FC(Buf, (int)"Invalid IHDR chunk");
  Buf[22] |= 1u;
  sub_554EE6(Buf, (int)&v11, 13);
  sub_5557B6(Buf, 0);
  v4 = sub_554EC3((unsigned __int8 *)&v11);
  v5 = sub_554EC3(v12);
  v6 = v13;
  Bufa = (int *)v5;
  v22 = v14;
  v18 = v15;
  v19 = v16;
  v20 = v17;
  if ( v4 <= 0 || v5 <= 0 )
    sub_54E7FC(Buf, (int)"Invalid image size in IHDR");
  if ( v13 != 1 && v13 != 2 && v13 != 4 && v13 != 8 && v13 != 16 )
    sub_54E7FC(Buf, (int)"Invalid bit depth in IHDR");
  if ( v14 == 1 || v14 == 5 || v14 > 6u )
    sub_54E7FC(Buf, (int)"Invalid color type in IHDR");
  if ( v14 == 3 && v13 > 8u || (v14 == 2 || v14 == 4 || v14 == 6) && v13 < 8u )
    sub_54E7FC(Buf, (int)"Invalid color type/bit depth combination in IHDR");
  if ( v20 >= 2 )
    sub_54E7FC(Buf, (int)"Unknown interlace method in IHDR");
  if ( v18 )
    sub_54E7FC(Buf, (int)"Unknown compression method in IHDR");
  if ( v19 )
    sub_54E7FC(Buf, (int)"Unknown filter method in IHDR");
  *((_BYTE *)Buf + 275) = v20;
  Buf[46] = v4;
  Buf[47] = v5;
  *((_BYTE *)Buf + 279) = v6;
  *((_BYTE *)Buf + 278) = v22;
  switch ( v22 )
  {
    case 0:
      goto LABEL_39;
    case 2:
      *((_BYTE *)Buf + 282) = 3;
      break;
    case 3:
LABEL_39:
      *((_BYTE *)Buf + 282) = 1;
      break;
    case 4:
      *((_BYTE *)Buf + 282) = 2;
      break;
    case 6:
      *((_BYTE *)Buf + 282) = 4;
      break;
  }
  v10 = v19;
  v7 = v6 * *((_BYTE *)Buf + 282);
  v9 = v18;
  *((_BYTE *)Buf + 281) = v7;
  v8 = v20;
  Buf[50] = (v4 * (unsigned int)v7 + 7) >> 3;
  sub_550A04((int)Buf, a2, v4, (int)Bufa, v6, v22, v8, v9, v10);
}
