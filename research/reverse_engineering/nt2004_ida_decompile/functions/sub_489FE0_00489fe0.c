_DWORD *__thiscall sub_489FE0(_DWORD *this, int a2)
{
  _DWORD *result; // eax
  int v4; // ecx
  int v5; // eax

  result = (_DWORD *)(*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
  if ( result )
  {
    result = (_DWORD *)result[7];
    if ( result )
    {
      v4 = (*(unsigned __int8 (__thiscall **)(_DWORD *))(*result + 124))(result);
      v5 = this[210];
      if ( a2 == 1 )
        result = (_DWORD *)(v5 + 1);
      else
        result = (_DWORD *)(v5 - 1);
      this[210] = result;
      if ( (int)result < v4 )
      {
        if ( (int)result < 0 )
          this[210] = v4 - 1;
      }
      else
      {
        this[210] = 0;
      }
    }
  }
  return result;
}
