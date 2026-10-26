int __stdcall sub_5DCFA0(char a1)
{
  int v1; // ecx

  dword_FB28C4 = (int)dword_FB28BC;
  if ( !dword_FB28BC )
    return 0;
  v1 = *(_DWORD *)dword_FB28BC;
  if ( !*(_DWORD *)dword_FB28BC )
    return 0;
  do
  {
    sub_5FC390(v1, a1);
    if ( !dword_FB28C4 )
      break;
    dword_FB28C4 = *(_DWORD *)(dword_FB28C4 + 4);
    if ( !dword_FB28C4 )
      break;
    v1 = *(_DWORD *)dword_FB28C4;
  }
  while ( *(_DWORD *)dword_FB28C4 );
  return 0;
}
