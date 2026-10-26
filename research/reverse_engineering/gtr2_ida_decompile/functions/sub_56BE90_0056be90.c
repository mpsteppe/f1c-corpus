char __thiscall sub_56BE90(int this)
{
  char v2; // bl
  int v3; // eax
  int v4; // ecx
  char v6; // [esp+Bh] [ebp-Dh]
  float v7; // [esp+Ch] [ebp-Ch] BYREF
  int v8; // [esp+10h] [ebp-8h]
  int v9; // [esp+14h] [ebp-4h]

  v2 = 1;
  if ( !*(_DWORD *)(this + 1784) || !*(_BYTE *)(this + 1848) || (v6 = 1, !*(_BYTE *)(this + 3061)) )
    v6 = 0;
  v3 = *(_DWORD *)(this + 1852);
  if ( !v3 || (LOBYTE(v3) = *(_BYTE *)(this + 1916), !(_BYTE)v3) || (LOBYTE(v3) = *(_BYTE *)(this + 3061), !(_BYTE)v3) )
    v2 = 0;
  if ( *(_DWORD *)(this + 2492) )
  {
    if ( v6 && v2 )
      LOBYTE(v3) = ((int (*)(void))sub_5FF0C0)();
    else
      LOBYTE(v3) = sub_5FF0D0();
  }
  v4 = *(_DWORD *)(this + 2496);
  if ( v4 )
  {
    if ( v6 )
    {
      if ( !v2 )
      {
        v7 = fabs(*(float *)(v4 + 188));
        v8 = *(_DWORD *)(v4 + 192);
        v9 = *(_DWORD *)(v4 + 196);
        sub_5FF0C0(v4);
        LOBYTE(v3) = sub_5FEE10(&v7);
        return v3;
      }
    }
    else if ( v2 )
    {
      v7 = -fabs(*(float *)(v4 + 188));
      v8 = *(_DWORD *)(v4 + 192);
      v9 = *(_DWORD *)(v4 + 196);
      sub_5FEE10(&v7);
      LOBYTE(v3) = sub_5FF0C0(*(_DWORD *)(this + 2496));
      return v3;
    }
    LOBYTE(v3) = sub_5FF0D0();
  }
  return v3;
}
