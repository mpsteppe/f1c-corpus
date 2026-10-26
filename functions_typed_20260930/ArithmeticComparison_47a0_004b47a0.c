int __fastcall sub_4B47A0(int a1, int a2, char a3, int a4, int a5)
{
  int result; // eax
  int v6; // esi
  char v7; // dl
  char v8; // cl

  result = a1;
  if ( a5 != 255 )
  {
    v6 = 13 * a4 + a1 + 1;
    result = a5 / 8;
    v7 = 1 << (a5 % 8);
    v8 = *(_BYTE *)(a5 / 8 + v6);
    if ( a3 )
      *(_BYTE *)(result + v6) = v7 | v8;
    else
      *(_BYTE *)(result + v6) = ~v7 & v8;
  }
  return result;
}

