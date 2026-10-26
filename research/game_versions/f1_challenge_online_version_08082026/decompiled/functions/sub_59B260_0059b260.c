int __fastcall sub_59B260(unsigned __int8 *a1, unsigned __int8 **a2, unsigned __int8 *a3, unsigned __int8 *a4)
{
  unsigned __int8 *v5; // eax
  int result; // eax
  int v7; // edi
  unsigned __int8 *v8[14]; // [esp+8h] [ebp-38h] BYREF

  v8[0] = a3;
  v5 = *a2;
  v8[1] = a4;
  v8[3] = a1;
  v8[4] = v5;
  v8[8] = 0;
  v8[9] = 0;
  result = sub_5357C0(v8, a113_0, 56);
  if ( !result )
  {
    v7 = sub_5357E0(v8, 4);
    if ( v7 == 1 )
    {
      *a2 = v8[5];
      return sub_535660(v8);
    }
    else
    {
      sub_535660(v8);
      result = -5;
      if ( v7 )
        return v7;
    }
  }
  return result;
}
