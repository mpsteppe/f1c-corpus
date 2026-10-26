float *__thiscall sub_600C90(char *this, int a2, int a3, int a4)
{
  float *v5; // edi
  float *result; // eax
  int v7; // ebx
  char v8; // ch
  float *v9; // ebx
  int v10; // edx
  _DWORD *v11; // esi

  v5 = (float *)(this + 84);
  *((_DWORD *)this + 21) = a2;
  *((_DWORD *)this + 22) = a3;
  *((_DWORD *)this + 23) = a4;
  sub_5D7750((float *)this + 21);
  result = (float *)*((_DWORD *)this + 50);
  v7 = *(_DWORD *)this | 0x200;
  *(_DWORD *)this = v7;
  v8 = BYTE1(v7);
  if ( !result || (v9 = result + 45, result == (float *)-180) )
  {
    if ( (v8 & 1) != 0 )
    {
      *((_DWORD *)this + 51) = *((_DWORD *)this + 18);
      result = (float *)*((_DWORD *)this + 20);
      *((_DWORD *)this + 52) = *((_DWORD *)this + 19);
      *((_DWORD *)this + 53) = result;
    }
    if ( (v8 & 2) != 0 )
    {
      v10 = *((_DWORD *)this + 22);
      result = (float *)*((_DWORD *)this + 23);
      v11 = this + 216;
      *v11 = *(_DWORD *)v5;
      v11[1] = v10;
      v11[2] = result;
    }
  }
  else
  {
    if ( (v8 & 1) != 0 )
      sub_5D7810((float *)this + 18, (float *)this + 51, result + 46);
    result = *(float **)this;
    if ( (*(_DWORD *)this & 0x200) != 0 )
      return sub_5D77B0(v5, (float *)this + 54, v9 + 1);
  }
  return result;
}
