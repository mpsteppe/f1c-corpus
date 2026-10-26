int __thiscall sub_4A6150(int this)
{
  int v2; // esi
  _DWORD *v3; // edi
  bool v4; // zf

  *(_DWORD *)this = &off_5E9F58;
  v2 = *(_DWORD *)(this + 268);
  while ( v2 )
  {
    v3 = (_DWORD *)v2;
    v4 = *(_BYTE *)(v2 + 12) == 0;
    v2 = *(_DWORD *)(v2 + 4);
    if ( !v4 && *v3 )
      (**(void (__thiscall ***)(_DWORD, int))*v3)(*v3, 1);
    sub_5BE8AE(v3);
  }
  *(_DWORD *)(this + 268) = 0;
  *(_DWORD *)(this + 272) = 0;
  *(_DWORD *)(this + 276) = 0;
  *(_DWORD *)(this + 280) = 0;
  return sub_49C520((LPVOID *)this);
}
