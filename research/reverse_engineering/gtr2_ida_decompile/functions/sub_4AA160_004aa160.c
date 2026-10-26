int __thiscall sub_4AA160(_DWORD *this)
{
  const CHAR *v2; // eax
  const CHAR *v3; // esi

  v2 = (const CHAR *)this[69];
  if ( !v2 )
    v2 = WindowName;
  sub_615860(v2);
  if ( *(_DWORD *)dword_B72314 != 4 )
  {
    v3 = (const CHAR *)this[69];
    if ( !v3 )
      v3 = WindowName;
    sub_615860(v3);
  }
  return 0;
}
