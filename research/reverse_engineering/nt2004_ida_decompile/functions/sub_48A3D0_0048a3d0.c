int __userpurge sub_48A3D0@<eax>(int a1@<edi>, int a2)
{
  int result; // eax
  int v3; // esi

  result = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
  if ( result )
  {
    v3 = *(_DWORD *)(result + 28);
    if ( v3 )
    {
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 156))(v3, a1);
      (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 144))(v3);
      result = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 160))(v3);
      if ( (_BYTE)result )
        dword_600F44 = 1;
    }
  }
  return result;
}
