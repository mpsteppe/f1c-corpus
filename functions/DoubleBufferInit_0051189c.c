int __cdecl sub_51189C(int a1, const void *a2)
{
  _BYTE v3[80]; // [esp+0h] [ebp-50h] BYREF

  sub_5117C8(a1, a2);
  return GuardedCallWithLongjmp(a1, (int)v3);
}
