char __thiscall sub_404F90(_BYTE *this)
{
  char v2; // al
  char v3; // al
  int v4; // eax
  int v6[3]; // [esp+4h] [ebp-18h] BYREF
  _DWORD v7[3]; // [esp+10h] [ebp-Ch] BYREF

  if ( !(unsigned __int8)sub_42DBA0(&unk_62BF64)
    || !dword_75AACC
    || *(_DWORD *)((unsigned __int8)sub_42DBA0(&unk_62BF64) != 0 ? dword_75AACC + 0x62B0 : 25264) == -1 )
  {
    return this[432];
  }
  v2 = sub_42DBA0(&unk_62BF64);
  sub_4045E0(&flt_628F60, *(_DWORD *)(v2 != 0 ? dword_75AACC + 0x62B0 : 25264), v6, v7);
  v3 = sub_42DBA0(&unk_62BF64);
  v4 = sub_4040B0(
         &flt_628F60,
         (float *)v6,
         0,
         dword_628FA8 + *(_DWORD *)(v3 != 0 ? dword_75AACC + 0x62B0 : 25264),
         0.0,
         0);
  return !v4 || *(float *)(v4 + 24) <= 0.0;
}
