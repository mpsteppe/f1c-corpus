// positive sp value has been detected, the output may be wrong!
int __usercall sub_48CB57@<eax>(int a1@<ecx>, int a2@<ebx>, int a3@<ebp>)
{
  int result; // eax
  int v4; // ebp
  int v5; // eax
  const CHAR *v6; // edi
  const char *v7; // ecx
  const char *v8; // eax
  const CHAR *v9; // eax
  char *v11; // [esp+4h] [ebp-14h]
  _UNKNOWN *retaddr; // [esp+18h] [ebp+0h]

  ((void (__cdecl *)(int, int))sub_4D0AC0)(a3, a2);
  result = sub_435D30(&dword_B65FF8);
  v4 = 0;
  v11 = (char *)result;
  if ( result > 0 )
  {
    do
    {
      retaddr = 0;
      v5 = sub_435D40();
      sub_615860(v5);
      v6 = v11;
      v7 = v11;
      if ( !v11 )
        v7 = WindowName;
      v8 = &v7[strlen(v7)];
      if ( v8 > v7 )
      {
        while ( *v8 != 46 )
        {
          if ( --v8 <= v7 )
            goto LABEL_9;
        }
        *v8 = 0;
        v6 = v11;
      }
LABEL_9:
      v9 = v6;
      if ( !v6 )
        v9 = WindowName;
      sub_4D93B0(v9, 0, 0, 0, 0, 0, -1, -1, -1, -1);
      if ( v11 )
        j_j__free(v11);
      result = a1;
      ++v4;
    }
    while ( v4 < a1 );
  }
  return result;
}
