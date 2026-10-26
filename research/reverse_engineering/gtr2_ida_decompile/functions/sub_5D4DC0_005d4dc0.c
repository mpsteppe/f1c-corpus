_DWORD *__userpurge sub_5D4DC0@<eax>(_DWORD *a1@<ecx>, int a2@<edi>, int a3)
{
  int v4; // eax
  int v5; // ecx
  _DWORD *result; // eax
  int v7; // ecx

  v4 = a1[14];
  v5 = a1[15];
  a1[14] = ++v4;
  if ( v5 >= v4 )
  {
    v7 = a1[16];
    result = (_DWORD *)(v7 + 4 * a1[14] - 4);
    if ( v7 + 4 * a1[14] != 4 )
      *result = a3;
  }
  else
  {
    sub_4F14D0(a2);
    return (_DWORD *)off_16C9778(a3);
  }
  return result;
}
