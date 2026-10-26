// positive sp value has been detected, the output may be wrong!
_DWORD *__userpurge sub_498DB4@<eax>(_DWORD *a1@<ebx>, int a2)
{
  _DWORD *v2; // eax

  v2 = operator new(0x360u);
  if ( v2 == a1 )
    return (_DWORD *)sub_49A511(a2);
  else
    return sub_487360(v2);
}
