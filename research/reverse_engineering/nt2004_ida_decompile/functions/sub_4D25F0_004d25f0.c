int __thiscall sub_4D25F0(LPVOID *this)
{
  _DWORD *v2; // ebp
  int v3; // esi
  LPVOID *v4; // edi
  bool v5; // zf
  int result; // eax
  int v7; // [esp+10h] [ebp-4h]

  if ( this[1602] )
    sub_5BE8AE(this[1602]);
  v2 = this + 1600;
  v7 = 256;
  do
  {
    v3 = *(v2 - 4);
    v2 -= 4;
    while ( v3 )
    {
      v4 = (LPVOID *)v3;
      v5 = *(_BYTE *)(v3 + 8) == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 )
        sub_5BE8AE(*v4);
      sub_5BE8AE(v4);
    }
    result = v7 - 1;
    v5 = v7 == 1;
    *v2 = 0;
    v2[1] = 0;
    v2[2] = 0;
    v2[3] = 0;
    --v7;
  }
  while ( !v5 );
  return result;
}
