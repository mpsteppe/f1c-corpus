void *__thiscall sub_59DF90(int this)
{
  void *result; // eax
  char **v3; // eax
  char *v4; // eax
  char v5; // [esp+4h] [ebp-10h] BYREF

  result = *(void **)(this + 2860);
  if ( result )
  {
    result = (void *)WaitForSingleObject(result, *(_DWORD *)(this + 2864));
    if ( !result || result == (void *)128 )
    {
      htonl(0);
      htons(0);
      v3 = *(char ***)(this + 2844);
      if ( v3 )
      {
        while ( !*v3 || *v3 != &v5 )
        {
          v3 = (char **)v3[1];
          if ( !v3 )
            goto LABEL_11;
        }
        v4 = *v3;
        if ( v4 )
        {
          *((_DWORD *)v4 + 1) = 0;
          *((_DWORD *)v4 + 2) = 0;
          *((_DWORD *)v4 + 3) = 0;
        }
      }
LABEL_11:
      result = *(void **)(this + 2860);
      if ( result )
        return (void *)ReleaseMutex(*(HANDLE *)(this + 2860));
    }
  }
  return result;
}
