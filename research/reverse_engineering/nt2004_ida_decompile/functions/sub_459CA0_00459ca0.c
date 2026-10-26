_DWORD *__thiscall sub_459CA0(_DWORD *this, _DWORD *a2, _DWORD *a3, char a4)
{
  _DWORD *result; // eax
  _DWORD *v5; // ecx
  _DWORD *v6; // ecx

  v6 = (_DWORD *)*this;
  if ( a2 )
  {
    v6[5] = *a2;
    v6[6] = a2[1];
    v6[7] = a2[2];
  }
  result = a3;
  if ( a3 )
  {
    v6[8] = *a3;
    v6[9] = a3[1];
    v6[10] = a3[2];
  }
  if ( a4 )
  {
    if ( a3 )
    {
      v5 = v6 + 26;
      *v5 = *a3;
      v5[1] = a3[1];
      result = (_DWORD *)a3[2];
      v5[2] = result;
    }
  }
  return result;
}
