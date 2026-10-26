int __stdcall sub_495930(_DWORD *a1)
{
  _DWORD *v1; // esi

  v1 = a1;
  if ( !a1 )
    return -1;
  do
  {
    (*(void (__thiscall **)(_DWORD *))(*v1 + 160))(v1);
    sub_495930(v1[36]);
    v1 = (_DWORD *)v1[35];
  }
  while ( v1 );
  return 0;
}
