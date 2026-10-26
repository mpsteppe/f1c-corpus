// positive sp value has been detected, the output may be wrong!
int __thiscall sub_4E8030(_DWORD *this)
{
  int result; // eax
  int v3; // [esp-8h] [ebp-Ch]
  int v4; // [esp-4h] [ebp-8h]

  sub_4E6280(this);
  sub_40DEA0(&flt_757718);
  sub_4744F0(&dword_B6CBA8);
  ((void (__thiscall *)(int *))sub_563AC0)(&dword_FAE988);
  if ( byte_B6FAB4 )
    sub_41D510(flt_91CB98);
  if ( byte_B6FACC )
    sub_41D7B0();
  sub_4EA810(&unk_B6E7A8);
  sub_472FD0(&dword_B6CB98);
  sub_4E7B50(this);
  result = sub_4E7A30(v3, v4);
  if ( (byte_B72254 & 8) != 0 )
    return sub_44AB50(&dbl_B66040);
  return result;
}
