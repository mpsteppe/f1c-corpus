void __thiscall sub_41AB30(_DWORD *this, int a2)
{
  int v3; // edx
  _DWORD *v4; // eax
  int v5; // ecx
  float v6[8]; // [esp+4h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 && dword_7C56A8 != 8 )
  {
    this[a2 + 657] = 2;
    sub_4144D0(v6);
    v3 = 0;
    v4 = this + 657;
    v5 = 4;
    do
    {
      if ( *v4 == 2 )
        ++v3;
      ++v4;
      --v5;
    }
    while ( v5 );
    if ( v3 < 3 )
    {
      switch ( a2 )
      {
        case 0:
          sub_4144F0(v6, 94, -1, -1, -1, -1, -2.0, -2.0);
          break;
        case 1:
          sub_4144F0(v6, 96, -1, -1, -1, -1, -2.0, -2.0);
          break;
        case 2:
          sub_4144F0(v6, 98, -1, -1, -1, -1, -2.0, -2.0);
          break;
        case 3:
          sub_4144F0(v6, 100, -1, -1, -1, -1, -2.0, -2.0);
          break;
        default:
          break;
      }
    }
    else
    {
      sub_4144F0(v6, 104, -1, -1, -1, -1, -2.0, -2.0);
    }
    sub_418560(flt_5EA618, v6);
  }
}
