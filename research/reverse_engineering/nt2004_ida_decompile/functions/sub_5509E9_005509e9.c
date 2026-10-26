void __cdecl sub_5509E9(int a1, int a2, double a3)
{
  if ( a1 )
  {
    if ( a2 )
    {
      *(_DWORD *)(a2 + 8) |= 1u;
      *(float *)(a2 + 40) = a3;
    }
  }
}
