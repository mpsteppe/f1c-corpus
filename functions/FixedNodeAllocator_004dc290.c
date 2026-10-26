int sub_4DC290()
{
  int result; // eax

  result = OperatorNewNhMallocWrapper(16);
  if ( !result )
    return 0;
  *(_DWORD *)(result + 4) = 4;
  *(_BYTE *)(result + 8) = 0;
  *(_DWORD *)(result + 12) = 0;
  *(_DWORD *)result = &off_5AD11C;
  return result;
}
