int __thiscall sub_6C59C9(_DWORD *this, int a2, unsigned int *a3, int a4, _DWORD *a5)
{
  int v6; // eax
  unsigned int v7; // eax
  bool v8; // cf
  unsigned int v9; // ecx
  int result; // eax
  int v11; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v12; // [esp+10h] [ebp-4h] BYREF

  v11 = 0;
  v12 = 0;
  if ( a5 )
    *a5 = 0;
  v6 = *(_DWORD *)(a2 + 4);
  if ( this[34] == v6 )
  {
    v7 = *(_DWORD *)(a2 + 12);
    v8 = v7 < this[11];
    v11 = 0;
    v12 = v7;
    if ( !v8 )
    {
      sub_686791((int)this, *(_DWORD *)(this[64] + 60), 4505, "maximum temp register index exceeded");
      return -2005529767;
    }
    v9 = this[20];
    if ( v9 && v7 >= v9 )
    {
      v7 -= v9;
      v12 = v7;
      v11 = 3;
    }
  }
  else if ( this[35] == v6 )
  {
    v7 = *(_DWORD *)(a2 + 12);
    v11 = 3;
    v12 = v7;
    if ( v7 )
    {
      sub_686791((int)this, *(_DWORD *)(this[64] + 60), 4508, "maximum address register index exceeded");
      return -2005529767;
    }
  }
  else if ( this[33] == v6 )
  {
    if ( (*(int (__thiscall **)(_DWORD *, int, unsigned int *, int *, _DWORD *))(*this + 132))(this, a2, &v12, &v11, a5) < 0 )
      return -2147467259;
    LOWORD(v7) = v12;
  }
  else
  {
    if ( this[36] != v6 )
    {
      sub_686791((int)this, 0, 0, "internal error: unexpected output register type");
      return -2147467259;
    }
    v7 = *(_DWORD *)(a2 + 12);
    v8 = v7 < this[13];
    v11 = 19;
    v12 = v7;
    if ( !v8 )
    {
      sub_686791((int)this, *(_DWORD *)(this[64] + 60), 4549, "maximum predicate register index exceeded");
      return -2005529767;
    }
  }
  if ( a3 )
    *a3 = v7 & 0x7FF | ((v11 & 0x18 | ((v11 | 0xFFFFFFF8) << 20)) << 8);
  result = (*(int (__thiscall **)(_DWORD *, int, int))(*this + 124))(this, a2, a4);
  if ( result >= 0 )
    return 0;
  return result;
}
