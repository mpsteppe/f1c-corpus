float *__thiscall sub_600D60(char *this, int a2, int a3, int a4)
{
  float *result; // eax
  int v6; // ecx
  char v7; // dh
  int v8; // ecx
  int v9; // edi
  int v10; // edi
  int v11; // edx
  int v12; // ecx
  _DWORD *v13; // esi

  *((_DWORD *)this + 18) = a2;
  result = (float *)(this + 72);
  *((_DWORD *)this + 20) = a4;
  v6 = *(_DWORD *)this | 0x100;
  *((_DWORD *)this + 19) = a3;
  *(_DWORD *)this = v6;
  v7 = BYTE1(v6);
  v8 = *((_DWORD *)this + 50);
  if ( !v8 || (v9 = v8 + 180, v8 == -180) )
  {
    if ( (v7 & 1) != 0 )
    {
      *((float *)this + 51) = *result;
      v10 = *((_DWORD *)result + 1);
      result = (float *)*((_DWORD *)result + 2);
      *((_DWORD *)this + 52) = v10;
      *((_DWORD *)this + 53) = result;
    }
    if ( (v7 & 2) != 0 )
    {
      v11 = *((_DWORD *)this + 21);
      result = (float *)*((_DWORD *)this + 22);
      v12 = *((_DWORD *)this + 23);
      v13 = this + 216;
      *v13 = v11;
      v13[1] = result;
      v13[2] = v12;
    }
  }
  else
  {
    if ( (v7 & 1) != 0 )
      sub_5D7810(result, (float *)this + 51, (float *)(v8 + 184));
    result = *(float **)this;
    if ( (*(_DWORD *)this & 0x200) != 0 )
      return sub_5D77B0((float *)this + 21, (float *)this + 54, (float *)(v9 + 4));
  }
  return result;
}
