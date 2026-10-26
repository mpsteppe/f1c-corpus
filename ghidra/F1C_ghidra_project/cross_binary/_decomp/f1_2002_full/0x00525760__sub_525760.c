// f1_2002_full  0x00525760  size=140
size_t __stdcall sub_525760(_DWORD *a1)
{
  size_t result; // eax
  int v2; // ecx
  int v3; // ecx

  result = ElementCount;
  if ( ElementCount )
  {
    while ( a1 != (_DWORD *)result )
    {
      result = *(_DWORD *)(result + 304);
      if ( !result )
        return result;
    }
    v2 = *(_DWORD *)(result + 300);
    if ( v2 )
      *(_DWORD *)(v2 + 304) = *(_DWORD *)(result + 304);
    v3 = *(_DWORD *)(result + 304);
    if ( v3 )
      *(_DWORD *)(v3 + 300) = *(_DWORD *)(result + 300);
    if ( !a1[75] )
      ElementCount = a1[76];
    sub_547DB0(a1);
    j_nullsub_8(a1);
    sub_56BEF1(a1);
    --dword_6C6898;
  }
  return 0;
}
