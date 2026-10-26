// f1c  0x00598a41  size=95
_DWORD *__userpurge sub_598A41@<eax>(int a1@<ebp>, int a2, int a3)
{
  _DWORD *v3; // ecx
  bool v4; // zf
  _DWORD *v5; // esi

  sub_58A5D8();
  v4 = *(_DWORD *)(a1 + 12) == 0;
  v5 = v3;
  *(_DWORD *)(a1 - 20) = v3;
  *(_DWORD *)(a1 - 16) = 0;
  if ( !v4 )
  {
    *v3 = &unk_5B9BB8;
    v3[10] = 0;
    v3[1] = &std::ios::`vftable';
    *(_DWORD *)(a1 - 16) = 1;
    *(_DWORD *)(a1 - 4) = 0;
  }
  *(_DWORD *)((char *)v3 + *(_DWORD *)(*v3 + 4)) = &std::ostream::`vftable';
  sub_59A8FA((char *)v3 + *(_DWORD *)(*v3 + 4));
  return v5;
}
