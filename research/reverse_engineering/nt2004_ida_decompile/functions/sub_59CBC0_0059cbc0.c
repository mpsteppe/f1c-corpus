_DWORD *__thiscall sub_59CBC0(_DWORD *this, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  _DWORD *result; // eax
  unsigned __int16 *v6; // eax
  _DWORD *v7; // ecx
  _DWORD *v8; // ecx
  int v9; // ecx
  int v10; // edx
  _DWORD *v11; // ecx

  result = (_DWORD *)a2;
  if ( a2 < this[72] )
  {
    v6 = (unsigned __int16 *)(this[73] + 36 * a2);
    v7 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)v6 + 2) + 12) + 48 * *v6);
    if ( a3 )
    {
      *a3 = *v7;
      a3[1] = v7[1];
      a3[2] = v7[2];
    }
    v8 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)v6 + 2) + 12) + 48 * v6[1]);
    if ( a4 )
    {
      *a4 = *v8;
      a4[1] = v8[1];
      a4[2] = v8[2];
    }
    v9 = v6[2];
    v10 = *((_DWORD *)v6 + 2);
    result = a5;
    v11 = (_DWORD *)(*(_DWORD *)(v10 + 12) + 48 * v9);
    if ( a5 )
    {
      *a5 = *v11;
      a5[1] = v11[1];
      a5[2] = v11[2];
    }
  }
  return result;
}
