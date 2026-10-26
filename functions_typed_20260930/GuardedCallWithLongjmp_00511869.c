int __cdecl sub_511869(int a1, int a2)
{
  void (__cdecl *v2)(int, int); // eax

  v2 = *(void (__cdecl **)(int, int))(a1 + 64);
  if ( v2 )
    v2(a1, a2);
  LongjmpMSVCCRT(a1, 1);
  return CallbackDispatch(a1, a2);
}

