_DWORD *__thiscall sub_5FCB20(_DWORD *this, int a2)
{
  _DWORD *result; // eax
  int v3; // ecx
  _DWORD *v4; // edx
  _DWORD *v5; // ebx

  result = this;
  v3 = this[12];
  if ( v3 > 0 && a2 < result[11] )
  {
    v4 = (_DWORD *)(result[13] + 132 * a2);
    if ( (*v4 & 0x100) != 0 )
    {
      v5 = *(_DWORD **)(result[14] + 4 * v3 - 4);
      if ( v5 != v4 )
      {
        if ( v5 )
        {
          qmemcpy(
            (void *)(result[24] + ((result[9] * v4[1]) << 6)),
            (const void *)(result[24] + ((result[9] * v5[1]) << 6)),
            result[9] << 6);
          v5[1] = v4[1];
          v5[32] = result[24] + ((v4[1] * result[9]) << 6);
          *(_DWORD *)(result[14] + 4 * v4[1]) = v5;
        }
      }
      *v4 &= ~0x100u;
      --result[12];
    }
  }
  return result;
}
