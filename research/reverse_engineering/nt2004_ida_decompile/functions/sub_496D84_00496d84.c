// positive sp value has been detected, the output may be wrong!
_DWORD *__userpurge sub_496D84@<eax>(_DWORD *a1@<ebx>, int a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi

  v2 = operator new(0x134u);
  v3 = v2;
  if ( v2 == a1 )
    return (_DWORD *)sub_49A511(a2);
  sub_48D440((int)v2);
  *v3 = &off_5E08E8;
  v3[76] = 260;
  return v3;
}
