int sub_42C1A0()
{
  int v0; // esi
  int v1; // edx
  int *v2; // eax
  int v3; // edx
  bool v4; // al
  double v5; // st7
  int v6; // esi
  double v7; // st7
  int result; // eax
  float v9; // [esp+4h] [ebp-218h]
  float v10; // [esp+4h] [ebp-218h]
  _BYTE v11[4]; // [esp+10h] [ebp-20Ch] BYREF
  int v12; // [esp+14h] [ebp-208h]
  float v13; // [esp+18h] [ebp-204h]
  _BYTE v14[512]; // [esp+1Ch] [ebp-200h] BYREF

  if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_12, 525) )
    sub_4D7AA0(&unk_8AD25C, aEnteredDynmanI);
  sub_40FE50(dword_5EA560);
  v0 = dword_7D0410;
  v1 = 0;
  v2 = &dword_5EF9A0;
  while ( 1 )
  {
    if ( v0 != 4 )
      v2[868] = v1 + 1;
    if ( !*v2 )
      break;
    v2 += 4656;
    ++v1;
    if ( (int)v2 >= (int)dword_7C87A0 )
      goto LABEL_10;
  }
  sub_42BBD0(v1);
  sub_42BC40(v3);
LABEL_10:
  if ( v1 == 104 )
  {
    sub_42BBD0(0);
    sub_42BC40(0);
  }
  v4 = dword_7C56A4 == 1 || dword_7C56A4 == 2 || dword_7C56A4 == 3 || dword_7C56A4 == 4;
  if ( !byte_7C5690 )
  {
    sub_4B1520(v0, v14, 512);
    sub_4BFD90(v14);
    if ( dword_7D0410 != 3 || !byte_7CEBC4 )
    {
      sub_4BFF70(v11);
      goto LABEL_25;
    }
    goto LABEL_24;
  }
  if ( v0 == 4 && v4 )
LABEL_24:
    sub_4C01A0(v11);
LABEL_25:
  sub_42BC80();
  v5 = (double)dword_5C329C * 1.5 + 113.0;
  sub_5895A2(v5);
  v13 = v5 - 101.0;
  sub_4F9480(101.0);
  v6 = 0;
  while ( v6 < dword_5C329C )
  {
    sub_4C6C40(1);
    v12 = ++v6;
    v9 = (double)v6 / (double)dword_5C329C * v13 + 101.0;
    sub_4F9480(v9);
  }
  v7 = (double)dword_5C329C * 1.5 + 113.0;
  sub_5895A2(v7);
  v10 = v7;
  sub_4F9480(v10);
  sub_4326E0(&unk_7C73E0);
  result = dword_7C54E4;
  if ( (unsigned int)dword_7C54E4 < 0x68 && !*(_DWORD *)(dword_7C54F0[dword_7C54E4] + 13000) )
    return sub_4336F0(dword_7C54E4);
  return result;
}
