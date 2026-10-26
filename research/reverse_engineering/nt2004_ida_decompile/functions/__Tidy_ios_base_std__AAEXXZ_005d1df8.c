void __thiscall std::ios_base::_Tidy(std::ios_base *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // edi
  _DWORD *v4; // eax
  _DWORD *v5; // edi

  std::ios_base::_Callfns(this, 0);
  v2 = (_DWORD *)*((_DWORD *)this + 6);
  if ( v2 )
  {
    do
    {
      v3 = (_DWORD *)*v2;
      sub_5BE8AE(v2);
      v2 = v3;
    }
    while ( v3 );
  }
  v4 = (_DWORD *)*((_DWORD *)this + 7);
  *((_DWORD *)this + 6) = 0;
  if ( v4 )
  {
    do
    {
      v5 = (_DWORD *)*v4;
      sub_5BE8AE(v4);
      v4 = v5;
    }
    while ( v5 );
  }
  *((_DWORD *)this + 7) = 0;
}
