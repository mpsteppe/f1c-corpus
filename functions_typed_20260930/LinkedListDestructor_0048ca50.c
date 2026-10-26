int __thiscall sub_48CA50(int this)
{
  int v2; // esi
  _DWORD *v3; // edi
  bool v4; // zf

  *(_DWORD *)this = &off_5AC048;
  v2 = *(_DWORD *)(this + 796);
  while ( v2 )
  {
    v3 = (_DWORD *)v2;
    v4 = *(_BYTE *)(v2 + 12) == 0;
    v2 = *(_DWORD *)(v2 + 4);
    if ( !v4 && *v3 )
      (**(void (__thiscall ***)(_DWORD, int))*v3)(*v3, 1);
    FreeWrapper_7bcf(v3);
  }
  *(_DWORD *)(this + 796) = 0;
  *(_DWORD *)(this + 800) = 0;
  *(_DWORD *)(this + 804) = 0;
  *(_DWORD *)(this + 808) = 0;
  *(_DWORD *)(this + 796) = 0;
  *(_DWORD *)(this + 800) = 0;
  *(_DWORD *)(this + 804) = 0;
  *(_DWORD *)(this + 808) = 0;
  return VTableInit((LPVOID *)this);
}

