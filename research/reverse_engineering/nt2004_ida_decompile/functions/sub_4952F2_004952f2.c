// positive sp value has been detected, the output may be wrong!
_DWORD *__userpurge sub_4952F2@<eax>(_DWORD *a1@<ebx>, int a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi

  v2 = operator new(0x10Cu);
  v3 = v2;
  if ( v2 == a1 )
    return (_DWORD *)sub_49A511(a2);
  ((void (__thiscall *)(_DWORD *))sub_49D930)(v2);
  *v3 = &off_5E3630;
  return v3;
}
