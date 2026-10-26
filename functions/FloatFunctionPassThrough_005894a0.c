int __usercall sub_5894A0@<eax>(unsigned __int64 a1@<st0>)
{
  int v2; // [esp+0h] [ebp-8h]
  int v3; // [esp+4h] [ebp-4h]

  FloatExponentExtractWithNaNGuard(a1, HIDWORD(a1));
  return sub_5894BD(v2, v3);
}
