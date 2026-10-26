// f1c  0x00563020  size=92
int __fastcall sub_563020(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int result; // eax

  if ( *a1 )
    return 4;
  result = sub_562D20(a1);
  if ( !result )
  {
    result = sub_563080(a1);
    if ( !result )
    {
      result = sub_5630D0(a1, a3, a4, a5);
      if ( !result )
      {
        a1[28] = 0;
        a1[29] = 0;
        if ( !a2 )
          sub_563000(a1);
        return 0;
      }
    }
  }
  return result;
}
