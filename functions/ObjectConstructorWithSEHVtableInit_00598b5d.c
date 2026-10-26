_DWORD *__userpurge sub_598B5D@<eax>(int a1@<ebp>, int a2, int a3)
{
  _DWORD *v3; // ecx
  bool v4; // zf
  _DWORD *v5; // esi

  SEHHandlerInit();
  v4 = *(_DWORD *)(a1 + 12) == 0;
  v5 = v3;
  *(_DWORD *)(a1 - 20) = v3;
  *(_DWORD *)(a1 - 16) = 0;
  if ( !v4 )
  {
    *v3 = &unk_5B9BC0;
    v3[11] = 0;
    v3[2] = &std::ios::`vftable';
    *(_DWORD *)(a1 - 16) = 1;
    *(_DWORD *)(a1 - 4) = 0;
  }
  *(_DWORD *)((char *)v3 + *(_DWORD *)(*v3 + 4)) = &std::istream::`vftable';
  sub_59A8FA((char *)v3 + *(_DWORD *)(*v3 + 4));
  return v5;
}
