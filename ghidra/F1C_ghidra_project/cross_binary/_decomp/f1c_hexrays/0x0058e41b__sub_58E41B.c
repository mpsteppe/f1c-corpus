// f1c  0x0058e41b  size=141
int __cdecl sub_58E41B(int a1)
{
  int v1; // eax
  int *v2; // edi
  int v3; // eax
  int v4; // edi

  if ( !sub_596007(*(_DWORD *)(a1 + 16)) )
    return 0;
  if ( (_UNKNOWN *)a1 == &unk_5E6768 )
  {
    v1 = 0;
  }
  else
  {
    if ( (_UNKNOWN *)a1 != &unk_5E6788 )
      return 0;
    v1 = 1;
  }
  ++dword_8D3EC8;
  if ( (*(_WORD *)(a1 + 12) & 0x10C) != 0 )
    return 0;
  v2 = (int *)(4 * v1 + 9256784);
  if ( dword_8D3F50[v1] || (v3 = sub_58A935(4096), (*v2 = v3) != 0) )
  {
    v4 = *v2;
    *(_DWORD *)(a1 + 24) = 4096;
    *(_DWORD *)(a1 + 8) = v4;
    *(_DWORD *)a1 = v4;
    *(_DWORD *)(a1 + 4) = 4096;
  }
  else
  {
    *(_DWORD *)(a1 + 8) = a1 + 20;
    *(_DWORD *)a1 = a1 + 20;
    *(_DWORD *)(a1 + 24) = 2;
    *(_DWORD *)(a1 + 4) = 2;
  }
  *(_WORD *)(a1 + 12) |= 0x1102u;
  return 1;
}
