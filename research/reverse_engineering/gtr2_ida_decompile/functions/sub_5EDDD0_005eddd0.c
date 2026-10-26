int __userpurge sub_5EDDD0@<eax>(int a1@<ecx>, int a2@<edi>, int a3, char *a4)
{
  int result; // eax
  int v6; // edi

  result = *(_DWORD *)(a1 + 24);
  if ( result > 0 )
  {
    if ( a4 )
    {
      sub_5E5050(a4, 286);
      sub_5EDC50(a1);
      v6 = 2;
      if ( (*(_BYTE *)a1 & 1) != 0 )
        v6 = 0;
      (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)dword_FB27A4 + 460))(dword_FB27A4, 0, a2);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)dword_FB27A4 + 572))(dword_FB27A4, *(_DWORD *)(a1 + 16));
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int))(*(_DWORD *)dword_FB27A4 + 420))(
        dword_FB27A4,
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 28),
        *(_DWORD *)(a1 + 24),
        *(_DWORD *)(a1 + 40),
        *(_DWORD *)(a1 + 36),
        *(_DWORD *)(a1 + 8),
        *(_DWORD *)(a1 + 12),
        3,
        v6);
      return (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_FB27A4 + 572))(dword_FB27A4, 2);
    }
    else
    {
      return off_16C9868(a3, 0);
    }
  }
  return result;
}
