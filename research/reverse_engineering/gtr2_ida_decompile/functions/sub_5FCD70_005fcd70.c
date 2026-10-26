unsigned int __thiscall sub_5FCD70(_DWORD *this, int a2)
{
  unsigned int result; // eax
  unsigned int *v3; // ecx
  unsigned int v4; // eax

  result = a2;
  if ( (unsigned int)a2 < 0x10 )
  {
    *(float *)(this[16] + 100) = (float)a2;
    v3 = (unsigned int *)this[16];
    v4 = *v3;
    if ( a2 <= 0 )
      result = v4 & 0xFFFFDFFF;
    else
      result = v4 | 0x2000;
    *v3 = result;
  }
  return result;
}
