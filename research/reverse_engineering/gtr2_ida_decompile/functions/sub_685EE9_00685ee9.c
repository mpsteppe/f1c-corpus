_DWORD *__thiscall sub_685EE9(_DWORD *this, int a2, unsigned int a3)
{
  int v4; // edx
  _DWORD *result; // eax
  int v6; // edi
  _DWORD *v7; // edx

  while ( 1 )
  {
    v4 = this[5];
    result = *(_DWORD **)(v4 + 4 * a2);
    v6 = result[14];
    if ( v6 != -1 )
      result = *(_DWORD **)(v4 + 4 * v6);
    v7 = *(_DWORD **)(this[4] + 4 * result[1]);
    if ( result[21] > a3 )
      result[21] = a3;
    if ( result[22] < a3 )
      result[22] = a3;
    ++result[23];
    if ( result[2] == -1 )
      break;
    if ( v7[10] > a3 )
      v7[10] = a3;
    if ( v7[11] < a3 )
      v7[11] = a3;
    ++v7[12];
    a2 = result[2];
  }
  return result;
}
