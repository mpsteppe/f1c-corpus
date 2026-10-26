int __thiscall sub_6028C0(void *this, int *a2)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  char v8; // [esp+0h] [ebp-8h]

  if ( (*(int (__thiscall **)(void *, int *))(*(_DWORD *)this + 248))(this, a2) )
    return -1;
  v3 = sub_5E7150(a2, 4);
  if ( (*(_BYTE *)a2 & 4) != 0 && v3 )
  {
    if ( (*(int (__stdcall **)(int))(*(_DWORD *)v3 + 8))(v3) )
    {
      sub_5D8C80((int)this + 4, (char *)0xFFFFFFFF, "Error releasing D3D system texture", v8);
      return -1;
    }
    sub_5E71A0(a2, 0, 4);
    *a2 &= ~4u;
  }
  v4 = sub_5E7150(a2, 8);
  if ( (*(_BYTE *)a2 & 8) != 0 && v4 )
  {
    if ( (*(int (__stdcall **)(int))(*(_DWORD *)v4 + 8))(v4) )
    {
      sub_5D8C80((int)this + 4, (char *)0xFFFFFFFF, "Error releasing D3D video texture", v8);
      return -1;
    }
    sub_5E71A0(a2, 0, 8);
    *a2 &= ~8u;
  }
  v5 = sub_5E7120(a2, 1);
  if ( (*(_BYTE *)a2 & 1) != 0 && v5 )
  {
    if ( (*(int (__stdcall **)(int))(*(_DWORD *)v5 + 8))(v5) )
    {
      sub_5D8C80((int)this + 4, (char *)0xFFFFFFFF, "Error releasing D3D system surface", v8);
      return -1;
    }
    sub_5E7180(a2, 0, 1);
    *a2 &= ~1u;
  }
  v6 = sub_5E7120(a2, 2);
  if ( (*(_BYTE *)a2 & 2) != 0 && v6 )
  {
    if ( (*(int (__stdcall **)(int))(*(_DWORD *)v6 + 8))(v6) )
    {
      sub_5D8C80((int)this + 4, (char *)0xFFFFFFFF, "Error releasing D3D video surface", v8);
      return -1;
    }
    sub_5E7180(a2, 0, 2);
    *a2 &= ~2u;
  }
  return 0;
}
