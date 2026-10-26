// f1c  0x004c0260  size=107
int __stdcall sub_4C0260(int a1)
{
  int v1; // esi
  _DWORD *v2; // eax
  char *v3; // eax

  if ( !a1 || !sub_4C5840(0) || !sub_5679C0(aQualifying) )
    return 104;
  v1 = 0;
  while ( 1 )
  {
    v2 = (_DWORD *)sub_5679A0(v1);
    if ( v2 )
    {
      v3 = sub_499E20(v2);
      if ( !sub_588410(a1, v3) )
        break;
    }
    if ( ++v1 >= 104 )
      return 104;
  }
  return v1 + 1;
}
