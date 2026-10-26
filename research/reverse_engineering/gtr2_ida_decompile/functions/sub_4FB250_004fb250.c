int __thiscall sub_4FB250(int *this)
{
  int v3; // [esp+4h] [ebp-50h]
  float v4[2]; // [esp+10h] [ebp-44h] BYREF
  int v5; // [esp+24h] [ebp-30h] BYREF
  _BYTE v6[12]; // [esp+48h] [ebp-Ch] BYREF

  v3 = this[25];
  v4[1] = 0.0;
  sub_54FDF0(&unk_FADD40, v3, &v5, v6);
  if ( sub_4031C0() )
    return off_16C9700();
  else
    return sub_409A10(this, v4, 1);
}
