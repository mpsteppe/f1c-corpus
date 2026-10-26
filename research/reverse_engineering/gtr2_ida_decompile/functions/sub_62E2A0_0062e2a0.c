_DWORD *__fastcall sub_62E2A0(int a1, _BYTE *a2, int a3, int a4)
{
  int v5; // ecx
  int v7; // edx
  int v8; // ecx
  char v9; // bl
  int v10; // edx
  int v11; // ecx
  int v12; // ebx

  v5 = *(_DWORD *)(a1 + 5805);
  if ( v5 <= 13 )
  {
    *(_DWORD *)(a1 + 5805) = v5 + 3;
    *(_WORD *)(a1 + 5803) |= a4 << v5;
  }
  else
  {
    v7 = a4 << v5;
    v8 = *(_DWORD *)(a1 + 8);
    *(_WORD *)(a1 + 5803) |= v7;
    *(_BYTE *)(v8 + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5803);
    v9 = *(_BYTE *)(a1 + 5804);
    v10 = *(_DWORD *)(a1 + 8);
    v11 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v11;
    *(_BYTE *)(v11 + v10) = v9;
    ++*(_DWORD *)(a1 + 20);
    v12 = *(_DWORD *)(a1 + 5805);
    *(_DWORD *)(a1 + 5805) = v12 - 13;
    *(_WORD *)(a1 + 5803) = (unsigned __int16)a4 >> (16 - v12);
  }
  return sub_62DEC0(a1, a2, a3, 1);
}
