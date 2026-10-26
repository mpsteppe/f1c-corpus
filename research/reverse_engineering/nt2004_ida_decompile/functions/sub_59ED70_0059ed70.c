BOOL __thiscall sub_59ED70(int this, float *a2, int a3)
{
  int *v5; // edi
  int v6; // eax
  int v7; // esi
  int v8; // ebp
  int v10; // [esp+14h] [ebp+8h]

  if ( (*(_BYTE *)(this + 60) & 0x10) != 0 )
  {
    v5 = (int *)(a3 + 20);
    if ( (*(_DWORD *)(a3 + 20) & 0x20000000) == 0 )
    {
      (*(void (__cdecl **)(int, int, int, int))(*(_DWORD *)dword_7E8E58 + 4))(
        dword_7E8E58,
        *(_DWORD *)(this + 516) + 220,
        a3 + 232,
        this + 276);
      *v5 |= 0x20000000u;
    }
    sub_59C1A0(a3, a2, (float *)(a3 + 232), 1);
    v6 = *v5;
    if ( (*v5 & 4) != 0 )
    {
      if ( (v6 & 8) == 0 )
      {
        v10 = this + 276;
        *v5 = v6 | 8;
        v7 = a3 + 28;
        v8 = 8;
        do
        {
          (*(void (__cdecl **)(int, int, int, int))(*(_DWORD *)dword_7E8E58 + 4))(dword_7E8E58, v7, v7 + 96, v10);
          v7 += 12;
          --v8;
        }
        while ( v8 );
      }
      sub_59C310((_DWORD *)a3, (int)a2, a3 + 124);
    }
  }
  else
  {
    sub_59C1A0(a3, a2, (float *)(a3 + 220), 1);
    v5 = (int *)(a3 + 20);
    if ( (*(_BYTE *)(a3 + 20) & 4) != 0 )
      sub_59C310((_DWORD *)a3, (int)a2, a3 + 28);
  }
  return (*(_BYTE *)v5 & 5) != 0;
}
