float *__thiscall sub_600870(void *this, int a2, char a3)
{
  int v4; // eax
  int v5; // edi
  float *result; // eax
  int v7; // edx
  int v8; // edx

  v4 = *((_DWORD *)this + 50);
  v5 = v4 + 180;
  if ( !v4 )
    v5 = a2;
  if ( v5 )
  {
    if ( (*(_DWORD *)this & 0x100) != 0 || a3 )
      sub_5D7810((float *)this + 18, (float *)this + 51, (float *)(v5 + 4));
    result = *(float **)this;
    if ( (*(_DWORD *)this & 0x200) != 0 || a3 )
      return sub_5D77B0((float *)this + 21, (float *)this + 54, (float *)(v5 + 4));
  }
  else
  {
    result = *(float **)this;
    if ( (*(_DWORD *)this & 0x100) != 0 || a3 )
    {
      *((_DWORD *)this + 51) = *((_DWORD *)this + 18);
      v7 = *((_DWORD *)this + 20);
      *((_DWORD *)this + 52) = *((_DWORD *)this + 19);
      *((_DWORD *)this + 53) = v7;
    }
    if ( (BYTE1(result) & 2) != 0 || a3 )
    {
      v8 = *((_DWORD *)this + 22);
      result = (float *)*((_DWORD *)this + 23);
      *((_DWORD *)this + 54) = *((_DWORD *)this + 21);
      *((_DWORD *)this + 55) = v8;
      *((_DWORD *)this + 56) = result;
    }
  }
  return result;
}
