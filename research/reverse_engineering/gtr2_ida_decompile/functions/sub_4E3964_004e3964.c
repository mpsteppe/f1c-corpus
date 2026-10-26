// positive sp value has been detected, the output may be wrong!
int __thiscall sub_4E3964(int *this, const char *a2)
{
  _DWORD v3[5]; // [esp+4h] [ebp-1Ch] BYREF

  v3[4] = NtCurrentTeb()->NtTib.ExceptionList;
  if ( !--dword_1739812 )
    dword_1739812 = 714;
  if ( this[111] <= 0 )
    return 0;
  strlen(a2);
  return ((int (__thiscall *)(_DWORD *))sub_5A8860)(v3);
}
