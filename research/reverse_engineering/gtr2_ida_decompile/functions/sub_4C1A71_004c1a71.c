// positive sp value has been detected, the output may be wrong!
int __userpurge sub_4C1A71@<eax>(_DWORD *a1@<edi>, int a2)
{
  if ( sub_4BFDE0(a1, 6) )
    return (*(int (__thiscall **)(_DWORD *, int))(*a1 + 28))(a1, 6);
  else
    return ((int (__stdcall *)(int))sub_4CC3A1)(a2);
}
