// positive sp value has been detected, the output may be wrong!
_DWORD *__userpurge sub_49590E@<eax>(_DWORD *a1@<ebx>, int a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi

  v2 = operator new(0x1A4u);
  v3 = v2;
  if ( v2 == a1 )
    return (_DWORD *)sub_49A511(a2);
  ((void (__thiscall *)(_DWORD *))sub_4A2F50)(v2);
  v3[101] = a1;
  v3[102] = a1;
  v3[103] = a1;
  v3[104] = a1;
  *v3 = &off_5E1FC8;
  return v3;
}
