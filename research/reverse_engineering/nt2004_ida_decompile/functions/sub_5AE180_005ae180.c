int __thiscall sub_5AE180(void *this, int a2, int a3, int a4)
{
  int v4; // ebp
  int v5; // edi
  int v6; // eax
  int v7; // ebp
  int v8; // edi
  int v9; // ebx
  int result; // eax

  v4 = (int)this;
  sub_5ADB50((_DWORD *)a3);
  v5 = a2;
  sub_59E210(v4, (float *)a2, a3);
  if ( !*(_DWORD *)(a2 + 620) )
    sub_59C3F0(a3, 0.0);
  if ( (*(_DWORD *)(a3 + 20) & 0x20000000) == 0 )
  {
    (*(void (__cdecl **)(int, int, int, int))(*(_DWORD *)dword_7E8E58 + 4))(
      dword_7E8E58,
      *(_DWORD *)(v4 + 516) + 220,
      a3 + 232,
      v4 + 416);
    *(_DWORD *)(a3 + 20) |= 0x20000000u;
  }
  sub_59C1A0(a3, (float *)a2, (float *)(a3 + 232), 0);
  v6 = *(_DWORD *)(a3 + 20);
  if ( (v6 & 4) != 0 && (v6 & 8) == 0 )
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
    v5 = a2;
    v4 = (int)this;
    *(_DWORD *)(a3 + 20) |= 8u;
  }
  result = *(_DWORD *)(a3 + 20);
  if ( (result & 5) != 0 )
  {
    if ( (result & 0x20) == 0 && (result & 0x2000000) == 0 )
    {
      if ( (**(_DWORD **)(a3 + 284) & 0x100) != 0 )
        sub_5B7210(v4, a3, v4 + 276);
      if ( (*(_DWORD *)(a3 + 20) & 0x100000) != 0 )
        sub_5B5C60(v5, 0);
    }
    return sub_5AE500(a3, v5);
  }
  return result;
}
