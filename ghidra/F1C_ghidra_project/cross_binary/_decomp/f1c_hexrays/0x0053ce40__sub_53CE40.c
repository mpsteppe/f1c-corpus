// f1c  0x0053ce40  size=140
int __stdcall sub_53CE40(_DWORD *a1)
{
  int result; // eax
  int v2; // ecx
  int v3; // ecx

  result = dword_8B8F14;
  if ( dword_8B8F14 )
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
      dword_8B8F14 = a1[76];
    sub_55FE30(a1);
    j_nullsub_3(a1);
    sub_587BCF(a1);
    --dword_8B6AC0;
  }
  return 0;
}
