char __thiscall sub_5C54D0(_BYTE *this, int a2, int a3, int a4, int a5)
{
  int i; // edi
  _BYTE v7[4]; // [esp+Ch] [ebp-10h] BYREF
  int v8; // [esp+10h] [ebp-Ch]
  _BYTE v9[8]; // [esp+14h] [ebp-8h] BYREF

  if ( a4 )
  {
    (*(void (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)a2 + 4))(a2, v7, 8);
    for ( i = 0; i < v8; ++i )
      (*(void (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)a2 + 4))(a2, v9, 8);
    return 1;
  }
  else
  {
    if ( this[12] )
      sub_643E40("Passed motion seems to be not valid!");
    return 0;
  }
}
