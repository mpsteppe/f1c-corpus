int __thiscall sub_5AE2B0(int this, float *a2, int a3, int a4)
{
  int v4; // edi
  int v5; // ebp
  int v6; // eax
  int v7; // ebp
  int v8; // edi
  int v9; // ebx
  int result; // eax
  int v11; // ebx
  int v12; // edi

  v4 = this;
  if ( (*(_BYTE *)(this + 60) & 0x10) != 0 )
  {
    if ( (*(_DWORD *)(a3 + 20) & 0x20000000) == 0 )
    {
      (*(void (__cdecl **)(int, int, int, int))(*(_DWORD *)dword_7E8E58 + 4))(
        dword_7E8E58,
        *(_DWORD *)(this + 516) + 220,
        a3 + 232,
        this + 416);
      *(_DWORD *)(a3 + 20) |= 0x20000000u;
    }
    v5 = (int)a2;
    sub_59C1A0(a3, a2, (float *)(a3 + 232), 0);
    v6 = *(_DWORD *)(a3 + 20);
    if ( (v6 & 4) != 0 )
    {
      if ( (v6 & 8) == 0 )
      {
        v7 = v4 + 416;
        v8 = a3 + 28;
        v9 = 8;
        do
        {
          (*(void (__cdecl **)(int, int, int, int))(*(_DWORD *)dword_7E8E58 + 4))(dword_7E8E58, v8, v8 + 96, v7);
          v8 += 12;
          --v9;
        }
        while ( v9 );
        v5 = (int)a2;
        v4 = this;
        *(_DWORD *)(a3 + 20) |= 8u;
      }
      sub_59C310((_DWORD *)a3, v5, a3 + 124);
    }
  }
  else
  {
    sub_59C1A0(a3, a2, (float *)(a3 + 220), 0);
    if ( (*(_BYTE *)(a3 + 20) & 4) != 0 )
      sub_59C310((_DWORD *)a3, (int)a2, a3 + 28);
    v5 = (int)a2;
  }
  result = *(_DWORD *)(a3 + 20);
  if ( (result & 5) != 0 )
  {
    if ( (*(_BYTE *)(v4 + 60) & 0x10) != 0 )
    {
      if ( (result & 0x20) == 0 && (result & 0x2000000) == 0 )
      {
        if ( (**(_DWORD **)(a3 + 284) & 0x100) != 0 )
          sub_5B7210(v4, a3, v4 + 276);
        if ( (*(_DWORD *)(a3 + 20) & 0x100000) != 0 )
        {
          sub_5B5C60(v5, 0);
          return sub_5AE500(a3, v5);
        }
      }
    }
    else if ( (result & 0x10000000) != 0 )
    {
      v11 = 0;
      if ( *(int *)(a3 + 280) > 0 )
      {
        v12 = 0;
        do
        {
          *(_DWORD *)(*(_DWORD *)(a3 + 284) + v12 + 56) |= 0x400u;
          sub_5B5DC0(v5, 1);
          ++v11;
          v12 += 64;
        }
        while ( v11 < *(_DWORD *)(a3 + 280) );
      }
      *(_DWORD *)(a3 + 20) &= ~0x10000000u;
    }
    return sub_5AE500(a3, v5);
  }
  return result;
}
