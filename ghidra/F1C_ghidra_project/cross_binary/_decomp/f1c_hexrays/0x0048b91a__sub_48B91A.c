// f1c  0x0048b91a  size=50
// positive sp value has been detected, the output may be wrong!
int __userpurge sub_48B91A@<eax>(int a1@<eax>, char a2@<bl>, int a3@<esi>, int a4)
{
  int result; // eax

  *(_BYTE *)(a3 + 224) = a2;
  result = (*(int (__cdecl **)(int))(a1 + 44))(1);
  if ( !a2 )
  {
    if ( sub_4979D0(*(_DWORD *)(a3 + 64)) == a3 )
      ((void (__thiscall *)(_DWORD))sub_4979E0)(*(_DWORD *)(a3 + 64));
    return (*(int (__thiscall **)(int))(*(_DWORD *)a3 + 176))(a3);
  }
  return result;
}
