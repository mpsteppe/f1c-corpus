int *__thiscall sub_4492D0(_DWORD *this, int a2)
{
  int *result; // eax
  int v4; // esi
  _DWORD *v5; // ebx
  int v6; // edi

  result = (int *)sub_449340();
  v4 = a2;
  if ( a2 > 0 )
  {
    this[1] = a2;
    result = (int *)sub_587C03(32 * a2 + 4);
    if ( result )
    {
      v5 = result + 1;
      *result = a2;
      result = (int *)(a2 - 1);
      v6 = (int)v5;
      if ( a2 - 1 >= 0 )
      {
        do
        {
          result = (int *)sub_448E90(v6);
          v6 += 32;
          --v4;
        }
        while ( v4 );
      }
      this[2] = v5;
    }
    else
    {
      this[2] = 0;
    }
  }
  return result;
}
