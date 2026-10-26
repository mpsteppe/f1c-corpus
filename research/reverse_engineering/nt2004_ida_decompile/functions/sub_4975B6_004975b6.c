// positive sp value has been detected, the output may be wrong!
_DWORD *__userpurge sub_4975B6@<eax>(int a1@<ebx>, int a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi

  v2 = operator new(0x378u);
  v3 = v2;
  if ( v2 == (_DWORD *)a1 )
    return (_DWORD *)sub_49A511(a2);
  sub_46FAE0(v2, a1);
  v3[216] = a1;
  v3[217] = a1;
  v3[218] = a1;
  v3[219] = a1;
  v3[220] = a1;
  v3[221] = -1;
  *v3 = &off_5E06C8;
  return v3;
}
