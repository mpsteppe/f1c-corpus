char *__fastcall sub_561D40(
        char **a1,
        int a2,
        int a3,
        int a4,
        const char *a5,
        const char *a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11)
{
  char *result; // eax

  if ( a1 )
  {
    result = (char *)MallocWrapperForNhMalloc(260);
    *a1 = result;
  }
  else
  {
    result = (char *)&unk_5E4CF8;
  }
  strcpy(result + 8, a5);
  strcpy(result + 72, a6);
  *((_DWORD *)result + 1) = a3;
  *((_DWORD *)result + 55) = 1;
  result[232] = 1;
  *(_DWORD *)result = a4;
  *((_DWORD *)result + 64) = a11;
  *((_DWORD *)result + 50) = a7;
  *((_DWORD *)result + 51) = a8;
  *((_DWORD *)result + 57) = a2;
  *((_DWORD *)result + 54) = 0;
  *((_DWORD *)result + 56) = 0;
  *((_DWORD *)result + 53) = a10;
  *((_DWORD *)result + 52) = a9;
  *((_DWORD *)result + 63) = 0;
  return result;
}

