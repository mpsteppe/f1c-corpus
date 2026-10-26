void __thiscall sub_4EEFF0(float *this)
{
  double v2; // st7
  double v3; // st7
  int v4; // ecx
  _DWORD *v5; // eax
  bool v6; // zf
  int v7; // eax
  int v8; // ecx
  _DWORD *v9; // eax

  if ( *((_DWORD *)this + 2) )
  {
    v2 = *this - dbl_7DA9C8;
    *this = v2;
    if ( v2 < 0.0 )
    {
      sub_4EF140(0.40000001);
      v3 = *this + 0.40000001;
      *this = v3;
      if ( v3 < 0.0 )
        *this = 0.0;
    }
    if ( dword_7D6BB0 )
    {
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)dword_7D6BB0 + 44))(dword_7D6BB0, 0, 0, 0);
      v4 = *((_DWORD *)this + 2);
      v5 = *(_DWORD **)v4;
      v6 = *(_DWORD *)v4 == 0;
      *(_DWORD *)(v4 + 8) = *(_DWORD *)v4;
      if ( !v6 )
      {
        if ( *v5 )
        {
          do
          {
            sub_4F0500();
            v7 = *((_DWORD *)this + 2);
            v8 = *(_DWORD *)(v7 + 8);
            if ( v8 )
              *(_DWORD *)(v7 + 8) = *(_DWORD *)(v8 + 4);
            v9 = *(_DWORD **)(v7 + 8);
          }
          while ( v9 && *v9 );
        }
      }
    }
  }
}
