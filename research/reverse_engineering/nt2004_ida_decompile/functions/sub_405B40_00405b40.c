_DWORD *__thiscall sub_405B40(_DWORD *this, int a2)
{
  _DWORD *result; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // edi
  _DWORD *v6; // esi

  result = operator new(8u);
  v4 = result;
  if ( result )
  {
    *result = 0;
    result[1] = -1;
    result = (_DWORD *)sub_578600(a2);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  v6 = (_DWORD *)(*this + 68);
  if ( v5 )
  {
    result = operator new(0xCu);
    if ( result )
    {
      *result = v5;
      result[1] = 0;
      *((_BYTE *)result + 8) = 1;
    }
    else
    {
      result = 0;
    }
    if ( *v6 )
    {
      *(_DWORD *)(v6[1] + 4) = result;
      v6[1] = result;
      ++v6[3];
    }
    else
    {
      *v6 = result;
      v6[2] = result;
      v6[1] = result;
      result = (_DWORD *)(v6[3] + 1);
      v6[3] = result;
    }
  }
  return result;
}
