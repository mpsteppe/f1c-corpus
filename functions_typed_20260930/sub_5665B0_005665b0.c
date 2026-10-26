void __thiscall sub_5665B0(int this, const char *a2)
{
  unsigned int v3; // kr04_4
  unsigned int v4; // kr08_4
  int v5; // esi
  char *v6; // edi

  if ( a2 )
  {
    if ( *(_DWORD *)this )
    {
      v3 = strlen(*(const char **)this) + 1;
      v4 = strlen(a2) + 1;
      v5 = v4 - 1 + v3 - 1;
      if ( *(_DWORD *)(this + 4) < v5 )
      {
        v6 = (char *)OperatorNewNhMallocWrapper(v4 + v3 - 1);
        strcpy(v6, *(const char **)this);
        FreeWrapper_7bcf(*(LPVOID *)this);
        *(_DWORD *)this = v6;
        *(_DWORD *)(this + 4) = v5;
      }
      strcat(*(char **)this, a2);
    }
    else
    {
      StringCopyWithBufferRealloc(a2);
    }
  }
}

