char __thiscall sub_45BD10(char **this, int a2, int a3, int a4)
{
  char result; // al
  int v6; // esi
  int i; // eax
  int v8; // eax
  char v9[80]; // [esp+8h] [ebp-50h] BYREF

  result = dword_7D02E4;
  if ( a3 <= dword_7D02E4 )
  {
    if ( a4 == 16909060 )
      a4 = IDToColorMaskMapper(a3);
    v6 = 0;
    while ( (int)strlen((const char *)(v6 + a2)) >= 80 )
    {
      sub_587DD0(v9, v6 + a2, 79);
      v9[79] = 0;
      for ( i = 78; i > 40; --i )
      {
        if ( v9[i] == 32 )
          break;
      }
      if ( i == 40 )
        v8 = 79;
      else
        v8 = i + 1;
      v9[v8] = 0;
      v6 += v8;
      UtilityFunction_b9c0(*this, v9, a4, 1084227584, a3);
    }
    return UtilityFunction_b9c0(*this, (const char *)(a2 + v6), a4, 1084227584, a3);
  }
  return result;
}

