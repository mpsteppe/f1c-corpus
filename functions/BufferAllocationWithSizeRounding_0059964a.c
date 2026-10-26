int __userpurge sub_59964A@<eax>(int a1@<ebp>, int a2)
{
  unsigned int v2; // edi
  int v3; // ecx
  int v4; // esi
  int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // ebx
  int v8; // eax
  int result; // eax
  int v10; // [esp-18h] [ebp-18h] BYREF

  SEHHandlerInit();
  v2 = *(_DWORD *)(a1 + 8) | 0x1F;
  v4 = v3;
  *(_DWORD *)(a1 - 16) = &v10;
  *(_DWORD *)(a1 - 20) = v3;
  if ( v2 > 0xFFFFFFFD )
    v2 = *(_DWORD *)(a1 + 8);
  *(_DWORD *)(a1 - 4) = 0;
  v5 = v2 + 2;
  if ( (int)(v2 + 2) < 0 )
    v5 = 0;
  *(_DWORD *)(a1 + 8) = OperatorNewNhMallocWrapper(v5);
  v6 = *(_DWORD *)(v4 + 8);
  if ( v6 )
  {
    if ( v6 > v2 )
      v6 = v2;
    MemoryCopy_cc00(*(_DWORD *)(a1 + 8) + 1, *(_BYTE **)(v4 + 4), v6);
  }
  v7 = *(_DWORD *)(v4 + 8);
  ReferenceCountDecrementWithConditionalFree((_DWORD *)v4, 1);
  v8 = *(_DWORD *)(a1 + 8) + 1;
  *(_DWORD *)(v4 + 4) = v8;
  *(_BYTE *)(v8 - 1) = 0;
  *(_DWORD *)(v4 + 12) = v2;
  if ( v7 <= v2 )
    v2 = v7;
  result = *(_DWORD *)(v4 + 4);
  *(_DWORD *)(v4 + 8) = v2;
  *(_BYTE *)(result + v2) = 0;
  return result;
}
