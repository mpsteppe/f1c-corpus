char __thiscall sub_464290(void *this)
{
  int v2; // edi
  float v4; // [esp+0h] [ebp-13Ch]
  _BYTE v5[32]; // [esp+10h] [ebp-12Ch] BYREF
  _BYTE v6[60]; // [esp+30h] [ebp-10Ch] BYREF
  _BYTE v7[208]; // [esp+6Ch] [ebp-D0h] BYREF

  sub_462C80(v5);
  if ( !(unsigned __int8)sub_464BD0(v5) )
    return 0;
  sub_465330(0);
  v2 = dword_7D6B54;
  sub_4E8D60(v6);
  sub_4E6000(&unk_76BB28);
  sub_4E8D80(v2);
  sub_462D30((int)v5);
  sub_464150(this, (int)v5);
  v4 = dbl_7DA9D0;
  sub_4D0D00(4, 5, 0, 0, LODWORD(v4), 3);
  sub_463A40(this, (int)v7, 2, -1, -1);
  sub_4BA680(&unk_76612C);
  return 1;
}
