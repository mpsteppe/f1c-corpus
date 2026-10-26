_DWORD *__thiscall sub_60D550(void *this, int a2)
{
  _DWORD *result; // eax
  _DWORD *v4; // esi
  int v5; // ebp
  _DWORD *v6; // edi

  result = dword_FB2D78;
  dword_FB2D80 = (int)dword_FB2D78;
  if ( dword_FB2D78 )
  {
    v4 = *(_DWORD **)dword_FB2D78;
    if ( *(_DWORD *)dword_FB2D78 )
    {
      do
      {
        v5 = 0;
        if ( (int)v4[53] > 0 )
        {
          v6 = v4;
          do
          {
            if ( (*v4 & 0x10000) == 0 || (_BYTE)a2 )
            {
              (*(void (__thiscall **)(void *, _DWORD *, int))(*(_DWORD *)this + 336))(this, v6, a2);
              result = (_DWORD *)dword_FB2D80;
            }
            ++v5;
            v6 += 54;
          }
          while ( v5 < v4[53] );
        }
        if ( !result )
          break;
        result = (_DWORD *)result[1];
        dword_FB2D80 = (int)result;
        if ( !result )
          break;
        v4 = (_DWORD *)*result;
      }
      while ( *result );
    }
  }
  return result;
}
