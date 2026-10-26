int __thiscall sub_5569F0(void *this, int a2, int a3)
{
  int v3; // ebp
  int v4; // edi
  int v5; // eax
  int v6; // ebp
  int v7; // edi
  int v8; // ebx
  int result; // eax

  v3 = (int)this;
  LinkedListTraversalWithConditionalTimerUpdate((_DWORD *)a3);
  v4 = a2;
  sub_54B570(v3, (float *)a2, a3);
  if ( !*(_DWORD *)(a2 + 428) )
    MeshBoundingBoxComputation(a3);
  if ( (*(_DWORD *)(a3 + 20) & 0x20000000) == 0 )
  {
    (*(void (__cdecl **)(int, int, int, int))(*(_DWORD *)dword_8B8F24 + 4))(
      dword_8B8F24,
      *(_DWORD *)(v3 + 516) + 220,
      a3 + 232,
      v3 + 416);
    *(_DWORD *)(a3 + 20) |= 0x20000000u;
  }
  CollisionContactStateDetection(a3, (float *)a2, (float *)(a3 + 232), 0);
  v5 = *(_DWORD *)(a3 + 20);
  if ( (v5 & 4) != 0 && (v5 & 8) == 0 )
  {
    *(_DWORD *)(a3 + 20) = v5 | 8;
    v6 = v3 + 416;
    v7 = a3 + 28;
    v8 = 8;
    do
    {
      (*(void (__cdecl **)(int, int, int, int))(*(_DWORD *)dword_8B8F24 + 4))(dword_8B8F24, v7, v7 + 96, v6);
      v7 += 12;
      --v8;
    }
    while ( v8 );
    v4 = a2;
    v3 = (int)this;
  }
  result = *(_DWORD *)(a3 + 20);
  if ( (result & 5) != 0 )
  {
    if ( (result & 0x20) == 0 )
    {
      if ( (**(_DWORD **)(a3 + 284) & 0x100) != 0 )
        sub_55ED10(v3, a3, v3 + 276);
      if ( (*(_DWORD *)(a3 + 20) & 0x100000) != 0 )
        sub_55D5C0(v4, 0);
    }
    return sub_556D60(a3, v4);
  }
  return result;
}
