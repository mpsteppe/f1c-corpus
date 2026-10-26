int __fastcall sub_62B590(int a1, int a2)
{
  int v2; // ecx
  int v3; // eax
  int result; // eax

  v2 = *(_DWORD *)(a2 + 66);
  *(_DWORD *)(a2 + 50) = 2 * *(_DWORD *)(a2 + 34);
  *(_WORD *)(*(_DWORD *)(a2 + 58) + 2 * v2 - 2) = 0;
  memset(*(void **)(a2 + 58), 0, 2 * *(_DWORD *)(a2 + 66) - 2);
  v3 = 6 * *(_DWORD *)(a2 + 122);
  *(_DWORD *)(a2 + 118) = (unsigned __int16)word_72EDAA[v3];
  *(_DWORD *)(a2 + 130) = (unsigned __int16)word_72EDA8[v3];
  *(_DWORD *)(a2 + 134) = (unsigned __int16)word_72EDAC[v3];
  *(_DWORD *)(a2 + 114) = (unsigned __int16)word_72EDAE[v3];
  *(_DWORD *)(a2 + 98) = 0;
  *(_DWORD *)(a2 + 82) = 0;
  *(_DWORD *)(a2 + 106) = 0;
  result = 2;
  *(_DWORD *)(a2 + 94) = 0;
  *(_DWORD *)(a2 + 62) = 0;
  *(_DWORD *)(a2 + 110) = 2;
  *(_DWORD *)(a2 + 86) = 2;
  return result;
}
