int __thiscall sub_4902C0(int this)
{
  int v2; // esi
  _DWORD *v3; // edi
  bool v4; // zf

  *(_DWORD *)this = &off_5AC760;
  v2 = *(_DWORD *)(this + 224);
  while ( v2 )
  {
    v3 = (_DWORD *)v2;
    v4 = *(_BYTE *)(v2 + 12) == 0;
    v2 = *(_DWORD *)(v2 + 4);
    if ( !v4 && *v3 )
      (**(void (__thiscall ***)(_DWORD, int))*v3)(*v3, 1);
    sub_587BCF(v3);
  }
  *(_DWORD *)(this + 224) = 0;
  *(_DWORD *)(this + 228) = 0;
  *(_DWORD *)(this + 232) = 0;
  *(_DWORD *)(this + 236) = 0;
  return sub_485EB0((LPVOID *)this);
}
