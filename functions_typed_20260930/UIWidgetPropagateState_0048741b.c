// positive sp value has been detected, the output may be wrong!
char __userpurge sub_48741B@<al>(_BYTE *a1@<ecx>, char a2@<bl>, _DWORD *a3@<esi>, int a4)
{
  int v4; // eax
  char v5; // al
  _DWORD *v6; // esi
  int v8; // [esp-4h] [ebp-4h]

  StateChangeNotification(a1, v8);
  if ( a2 )
  {
    LOBYTE(v4) = (*(int (__thiscall **)(_DWORD *, int))(*a3 + 64))(a3, 4);
  }
  else
  {
    v5 = ((int (__thiscall *)(_DWORD *))RangeCheck)(a3);
    LOBYTE(v4) = StateDependentVTableDispatch(a3, v5);
  }
  v6 = (_DWORD *)a3[36];
  if ( v6 )
  {
    do
    {
      (*(void (__thiscall **)(_DWORD *, char))(*v6 + 56))(v6, a2);
      v4 = StructFieldAccessor(v6);
      v6 = (_DWORD *)v4;
    }
    while ( v4 );
  }
  return v4;
}

