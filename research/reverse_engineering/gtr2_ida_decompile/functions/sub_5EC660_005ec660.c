char __thiscall sub_5EC660(_DWORD *this)
{
  int v2; // ebp
  int v3; // edi
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // ecx
  int v10; // eax
  int v11; // ecx
  int v12; // ecx
  int *v13; // ecx
  _DWORD *v14; // eax

  v2 = 0;
  if ( (int)this[90] > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this[91];
      v5 = *(_DWORD *)(v4 + v3);
      v6 = v3 + v4;
      if ( (v5 & 0x80000) != 0 )
      {
        sub_5E87D0(*(_DWORD **)(v6 + 4));
        sub_5EA540((int)&unk_FB27F8, 0, *(_DWORD *)(v3 + this[91] + 4), 0);
        *(_DWORD *)(v3 + this[91] + 4) = 0;
      }
      v7 = *(_DWORD *)(v3 + this[91] + 44);
      if ( v7 )
      {
        v8 = *(_DWORD *)(v7 + 12);
        if ( v8 <= 0 || (v9 = v8 - 1, (*(_DWORD *)(v7 + 12) = v9) == 0) )
          (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)dword_FB27A4 + 408))(
            dword_FB27A4,
            *(_DWORD *)(v3 + this[91] + 44),
            0);
        *(_DWORD *)(v3 + this[91] + 44) = 0;
        *(_DWORD *)(v3 + this[91] + 52) = 0;
      }
      v10 = *(_DWORD *)(v3 + this[91] + 48);
      if ( v10 )
      {
        v11 = *(_DWORD *)(v10 + 12);
        if ( v11 <= 0 || (v12 = v11 - 1, (*(_DWORD *)(v10 + 12) = v12) == 0) )
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)dword_FB27A4 + 448))(
            dword_FB27A4,
            *(_DWORD *)(v3 + this[91] + 48));
        *(_DWORD *)(v3 + this[91] + 48) = 0;
        *(_DWORD *)(v3 + this[91] + 56) = 0;
      }
      ++v2;
      v3 += 108;
    }
    while ( v2 < this[90] );
  }
  v13 = (int *)(*(_DWORD *)(this[98] + 620) + 516);
  v14 = (_DWORD *)*v13;
  if ( *v13 )
  {
    while ( !*v14 || (_DWORD *)*v14 != this )
    {
      v14 = (_DWORD *)v14[1];
      if ( !v14 )
        return (char)v14;
    }
    if ( *v14 )
      LOBYTE(v14) = sub_5DB730(v13, (int)this, 1);
  }
  return (char)v14;
}
