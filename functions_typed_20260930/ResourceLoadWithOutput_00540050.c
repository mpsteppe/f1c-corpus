int __thiscall sub_540050(int *this, int a2, int a3, _DWORD *a4, _DWORD *a5, int a6)
{
  int v7; // eax
  _DWORD v9[7]; // [esp+4h] [ebp-1Ch] BYREF

  v7 = LockUnlockWrapper(a2, a3, (int)v9);
  *this = v7;
  if ( v7 )
    return -1;
  if ( a4 )
    *a4 = v9[0];
  if ( a5 )
    *a5 = v9[1];
  if ( a6 )
    sub_55C450(v9[4], 0, a6);
  return 0;
}

