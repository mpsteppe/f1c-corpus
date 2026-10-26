void __stdcall sub_526AF0(int a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  _DWORD *v5; // eax

  if ( dword_7DA98C )
  {
    v5 = (_DWORD *)sub_5A95A0(a1);
    if ( a2 )
      *a2 = v5[2];
    if ( a3 )
      *a3 = v5[3];
    if ( a4 )
      *a4 = v5[5];
    if ( a5 )
      *a5 = v5[6];
  }
}
