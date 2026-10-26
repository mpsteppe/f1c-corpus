// f1c  0x004d1a50  size=118
int __thiscall sub_4D1A50(_DWORD *this, _DWORD *a2)
{
  int result; // eax
  int i; // edx
  int v5; // edx
  int v6; // edi
  _WORD *v7; // edx
  int v8; // edx

  result = *a2 & 0xFC0000;
  if ( result == 2621440 )
  {
    result = this[67];
    for ( i = 0; i < result; i = v5 + 1 )
    {
      sub_4D0F00((_DWORD *)(this[68] + 8 * i), 0);
      result = this[67];
    }
  }
  v6 = (*a2 >> 9) & 0x1FF;
  if ( v6 )
  {
    v7 = a2 + 2;
    do
    {
      result = sub_4D0F00((_DWORD *)(this[68] + 8 * ((unsigned __int16)*v7 >> 6)), *v7 & 0x3F);
      v7 = (_WORD *)(v8 + 2);
      --v6;
    }
    while ( v6 );
  }
  return result;
}
