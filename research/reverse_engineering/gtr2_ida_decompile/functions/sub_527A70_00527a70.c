int *__thiscall sub_527A70(_DWORD *this)
{
  int *result; // eax
  int v3; // esi
  int v4; // esi

  result = (int *)this[21];
  this[22] = result;
  if ( result )
  {
    v3 = *result;
    if ( *result )
    {
      result = (int *)sub_5214A0();
      if ( (_BYTE)result )
        return result;
      if ( *(_DWORD *)(v3 + 200) == -190986834 )
        *(float *)(v3 + 200) = dbl_FB1D18;
    }
  }
  if ( dword_923E84[0] != -1 )
  {
    v4 = sub_5264F0();
    sub_521530();
    *(_BYTE *)v4 = 1;
    *(_DWORD *)(v4 + 196) = this[723213];
    return (int *)sub_5FDFB0(v4, 0);
  }
  return result;
}
