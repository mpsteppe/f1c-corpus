int __thiscall sub_4DC220(void *this)
{
  int result; // eax

  result = 0;
  if ( !this )
  {
    result = OperatorNewNhMallocWrapper(16);
    if ( result )
    {
      *(_DWORD *)(result + 4) = 3;
      *(_BYTE *)(result + 8) = 0;
      *(_DWORD *)(result + 12) = 0;
      *(_DWORD *)result = &off_5AD0F8;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
