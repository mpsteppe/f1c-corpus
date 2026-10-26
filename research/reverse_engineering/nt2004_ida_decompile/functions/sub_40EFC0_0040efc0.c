int *__thiscall sub_40EFC0(_DWORD *this, __int16 a2, char a3)
{
  void *v4; // eax
  int v5; // esi
  int *result; // eax
  int v7; // ecx

  v4 = operator new(0x1Cu);
  if ( v4 )
    v5 = sub_413DB0(v4);
  else
    v5 = 0;
  result = (int *)sub_413E60(a2, a3);
  if ( v5 )
  {
    result = (int *)operator new(0xCu);
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
    v7 = this[3];
    if ( v7 )
    {
      result[1] = v7;
    }
    else
    {
      this[4] = result;
      this[5] = result;
    }
    this[3] = result;
    ++this[6];
  }
  return result;
}
