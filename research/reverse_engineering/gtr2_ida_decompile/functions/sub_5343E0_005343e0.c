char __stdcall sub_5343E0(int a1)
{
  _DWORD *v1; // eax

  if ( !*(_DWORD *)(a1 + 4) )
    return 0;
  v1 = operator new(0x24u);
  if ( v1 )
  {
    *v1 = 0;
    v1[1] = -1;
    v1[2] = 0;
    v1[3] = -1;
    v1[4] = 0;
    v1[5] = -1;
    v1[7] = 0;
    v1[8] = 0;
    v1[6] = 3;
  }
  return off_16C9738(a1);
}
