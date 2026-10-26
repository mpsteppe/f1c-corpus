// f1c  0x004c7de0  size=156
void __thiscall sub_4C7DE0(int this)
{
  double v2; // st7
  double v3; // st7
  int v4; // ecx
  _DWORD *v5; // eax
  bool v6; // zf
  int v7; // eax
  int v8; // ecx
  _DWORD *v9; // eax

  if ( *(_DWORD *)(this + 12) )
  {
    v2 = *(float *)(this + 4) - dbl_8AFE98;
    *(float *)(this + 4) = v2;
    if ( v2 < 0.0 )
    {
      sub_4C7F30(0.40000001);
      v3 = *(float *)(this + 4) + 0.40000001;
      *(float *)(this + 4) = v3;
      if ( v3 < 0.0 )
        *(_DWORD *)(this + 4) = 0;
    }
    if ( dword_8AC4C4 )
    {
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)dword_8AC4C4 + 40))(dword_8AC4C4, 0, 0, 0);
      v4 = *(_DWORD *)(this + 12);
      v5 = *(_DWORD **)v4;
      v6 = *(_DWORD *)v4 == 0;
      *(_DWORD *)(v4 + 8) = *(_DWORD *)v4;
      if ( !v6 )
      {
        if ( *v5 )
        {
          do
          {
            sub_4C8FC0();
            v7 = *(_DWORD *)(this + 12);
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
