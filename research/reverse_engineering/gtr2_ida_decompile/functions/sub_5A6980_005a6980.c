int __thiscall sub_5A6980(_DWORD *this, void *a2, signed int a3, signed int *a4)
{
  int v4; // eax
  signed int v6; // eax
  const void *v7; // [esp+4h] [ebp-4h] BYREF

  v4 = sub_4FB7D0(this + 2);
  if ( v4 <= a3 )
  {
    if ( (unsigned __int8)sub_5A70F0(&v7, &a3) )
    {
      v6 = a3;
      qmemcpy(a2, v7, a3);
      if ( a4 )
        *a4 = v6;
      return 0;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    if ( a4 )
      *a4 = 0;
    return 4;
  }
}
