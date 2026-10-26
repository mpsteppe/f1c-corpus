void __thiscall sub_49A190(int *this)
{
  _DWORD *v2; // ecx
  void (__thiscall ***v3)(_DWORD, int); // ecx

  v2 = (_DWORD *)*this;
  if ( v2 )
  {
    do
    {
      *this = sub_499E00(v2);
      if ( v3 )
        (**v3)(v3, 1);
      v2 = (_DWORD *)*this;
    }
    while ( *this );
  }
}

