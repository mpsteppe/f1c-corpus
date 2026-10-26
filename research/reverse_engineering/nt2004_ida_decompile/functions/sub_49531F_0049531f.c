// positive sp value has been detected, the output may be wrong!
_BYTE *__userpurge sub_49531F@<eax>(_BYTE *a1@<ebx>, int a2)
{
  _BYTE *v2; // eax
  _BYTE *v3; // esi

  v2 = operator new(0x138u);
  v3 = v2;
  if ( v2 == a1 )
    return (_BYTE *)sub_49A511(a2);
  ((void (__thiscall *)(_BYTE *))sub_49D930)(v2);
  sub_506720(v3 + 268);
  v3[308] = (_BYTE)a1;
  *(_DWORD *)v3 = &off_5E3580;
  return v3;
}
