void *sub_588D95()
{
  _BYTE *v0; // eax
  int v1; // ebp
  _UNKNOWN **v2; // esi
  _DWORD *v3; // ebx
  void *v5; // [esp-Ch] [ebp-1Ch]

  v0 = dword_5E64F4;
  v1 = 1;
  if ( !dword_5E64F4 )
  {
    v0 = (_BYTE *)MallocWrapperForNhMalloc(849);
    dword_5E64F4 = v0;
  }
  *v0 = 0;
  BatchFunctionCallOverVarargs(dword_5E64F4, 3);
  v2 = &off_5E6500;
  v3 = &off_5E6500;
  do
  {
    sub_58FCB0(dword_5E64F4, ";");
    v5 = v2[3];
    v2 += 3;
    if ( sub_58FB90(*v3, v5) )
      v1 = 0;
    v3 = v2;
    BatchFunctionCallOverVarargs(dword_5E64F4, 3);
  }
  while ( (int)v2 < (int)&off_5E6530 );
  if ( !v1 )
    return dword_5E64F4;
  sub_58AA6F(dword_5E64F4);
  dword_5E64F4 = 0;
  return off_5E650C;
}
