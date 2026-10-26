int __thiscall sbdt::TvOverlayMan::CreateOverlays(sbdt::TvOverlayMan *this)
{
  int v1; // ebx
  int v3; // esi
  _DWORD *v4; // edi
  int v5; // esi
  _DWORD *v6; // edi
  int i; // esi

  v1 = *(_DWORD *)dword_B72314;
  v3 = 0;
  v4 = (_DWORD *)((char *)this + 24);
  do
  {
    if ( sub_561FF0(v3, v1) )
      *v4 = sub_566050(v3);
    ++v3;
    ++v4;
  }
  while ( v3 < 25 );
  v5 = 0;
  v6 = (_DWORD *)((char *)this + 124);
  do
    *v6++ = sub_5664A0(v5++);
  while ( v5 < 3 );
  for ( i = 0; i < 3; ++i )
  {
    switch ( v1 )
    {
      case 1:
      case 2:
      case 7:
      case 8:
        if ( i == 1 || i == 2 )
          goto LABEL_14;
        break;
      case 3:
      case 4:
      case 5:
        if ( i == 1 || i == 2 )
LABEL_14:
          *((_DWORD *)this + i + 3) = sub_566540(i);
        break;
      default:
        continue;
    }
  }
  *((_DWORD *)this + 56) = sub_567120();
  *((_DWORD *)this + 59) = sub_567150();
  *((_DWORD *)this + 57) = sub_5670F0();
  *((_DWORD *)this + 58) = sub_567180();
  return 0;
}
