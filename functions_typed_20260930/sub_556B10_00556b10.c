int __thiscall sub_556B10(int this, float *a2, int a3)
{
  int v3; // edi
  int v4; // ebp
  int v5; // eax
  int v6; // ebp
  int v7; // edi
  int v8; // ebx
  int result; // eax
  int v10; // ebx
  int v11; // edi

  v3 = this;
  if ( (*(_BYTE *)(this + 60) & 0x10) != 0 )
  {
    if ( (*(_DWORD *)(a3 + 20) & 0x20000000) == 0 )
    {
      (*(void (__cdecl **)(int, int, int, int))(*(_DWORD *)dword_8B8F24 + 4))(
        dword_8B8F24,
        *(_DWORD *)(this + 516) + 220,
        a3 + 232,
        this + 416);
      *(_DWORD *)(a3 + 20) |= 0x20000000u;
    }
    v4 = (int)a2;
    CollisionContactStateDetection(a3, a2, (float *)(a3 + 232), 0);
    v5 = *(_DWORD *)(a3 + 20);
    if ( (v5 & 4) != 0 )
    {
      if ( (v5 & 8) == 0 )
      {
        v6 = v3 + 416;
        *(_DWORD *)(a3 + 20) = v5 | 8;
        v7 = a3 + 28;
        v8 = 8;
        do
        {
          (*(void (__cdecl **)(int, int, int, int))(*(_DWORD *)dword_8B8F24 + 4))(dword_8B8F24, v7, v7 + 96, v6);
          v7 += 12;
          --v8;
        }
        while ( v8 );
        v4 = (int)a2;
        v3 = this;
      }
      AABBFrustumVisibilityClassification((_DWORD *)a3, v4, a3 + 124);
    }
  }
  else
  {
    CollisionContactStateDetection(a3, a2, (float *)(a3 + 220), 0);
    if ( (*(_BYTE *)(a3 + 20) & 4) != 0 )
      AABBFrustumVisibilityClassification((_DWORD *)a3, (int)a2, a3 + 28);
    v4 = (int)a2;
  }
  result = *(_DWORD *)(a3 + 20);
  if ( (result & 5) != 0 )
  {
    if ( (*(_BYTE *)(v3 + 60) & 0x10) != 0 )
    {
      if ( (result & 0x20) == 0 && (result & 0x2000000) == 0 )
      {
        if ( (**(_DWORD **)(a3 + 284) & 0x100) != 0 )
          sub_55ED10(v3, a3, v3 + 276);
        if ( (*(_DWORD *)(a3 + 20) & 0x100000) != 0 )
        {
          sub_55D5C0(v4, 0);
          return sub_556D60(a3, v4);
        }
      }
    }
    else if ( (result & 0x10000000) != 0 )
    {
      v10 = 0;
      if ( *(int *)(a3 + 280) > 0 )
      {
        v11 = 0;
        do
        {
          *(_DWORD *)(*(_DWORD *)(a3 + 284) + v11 + 56) |= 0x400u;
          sub_55D720(v4, 1);
          ++v10;
          v11 += 64;
        }
        while ( v10 < *(_DWORD *)(a3 + 280) );
      }
      *(_DWORD *)(a3 + 20) &= ~0x10000000u;
    }
    return sub_556D60(a3, v4);
  }
  return result;
}

