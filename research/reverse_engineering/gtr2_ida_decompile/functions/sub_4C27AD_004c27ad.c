// positive sp value has been detected, the output may be wrong!
_DWORD *__stdcall sub_4C27AD(int a1)
{
  _DWORD *v1; // eax

  v1 = operator new(0x124u);
  if ( v1 )
    return sub_4A4410(v1, 30);
  else
    return (_DWORD *)((int (__stdcall *)(_DWORD))sub_4CC3A1)(0);
}
