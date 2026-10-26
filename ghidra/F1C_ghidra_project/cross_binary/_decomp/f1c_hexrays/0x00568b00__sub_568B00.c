// f1c  0x00568b00  size=159
char __fastcall sub_568B00(int a1, int a2)
{
  int v3; // esi
  int v4; // edi
  int i; // eax
  _BYTE v7[2048]; // [esp+8h] [ebp-800h] BYREF

  v3 = sub_587DB0(a1, aRb);
  if ( !v3 )
    return 0;
  v4 = sub_587DB0(a2, &unk_5C2AB0);
  if ( !v4 )
  {
    sub_587D02(v3);
    return 0;
  }
  for ( i = sub_58803F(v7, 1, 2048, v3); i > 0; i = sub_58803F(v7, 1, 2048, v3) )
    sub_588678(v7, 1, i, v4);
  sub_587D02(v3);
  sub_587D02(v4);
  return 1;
}
