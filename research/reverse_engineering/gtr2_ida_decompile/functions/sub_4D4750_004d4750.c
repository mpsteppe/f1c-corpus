int __thiscall sub_4D4750(int this)
{
  int v2; // eax
  int v3; // eax
  int v4; // edi
  int v5; // edi
  int v7; // [esp+4h] [ebp-8h] BYREF
  _BYTE v8[4]; // [esp+8h] [ebp-4h] BYREF

  sub_4DE540(v8, &v7);
  *(float *)(this + 552) = sub_4DE590(*(_DWORD *)(this + 48));
  if ( *(_BYTE *)(this + 550) && *(int *)(this + 576) > 0 )
  {
    v2 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 8))(this);
    v3 = v7 - *(_DWORD *)(this + 572) / 2 - v2;
    *(_DWORD *)(this + 560) = v3;
    if ( v3 < 0 )
      *(_DWORD *)(this + 560) = 0;
    v4 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 16))(this) - *(_DWORD *)(this + 572);
    if ( *(_DWORD *)(this + 560) > v4 - (*(int (__thiscall **)(int))(*(_DWORD *)this + 8))(this) )
    {
      v5 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 16))(this) - *(_DWORD *)(this + 572);
      *(_DWORD *)(this + 560) = v5 - (*(int (__thiscall **)(int))(*(_DWORD *)this + 8))(this);
    }
    sub_4CE550((_DWORD *)this);
  }
  if ( *(float *)(this + 552) > 0.25 && *(float *)(this + 552) > 0.2 )
  {
    if ( *(_BYTE *)(this + 548) )
    {
      sub_4D3DA0((_DWORD *)this);
      return 0;
    }
    if ( *(_BYTE *)(this + 549) )
      sub_4D3E00((_DWORD *)this);
  }
  return 0;
}
