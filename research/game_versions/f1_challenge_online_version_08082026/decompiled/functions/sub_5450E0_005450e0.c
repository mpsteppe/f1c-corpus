int __stdcall sub_5450E0(_DWORD *a1, int a2, int a3, int a4)
{
  int v4; // eax
  _DWORD *v5; // esi

  if ( a1 )
    *a1 = 0;
  v4 = sub_587C03(572);
  if ( v4 )
    v5 = (_DWORD *)sub_54A600(v4);
  else
    v5 = 0;
  v5[15] = a4;
  if ( sub_54A730((LPCSTR)v5, a2, a3) )
  {
    sub_54A710(v5);
    sub_587BCF(v5);
    return -1;
  }
  else
  {
    if ( a1 )
      *a1 = v5;
    return 0;
  }
}
