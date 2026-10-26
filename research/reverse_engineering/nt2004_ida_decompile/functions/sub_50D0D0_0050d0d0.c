int __stdcall sub_50D0D0(int a1, float a2, char a3)
{
  int result; // eax
  int v5; // ebp
  int i; // esi

  do
  {
    result = sub_59EFD0(a1);
    v5 = result;
    for ( i = 0; i < v5; *(float *)(result + 248) = a2 * *(float *)(result + 248) )
    {
      result = sub_59EFF0(i++);
      *(float *)(result + 244) = a2 * *(float *)(result + 244);
    }
    if ( !a3 )
      break;
    a1 = *(_DWORD *)(a1 + 76);
  }
  while ( a1 );
  return result;
}
