// positive sp value has been detected, the output may be wrong!
_DWORD *__userpurge sub_4848CC@<eax>(_DWORD *a1@<ebx>, int a2)
{
  _DWORD *v2; // esi

  v2 = (_DWORD *)sub_587C03(236);
  if ( v2 == a1 )
    return (_DWORD *)sub_484CEB(a2);
  sub_488B00(1, -1);
  *v2 = &off_5A7FA0;
  return v2;
}
