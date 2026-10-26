_DWORD *__thiscall sub_5857C0(_DWORD *this, int a2)
{
  void *v2; // eax
  _DWORD *v3; // esi
  DWORD v4; // eax
  _DWORD *result; // eax
  void *v6; // esi

  v2 = (void *)this[60];
  v3 = this + 59;
  if ( v2 && ((v4 = WaitForSingleObject(v2, this[61])) == 0 || v4 == 128) )
    result = v3;
  else
    result = 0;
  *result = a2;
  v6 = (void *)v3[1];
  if ( v6 )
    return (_DWORD *)ReleaseMutex(v6);
  return result;
}
