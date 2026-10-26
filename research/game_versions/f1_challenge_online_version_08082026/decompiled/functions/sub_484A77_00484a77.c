// positive sp value has been detected, the output may be wrong!
_DWORD *__userpurge sub_484A77@<eax>(_DWORD *a1@<ebx>, int a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi

  v2 = (_DWORD *)sub_587C03(380);
  v3 = v2;
  if ( v2 == a1 )
    return (_DWORD *)sub_484CEB(a2);
  ((void (__thiscall *)(_DWORD *))sub_4893C0)(v2);
  v3[93] = a1;
  v3[94] = -1;
  *v3 = &off_5A7A48;
  return v3;
}
