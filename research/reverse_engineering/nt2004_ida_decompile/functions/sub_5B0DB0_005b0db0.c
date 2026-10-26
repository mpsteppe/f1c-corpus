char __thiscall sub_5B0DB0(int this, int a2, int a3, int a4, int a5)
{
  int v6; // eax
  int v7; // ecx

  if ( *(_DWORD *)(this + 76) == 1 )
  {
    LOBYTE(v6) = *(_BYTE *)(this + 32);
    if ( (v6 & 0x80u) != 0 )
    {
      sub_5B0C50((_DWORD *)this, 0);
      v6 = *(_DWORD *)(this + 80);
      v7 = *(_DWORD *)(v6 + 32);
      if ( v7 )
      {
        v6 = v7 + ((a3 + *(_DWORD *)(this + 36) * *(_DWORD *)((a2 << 7) + *(_DWORD *)(this + 52) + 4)) << 6);
        *(_DWORD *)(v6 + 32) = a4;
        *(_DWORD *)(v6 + 36) = a5;
      }
    }
  }
  return v6;
}
