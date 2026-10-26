// f1c  0x0041aa10  size=265
void __thiscall sub_41AA10(_DWORD *this, int a2)
{
  int v3; // edx
  _DWORD *v4; // eax
  int v5; // ecx
  float v6[8]; // [esp+4h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 && dword_7C56A8 != 8 )
  {
    this[a2 + 657] = 1;
    sub_4144D0(v6);
    v3 = 0;
    v4 = this + 657;
    v5 = 4;
    do
    {
      if ( *v4 )
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
          sub_4144F0(v6, 95, -1, -1, -1, -1, -2.0, -2.0);
          break;
        case 1:
          sub_4144F0(v6, 97, -1, -1, -1, -1, -2.0, -2.0);
          break;
        case 2:
          sub_4144F0(v6, 99, -1, -1, -1, -1, -2.0, -2.0);
          break;
        case 3:
          sub_4144F0(v6, 101, -1, -1, -1, -1, -2.0, -2.0);
          break;
        default:
          break;
      }
    }
    else
    {
      sub_4144F0(v6, 105, -1, -1, -1, -1, -2.0, -2.0);
    }
    sub_418560(flt_5EA618, v6);
  }
}
