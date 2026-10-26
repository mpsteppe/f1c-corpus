int __userpurge sub_4108FE@<eax>(int a1@<eax>, int a2@<ecx>, int a3@<edi>, int a4, int a5)
{
  int v5; // eax
  int v6; // ebx
  char v7; // al
  int v8; // ecx
  int v9; // edi
  int i; // esi
  int v11; // eax

  v5 = *(int *)((char *)&dword_92501C + a1);
  v6 = v5 - 1;
  if ( a2 >= 0 )
    v6 = v5 + 1;
  v7 = sub_523BA0(&unk_BE1210, a3);
  v8 = dword_757C10;
  if ( v7 )
  {
    v9 = 0;
    for ( i = 0; i < dword_757C10; ++i )
    {
      if ( !(unsigned __int8)sub_523BD0(&unk_BE1210, *(_DWORD *)(*(&dword_91E088 + i) + 22468)) )
        ++v9;
      v8 = dword_757C10;
    }
  }
  else
  {
    v9 = dword_757C10;
  }
  if ( v6 >= 1 )
  {
    if ( v6 > v9 )
      v6 = 1;
  }
  else
  {
    v6 = v9;
  }
  v11 = 0;
  if ( v8 <= 0 )
    return 0;
  while ( v6 != *(_DWORD *)(*(&dword_91E088 + v11) + 19324) )
  {
    if ( ++v11 >= v8 )
      return 0;
  }
  return *(_DWORD *)(*(&dword_91E088 + v11) + 22468);
}
