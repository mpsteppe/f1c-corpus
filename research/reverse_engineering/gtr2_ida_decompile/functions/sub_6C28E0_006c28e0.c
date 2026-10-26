int __thiscall sub_6C28E0(int *this)
{
  _DWORD *v3; // eax
  char *v4; // edi
  int v5; // ebx
  unsigned int i; // eax
  int v7; // eax

  if ( *(_DWORD *)this[64] != 1342177282 )
    return 1;
  v3 = (_DWORD *)sub_681186(116);
  if ( v3 )
    v4 = (char *)sub_680CEC(v3);
  else
    v4 = 0;
  if ( !v4 )
    return -2147024882;
  v5 = sub_6811D1(v4, 1887436802, 6, 1, 0);
  if ( v5 >= 0 )
  {
    v5 = sub_680D22(v4, this[64]);
    if ( v5 >= 0 )
    {
      **((_DWORD **)v4 + 4) = **(_DWORD **)(this[64] + 16);
      for ( i = 0; i < 0x10; i += 4 )
        *(_DWORD *)(i + *((_DWORD *)v4 + 2)) = *(_DWORD *)(i + *(_DWORD *)(this[64] + 8));
      v7 = sub_681AAA(this, this[30], 0, 0, 0.0);
      if ( v7 == -1 )
        return -2147024882;
      *(_DWORD *)(*((_DWORD *)v4 + 2) + 16) = v7;
      *(_DWORD *)(*((_DWORD *)v4 + 2) + 20) = v7;
      if ( (*(int (__thiscall **)(int *, char *))(*this + 48))(this, v4) )
        v5 = 1;
      else
        v5 = sub_681430((char *)this[64], v4);
    }
  }
  sub_66238F(v4, 1);
  return v5;
}
