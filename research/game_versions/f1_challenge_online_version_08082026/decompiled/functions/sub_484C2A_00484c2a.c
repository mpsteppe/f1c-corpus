// positive sp value has been detected, the output may be wrong!
_DWORD *__userpurge sub_484C2A@<eax>(_DWORD *a1@<ebx>, int a2)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)sub_587C03(240);
  if ( v2 == a1 )
    return (_DWORD *)sub_484CEB(a2);
  else
    return sub_47DAF0(v2, 483);
}
