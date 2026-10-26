int __thiscall sub_4E8200(_DWORD *this)
{
  int result; // eax
  int i; // esi
  LPVOID *v4; // edi
  bool v5; // zf

  result = sub_578600(&byte_629120);
  for ( i = this[2]; i; result = sub_5BE8AE(v4) )
  {
    v4 = (LPVOID *)i;
    v5 = *(_BYTE *)(i + 8) == 0;
    i = *(_DWORD *)(i + 4);
    if ( !v5 )
      sub_5BE8AE(*v4);
  }
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  return result;
}
