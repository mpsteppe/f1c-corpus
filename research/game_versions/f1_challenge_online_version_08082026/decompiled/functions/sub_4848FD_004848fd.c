// positive sp value has been detected, the output may be wrong!
_DWORD *__userpurge sub_4848FD@<eax>(_DWORD *a1@<ebx>, int a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi

  v2 = (_DWORD *)sub_587C03(396);
  v3 = v2;
  if ( v2 == a1 )
    return (_DWORD *)sub_484CEB(a2);
  sub_4685B0(v2);
  v3[95] = a1;
  v3[96] = -1;
  v3[97] = a1;
  v3[98] = -1;
  *v3 = &off_5A7EF0;
  return v3;
}
