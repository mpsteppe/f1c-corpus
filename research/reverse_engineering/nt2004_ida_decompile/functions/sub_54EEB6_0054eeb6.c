int (__cdecl *__cdecl sub_54EEB6(jmp_buf Buf, int *a2))(jmp_buf, int, _DWORD)
{
  int (__cdecl *result)(int *__attribute__((__org_typedef(jmp_buf))), int, _DWORD); // eax
  int v4; // edi
  int *v5; // ebx
  int (__cdecl *v6)(int *__attribute__((__org_typedef(jmp_buf))), int, _DWORD); // [esp+8h] [ebp-4h]
  int *__attribute__((__org_typedef(jmp_buf))) Bufa; // [esp+14h] [ebp+8h]

  result = (int (__cdecl *)(int *__attribute__((__org_typedef(jmp_buf))), int, _DWORD))sub_54F2E0(Buf);
  v4 = Buf[47];
  Buf[48] = v4;
  if ( (int)result > 0 )
  {
    v6 = result;
    do
    {
      v5 = a2;
      if ( v4 )
      {
        Bufa = (int *)v4;
        do
        {
          result = sub_54EB0F(Buf, *v5++, 0);
          Bufa = (int *)((char *)Bufa - 1);
        }
        while ( Bufa );
      }
      v6 = (int (__cdecl *)(int *__attribute__((__org_typedef(jmp_buf))), int, _DWORD))((char *)v6 - 1);
    }
    while ( v6 );
  }
  return result;
}
