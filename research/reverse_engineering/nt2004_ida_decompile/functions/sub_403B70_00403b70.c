int __thiscall sub_403B70(_DWORD *this)
{
  int result; // eax
  int v3; // ecx
  void *v4; // ebp
  char *v5; // esi
  int v6; // ecx
  int v7; // ebx

  result = this[90];
  if ( result )
  {
    v3 = *(_DWORD *)(result - 4);
    v4 = (void *)(result - 4);
    v5 = (char *)(result + 348 * v3);
    v6 = v3 - 1;
    if ( v6 >= 0 )
    {
      v7 = v6 + 1;
      do
      {
        v5 -= 348;
        nullsub_6(v5);
        --v7;
      }
      while ( v7 );
    }
    sub_5BE8AE(v4);
    result = 0;
    this[90] = 0;
    this[89] = 0;
  }
  else
  {
    this[90] = 0;
    this[89] = 0;
  }
  return result;
}
