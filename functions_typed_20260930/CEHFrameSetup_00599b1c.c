_DWORD *__userpurge sub_599B1C@<eax>(int a1@<ebp>, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // ecx
  bool v6; // zf
  _DWORD *v7; // esi

  SEHHandlerInit();
  v6 = *(_DWORD *)(a1 + 20) == 0;
  v7 = v5;
  *(_DWORD *)(a1 - 20) = v5;
  *(_DWORD *)(a1 - 16) = 0;
  if ( !v6 )
  {
    *v5 = &unk_5B9C54;
    v5[10] = 0;
    v5[1] = &std::basic_ios<unsigned short>::`vftable';
    *(_DWORD *)(a1 - 16) = 1;
    *(_DWORD *)(a1 - 4) = 0;
  }
  v6 = *(_BYTE *)(a1 + 16) == 0;
  *(_DWORD *)((char *)v5 + *(_DWORD *)(*v5 + 4)) = &std::basic_ostream<unsigned short>::`vftable';
  if ( !v6 )
    StreamCreationWithFlagInit(*(_DWORD *)(a1 + 8), *(_DWORD *)(a1 + 12));
  return v7;
}

