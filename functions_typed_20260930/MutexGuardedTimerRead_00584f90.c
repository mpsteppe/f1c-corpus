double __thiscall sub_584F90(char *this)
{
  void *v1; // eax
  char *v2; // esi
  DWORD v3; // eax
  char *v4; // ecx
  double result; // st7
  void *v6; // esi

  v1 = (void *)*((_DWORD *)this + 53);
  v2 = this + 132;
  if ( v1 && ((v3 = WaitForSingleObject(v1, *((_DWORD *)this + 54))) == 0 || v3 == 128) )
    v4 = v2;
  else
    v4 = 0;
  result = FloatAdditionReturnsFUN00568d90Param1(v4);
  v6 = (void *)*((_DWORD *)v2 + 20);
  if ( v6 )
    ReleaseMutex(v6);
  return result;
}

