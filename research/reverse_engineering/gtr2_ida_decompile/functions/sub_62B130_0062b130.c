int __fastcall sub_62B130(int a1, int *a2, int a3, int a4)
{
  int v5; // eax
  int result; // eax
  int v7; // edi
  _DWORD v8[14]; // [esp+4h] [ebp-38h] BYREF

  v8[0] = a3;
  v5 = *a2;
  v8[1] = a4;
  v8[3] = a1;
  v8[4] = v5;
  v8[8] = 0;
  v8[9] = 0;
  result = sub_62C680(56);
  if ( !result )
  {
    v7 = sub_62C6A0(v8, 4);
    if ( v7 == 1 )
    {
      *a2 = v8[5];
      return sub_62C540(v8);
    }
    else
    {
      sub_62C540(v8);
      result = -5;
      if ( v7 )
        return v7;
    }
  }
  return result;
}
