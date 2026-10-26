int __thiscall sub_561AD0(int **this)
{
  int **v2; // esi
  int v3; // edi
  int *v4; // ecx
  int v5; // eax
  int result; // eax
  int *v7; // ecx
  int v8; // edx

  v2 = this + 6;
  v3 = 25;
  do
  {
    v4 = *v2;
    if ( *v2 )
    {
      v5 = *v4;
      v4[3] = 0;
      result = (*(int (**)(void))(v5 + 16))();
    }
    ++v2;
    --v3;
  }
  while ( v3 );
  v7 = this[59];
  if ( v7 )
  {
    v8 = *v7;
    v7[3] = 0;
    return (*(int (**)(void))(v8 + 16))();
  }
  return result;
}
