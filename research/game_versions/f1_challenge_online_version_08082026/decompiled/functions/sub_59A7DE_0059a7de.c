int __usercall sub_59A7DE@<eax>(int a1@<ebp>)
{
  _DWORD *v1; // ecx
  _DWORD *v2; // esi

  sub_58A5D8();
  v2 = v1;
  *(_DWORD *)(a1 - 16) = v1;
  *v1 = &std::runtime_error::`vftable';
  *(_DWORD *)(a1 - 4) = 0;
  sub_5993AF(v1 + 3, 1);
  *(_DWORD *)(a1 - 4) = -1;
  return sub_59BFA0(v2);
}
