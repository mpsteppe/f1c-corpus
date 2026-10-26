// positive sp value has been detected, the output may be wrong!
_DWORD *__userpurge sub_499360@<eax>(_DWORD *a1@<ebx>, int a2@<edi>, int a3)
{
  _DWORD *v3; // eax

  v3 = operator new(0x364u);
  if ( v3 == a1 )
    return (_DWORD *)sub_49A511(a3);
  else
    return sub_488FB0(v3, a2);
}
