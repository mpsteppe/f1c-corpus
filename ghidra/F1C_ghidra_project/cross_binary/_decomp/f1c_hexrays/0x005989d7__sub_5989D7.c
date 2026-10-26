// f1c  0x005989d7  size=106
_DWORD *__userpurge sub_5989D7@<eax>(int a1@<ebp>, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // ecx
  bool v6; // zf
  _DWORD *v7; // esi

  sub_58A5D8();
  v6 = *(_DWORD *)(a1 + 20) == 0;
  v7 = v5;
  *(_DWORD *)(a1 - 20) = v5;
  *(_DWORD *)(a1 - 16) = 0;
  if ( !v6 )
  {
    *v5 = &unk_5B9BB8;
    v5[10] = 0;
    v5[1] = &std::ios::`vftable';
    *(_DWORD *)(a1 - 16) = 1;
    *(_DWORD *)(a1 - 4) = 0;
  }
  v6 = *(_BYTE *)(a1 + 16) == 0;
  *(_DWORD *)((char *)v5 + *(_DWORD *)(*v5 + 4)) = &std::ostream::`vftable';
  if ( !v6 )
    sub_5993EB(*(_DWORD *)(a1 + 8), *(_DWORD *)(a1 + 12));
  return v7;
}
