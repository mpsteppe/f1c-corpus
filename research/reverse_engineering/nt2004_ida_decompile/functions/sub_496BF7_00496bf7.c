// positive sp value has been detected, the output may be wrong!
_DWORD *__userpurge sub_496BF7@<eax>(_DWORD *a1@<ebx>, int a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi

  v2 = operator new(0x134u);
  v3 = v2;
  if ( v2 == a1 )
    return (_DWORD *)sub_49A511(a2);
  sub_48D130((int)v2);
  *v3 = &off_5E0998;
  v3[76] = 253;
  v3[73] = 1056964608;
  return v3;
}
