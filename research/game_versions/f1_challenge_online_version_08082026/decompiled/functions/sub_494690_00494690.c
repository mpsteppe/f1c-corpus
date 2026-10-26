int sub_494690()
{
  int v0; // eax
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int result; // eax
  float v7; // [esp+0h] [ebp-8h]
  float v8; // [esp+0h] [ebp-8h]
  float v9; // [esp+4h] [ebp-4h]
  float v10; // [esp+4h] [ebp-4h]

  v0 = sub_587C03(96);
  if ( v0 )
    v1 = sub_54FE10(v0);
  else
    v1 = 0;
  dword_7CDE04 = v1;
  sub_54FEC0(aSbuf, 256, 256, 0, 4);
  dword_7CDE08 = *(_DWORD *)(dword_7CDE04 + 84);
  sub_553980(&dword_7CDE0C, 2, dword_7CDE04, 48, 64);
  v2 = sub_587C03(96);
  if ( v2 )
    v3 = sub_54FE10(v2);
  else
    v3 = 0;
  dword_7CDE10 = v3;
  sub_54FEC0(aBbuf, 1024, 1024, 0, 4);
  dword_7CDE14 = *(_DWORD *)(dword_7CDE10 + 84);
  if ( !sub_553980(&dword_7CDE18, 2, dword_7CDE10, 16, 64) )
  {
    v9 = (float)dword_5D6D60;
    v7 = (float)dword_5D6D64;
    sub_553650(0, 0.0, 0.0, 1.0, 0.0, 0.0, 0xFFFFFF);
    sub_553650(1, 0.0, v7, 1.0, 0.0, 0.5859375, 0xFFFFFF);
    sub_553650(2, v9, v7, 1.0, 0.78125, 0.5859375, 0xFFFFFF);
    sub_553650(3, v9, 0.0, 1.0, 0.78125, 0.0, 0xFFFFFF);
  }
  v4 = sub_587C03(96);
  if ( v4 )
    v5 = sub_54FE10(v4);
  else
    v5 = 0;
  dword_7CDE1C = v5;
  sub_54FEC0(aAbuf, 512, 512, 0, 4);
  dword_7CDE20 = *(_DWORD *)(dword_7CDE1C + 84);
  result = sub_553980(&dword_7CDE24, 2, dword_7CDE1C, 16, 64);
  if ( !result )
  {
    v8 = (float)dword_5D6D60;
    v10 = (float)dword_5D6D64;
    sub_553650(0, 0.0, 0.0, 1.0, 0.0, 0.0, 0xFFFFFF);
    sub_553650(1, 0.0, v10, 1.0, 0.0, 0.5859375, 0xFFFFFF);
    sub_553650(2, v8, v10, 1.0, 0.78125, 0.5859375, 0xFFFFFF);
    return sub_553650(3, v8, 0.0, 1.0, 0.78125, 0.0, 0xFFFFFF);
  }
  return result;
}
