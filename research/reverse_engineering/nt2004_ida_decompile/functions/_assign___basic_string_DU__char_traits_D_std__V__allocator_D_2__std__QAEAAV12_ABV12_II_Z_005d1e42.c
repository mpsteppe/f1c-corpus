int __thiscall std::string::assign(int this, _DWORD *a2, unsigned int a3, size_t a4)
{
  size_t v5; // esi
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  int v9; // eax

  if ( a2[2] < a3 )
    std::_Xran();
  v5 = a2[2] - a3;
  if ( a4 < v5 )
    v5 = a4;
  if ( (_DWORD *)this == a2 )
  {
    std::string::erase((_DWORD *)this, a3 + v5, 0xFFFFFFFF);
    std::string::erase((_DWORD *)this, 0, a3);
  }
  else
  {
    if ( !v5 || v5 != a2[2] )
      goto LABEL_22;
    v6 = (char *)a2[1];
    if ( !v6 )
      v6 = (char *)&unk_5F76C4;
    if ( (unsigned __int8)*(v6 - 1) < 0xFEu )
    {
      std::string::_Tidy((_DWORD *)this, 1);
      v7 = (char *)a2[1];
      if ( !v7 )
        v7 = (char *)&unk_5F76C4;
      *(_DWORD *)(this + 4) = v7;
      *(_DWORD *)(this + 8) = a2[2];
      *(_DWORD *)(this + 12) = a2[3];
      ++*(v7 - 1);
    }
    else
    {
LABEL_22:
      if ( std::string::_Grow((_DWORD *)this, v5, 1) )
      {
        v8 = (char *)a2[1];
        if ( !v8 )
          v8 = (char *)&unk_5F76C4;
        memcpy_0(*(void **)(this + 4), &v8[a3], v5);
        v9 = *(_DWORD *)(this + 4);
        *(_DWORD *)(this + 8) = v5;
        *(_BYTE *)(v9 + v5) = 0;
      }
    }
  }
  return this;
}
