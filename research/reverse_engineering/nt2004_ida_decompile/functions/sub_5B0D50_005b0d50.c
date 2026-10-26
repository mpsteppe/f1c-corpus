char __thiscall sub_5B0D50(int this, int a2, int a3, int a4, int a5, int a6, int a7)
{
  _DWORD *v8; // eax
  int v9; // ecx

  if ( *(_DWORD *)(this + 76) == 1 )
  {
    LOBYTE(v8) = *(_BYTE *)(this + 32);
    if ( (char)v8 < 0 )
    {
      sub_5B0C50((_DWORD *)this, 0);
      v8 = *(_DWORD **)(this + 80);
      v9 = v8[8];
      if ( v9 )
      {
        v8 = (_DWORD *)(v9 + ((a3 + *(_DWORD *)(this + 36) * *(_DWORD *)((a2 << 7) + *(_DWORD *)(this + 52) + 4)) << 6));
        *v8 = a4;
        v8[1] = a5;
        v8[2] = a6;
        v8[6] = a7;
      }
    }
  }
  return (char)v8;
}
