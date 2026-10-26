int __cdecl sub_58B903(int a1, int a2)
{
  int v2; // esi

  CriticalSectionLazyInitEnter(12);
  v2 = sub_58B92A(0, a1, a2);
  CritSectLeave(12);
  return v2;
}
