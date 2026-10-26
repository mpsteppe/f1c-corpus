int sub_5BAC00()
{
  int result; // eax
  int v1; // ecx
  int *v2; // edx

  result = sub_5BDC60();
  if ( result )
  {
    v1 = 0;
    dword_7FEFDC = 0;
    do
    {
      v2 = *(int **)(*(_DWORD *)(result + 12) + 4 * v1);
      if ( !v2 )
        break;
      dword_7FEFC8[v1++] = *v2;
      dword_7FEFDC = v1;
    }
    while ( v1 < 5 );
  }
  return result;
}
