int __userpurge sub_67347A@<eax>(char *a1@<eax>, int a2@<ebx>, unsigned int a3)
{
  unsigned int v3; // edi
  bool v4; // zf
  int v5; // esi
  char v6; // cl

  v3 = 0;
  v4 = a3 == 0;
  if ( a3 )
  {
    v5 = a2 - (_DWORD)a1;
    while ( 1 )
    {
      v6 = a1[v5];
      if ( v6 < *a1 )
        break;
      if ( v6 > *a1 )
        return 1;
      ++v3;
      ++a1;
      if ( v3 >= a3 )
      {
        v4 = v3 == a3;
        return v4 && *(_BYTE *)(v3 + a2);
      }
    }
    return -1;
  }
  else
  {
    return v4 && *(_BYTE *)(v3 + a2);
  }
}
