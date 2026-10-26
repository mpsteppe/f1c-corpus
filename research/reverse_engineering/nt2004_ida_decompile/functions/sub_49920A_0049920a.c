// positive sp value has been detected, the output may be wrong!
_DWORD *__userpurge sub_49920A@<eax>(_DWORD *a1@<ebx>, int a2)
{
  _DWORD *v2; // eax

  v2 = operator new(0x368u);
  if ( v2 == a1 )
    return (_DWORD *)sub_49A511(a2);
  else
    return sub_48A960(v2);
}
