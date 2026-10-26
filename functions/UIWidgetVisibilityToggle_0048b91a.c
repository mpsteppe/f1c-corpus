// positive sp value has been detected, the output may be wrong!
int __userpurge sub_48B91A@<eax>(int a1@<eax>, char a2@<bl>, int a3@<esi>, int a4)
{
  int result; // eax

  *(_BYTE *)(a3 + 224) = a2;
  result = (*(int (__cdecl **)(int))(a1 + 44))(1);
  if ( !a2 )
  {
    if ( FieldGetter_79d0(*(_DWORD *)(a3 + 64)) == a3 )
      ((void (__thiscall *)(_DWORD))SimpleSetter_79e0)(*(_DWORD *)(a3 + 64));
    return (*(int (__thiscall **)(int))(*(_DWORD *)a3 + 176))(a3);
  }
  return result;
}
