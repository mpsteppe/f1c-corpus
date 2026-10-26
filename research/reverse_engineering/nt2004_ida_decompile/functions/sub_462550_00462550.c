void __fastcall sub_462550(int a1)
{
  int v1; // edi
  int *v2; // esi
  float *v3; // ebx
  bool v4; // al
  float v5; // [esp+Ch] [ebp-Ch]
  int v6; // [esp+10h] [ebp-8h]
  float v7; // [esp+14h] [ebp-4h] BYREF

  v6 = a1;
  v1 = 0;
  v2 = (int *)&unk_62BF68;
  v3 = (float *)(a1 + 27736);
  while ( 1 )
  {
    if ( v2[4146] == 2 )
    {
      v4 = sub_45E160((_WORD *)(a1 + 27716), v1, &v7);
      v5 = *v3;
      if ( v5 > (double)flt_769A90 || v4 )
      {
        sub_4EEC20(0);
        if ( v5 > 1.0 )
          sub_4EEC50(0);
      }
    }
    v2 += 6326;
    ++v1;
    ++v3;
    if ( (int)v2 >= (int)&dword_75AAC0 )
      break;
    a1 = v6;
  }
}
