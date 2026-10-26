int __thiscall sub_6713D0(int this)
{
  _DWORD *v2; // ebx
  int result; // eax
  void *v4; // edi
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // eax

  v2 = *(_DWORD **)(this + 4);
  if ( !v2 || v2[1] != 4 )
    return 0;
  if ( !*(_DWORD *)(this + 8) )
    return -2147467259;
  result = sub_686A7B(v2, *(_DWORD *)this + 24, *(_DWORD *)(this + 16), *(_DWORD *)(this + 20));
  if ( result >= 0 )
  {
    j__free(*(void **)(this + 24));
    v4 = operator new(4 * v2[6]);
    *(_DWORD *)(this + 24) = v4;
    if ( v4 )
    {
      memset(v4, 0xFFu, 4 * v2[6]);
      v5 = sub_681AAA(*(_DWORD *)(*(_DWORD *)(this + 8) + 120), 0, 0, 1.0);
      v6 = *(_DWORD *)(this + 8);
      *(_DWORD *)(this + 32) = v5;
      v7 = sub_681AAA(*(_DWORD *)(v6 + 120), 0, 0, 0.0);
      v8 = *(_DWORD *)(this + 8);
      *(_DWORD *)(this + 36) = v7;
      v9 = sub_681AAA(*(_DWORD *)(v8 + 120), 0, 0, -1.0);
      *(_DWORD *)(this + 48) = -1;
      *(_DWORD *)(this + 40) = v9;
      *(_DWORD *)(this + 44) = *(_DWORD *)(this + 32);
      *(_DWORD *)(this + 52) = 1;
      result = sub_67051D(this, v2[7], 0);
      if ( result >= 0 )
        return *(_DWORD *)(this + 76) != 0 ? 0x80004005 : 0;
    }
    else
    {
      return -2147024882;
    }
  }
  return result;
}
