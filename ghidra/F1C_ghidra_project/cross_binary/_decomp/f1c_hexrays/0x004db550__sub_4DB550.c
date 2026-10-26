// f1c  0x004db550  size=118
int __stdcall sub_4DB550(int a1)
{
  double v1; // st7
  int v2; // eax
  int v3; // eax
  float v5; // [esp+8h] [ebp-4h]

  if ( byte_7D0474 )
    v1 = (double)sub_49B900();
  else
    v1 = (double)sub_49B950();
  v5 = v1;
  v2 = sub_49B8F0();
  sub_4DB6F0(v2, a1, 20);
  sub_4DB9A0(v5, a1, 68);
  v3 = sub_49B7A0(&unk_7CE234);
  return sub_4DB7F0(v3, a1, 10);
}
