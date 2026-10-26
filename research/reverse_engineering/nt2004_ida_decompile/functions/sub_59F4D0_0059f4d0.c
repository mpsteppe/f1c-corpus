int __thiscall sub_59F4D0(void *this, int ArgList, int a3, int a4, int a5, int a6, LPCWCH *a7, int *a8)
{
  LPCWCH lpWideCharStr; // [esp+4h] [ebp-8h] BYREF
  int v11; // [esp+8h] [ebp-4h] BYREF

  lpWideCharStr = 0;
  v11 = 0;
  if ( sub_59F2A0(this, ArgList, &lpWideCharStr, (unsigned int *)&v11) )
  {
    if ( lpWideCharStr )
      sub_5BE8AE();
    sub_59FA90((int)this);
    return -1;
  }
  else
  {
    sub_5A6F80((int)&unk_7E6B48, lpWideCharStr, v11, a3, a4, a5, a6);
    if ( a7 )
      *a7 = lpWideCharStr;
    else
      sub_5BE8AE();
    if ( a8 )
      *a8 = v11;
    return 0;
  }
}
