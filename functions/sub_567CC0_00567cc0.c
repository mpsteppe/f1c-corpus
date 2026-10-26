int __stdcall sub_567CC0(_DWORD *a1)
{
  int result; // eax

  if ( a1 )
  {
    sub_567CC0(a1[1]);
    sub_567CC0(a1[2]);
    sub_567CC0(a1[3]);
    DualPointerCleanup((int)a1);
    return FreeWrapper_7bcf(a1);
  }
  return result;
}
