int __thiscall sub_60CFE0(void *this, int a2, _DWORD *a3)
{
  int result; // eax
  _DWORD *v5; // edi

  result = a2;
  if ( a2 )
  {
    v5 = *(_DWORD **)(a2 + 44);
    result = *(_DWORD *)(a2 + 48);
    if ( result )
      result = (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 36))(this, result);
  }
  else
  {
    v5 = a3;
  }
  if ( v5 )
  {
    result = v5[6];
    if ( (result & 0xFF000) != 0 )
    {
      if ( (result & 0x2000) != 0
        || (result & 0x1000) != 0
        || (result & 0x8000) != 0
        || (result & 0x4000) != 0
        || (result & 0x20000) != 0 )
      {
        result = (*(int (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 32))(this, v5[8]);
        ++v5[4];
        return result;
      }
    }
    else
    {
      if ( (result & 1) != 0 )
        result = (*(int (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 32))(this, v5[9]);
      if ( (v5[6] & 2) != 0 )
        result = (*(int (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 32))(this, v5[10]);
      if ( (v5[6] & 4) != 0 )
        result = (*(int (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 32))(this, v5[11]);
      if ( (v5[6] & 0x10) != 0 )
        result = (*(int (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 32))(this, v5[12]);
      if ( (v5[6] & 0x20) != 0 )
        result = (*(int (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 32))(this, v5[13]);
    }
    ++v5[4];
  }
  return result;
}
